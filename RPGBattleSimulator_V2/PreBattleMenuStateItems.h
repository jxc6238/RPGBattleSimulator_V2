#pragma once
#include "PreBattleMenuStateMain.h"
#include "PreBattleInit.h"

class PreBattleMenuStateItems : public PreBattleMenuState
{
private:
	enum class menuEnums{EQUIPITEMS = 1, CONSUMABLES = 2, RETURN = PreBattleMenuState::returnMenuVal};
	int upperBound = 2;
protected:
	void printMenuOptions() override;
	PreBattleMenuState* processUserSlection(PreBattleInit& preBattle, int selection) override;
public:
	PreBattleMenuState* enterState(PreBattleInit& preBattle) override;
};

