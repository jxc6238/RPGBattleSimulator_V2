#include "PartyInventory.h"
#include "NamespaceUserSelection.h"
#include "NamespaceItemPrinter.h"
#include "NamespaceMenuHeader.h"
#include <iostream>

//need better solution to compiler warning
std::vector<ItemEquipped*>& PartyInventory::getEquippedItemVector(const ItemSlots& slot) {
	switch (slot) {
	case ItemSlots::HEAD: return headSlotItems;
	case ItemSlots::CHEST: return chestSlotItems;
	case ItemSlots::HANDS: return handsSlotItems;
	case ItemSlots::FEET: return feetSlotItems;
	case ItemSlots::TRINKET: return trinketSlotItems;
	case ItemSlots::WEAPON: return weaponSlotItems;
	}
	return headSlotItems;
}

void PartyInventory::addItemToEquippedInventory(ItemEquipped* item) {
	ItemSlots slot = item->getSlot();
	switch (slot) {
	case ItemSlots::HEAD: headSlotItems.push_back(item); return;
	case ItemSlots::CHEST: chestSlotItems.push_back(item); return;
	case ItemSlots::HANDS: handsSlotItems.push_back(item); return;
	case ItemSlots::FEET: feetSlotItems.push_back(item); return;
	case ItemSlots::TRINKET: trinketSlotItems.push_back(item); return;
	case ItemSlots::WEAPON: weaponSlotItems.push_back(item); return;
	}
}

ItemEquipped* PartyInventory::getItemToEquip(const ItemSlots& slot) {
	std::vector<ItemEquipped*> tmpVec = getEquippedItemVector(slot);
	ItemPrinter::printEquippedItemContainer(tmpVec, true);
	int selection = UserSelection::getUserSelection("Selection: ", tmpVec.size());
	if (selection == -1) { return nullptr; }
	else { selection--; }
	return tmpVec[selection];
}

void PartyInventory::printItems(const ItemSlots& slot) {
	std::vector<ItemEquipped*> tmpVec;
	tmpVec = getEquippedItemVector(slot);
	ItemPrinter::printEquippedItemContainer(tmpVec, false);
}

std::string PartyInventory::printAndGetItemSlotOptions() {
	MenuHeader::printMenuHeader("Slot Items");
	std::cout
		<< "1. Head Slot Items" << std::endl
		<< "2. Chest Slot Items" << std::endl
		<< "3. Hand Slot Items" << std::endl
		<< "4. Feet Slot Items" << std::endl
		<< "5. Trinket Slot Items" << std::endl
		<< "6. Weapon Slot Items" << std::endl;
	int selection = UserSelection::getUserSelection("Selection: ", 6);
	if (selection == -1) { return ""; }
	switch (selection) {
	case 1: return "Head";
	case 2: return "Chest";
	case 3: return "Hands";
	case 4: return "Feet";
	case 5: return "Trinket";
	case 6: return "Weapon";
	}
	return "";
}