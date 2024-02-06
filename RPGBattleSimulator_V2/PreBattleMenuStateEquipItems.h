#pragma once
#include "PreBattleMenuState.h"

class PreBattleMenuStateEquipItems : public PreBattleMenuState
{
private:
	enum class menuEnums {SELECTCHARACTER = 1, VIEWEQUIP = 2, RETURN = PreBattleMenuState::returnMenuVal };
	//enum class menuEnums{HEAD = 1, CHEST = 2, HANDS = 3,
		//FEET = 4, TRINKET = 5, WEAPON = 6, RETURN = PreBattleMenuState::returnMenuVal};
	int upperBound = 2;
protected:
	void printMenuOptions() override;
	PreBattleMenuState* processUserSlection(PreBattleInit& preBattle, int selection) override;
private:
	PreBattleMenuState* enterState(PreBattleInit& preBattle) override;
};

