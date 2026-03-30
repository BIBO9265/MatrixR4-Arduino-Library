#ifndef AXISCONTROLLER_H
#define AXISCONTROLLER_H

#include <Arduino.h>
#include <MatrixMiniR4.h>
#include <UIController.h>

class AXISController {
private:
    UIController EMS;
public:
    AXISController(); 
    
    void begin();
    void EMSoff();
    void reset();
    void AxisYdist(int speed, int dist);
    void AxisYTouch(int speed);
    void AxisXTouch();
    void AxisXTime(int speed, int time);
    void AxisZdist(int angle);
    void AxisCatchdist(int angle);
};

#endif // AXISCONTROLLER_H