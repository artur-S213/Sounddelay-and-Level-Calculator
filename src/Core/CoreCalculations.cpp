#include "CoreCalculations.h"
#include <math.h>
#include <cmath>

AcousticCalcResults CoreCalculations::calculateAllValues(float distance, float soundLevel)
{
    AcousticCalcResults res;

    // Delay = distance/343 *1000
    res.delay = (distance / 343) * 1000;

    // soundLevelL2 =  soundlevelL1 - 20 * LOG_10(distance)
    if (distance <= 0.0)
    {
        res.soundLevelL2 = 0.0;
    }
    else
    {
        float calL2 = soundLevel - (20 * (std::log10(distance)));
        res.soundLevelL2 = (calL2 < 0.0) ? 0 : calL2;
    }

    // =soundLevelL1 - soundLevelL2
    res.dropLevel = soundLevel - res.soundLevelL2;

    // =WENN(droplevel<11;0; WENN(droplevel>11;droplevel-11))
    //  => Wenn der Abfallpegel kleiner 11 -> 0 sonst Abfallpegel - 11
    res.adjustmentLevel = (res.dropLevel < ((float)11)) ? 0 : res.dropLevel - ((float)11);

    // =soundLevelL1 - Einstellspegel
    res.setpoint = soundLevel - res.adjustmentLevel;

    return res;
}
