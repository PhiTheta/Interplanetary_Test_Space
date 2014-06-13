#include "Battery.h"


void Battery::initializeSystem()
{
	charge = 5000.0;
}

void Battery::calculateStep()
{
	double in = getPortValuesSum(collectAllActiveSubSystemsWithClassifier(inputStreams,"Energy[J]"));
	double out = getPortValuesSum(collectAllActiveSubSystemsWithClassifier(outputStreams,"Energy[J]"));

	if(status == ACTIVE)
	{
		charge = charge + in - out;
		resetAllPortValues();
	}
	
}

void Battery::writeAttributesToMap()
{
	attributes.insert(std::pair<std::string,double>("Energy[J]",charge));
}