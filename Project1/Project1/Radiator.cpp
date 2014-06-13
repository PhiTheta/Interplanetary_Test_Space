#include "Radiator.h"

void Radiator::initializeSystem()
{
	heat = 0.0;
}

void Radiator::calculateStep()
{
	double in = getPortValuesSum(collectAllActiveSubSystemsWithClassifier(inputStreams,"Heat[J]"));
	double out = getPortValuesSum(collectAllActiveSubSystemsWithClassifier(outputStreams,"Heat[J]"));

	if(status == ACTIVE)
	{
		heat = heat + in - out;
		resetAllPortValues();
	}
}

void Radiator::writeAttributesToMap()
{
	attributes.insert(std::pair<std::string,double>("Heat[J]",heat));
}


