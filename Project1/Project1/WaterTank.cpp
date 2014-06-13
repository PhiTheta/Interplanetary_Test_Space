#include "WaterTank.h"


void WaterTank::initializeSystem()
{
	amount = 5000.0;
}

void WaterTank::calculateStep()
{
	double in = getPortValuesSum(collectAllActiveSubSystemsWithClassifier(inputStreams,"H2O"));
	double out = getPortValuesSum(collectAllActiveSubSystemsWithClassifier(outputStreams,"H2O"));

	if(status == ACTIVE)
	{
		amount = amount + in - out;
		resetAllPortValues();
	}

	
}

void WaterTank::writeAttributesToMap()
{
	attributes.insert(std::pair<std::string,double>("Amount[kg]",amount));
}