#include "OxygenTank.h"


void OxygenTank::initializeSystem()
{
	amount = 5000.0;
}

void OxygenTank::calculateStep()
{
	double in = inputStreams.find("O2")->second->getValue;
	double out = outputStreams.find("O2")->second->getValue;

	if(status == ACTIVE)
	{
		amount = amount + in - out;
		inputStreams.find("O2")->second->setValue(0.0);
		outputStreams.find("O2")->second->setValue(0.0);
	}
}

void OxygenTank::writeAttributesToMap()
{
	attributes.insert(std::pair<std::string,double>("Amount[kg]",amount));
}