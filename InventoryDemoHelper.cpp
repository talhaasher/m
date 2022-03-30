#include "InventoryDemoHelper.h"
#include "Item.h"
#include <iostream>
#include <string>
using namespace std;


/*
Initialize a beginning state for the character inventory for the purposes of this demo.
*/
void InventoryDemoHelper::initialize_Inventory(Inventory* inventory) {
	//common items
	Item* basicHelm = new Item("Leather Cap", "common", "head",0,1);
	Item* basicMail = new Item("Leather Vest", "common", "chest", 0, 1);
	Item* basicLegs = new Item("Leather Greaves", "common", "legs", 0, 1);
	Item* basicSword = new Item("Short Sword", "common", "rightHand", 2,0);
	Item* basicDagger = new Item("Dagger", "common", "rightHand", 1, 0);
	Item* basicShield = new Item("Wooden Shield", "common", "leftHand", 0, 1);

	//Equip these as default loadout
	inventory->equip_Item(*basicHelm);
	inventory->equip_Item(*basicMail);
	inventory->equip_Item(*basicLegs);
	inventory->equip_Item(*basicDagger);
	inventory->equip_Item(*basicShield);

	//Put the rest in the backpack
	inventory->add_Item_To_Backpack(*basicSword);

	//rare items

	Item* rareHelm = new Item("Soldier Helm", "rare", "head", 0, 2);
	Item* rareMail = new Item("Soldier Chainmail", "rare", "chest",0,2);
	Item* rareLegs = new Item("Soldier Greaves", "rare", "legs",0,2);
	Item* longSword = new Item("Long Sword", "rare", "rightHand",3,0);
	Item* mace = new Item("Spiked Mace", "rare", "rightHand",2,1);
	Item* rareShield = new Item("Kite Shield", "rare", "leftHand",0,3);

	inventory->add_Item_To_Backpack(*rareHelm);
	inventory->add_Item_To_Backpack(*rareMail);
	inventory->add_Item_To_Backpack(*rareLegs);
	inventory->add_Item_To_Backpack(*mace);
	inventory->add_Item_To_Backpack(*longSword);
	inventory->add_Item_To_Backpack(*rareShield);

	//legendary items
	Item* legendaryHelm = new Item("Iron Helm", "legendary", "head",0,5);
	Item* legendaryMail = new Item("Iron Platemail", "legendary", "chest",0,5);
	Item* legendaryLegs = new Item("Iron Greaves", "legendary", "legs",0,5);
	Item* legendarySword = new Item("Greatsword", "legendary", "rightHand",5,0);
	Item* legendaryShield = new Item("Tower Shield", "legendary", "leftHand", 0, 8);
	Item* legendaryShield2 = new Item("Spiked Shield", "legendary", "leftHand",2,5);
	
	inventory->add_Item_To_Backpack(*legendaryHelm);
	inventory->add_Item_To_Backpack(*legendaryMail);
	inventory->add_Item_To_Backpack(*legendaryLegs);
	inventory->add_Item_To_Backpack(*legendarySword);
	inventory->add_Item_To_Backpack(*legendaryShield);
	inventory->add_Item_To_Backpack(*legendaryShield2);

	//Mythic items
	Item* mythicHelm = new Item("Helm of the Destroyer", "mythic", "head",3,10);
	Item* mythicLance = new Item("Javalin of Light", "mythic", "rightHand",15,0);
	Item* mythicLegs = new Item("Boots of Hermes", "mythic", "legs",0,6);

	inventory->add_Item_To_Backpack(*mythicHelm);
	inventory->add_Item_To_Backpack(*mythicLance);
	inventory->add_Item_To_Backpack(*mythicLegs);
	
}

void InventoryDemoHelper::print_Full_Inventory(Inventory* inventory) {
	cout << "----------------------------" << endl;
	cout << "----- Equipped Loadout -----" << endl;
	cout << "----------------------------" << endl;
	Item* headItem = inventory->get_Item_In_Slot("head");
	Item* chestItem = inventory->get_Item_In_Slot("chest");
	Item* legsItem = inventory->get_Item_In_Slot("legs");
	Item* rightHandItem = inventory->get_Item_In_Slot("rightHand");
	Item* leftHandItem = inventory->get_Item_In_Slot("leftHand");

	string headStats = NONE;
	string chestStats = NONE;
	string legStats = NONE;
	string rightHandStats = NONE;
	string leftHandStats = NONE;
	if (headItem != nullptr) {
		headStats = headItem->ptItemStat();
	}
	cout << "Head: " << headStats << endl;
	if (chestItem != nullptr) {
		chestStats = chestItem->ptItemStat();
	}
	cout << "Chest: " << chestStats << endl;
	if (legsItem != nullptr) {
		legStats = legsItem->ptItemStat();
	}
	cout << "Legs: " << legStats << endl;
	if (rightHandItem != nullptr) {
		rightHandStats = rightHandItem->ptItemStat();
	}
	cout << "Right Hand: " << rightHandStats << endl;
	if (leftHandItem != nullptr) {
		leftHandStats = leftHandItem->ptItemStat();
	}
	cout << "Left Hand: " << leftHandStats << endl;

	vector<Item*> copy = inventory->get_Backpack();
	cout << "----------------------------" << endl;
	cout << "--------- Backpack ---------" << endl;
	cout << "----------------------------" << endl;
	if (copy.size() == 0) {
		cout << "*Backpack is Empty*" << endl;
	}
	for (int i = 0; i < copy.size(); i++) {
		string stats = copy[i]->ptItemStat();
		cout << i + 1 << "." << stats << endl;
	}
}

