#ifndef __BATTERY_H_INCLUDED__
#define __BATTERY_H_INCLUDED__
#include "SubSystem.h"

class Battery: public SubSystem
{
private:
	double charge;
public:
	void initializeSystem();
	void calculateStep();
	void writeAttributesToMap();
};

#endif