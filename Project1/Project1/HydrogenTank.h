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

