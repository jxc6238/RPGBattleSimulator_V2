#include "ItemEquipped.h"
#include <iostream>

const ItemSlots& ItemEquipped::getSlot() { return slot; }
const std::vector<std::pair<Buff, double>>& ItemEquipped::getModifiers() { return modifiers; }

void ItemEquipped::printItemInfo() {
	std::cout
		<< getName() << " "
		<< "Slot: " << ItemSlotToString.find(slot)->second << " "
		<< "Buffs: ";
	for (auto& buff : modifiers) {
		std::cout << BuffToString.find(buff.first)->second << " " << buff.second;
		std::cout << "  ";
	}
	std::cout << std::endl;
}