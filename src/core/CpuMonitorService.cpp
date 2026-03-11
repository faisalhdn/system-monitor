#include "CpuMonitorService.hpp"

CpuMonitorService::CpuMonitorService(ICpuReader& reader)
	: reader_(reader) {}

double CpuMonitorService::getCpuUsage() {
	CpuSnapshot currentSnapshot = reader_.readSnapshot();

	if (!hasPreviousSnapshot_) {
		previousSnapshot_ = currentSnapshot;
		hasPreviousSnapshot_ = true;
		return 0.0;
	}

	if (currentSnapshot.idle < previousSnapshot_.idle ||
		currentSnapshot.kernel < previousSnapshot_.kernel ||
		currentSnapshot.user < previousSnapshot_.user) {
		previousSnapshot_ = currentSnapshot;
		return 0.0;
	}

	std::uint64_t idleDelta = currentSnapshot.idle - previousSnapshot_.idle;
	std::uint64_t kernelDelta = currentSnapshot.kernel - previousSnapshot_.kernel;
	std::uint64_t userDelta = currentSnapshot.user - previousSnapshot_.user;

	std::uint64_t totalDelta = kernelDelta + userDelta;
	std::uint64_t activeDelta = totalDelta - idleDelta;

	previousSnapshot_ = currentSnapshot;

	if (totalDelta == 0) {
		return 0.0;
	}

	return (static_cast<double>(activeDelta) / static_cast<double>(totalDelta)) * 100.0;
}
