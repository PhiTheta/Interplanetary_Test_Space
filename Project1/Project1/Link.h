/*
Diese Klasse definiert, wie zwei Subsysteme miteinander verkn�pft werden k�nnen.
Dabei wird dem Link ein sogenannter "Classifier" als String �bergeben, welcher
definiert welche art von Str�men durch die Verbindung flie�t.
Jeder Link hat zwei Ports, welche an jeweils ein Subsystem angeschlossen werden,
wobei die Reihenfolge keine Rolle spielt. Um den Strom durch den Link zu simulieren
werden einfach die Informationen an den Ports vertauscht. Somit k�nnen Str�me in
beide Richtungen flie�en, je nach dem was das entsprechende Subsystem auf den Port
schreibt.
*/
#include <string>
#include "Port.h"

class Link
{
private:
	Port p1,p2;
	Port *ptrp1,*ptrp2;
	std::string classi;
public:
	Link(std::string classifier);
	~Link(void);

	void transfer();
	Port* getPort();
};

