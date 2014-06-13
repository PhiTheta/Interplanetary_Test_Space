#include "HydrogenTank.h"


void HydrogenTank::initializeSystem()
{
	amount = 5000.0;
}

void HydrogenTank::calculateStep()
{
	double in = getPortValuesSum(collectAllActiveSubSystemsWithClassifier(inputStreams,"H2"));
	double out = getPortValuesSum(collectAllActiveSubSystemsWithClassifier(outputStreams,"H2"));

	if(status == ACTIVE)
	{
		amount = amount + in - out;
		resetAllPortValues();
	}
	
}

void HydrogenTank::writeAttributesToMap()
{
	attributes.insert(std::pair<std::string,double>("Amount[kg]",amount));
}