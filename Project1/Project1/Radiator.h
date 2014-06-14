#ifndef __RADIATOR_H_INCLUDED__
#define __RADIATOR_H_INCLUDED__


#include "SubSystem.h"

class Radiator: public SubSystem
{
private:
	double heat;
public:
	Radiator(std::string name):SubSystem(name){initializeSystem();};
	void initializeSystem();
	void calculateStep();
	void writeAttributesToMap();
};

#endif