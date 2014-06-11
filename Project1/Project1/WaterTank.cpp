#include "WaterTank.h"


void WaterTank::initializeSystem()
{
	amount = 5000.0;
}

void WaterTank::calculateStep()
{
	double in = inputStreams.find("H2O")->second->getValue;
	double out = outputStreams.find("H2O")->second->getValue;

	if(status == ACTIVE)
	{
		amount = amount + in - out;
		inputStreams.find("H2O")->second->setValue(0.0);
		outputStreams.find("H2O")->second->setValue(0.0);
	}

	
}

void WaterTank::writeAttributesToMap()
{
	attributes.insert(std::pair<std::string,double>("Amount[kg]",amount));
}