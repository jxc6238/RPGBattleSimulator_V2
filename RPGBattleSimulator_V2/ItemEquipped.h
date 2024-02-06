#pragma once
#include "Item.h"
#include "EnumItemSlots.h"
#include "EnumBuff.h"
#include <vector>

class ItemEquipped : public Item
{
private:
	ItemSlots slot;
	std::vector<std::pair<Buff, double>> modifiers;
protected:

public:
	ItemEquipped(std::string itemName, ItemSlots slot, std::vector<std::pair<Buff, double>> const& modifiers) :
		Item(itemName), slot(slot), modifiers() {
		this->modifiers = modifiers;
	}
	const std::vector<std::pair<Buff, double>>&  getModifiers();
	const ItemSlots& getSlot();
	
	void printItemInfo() override;
};

