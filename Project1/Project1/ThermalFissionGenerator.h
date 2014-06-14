#ifndef __THERMAL_FISSION_GENERATOR_H_INCLUDED__
#define __THERMAL_FISSION_GENERATOR_H_INCLUDED__
#include "SubSystem.h"

class ThermalFissionGenerator: public SubSystem
{
private:
	double temp;
	double power;
public:
	ThermalFissionGenerator(std::string name):SubSystem(name){initializeSystem();};
	void initializeSystem();
	void calculateStep();
	void writeAttributesToMap();
};

#endif