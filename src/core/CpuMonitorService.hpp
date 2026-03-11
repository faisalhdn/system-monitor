#pragma once

#include "ICpuReader.hpp"

class CpuMonitorService {
public:
	explicit CpuMonitorService(ICpuReader& reader);
	double getCpuUsage();

private:
	ICpuReader& reader_;
	CpuSnapshot previousSnapshot_{};
	bool hasPreviousSnapshot_{ false };
};
