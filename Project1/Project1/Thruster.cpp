#include "Thruster.h"

void Thruster::initializeSystem()
{
	thrust = 8000.0;
	isp = 4000.0;
	group = "MAIN";
}

void Thruster::calculateStep()
{
	double totalMass;
	if(status == ACTIVE)
		totalMass = thrust*simTime/isp;
	else
		totalMass = 0.0;
	//Stoechiometrische verteilung der Masse
	//2 Teile Wasserstoff auf 8 Teile Sauerstoff
	inputStreams.find("H2")->second->setValue(totalMass*2/10);
	inputStreams.find("O2")->second->setValue(totalMass*8/10);
}

void Thruster::writeAttributesToMap()
{
	attributes.insert(std::pair<std::string,double>("Thrust[N]",thrust));
	attributes.insert(std::pair<std::string,double>("Isp[m/s]",isp));
}