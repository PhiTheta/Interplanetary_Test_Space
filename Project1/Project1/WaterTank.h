#ifndef __WATER_TANK_H_INCLUDED__
#define __WATER_TANK_H_INCLUDED__
#include "SubSystem.h"

class WaterTank: public SubSystem
{
private:
	double amount;
public:
	void initializeSystem();
	void calculateStep();
	void writeAttributesToMap();
};

#endif