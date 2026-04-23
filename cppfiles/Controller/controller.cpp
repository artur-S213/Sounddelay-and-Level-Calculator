#include "controller.h"
#include "CoreCalculations.h"
#include <QObject>
#include <QtQml/qqmlregistration.h>
#include <QQmlApplicationEngine>

// ### PRIVATE FUNCITONS ######################################

void Controller::calculateAndUpdateValues()
{
    AcousticCalcResults calcResults = CoreCalculations::calculateAllValues(m_distance, m_soundLevelL1);

    // Update Values
    m_delay = calcResults.delay;
    qDebug() << "Wert von Delay = " << calcResults.delay;
    m_soundLevelL2 = calcResults.soundLevelL2;
    m_dropLevel = calcResults.dropLevel;
    m_adjustmentLevel = calcResults.adjustmentLevel;
    m_setpoint = calcResults.setpoint;

    // Send Signals to UI
    emit delayChanged();
    emit soundLevelL2Changed();
    emit dropLevelChanged();
    emit adjustmentLevelChanged();
    emit setpointChanged();
};

// ### PUBLIC FUNCITONS ######################################

// ### SETTER ######################################

void Controller::setDistance(float distance)
{
    qDebug() << "Distance has changed = " << distance;
    if (qFuzzyCompare(m_distance, distance))
        return;
    m_distance = (distance < 0.0) ? 0.0 : distance;
    emit distanceChanged();
    calculateAndUpdateValues();
}

void Controller::setSoundLevelL1(float level)
{
    if (qFuzzyCompare(m_soundLevelL1, level))
        return;
    m_soundLevelL1 = (level < 0.0) ? 0 : level;
    emit soundLevelL1Changed();
    calculateAndUpdateValues();
}

// ### GETTER ######################################

float Controller::getDistance() const
{
    return m_distance;
}

float Controller::getSoundLevelL1() const
{
    return m_soundLevelL1;
}

float Controller::getDelay() const
{
    return m_delay;
}

float Controller::getSoundLevelL2() const
{
    return m_soundLevelL2;
}

float Controller::getDropLevel() const
{
    return m_dropLevel;
}

float Controller::getAdjustmentLevel() const
{
    return m_adjustmentLevel;
}

float Controller::getSetpoint() const
{
    return m_setpoint;
}
