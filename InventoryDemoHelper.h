#ifndef INVENTORY_HELPER
#define INVENTORY_HELPER
#include "Inventory.h"
#include "Item.h"
#include <string>
#include <iostream>
using namespace std;
class InventoryDemoHelper
{
public:
	void initialize_Inventory(Inventory* inventory);
	void print_Full_Inventory(Inventory* inventory);
	void handle_Print_Loadout(Inventory* inventory);
	void handle_Equip_Selection(Inventory* inventory);
	void handle_Unequip_Selection(Inventory* inventory);
private:
	const string NONE = "*EMPTY*";
};

#endif

