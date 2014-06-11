#include "ThermalFissionGenerator.h"


void ThermalFissionGenerator::initializeSystem()
{
	temp = 300.0;
	power = 5000000.0;
}

void ThermalFissionGenerator::calculateStep()
{
	outputStreams.find("Energy[J]")->second->getValue;

	/*
	Es wird angenommen, dass die Leistung des Generators alle angeschlossenen
	Verbraucher mit Elektrischer ENergie versorgt. Die restliche Energie wird
	in Form von Wärme[J] an die Radiatoren abgegeben.
	*/
	if(status == ACTIVE)
	{
		double elEnergy;
		double heatEnergy;
		elEnergy = outputStreams.find("Energy[J]")->second->getValue;

		Das muss ich noch machen!!!

		inputStreams.find("Energy[J]")->second->setValue(0.0);
		outputStreams.find("Energy[J]")->second->setValue(0.0);
	}
	
}

void ThermalFissionGenerator::writeAttributesToMap()
{
	attributes.insert(std::pair<std::string,double>("Energy[J]",charge));
}