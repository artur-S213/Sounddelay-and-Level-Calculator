#include <QtTest>
#include "CoreCalculations.h"


class TestCoreCalculations : public QObject {

    Q_OBJECT

private:
    float delay_actual = 0.0f;
    float soundLevelL2_actual = 0.0f;
    float dropLevel_actual = 0.0f;
    float adjustmentLevel_actual = 0.0f;
    float setpoint_actual = 0.0f;

    float delay_expected = 0.0f;
    float soundLevelL2_expected = 0.0f;
    float dropLevel_expected = 0.0f;
    float adjustmentLevel_expected = 0.0f;
    float setpoint_expected = 0.0f;


  private slots:

    void verify(float actual, float expected, float tolerance){
        QVERIFY(std::abs(actual - expected) < tolerance);

    }

    /**
     * @brief Test with normal values
     */
    void test_normal_values1(){
        auto res = CoreCalculations::calculateAllValues(10.00, 70.00);

        float tolerance = 0.1;

        //Delay
        verify(res.delay, 29.2, tolerance);

        // SoundLevelL2
        verify(res.soundLevelL2, 50.0, tolerance);

        // DropLevel
        verify(res.dropLevel, 20.0, tolerance);

        // AdjustmentLevel
        verify(res.adjustmentLevel, 9.0, tolerance);

        //Setpoint
        verify(res.setpoint, 61.0, tolerance);
    }

    /**
     * @brief Test if distance equals 0
     */
    void test_Distance_equals_Zero(){
        auto res = CoreCalculations::calculateAllValues(0.0f, 70.00);

        float tolerance = 0.01;

        //Delay
        verify(res.delay, 0.0f, tolerance);

        // SoundLevelL2
        verify(res.soundLevelL2, 0.0f, tolerance);

        // DropLevel
        verify(res.dropLevel, 70.0, tolerance);

        // AdjustmentLevel
        verify(res.adjustmentLevel, 59.00, tolerance);

        //Setpoint
        verify(res.setpoint, 11.00, tolerance);
    }

    /**
     * @brief Test if soundlevel 1 equals 0
     */
    void test_Level_equals_Zero(){
        auto res = CoreCalculations::calculateAllValues(1.0, 0.0f);

        float tolerance = 0.1;
        float expected = 0.0f;

        //Delay
        verify(res.delay, 2.9, tolerance);

        // SoundLevelL2
        verify(res.soundLevelL2, expected, tolerance);

        // DropLevel
        verify(res.dropLevel, expected, tolerance);

        // AdjustmentLevel
        verify(res.adjustmentLevel, expected, tolerance);

        //Setpoint
        verify(res.setpoint, expected, tolerance);
    }


    /**
     * @brief Test the correct Behaviour of the adjustmentlevel setting
     */
    void test_AdjustmentLevel(){
        float tolerance = 0.009;

        // droplevel == 11 && adjustmentlevel == 0
        auto res = CoreCalculations::calculateAllValues(3.550, 70.00);


        verify(res.dropLevel, 11.00, tolerance);
        verify(res.adjustmentLevel, 0.0f, tolerance);

        // droplevel > 11 && adjustmentlevel != 0
        res = CoreCalculations::calculateAllValues(3.551, 70.00);

        QVERIFY(res.dropLevel > 11.00);
        QVERIFY(res.adjustmentLevel > 0.0f);


    }
};

QTEST_MAIN(TestCoreCalculations)
#include "test_CoreCalculations.moc"
