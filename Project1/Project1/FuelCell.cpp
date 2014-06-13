#include "FuelCell.h"

void FuelCell::initializeSystem()
{
	efficiency = 0.4;
	coolingWaterPerSecond = 4.0;
	currentPower = 0.0;
}

void FuelCell::calculateStep()
{

	if(status == ACTIVE)
	{
		std::vector<Port*> activeConsumers = collectAllActiveSubSystemsWithClassifier(outputStreams,"Energy[J]");
		std::vector<Port*> waterTanksIn = collectAllActiveSubSystemsWithClassifier(inputStreams,"H2O");
		std::vector<Port*> waterTanksOut = collectAllActiveSubSystemsWithClassifier(inputStreams,"H2O");
		std::vector<Port*> hydrogenTanksIn = collectAllActiveSubSystemsWithClassifier(inputStreams,"H2");
		std::vector<Port*> oxygenTanksIn = collectAllActiveSubSystemsWithClassifier(inputStreams,"O2");
		std::vector<Port*> radiators = collectAllActiveSubSystemsWithClassifier(outputStreams,"Heat[J]");
		//Konstanter Eingangswasserstrom
		double waterIntake = coolingWaterPerSecond*simTime;
		//Die benötigte Energie wird anhand der angschlossenen Verbraucher ermittelt
		double requiredEnergy = getPortValuesSum(activeConsumers);
		double generatedEnergy = requiredEnergy / efficiency;
		currentPower = generatedEnergy/simTime;
		//Erfundene Formel für den Massenstrom im verhältnis zur Energie
		double coefficient = 0.01;
		double totalMass = generatedEnergy * coefficient;
		double heat = generatedEnergy;
		//Zuweisen der Variablen
		writePortValuesEqual(waterTanksIn,waterIntake);
		writePortValuesEqual(waterTanksOut,waterIntake + totalMass);
		writePortValuesEqual(hydrogenTanksIn,totalMass*2/10);
		writePortValuesEqual(oxygenTanksIn,totalMass*8/10);
		writePortValuesEqual(radiators,heat);
	}
}

void FuelCell::writeAttributesToMap()
{
	attributes.insert(std::pair<std::string,double>("Efficiency[-]",efficiency));
	attributes.insert(std::pair<std::string,double>("Cooling Water [kg]",coolingWaterPerSecond));
	attributes.insert(std::pair<std::string,double>("Power[W]",currentPower));
}


