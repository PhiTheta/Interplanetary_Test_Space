#ifndef __OXYGEN_TANK_H_INCLUDED__
#define __OXYGEN_TANK_H_INCLUDED__
#include "SubSystem.h"

class OxygenTank: public SubSystem
{
private:
	double amount;
public:
	OxygenTank(std::string name):SubSystem(name){initializeSystem();};
	void initializeSystem();
	void calculateStep();
	void writeAttributesToMap();
};

#endif