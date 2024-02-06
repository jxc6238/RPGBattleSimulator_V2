#pragma once
#include "PreBattleMenuState.h"

class PreBattleMenuStateMain : public PreBattleMenuState
{
private:
	enum class menuEnums{PARTY = 1, ITEMS = 2, RETURN = PreBattleMenuState::returnMenuVal};
	int upperBound = 2;
protected:
	void printMenuOptions() override;
	PreBattleMenuState* processUserSlection(PreBattleInit& preBattle, int selection) override;
public:
	PreBattleMenuState* enterState(PreBattleInit& preBattle) override;
};

