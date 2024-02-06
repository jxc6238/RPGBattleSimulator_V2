#include "NamespaceItemPrinter.h"
#include <iostream>

void ItemPrinter::printEquippedItemContainer(const std::vector<ItemEquipped*>& items, bool printReturn) {
	int count = 1;
	if (printReturn == true) { std::cout << returnVal << " Return" << std::endl; }
	for (const auto& item : items) {
		std::cout << count << " ";
		item->printItemInfo();
		count++;
	}
}

void ItemPrinter::printEquippedItemContainer(const std::unordered_map<ItemSlots, ItemEquipped*> items, bool printReturn) {
	int count = 1;
	if (printReturn == true) { std::cout << returnVal << " Return" << std::endl; }
	for (const auto& item : items) {
		std::cout << count << " ";
		item.second->printItemInfo();
		count++;
	}
}