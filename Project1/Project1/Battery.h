#include "SubSystem.h"

class Battery: public SubSystem
{
private:
	double charge;
public:
	void initializeSystem();
	void calculateStep();
	void writeAttributesToMap();
};

