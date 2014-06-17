#include "FuelCell.h"

void FuelCell::initializeSystem()
{
	efficiency = 0.4;
	coolingWaterPerSecond = 4.0;
	currentPower = 0.0;
}

void FuelCell::calculateStep()
{
	std::vector<Port*> activeConsumers = collectAllActiveSubSystemsWithClassifier(outputStreams,"Energy[J]");
		std::vector<Port*> waterTanksIn = collectAllActiveSubSystemsWithClassifier(inputStreams,"H2O");
		std::vector<Port*> waterTanksOut = collectAllActiveSubSystemsWithClassifier(outputStreams,"H2O");
		std::vector<Port*> hydrogenTanksIn = collectAllActiveSubSystemsWithClassifier(inputStreams,"H2");
		std::vector<Port*> oxygenTanksIn = collectAllActiveSubSystemsWithClassifier(inputStreams,"O2");
		std::vector<Port*> radiators = collectAllActiveSubSystemsWithClassifier(outputStreams,"Heat[J]");

	if(operationMode == ACTIVE)
	{
		//Konstanter Eingangswasserstrom
		double waterIntake = 4.0*simTime;
		//Die ben�tigte Energie wird anhand der angschlossenen Verbraucher ermittelt
		double requiredEnergy = getPortValuesSum(activeConsumers);
		double generatedEnergy = requiredEnergy / efficiency;
		currentPower = generatedEnergy/simTime;
		//Erfundene Formel f�r den Massenstrom im verh�ltnis zur Energie
		double coefficient = 0.01;
		double totalMass = generatedEnergy * coefficient;
		double heat = generatedEnergy;
		//Zuweisen der Variablen
		writePortValuesEqual(activeConsumers,requiredEnergy);
		writePortValuesEqual(waterTanksIn,waterIntake);
		writePortValuesEqual(waterTanksOut,waterIntake + totalMass);
		writePortValuesEqual(hydrogenTanksIn,totalMass*2/10);
		writePortValuesEqual(oxygenTanksIn,totalMass*8/10);
		writePortValuesEqual(radiators,heat);
		

		//Hier weiter machen:
		//Die Masse des Wassertanks wird nicht richtig aktualisiert!
	}

	if(operationMode == PASSIVE)
	{
		writePortValuesEqual(activeConsumers,0.0);
		writePortValuesEqual(waterTanksIn,0.0);
		writePortValuesEqual(waterTanksOut,0.0);
		writePortValuesEqual(hydrogenTanksIn,0.0);
		writePortValuesEqual(oxygenTanksIn,0.0);
		writePortValuesEqual(radiators,0.0);
		currentPower = 0.0;
		coolingWaterPerSecond = 0.0;
	}


}

void FuelCell::writeAttributesToMap()
{
	attributes["Efficiency[-]"] = efficiency;
	attributes["Cooling Water [kg]"] = coolingWaterPerSecond;
	attributes["Power[W]"]=currentPower;
}


