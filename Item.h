#ifndef ITEM
#define ITEM
#include <string>
#include <map>
using namespace std;
#include <iostream>
class Item
{

public:
	
	Item();
	~Item();
	Item(string name, string rare, string slotType, int attack, int defense);

	string gtName();
	string gtRarity();
	int gtAttack();
	int gtDefense();
	string gtSlotType();
	virtual string ptItemStat();
private:
	int def;
	string slotTp;
	string name;
	int att;
	string rare;
};

#endif

