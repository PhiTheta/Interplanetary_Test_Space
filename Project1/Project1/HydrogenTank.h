#ifndef __HYDROGEN_TANK_H_INCLUDED__
#define __HYDROGEN_TANK_H_INCLUDED__
#include "SubSystem.h"

class HydrogenTank: public SubSystem
{
private:
	double amount;
public:
	HydrogenTank(std::string name):SubSystem(name){initializeSystem();};
	void initializeSystem();
	void calculateStep();
	void writeAttributesToMap();
};

#endif