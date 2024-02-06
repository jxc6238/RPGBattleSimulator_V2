#pragma once
#include <string>
#include <unordered_map>

enum class ItemSlots {
	HEAD,
	CHEST,
	HANDS,
	FEET,
	TRINKET,
	WEAPON
};

static std::unordered_map<ItemSlots, std::string> ItemSlotToString =
{
	{ItemSlots::HEAD, "Head"},
	{ItemSlots::CHEST, "Chest"},
	{ItemSlots::HANDS, "Hands"},
	{ItemSlots::FEET, "Feet"},
	{ItemSlots::TRINKET, "Trinket"},
	{ItemSlots::WEAPON, "Weapon"}
};

static std::unordered_map<std::string, ItemSlots> StringToItemSlot =
{
	{"Head", ItemSlots::HEAD},
	{"Chest", ItemSlots::CHEST},
	{"Hands", ItemSlots::HANDS},
	{"Feet", ItemSlots::FEET},
	{"Trinket", ItemSlots::TRINKET},
	{"Weapon", ItemSlots::WEAPON}
};

