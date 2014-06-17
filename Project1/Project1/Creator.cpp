#include <iostream>
#include <string>
#include <map>
#include "SubSystemLib.h"

using namespace std;

void runSimulationSteps(vector<SubSystem*> subsys,vector<Link> links,int steps);


int main()
{
	//Subsysteme initialisieren
	vector<SubSystem*> subsys;
	vector<SubSystem*>::iterator ssit;

	WaterTank *water1 = new WaterTank("WasserTank1");
	OxygenTank *oxy1 = new OxygenTank("SauerstoffTank1");
	HydrogenTank *hydro1 = new HydrogenTank("WasserstoffTank1");
	Thruster *thrus1 = new Thruster("Thruster1");
	/*Thruster *thrus2 = new Thruster("Thruster2");
	Thruster *thrus3 = new Thruster("Thruster3");
	Thruster *thrus4 = new Thruster("Thruster4");*/
	FuelCell *fc1 = new FuelCell("Brennstoffzelle1");
	Battery *bat1 = new Battery("Batterie1");
	/*Battery *bat2 = new Battery("Batterie2");
	Battery *bat3 = new Battery("Batterie3");*/
	//ThermalFissionGenerator *tfg1 = new ThermalFissionGenerator("Reaktor1");
	Radiator *rad1 = new Radiator("Radiator1");

	subsys.push_back(water1);
	subsys.push_back(oxy1);
	subsys.push_back(hydro1);
	subsys.push_back(thrus1);
	/*subsys.push_back(thrus2);
	subsys.push_back(thrus3);
	subsys.push_back(thrus4);*/
	subsys.push_back(fc1);
	subsys.push_back(bat1);
	//subsys.push_back(bat2);
	//subsys.push_back(bat3);
	//subsys.push_back(tfg1);
	subsys.push_back(rad1);

	//Links instanzieren
	vector<Link> links;
	vector<Link>::iterator linkit;
	Link h2a("H2");
	Link h2b("H2");
	Link o2a("O2");
	Link o2b("O2");
	Link h2oa("H2O");
	Link h2ob("H2O");
	Link heat1("Heat[J]");
	Link power1("Energy[J]");

	links.push_back(h2a);
	links.push_back(h2b);
	links.push_back(o2a);
	links.push_back(o2b);
	links.push_back(h2oa);
	links.push_back(h2ob);
	links.push_back(heat1);
	links.push_back(power1);

	//Ports verbinden
	hydro1->connectPortToOutput(h2a.getPort());
	hydro1->connectPortToOutput(h2b.getPort());
	oxy1->connectPortToOutput(o2a.getPort());
	oxy1->connectPortToOutput(o2b.getPort());
	water1->connectPortToOutput(h2oa.getPort());
	water1->connectPortToInput(h2ob.getPort());
	thrus1->connectPortToInput(h2a.getPort());
	thrus1->connectPortToInput(o2a.getPort());
	fc1->connectPortToInput(h2b.getPort());
	fc1->connectPortToInput(o2b.getPort());
	fc1->connectPortToInput(h2oa.getPort());
	fc1->connectPortToOutput(h2ob.getPort());
	fc1->connectPortToOutput(power1.getPort());
	fc1->connectPortToOutput(heat1.getPort());
	rad1->connectPortToInput(heat1.getPort());
	bat1->connectPortToInput(power1.getPort());

	for(int i=0;i<100;i++)
		runSimulationSteps(subsys,links,30);
	hydro1->deactivate();
	//fc1->deactivate();
	for(int i=0;i<100;i++)
		runSimulationSteps(subsys,links,30);
	//fc1->activate();
	for(int i=0;i<100;i++)
		runSimulationSteps(subsys,links,30);
	//thrus1->deactivate();
	for(int i=0;i<100;i++)
		runSimulationSteps(subsys,links,30);
	//thrus1->activate();
	for(int i=0;i<100;i++)
		runSimulationSteps(subsys,links,30);
	for(int i=0;i<100;i++)
		runSimulationSteps(subsys,links,30);
	for(int i=0;i<100;i++)
		runSimulationSteps(subsys,links,30);

	/*for (ssit = subsys.begin();ssit!=subsys.end();++ssit)
	{
		cout << (*ssit)->report() <<"\n\n";
	}

	cout << string(30,'#') << "\n\n";

	for (int i = 0; i < 1000; i++)
	{
		for (ssit = subsys.begin();ssit!=subsys.end();++ssit)
		{
			(*ssit)->calculateStep();
		}

		for (linkit = links.begin();linkit!=links.end();++linkit)
		{
			linkit->transfer();
		}

	}


	for (ssit = subsys.begin();ssit!=subsys.end();++ssit)
	{
		cout << (*ssit)->report() <<"\n\n";
	}

	cout << string(30,'#') << "\n\n";

	for (int i = 0; i < 1000; i++)
	{
		for (ssit = subsys.begin();ssit!=subsys.end();++ssit)
		{
			(*ssit)->calculateStep();
		}

		for (linkit = links.begin();linkit!=links.end();++linkit)
		{
			linkit->transfer();
		}

	}

	for (ssit = subsys.begin();ssit!=subsys.end();++ssit)
	{
		cout << (*ssit)->report() <<"\n\n";
	}*/

	system("pause");
	return 0;
}

void runSimulationSteps(vector<SubSystem*> subsys,vector<Link> links,int steps)
{
	vector<SubSystem*>::iterator ssit;
	vector<Link>::iterator linkit;

	for (int i = 0; i < steps; i++)
	{
		for (ssit = subsys.begin();ssit!=subsys.end();++ssit)
		{
			(*ssit)->calculateStep();
		}

		for (linkit = links.begin();linkit!=links.end();++linkit)
		{
			linkit->transfer();
		}

	}

	system("cls");

	for (ssit = subsys.begin();ssit!=subsys.end();++ssit)
	{
		cout << (*ssit)->report() <<"\n\n";
	}
}
