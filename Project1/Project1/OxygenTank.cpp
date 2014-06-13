#include "OxygenTank.h"


void OxygenTank::initializeSystem()
{
	amount = 5000.0;
}

void OxygenTank::calculateStep()
{
	double in = getPortValuesSum(collectAllActiveSubSystemsWithClassifier(inputStreams,"O2"));
	double out = getPortValuesSum(collectAllActiveSubSystemsWithClassifier(outputStreams,"O2"));

	if(status == ACTIVE)
	{
		amount = amount + in - out;
		resetAllPortValues();
	}
}

void OxygenTank::writeAttributesToMap()
{
	attributes.insert(std::pair<std::string,double>("Amount[kg]",amount));
}