#include <iostream>
#include <thread>
#include <chrono>

#include "core/CpuMonitorService.hpp"

#ifdef _WIN32
#include "platform/windows/WindowsCpuReader.hpp"
#elif __linux__
#include "platform/linux/LinuxCpuReader.hpp"
#endif

int main() {
#ifdef _WIN32
	WindowsCpuReader reader;
#elif __linux__
	LinuxCpuReader reader;
#else
	std::cout << "Not a supported platform" << std::endl;
	return 1;
#endif

	CpuMonitorService cpuMonitor(reader);

	while (true) {
		try {
			double cpuUsage = cpuMonitor.getCpuUsage();
			std::cout << "CPU Usage: " << cpuUsage << "%" << std::endl;
		}
		catch (const std::exception& e) {
			std::cerr << "Error Reading CPU Usage: " << e.what() << std::endl;
		}

		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	return 0;
}