#ifndef __RADIATOR_H_INCLUDED__
#define __RADIATOR_H_INCLUDED__


#include "SubSystem.h"

class Radiator: public SubSystem
{
private:
	double heat;
public:
	void initializeSystem();
	void calculateStep();
	void writeAttributesToMap();
};

#endif