void InventoryDemoHelper::handle_Print_Loadout(Inventory* inventory)
{
	cout << "----------------------------" << endl;
	cout << "----- Equipped Loadout -----" << endl;
	cout << "----------------------------" << endl;
	int attackRating = 0;
	int defenseRating = 0;

	Item* headSlot = inventory->get_Item_In_Slot("head");
	cout << "Head: ";
	if (headSlot != nullptr) {
		cout << headSlot->ptItemStat() << endl;
		attackRating += headSlot->gtAttack();
		defenseRating += headSlot->gtDefense();
	} else {
		cout << NONE << endl;
	}
	Item* chestSlot = inventory->get_Item_In_Slot("chest");
	cout << "Chest: ";
	if (chestSlot != nullptr) {
		cout << chestSlot->ptItemStat() << endl;
		attackRating += chestSlot->gtAttack();
		defenseRating += chestSlot->gtDefense();
	} else {
		cout << NONE << endl;
	} 
	Item* legsSlot = inventory->get_Item_In_Slot("legs");
	cout << "Legs: ";
	if (legsSlot != nullptr) {
		cout << legsSlot->ptItemStat() << endl;
		attackRating += legsSlot->gtAttack();
		defenseRating += legsSlot->gtDefense();
	} else {
		cout << NONE << endl;
	}
	Item* rightHandSlot = inventory->get_Item_In_Slot("rightHand");
	cout << "Right Hand: ";
	if (rightHandSlot != nullptr) {
		cout << rightHandSlot->ptItemStat() << endl;
		attackRating += rightHandSlot->gtAttack();
		defenseRating += rightHandSlot->gtDefense();
	} else {
		cout << NONE << endl;
	}
	Item* leftHandSlot = inventory->get_Item_In_Slot("leftHand");
	cout << "Left Hand: ";
	if (leftHandSlot != nullptr) {
		cout << leftHandSlot->ptItemStat() << endl;
		attackRating += leftHandSlot->gtAttack();
		defenseRating += leftHandSlot->gtDefense();
	} else {
		cout << NONE << endl;
	}
	/*cout << "Chest: " << getItemInSlot("chest")->printItemStats() << endl;
	cout << "Legs: " << getItemInSlot("legs")->printItemStats() << endl;
	cout << "Right Hand: " << getItemInSlot("rightHand")->printItemStats() << endl;
	cout << "Left Hand: " << getItemInSlot("leftHand")->printItemStats() << endl;*/
	cout << "----------------------------" << endl;
	cout << "---------- Stats -----------" << endl;
	cout << "----------------------------" << endl;
	cout << "Total Attack: " << to_string(attackRating) << endl;
	cout << "Total Defense: " << to_string(defenseRating) << endl;

}

void InventoryDemoHelper::handle_Equip_Selection(Inventory* inventory)
{
	cout << "----------------------------" << endl;
	cout << "--------- Backpack ---------" << endl;
	cout << "----------------------------" << endl;
	//Print list of backpack items with a number
	vector<Item*> copy = inventory->get_Backpack();
	for (int i = 0; i < (int)copy.size(); i++) {
		string stats = copy[i]->ptItemStat();
		cout << i + 1 << ". " << stats << endl;
	}
	
	bool valid = false;
	int x{};
	while (!valid) {
		cout << "Enter the number of the item you want to equip:" << endl;
		cout << ">";
		cin >> x;
		if (x <= 0 || x > (int)copy.size()) {
			cout<< "***Invalid item number***" << endl;
		}
		else {
			valid = true;
		}
		cin.ignore();
	}
	
	Item* itemToEquip = inventory->remove_Item_From_Backpack(x-1);
	inventory->equip_Item(*itemToEquip);
}

void InventoryDemoHelper::handle_Unequip_Selection(Inventory* inventory)
{
	string input;
	bool valid = false;
	while (!valid) {
		cout << "----------------------------" << endl;
		cout << "Enter the slot you want to unequip:" << endl;
		cout << "Options are: head, chest, legs, rightHand, leftHand" << endl;
		cout << "> ";
		getline(cin, input);
		if (input == "head" || input == "chest" || input == "legs" || input == "leftHand" || input == "rightHand") {
			valid = true;
		}
		else {
			cout << "***Invalid slot***" << endl;
		}
	}
	inventory->unEquip_Item(input);
}

