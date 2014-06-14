#ifndef __FUELCELL_H_INCLUDED__
#define __FUELCELL_H_INCLUDED__
#include "SubSystem.h"

class FuelCell: public SubSystem
{
private:
	double efficiency;
	double coolingWaterPerSecond;
	double currentPower;
public:
	FuelCell(std::string name):SubSystem(name){initializeSystem();};
	void initializeSystem();
	void calculateStep();
	void writeAttributesToMap();
};

#endif