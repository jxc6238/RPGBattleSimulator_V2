#pragma once
#include "Character.h"
#include "EnumItemSlots.h"
#include "ItemEquipped.h"
#include "PartyInventory.h"
#include <unordered_map>
#include <functional>


class CharacterPlayer : public Character
{
private:
	std::unordered_map<ItemSlots, ItemEquipped*> equippedItems;
	static PartyInventory partyInventory;
public:
	CharacterPlayer(std::string characterName, int health, int mana, double baseSpeed,
		double basePhysDamage, double baseMagicDamage,
		double basePhysDefense, double baseMagicResist) : Character(characterName,
			health, mana, baseSpeed, basePhysDamage,
			baseMagicDamage, basePhysDefense, baseMagicResist),  
		equippedItems{{ItemSlots::HEAD, nullptr},
				{ItemSlots::CHEST, nullptr},
				{ItemSlots::HANDS, nullptr},
				{ItemSlots::FEET, nullptr},
				{ItemSlots::TRINKET, nullptr},
				{ItemSlots::WEAPON, nullptr}} {};

	void equipItem(ItemEquipped* item);
	void unequipItem(ItemEquipped* item);
	void applyEquipModifiers(ItemEquipped* item, bool equip);
	void printEquippedItemsSlots();
};

