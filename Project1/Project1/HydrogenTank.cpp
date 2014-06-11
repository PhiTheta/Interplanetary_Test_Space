#include "HydrogenTank.h"


void HydrogenTank::initializeSystem()
{
	amount = 5000.0;
}

void HydrogenTank::calculateStep()
{
	double in = inputStreams.find("H2")->second->getValue;
	double out = outputStreams.find("H2")->second->getValue;

	if(status == ACTIVE)
	{
		amount = amount + in - out;
		inputStreams.find("H2")->second->setValue(0.0);
		outputStreams.find("H2")->second->setValue(0.0);
	}
	
}

void HydrogenTank::writeAttributesToMap()
{
	attributes.insert(std::pair<std::string,double>("Amount[kg]",amount));
}