#include "CharacterPlayer.h"
#include "PartyInventory.h"
#include "NamespaceItemPrinter.h"
#include <iostream>

PartyInventory CharacterPlayer::partyInventory;

//needs to be updated to move unequipped item to available items
void CharacterPlayer::equipItem(ItemEquipped* item) {
	std::unordered_map<ItemSlots, ItemEquipped*>::iterator it = equippedItems.find(item->getSlot());
	if (it->second != nullptr) { //there is already an item in the slot
		unequipItem(item);
	}
	applyEquipModifiers(item, true); //scale
	it->second = item;
}

void CharacterPlayer::applyEquipModifiers(ItemEquipped* item, bool equip) {
	std::vector<std::pair<Buff, double>> tmp = item->getModifiers();
	std::function<double(double, double)> operation = std::plus<double>();
	if (equip) { operation = std::plus<double>(); }
	else { operation = std::minus<double>(); }
	for (auto& modifier : tmp) {
		switch (modifier.first) {
		case Buff::PHYSICALDAMAGE: setPhysDamage(operation(currentPhysDamage, modifier.second)); break;
		case Buff::MAGICDAMAGE: setMagicDamage(operation(currentMagicDamage, modifier.second)); break;
		case Buff::SPEED: setSpeed(operation(currentSpeed, modifier.second)); break;
		case Buff::PHYSICALDEFENSE: setPhysDefense(operation(currentPhysDefense, modifier.second)); break;
		case Buff::MAGICRESIST: setMagicResist(operation(currentMagicResist, modifier.second)); break;
		}
	}
}

//need to find better solution so no second search is done
//also need to be able to unequip from the unequip menu and from the equip function
//equip function already has an iterator
void CharacterPlayer::unequipItem(ItemEquipped* item) {
	std::unordered_map<ItemSlots, ItemEquipped*>::iterator it = equippedItems.find(item->getSlot());
	applyEquipModifiers(it->second, false); //descale
	//move to appropriate container for each slot
	partyInventory.getEquippedItemVector(it->second->getSlot()).push_back(it->second);
	it->second = nullptr;
}

void CharacterPlayer::printEquippedItemsSlots() {
	ItemPrinter::printEquippedItemContainer(equippedItems, true);
}