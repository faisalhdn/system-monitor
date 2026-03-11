#include <stdexcept>

#include "WindowsCpuReader.hpp"

std::uint64_t WindowsCpuReader::fileTimeToUInt64(const FILETIME& fileTime) {
	ULARGE_INTEGER value;
	value.LowPart = fileTime.dwLowDateTime;
	value.HighPart = fileTime.dwHighDateTime;
	return value.QuadPart;
}

CpuSnapshot WindowsCpuReader::readSnapshot() const {
	FILETIME idleTime{};
	FILETIME kernelTime{};
	FILETIME userTime{};

	if (!GetSystemTimes(&idleTime, &kernelTime, &userTime)) {
		throw std::runtime_error("GetSystemTimes failed");
	}

	CpuSnapshot snapshot;
	snapshot.idle = fileTimeToUInt64(idleTime);
	snapshot.kernel = fileTimeToUInt64(kernelTime);
	snapshot.user = fileTimeToUInt64(userTime);

	return snapshot;
}
