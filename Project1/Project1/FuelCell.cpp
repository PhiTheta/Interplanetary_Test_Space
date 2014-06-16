#include "FuelCell.h"

void FuelCell::initializeSystem()
{
	efficiency = 0.4;
	coolingWaterPerSecond = 4.0;
	currentPower = 0.0;
}

void FuelCell::calculateStep()
{

	if(operationMode == ACTIVE)
	{
		std::vector<Port*> activeConsumers = collectAllActiveSubSystemsWithClassifier(outputStreams,"Energy[J]");
		std::vector<Port*> waterTanksIn = collectAllActiveSubSystemsWithClassifier(inputStreams,"H2O");
		std::vector<Port*> waterTanksOut = collectAllActiveSubSystemsWithClassifier(outputStreams,"H2O");
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


		//Hier weiter machen:
		//Die Masse des Wassertanks wird nicht richtig aktualisiert!
	}
}

void FuelCell::writeAttributesToMap()
{
	attributes["Efficiency[-]"] = efficiency;
	attributes["Cooling Water [kg]"] = coolingWaterPerSecond;
	attributes["Power[W]"]=currentPower;
}


