#pragma once

#include <cstdint>
#include <Windows.h>

#include "core/ICpuReader.hpp"

class WindowsCpuReader : public ICpuReader {
public:
	CpuSnapshot readSnapshot() const override;

private:
	static std::uint64_t fileTimeToUInt64(const FILETIME& fileTime);
};
