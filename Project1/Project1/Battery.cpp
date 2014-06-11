#include "Battery.h"


void Battery::initializeSystem()
{
	charge = 5000.0;
}

void Battery::calculateStep()
{
	double in = inputStreams.find("Energy[J]")->second->getValue;
	double out = outputStreams.find("Energy[J]")->second->getValue;

	if(status == ACTIVE)
	{
		charge = charge + in - out;
		inputStreams.find("Energy[J]")->second->setValue(0.0);
		outputStreams.find("Energy[J]")->second->setValue(0.0);
	}
	
}

void Battery::writeAttributesToMap()
{
	attributes.insert(std::pair<std::string,double>("Energy[J]",charge));
}