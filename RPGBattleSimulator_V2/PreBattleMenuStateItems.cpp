#include "PreBattleMenuStateItems.h"
#include "PreBattleMenuStateEquipItems.h"
#include <iostream>

PreBattleMenuState* PreBattleMenuStateItems::enterState(PreBattleInit& preBattle) {
	printMenuOptions();
	return processUserSlection(preBattle, getUserSelection(upperBound));
}

void PreBattleMenuStateItems::printMenuOptions() {
	printMenuHeader("Items");
	std::cout
		<< "-1. Return" << std::endl
		<< "1. Equip Items" << std::endl
		<< "2. Available Consumables" << std::endl;
}

PreBattleMenuState* PreBattleMenuStateItems::processUserSlection(PreBattleInit& preBattle, int selection) {
	switch (selection) {
	case static_cast<int>(menuEnums::EQUIPITEMS): return new PreBattleMenuStateEquipItems();
	case static_cast<int>(menuEnums::CONSUMABLES): return nullptr;
	case static_cast<int>(menuEnums::RETURN): return nullptr;
	}
	return nullptr;
}