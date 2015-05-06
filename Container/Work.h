//=====================================================
#include <string>
#include "List.h"
//=====================================================
using namespace std;

class Entity;
class Work
{
private:
	string ID;
	double workTime;
	Entity* workEntity;
	
public:
	void setID(string ID);
	string getID();
	double getWorkTime();
	void setWorkTime(double workTime);
	void setEntity(Entity* e);
	Entity* getEntity();
	explicit Work(string ID, double workTime);
	~Work();
};