#ifndef __HYDROGEN_TANK_H_INCLUDED__
#define __HYDROGEN_TANK_H_INCLUDED__
#include "SubSystem.h"

class HydrogenTank: public SubSystem
{
private:
	double amount;
public:
	void initializeSystem();
	void calculateStep();
	void writeAttributesToMap();
};

#endif