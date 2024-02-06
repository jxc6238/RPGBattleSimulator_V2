#include "PreBattleMenuStateEquipItems.h"
#include "PreBattleMenuStateItems.h"
#include <iostream>

PreBattleMenuState* PreBattleMenuStateEquipItems::enterState(PreBattleInit& preBattle) {
	printMenuOptions();
	preBattle.printCharacterParty();
	return processUserSlection(preBattle, getUserSelection(upperBound));
}

void PreBattleMenuStateEquipItems::printMenuOptions() {
	printMenuHeader("Equip Items");
	std::cout
		<< "-1. Return" << std::endl
		<< "1. Select Character" << std::endl
		<< "2. View Equipment" << std::endl;
/**	
	std::cout
		<< "-1. Return" << std::endl
		<< "1. Head Items" << std::endl
		<< "2. Chest Items" << std::endl
		<< "3. Hand Items" << std::endl
		<< "4. Feet Items" << std::endl
		<< "5. Trinket Items" << std::endl
		<< "6. Weapon Items" << std::endl;
**/
}

PreBattleMenuState* PreBattleMenuStateEquipItems::processUserSlection(PreBattleInit& preBattle, int selection) {
	switch (selection) {
	case static_cast<int>(menuEnums::SELECTCHARACTER): { preBattle.equipItem(); return new PreBattleMenuStateEquipItems(); }
	case static_cast<int>(menuEnums::VIEWEQUIP): { preBattle.viewEquipment(); return new PreBattleMenuStateEquipItems(); }
	case static_cast<int>(menuEnums::RETURN): return new PreBattleMenuStateItems();
	}
	return nullptr;
}