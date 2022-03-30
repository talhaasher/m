#include "Inventory.h"
#include <iostream>


Inventory::Inventory() : backpack(0), head(nullptr), chest(nullptr), leftArm(nullptr), rightArm(nullptr), legs(nullptr) {
	
}

Inventory::~Inventory() {
	//Clean up pointer data
	delete head;
	delete chest;
	delete leftArm;
	delete rightArm;
	delete legs;
	for(int i = 0; i < backpack.size(); i++){
		Item* ptr = backpack.at(i);
		delete ptr;
	}
	backpack.clear();

}

void Inventory::set_Backpack(vector<Item*> &itemList) {
	backpack = itemList;
}

vector<Item*>& Inventory::get_Backpack()
{
	return backpack;
}

void Inventory::print_Full_Inventory()
{
	for (int i = 0; i < backpack.size(); i++) {
		string stats = backpack[i]->ptItemStat();

	}
}

void Inventory::print_Loadout()
{
	int attackRating = 0;
	int defenseRating = 0;

	Item* headSlot = get_Item_In_Slot("head");
	cout << "Head: ";
	if (headSlot != nullptr) {
		cout << headSlot->ptItemStat() << endl;
		attackRating += headSlot->gtAttack();
		defenseRating += headSlot->gtDefense();
	} else {
		cout << "EMPTY" << endl;
	}
	cout << "Chest: " << get_Item_In_Slot("chest")->ptItemStat() << endl;
	cout << "Legs: " << get_Item_In_Slot("legs")->ptItemStat() << endl;
	cout << "Right Hand: " << get_Item_In_Slot("rightHand")->ptItemStat() << endl;
	cout << "Left Hand: " << get_Item_In_Slot("leftHand")->ptItemStat() << endl;

	


}

void Inventory::equip_Item(Item& itemToEquip) {
	Item** tempSlot = nullptr;
	string slot = itemToEquip.gtSlotType();
	if (slot == "head") {
		tempSlot = &head;
	} else if (slot == "leftHand") {
		tempSlot = &leftArm;
	} else if (slot == "rightHand") {
		tempSlot = &rightArm;
	} else if (slot == "legs") {
		tempSlot = &legs;
	} else if (slot == "chest") {
		tempSlot = &chest;
	} else {
		throw ("Invalid slot selection");
	}

	if (*tempSlot != nullptr) {
		add_Item_To_Backpack(**tempSlot);
		cout << "Currently equipped " << (*tempSlot)->gtName() << " was moved to the backpack" << endl;
	}
	(*tempSlot) = &itemToEquip;
	cout << itemToEquip.gtName() << " equipped." << endl;
	
}

void Inventory::unEquip_Item(const string slot)
{
	Item** tempSlot = nullptr;
	if (slot == "head") {
		tempSlot = &head;
	}
	else if (slot == "leftHand") {
		tempSlot = &leftArm;
	}
	else if (slot == "rightHand") {
		tempSlot = &rightArm;
	}
	else if (slot == "legs") {
		tempSlot = &legs;
	}
	else if (slot == "chest") {
		tempSlot = &chest;
	} else {
		throw ("Invalid slot selection");
	}

	if (*tempSlot != nullptr) {
		//message 
		
		cout << (*tempSlot)->gtName() << " unequipped from " << slot << " slot and moved to backpack" << endl ;
		add_Item_To_Backpack(**tempSlot);
		*tempSlot = nullptr;
	}
	else {
		cout << "There is no item currently equipped in the " << slot << " slot." << endl;
	}
}

void Inventory::add_Item_To_Backpack(Item& item_To_Add)
{
	backpack.push_back(&item_To_Add);
}

Item* Inventory::remove_Item_From_Backpack(int index)
{
	Item* item = backpack[index];
	backpack.erase(backpack.begin() + index);
	return item;
}

Item* Inventory::get_Item_In_Slot(const string slot)
{
	if (slot == "head") 
	{
		return head;
	}
	else if (slot == "leftHand") 
	{
		return leftArm;
	}
	else if (slot == "rightHand") 
	{
		return rightArm;
	}
	else if (slot == "legs") 
	{
		return legs;
	}
	else if (slot == "chest") 
	{
		return chest;
	}
	//Invalid value passed.
	return nullptr;
}



