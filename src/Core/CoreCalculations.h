#ifndef CORECALCULATIONS_H
#define CORECALCULATIONS_H

struct AcousticCalcResults {
    float delay;
    float soundLevelL2;
    float dropLevel;
    float adjustmentLevel;
    float setpoint;
};

class CoreCalculations {
public:

    static AcousticCalcResults calculateAllValues(float distance, float levelL1);
};

#endif
