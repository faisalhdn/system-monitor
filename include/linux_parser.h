//read the normalize raw text files /proc/

#include <iostream>
#include <vector>

using namespace std;

namespace LinuxParser {
    const std::string kProcDirectory{"/proc/"};
    const std::string kMeminfoFilename{"/meminfo"};
    const std::string kStatFilename{"/stat"};
    const std::string kOSPath{"/etc/os-release"};
    const std::string kPasswordPath{"/etc/passwd"};

    float MemoryUtilization();
    long UpTime();
    std::vector<int> Pids();
    int TotalProcesses();
    int RunningProcesses();
    std::string OperatingSystem();
    std::string Kernel();

    std::vector<std::string> CpuUtilization();
    long Jiffies();
    long ActiveJiffies();
    long ActiveJiffies(int pid);
    long IdleJiffies();

    std::string Command(int pid);
    std::string Ram(int pid);
    std::string Uid(int pid);
    std::string User(int pid);
    long int UpTime(int pid);
}