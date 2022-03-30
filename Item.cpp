#include "Item.h"

Item::Item() {}
Item::~Item() {}

Item::Item(string name, string rarity, string slotType, int attack, int defense) {
	this->name = name;
	this->att = attack;
	this->def = defense;
	this->rare = rarity;
	this->slotTp = slotType;
}

//name
string Item::gtName() {
	return name;
}
//rarity
string Item::gtRarity() {
	return rare;
}
//Slot
string Item::gtSlotType() {
	return slotTp;
}

int Item::gtAttack() {
	return att;
}

int Item::gtDefense() {
	return def;
}

string Item::ptItemStat() {
	return name + " || " + rare + " || " + slotTp + " || ATK:"+ to_string(att)+" || DEF:"+ to_string(def) ;
}