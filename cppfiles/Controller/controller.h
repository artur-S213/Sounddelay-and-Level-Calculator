// #include "CoreCalculations.h"
#include <QObject>
#include <QtQml/qqmlregistration.h>


class Controller : public QObject {
  Q_OBJECT
  QML_ELEMENT
  QML_SINGLETON

  Q_PROPERTY(float distance READ getDistance WRITE setDistance NOTIFY distanceChanged)
  Q_PROPERTY(float soundLevelL1 READ getSoundLevelL1 WRITE setSoundLevelL1 NOTIFY soundLevelL1Changed)

  Q_PROPERTY(float delay READ getDelay NOTIFY delayChanged)
  Q_PROPERTY(float soundLevelL2 READ getSoundLevelL2 NOTIFY soundLevelL2Changed)
  Q_PROPERTY(float dropLevel READ getDropLevel NOTIFY dropLevelChanged)
  Q_PROPERTY(float adjustmentLevel READ getAdjustmentLevel NOTIFY adjustmentLevelChanged)
  Q_PROPERTY(float setpoint READ getSetpoint NOTIFY setpointChanged)

  private:
    float m_distance;
    float m_soundLevelL1;
    float m_delay;
    float m_soundLevelL2;
    float m_dropLevel;
    float m_adjustmentLevel;
    float m_setpoint;

    void calculateAndUpdateValues();

  public:

    // CONSTRUCTOR
    explicit Controller (QObject *parent = nullptr) : QObject(parent),
          m_distance(0.0f),
          m_soundLevelL1(0.0f),
          m_delay(0.0f),
          m_soundLevelL2(0.0f),
          m_dropLevel(0.0f),
          m_adjustmentLevel(0.0f),
          m_setpoint(0.0f)
    {}

    // ### SETTER ######################################
    void setDistance(float distance);

    void setSoundLevelL1(float level);

    // ### GETTER ######################################

    float getDistance() const;

    float getSoundLevelL1() const;

    float getDelay() const;

    float getSoundLevelL2() const;

    float getDropLevel()const;

    float getAdjustmentLevel()const;

    float getSetpoint()const;


  signals:
    void distanceChanged();
    void soundLevelL1Changed();
    void delayChanged();
    void soundLevelL2Changed();
    void dropLevelChanged();
    void adjustmentLevelChanged();
    void setpointChanged();

};
