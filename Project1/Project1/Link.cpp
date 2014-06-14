#include "Link.h"


Link::Link(std::string classifier)
{
	classi = classifier;
	p1.setClassifier(classifier);
	p2.setClassifier(classifier);
	ptrp1 = &p1;
	ptrp2 = &p2;
}


Link::~Link(void)
{
}

void Link::transfer()
{
	double temp = ptrp1->getValue();
	ptrp1->setValue(ptrp2->getValue());
	ptrp2->setValue(temp);
}

Port* Link::getPort()
{
	if(!p1.isAttached())
	{
		return ptrp1;
	}
	else if(!p2.isAttached())
	{
		return ptrp2;
	}
	else return nullptr;
}

