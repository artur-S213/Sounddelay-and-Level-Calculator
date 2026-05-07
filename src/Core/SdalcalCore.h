#ifndef SDALCALCORE_H
#define SDALCALCORE_H

struct SdalcalCoreResults {
    float delay;
    float soundLevelL2;
    float dropLevel;
    float adjustmentLevel;
    float setpoint;
};

class SdalcalCore {
public:

    static SdalcalCoreResults calculateAllValues(float distance, float levelL1);
};

#endif
