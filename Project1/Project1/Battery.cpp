#include "Battery.h"


void Battery::initializeSystem()
{
	charge = 0.0;
	maxCharge = 5000.0;
}

void Battery::calculateStep()
{
	std::vector<Port*> input = collectAllActiveSubSystemsWithClassifier(inputStreams,"Energy[J]");
	std::vector<Port*> output = collectAllActiveSubSystemsWithClassifier(outputStreams,"Energy[J]");
	double in = getPortValuesSum(input);
	double out = getPortValuesSum(output);

	if(operationMode == ACTIVE)
	{
		if(charge<maxCharge)
		{
			writePortValuesEqual(input,1.0);
			charge = charge + 1.0;
		}

		
	}
	
}

void Battery::writeAttributesToMap()
{
	attributes["Energy[J]"] = charge;
}