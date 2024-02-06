#pragma once
#include "ItemEquipped.h"
#include "EnumItemSlots.h"
#include <vector>
#include <unordered_map>

namespace ItemPrinter {
	const int returnVal = -1;
	void printEquippedItemContainer(const std::vector<ItemEquipped*>& items, bool printReturn);
	void printEquippedItemContainer(const std::unordered_map<ItemSlots, ItemEquipped*> items, bool printReturn);
}
