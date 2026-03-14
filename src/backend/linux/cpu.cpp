#include "system-monitor/include/cpu.h"
#include "system-monitor/include/linux_parser.h"

float CPU::Utilization(){

    long active = LinuxParser::ActiveJiffies();
    long idle = LinuxParser::IdleJiffies();
    long total = active + idle;

    
}