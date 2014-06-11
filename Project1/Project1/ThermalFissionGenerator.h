#include "SubSystem.h"

class ThermalFissionGenerator: public SubSystem
{
private:
	double temp;
	double power;
public:
	void initializeSystem();
	void calculateStep();
	void writeAttributesToMap();
};

