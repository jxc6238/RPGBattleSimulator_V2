#include "PreBattleMenuStateParty.h"
#include <iostream>

PreBattleMenuState* PreBattleMenuStateParty::enterState(PreBattleInit& preBattle) {
	printMenuOptions();
	return processUserSlection(preBattle, getUserSelection(upperBound));
}

void PreBattleMenuStateParty::printMenuOptions() {
	printMenuHeader("Party Menu");
	std::cout
		<< "-1. Return" << std::endl
		<< "1. Add Party Member" << std::endl
		<< "2. Remove Party Member" << std::endl;
}

PreBattleMenuState* PreBattleMenuStateParty::processUserSlection(PreBattleInit& preBattle, int selection) {
	switch (selection) {
	case static_cast<int>(menuEnums::ADDCHARACTER): preBattle.addCharacterToParty(); return new PreBattleMenuStateParty();
	case static_cast<int>(menuEnums::REMOVECHARACTER): preBattle.removeCharacterFromParty(); return new PreBattleMenuStateParty();
	case static_cast<int>(menuEnums::RETURN): return new PreBattleMenuStateMain();
	}
	return nullptr;
}