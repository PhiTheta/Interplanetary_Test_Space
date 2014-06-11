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

