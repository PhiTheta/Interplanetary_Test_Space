#include "SubSystem.h"

class Thruster: public SubSystem
{
private:
	double thrust;
	double isp;
	std::string group;
public:
	void initializeSystem();
	void calculateStep();
	void writeAttributesToMap();
};

