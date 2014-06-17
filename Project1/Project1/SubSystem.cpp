#include "SubSystem.h"

SubSystem::SubSystem(std::string name)
{
	//v=vessel;
	simTime = 0.00001;
	sName=name;
	operationMode = ACTIVE;
}

SubSystem::~SubSystem(void)
{
	//delete v;
}

std::string SubSystem::getName()
{
	return sName;
}

void SubSystem::activate()
{
	activateAllPorts();

	switch (operationMode){
case ACTIVE:		operationMode = ACTIVE;
					break;
case PASSIVE:		operationMode = ACTIVE;
					break;
case ACTIVE_WARNING:operationMode = ACTIVE_WARNING;
					break;
case ACTIVE_ERROR:	operationMode = ACTIVE_ERROR;
					break;
case PASSIVE_WARNING:operationMode = ACTIVE_WARNING;
					break;
case PASSIVE_ERROR:	operationMode = ACTIVE_ERROR;
					break;
default:			break;
	}
}

void SubSystem::deactivate()
{
	deactivateAllPorts();

	switch (operationMode){
case ACTIVE:		operationMode = PASSIVE;
					break;
case PASSIVE:		operationMode = PASSIVE;
					break;
case ACTIVE_WARNING:operationMode = PASSIVE_WARNING;
					break;
case ACTIVE_ERROR:	operationMode = PASSIVE_ERROR;
					break;
case PASSIVE_WARNING:operationMode = PASSIVE_WARNING;
					break;
case PASSIVE_ERROR:	operationMode = PASSIVE_ERROR;
					break;
default:			break;
	}
}

std::string SubSystem::report()
{
	writeAttributesToMap();
	std::string s;
	s.append("==== " + sName + " ====\n");
	s.append("Status:\t");
	s.append(SubSystem::getStatusAsString());
	s.append("\n");

	for (std::map<std::string,double>::iterator it = attributes.begin();it!=attributes.end();++it)
	{
		s.append(it->first).append("\t\t").append(std::to_string(it->second)).append("\n");
	}

	return s;
}

std::string SubSystem::getStatusAsString()
{
	switch (operationMode){
case ACTIVE:			return "ACTIVE";
case PASSIVE:			return "PASSIVE";
case ACTIVE_WARNING:	return "ACTIVE_WARNING";
case ACTIVE_ERROR:		return "ACTIVE_ERROR";
case PASSIVE_WARNING:	return "PASSIVE_WARNING";
case PASSIVE_ERROR:		return "PASSIVE_ERROR";
default:				return "NOT DEFINED";
	}
}

void SubSystem::connectPortToInput(Port* port)
{
	inputStreams.insert(std::pair<std::string,Port*>(port->getClassifier(),port));
	port->setAttached();
	port->activate();

}

void SubSystem::connectPortToOutput(Port* port)
{
	outputStreams.insert(std::pair<std::string,Port*>(port->getClassifier(),port));
	port->setAttached();
	port->activate();
}

void SubSystem::activateAllPorts()
{
	std::multimap<std::string,Port*>::iterator pos;

	for(pos=inputStreams.begin();pos!=inputStreams.end();++pos)
	{
		pos->second->activate();
	}

	for(pos=outputStreams.begin();pos!=outputStreams.end();++pos)
	{
		pos->second->activate();
	}
}

void SubSystem::deactivateAllPorts()
{
	std::multimap<std::string,Port*>::iterator pos;

	for(pos=inputStreams.begin();pos!=inputStreams.end();++pos)
	{
		pos->second->deactivate();
	}

	for(pos=outputStreams.begin();pos!=outputStreams.end();++pos)
	{
		pos->second->deactivate();
	}
}

void SubSystem::initializeSystem()
{
}

void SubSystem::calculateStep()
{
}

void SubSystem::writeAttributesToMap()
{
}

std::vector<Port*> SubSystem::collectAllActiveSubSystemsWithClassifier(std::multimap<std::string,Port*> map,std::string classifier)
{
	std::vector<Port*> ports;

	std::multimap<std::string,Port*>::iterator pos;

	for(pos=map.begin();pos!=map.end();++pos)
	{
		if(pos->first.compare(classifier) == 0)
		{
			if(pos->second->isActive())
				ports.push_back(pos->second);
		}

	}

	return ports;

}

double SubSystem::getPortValuesSum(std::vector<Port*> ports)
{
	std::vector<Port*>::iterator pos;
	double sum = 0;

	for(pos=ports.begin();pos!=ports.end();++pos)
	{
		sum = sum + (*pos)->getValue();
	}
	return sum;
}

void SubSystem::writePortValuesEqual(std::vector<Port*> ports,double sum)
{
	std::vector<Port*>::iterator pos;
	int size = ports.size();

	if(size != 0)
	{
		for(pos=ports.begin();pos!=ports.end();++pos)
		{
			(*pos)->setValue(sum/size);
		}
	}

}


void SubSystem::resetAllPortValues()
{
	std::multimap<std::string,Port*>::iterator pos;

	for(pos=inputStreams.begin();pos!=inputStreams.end();++pos)
	{
		pos->second->setValue(0.0);
	}

	for(pos=outputStreams.begin();pos!=outputStreams.end();++pos)
	{
		pos->second->setValue(0.0);
	}
}

void SubSystem::resetPortValuesWithClassifier(std::string classifier)
{
	std::multimap<std::string,Port*>::iterator pos;

	for(pos=inputStreams.begin();pos!=inputStreams.end();++pos)
	{
		if(pos->first.compare(classifier) == 0)
			pos->second->setValue(0.0);
	}

	for(pos=outputStreams.begin();pos!=outputStreams.end();++pos)
	{
		if(pos->first.compare(classifier) == 0)
			pos->second->setValue(0.0);
	}
}