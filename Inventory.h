#ifndef INVENTORY
#define INVENTORY
#include "Item.h"
#include <vector>
#include <iostream>


class Inventory
{
private:
	vector<Item*> backpack;
	Item* rightArm;
	Item* legs;
	Item* chest;
	Item* head;
	Item* leftArm;
	

public:
	Inventory();
	~Inventory();
	void set_Backpack(vector<Item*> &item_List);//this should just be the constructor and any additions should use equip.
	//full loot pool will be implemeted in another class.
	vector<Item*> &get_Backpack();
	void print_Full_Inventory();
	//print function for just equiped items
	void print_Loadout();
	void equip_Item(Item& item_To_Equip);
	void unEquip_Item(const string slot);
	void add_Item_To_Backpack(Item& item_To_Add);
	Item* remove_Item_From_Backpack(int index);
	Item* get_Item_In_Slot(const string slot);
};

#endif
