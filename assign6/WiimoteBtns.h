#ifndef WIIMOTEBTNS_H
#define WIIMOTEBTNS_H
#include "RoboticArm.h"

class WiimoteBtns
{
private:
	int fieldid;
  int accelid;

public:
	WiimoteBtns();
	~WiimoteBtns();
  int checkAngle(int angle);
	void ButtonEvent(RoboticArm *arm, int servo, int angle);
	void writeToAllServos(RoboticArm *arm, int ba, int bi, int el, int wr, int gr);
	void Listen();
};

#endif
