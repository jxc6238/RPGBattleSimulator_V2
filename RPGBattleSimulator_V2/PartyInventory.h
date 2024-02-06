#pragma once
#include "ItemEquipped.h"
#include "EnumItemSlots.h"

class PartyInventory
{
private:
	std::vector<ItemEquipped*> headSlotItems;
	std::vector<ItemEquipped*> chestSlotItems;
	std::vector<ItemEquipped*> handsSlotItems;
	std::vector<ItemEquipped*> feetSlotItems;
	std::vector<ItemEquipped*> trinketSlotItems;
	std::vector<ItemEquipped*> weaponSlotItems;
	const int returnVal = -1;
protected:
public:
	PartyInventory() : headSlotItems(), chestSlotItems(),
		handsSlotItems(), feetSlotItems(), trinketSlotItems(),
		weaponSlotItems() {};
	std::vector<ItemEquipped*>& getEquippedItemVector(const ItemSlots& slot);
	void addItemToEquippedInventory(ItemEquipped* item);
	ItemEquipped* getItemToEquip(const ItemSlots& slot);

	void printItems(const ItemSlots& slot);
	std::string printAndGetItemSlotOptions();
};

