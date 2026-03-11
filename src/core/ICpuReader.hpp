#pragma once

#include "CpuSnapshot.hpp"

class ICpuReader {
public:
	virtual ~ICpuReader() = default;
	virtual CpuSnapshot readSnapshot() const = 0;
};
