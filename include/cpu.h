#ifndef CPU_H
#define CPU_H

#include <vector>

class CPU{
    public:
        float Utilization(); //return cpu utilization

    private:
        long prevActive{0};
        long prevIdle{0};
        long prevTotal{0};

};

#endif 