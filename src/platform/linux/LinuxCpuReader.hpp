#pragma once

#include "core/ICpuReader.hpp"

class LinuxCpuReader : public ICpuReader {
public:
	CpuSnapshot readSnapshot() const override;
};
