#pragma once

#include <cstdint>

struct CpuSnapshot {
	std::uint64_t idle{ 0 };
	std::uint64_t kernel{ 0 };
	std::uint64_t user{ 0 };
};
