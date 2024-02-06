#include "PreBattleMenuStateMain.h"
#include "PreBattleMenuStateParty.h"
#include "PreBattleMenuStateItems.h"
#include <iostream>
#include <iomanip>

PreBattleMenuState* PreBattleMenuStateMain::enterState(PreBattleInit& preBattle) {
	printMenuOptions();
	return processUserSlection(preBattle, getUserSelection(upperBound));
}

void PreBattleMenuStateMain::printMenuOptions() {
	printMenuHeader("Main Menu");
	std::cout
		<< "-1. Return" << std::endl
		<< "1. Party" << std::endl
		<< "2. Items" << std::endl;
}

PreBattleMenuState* PreBattleMenuStateMain::processUserSlection(PreBattleInit& preBattle, int selection) {
	switch (selection) {
	case static_cast<int>(menuEnums::PARTY): return new PreBattleMenuStateParty();
	case static_cast<int>(menuEnums::ITEMS): return new PreBattleMenuStateItems();
	case static_cast<int>(menuEnums::RETURN): return nullptr;
	}
	return nullptr;
}