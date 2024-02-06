#pragma once
#include "PreBattleMenuState.h"
#include "PreBattleInit.h"

class PreBattleMenuStateParty : public PreBattleMenuState
{
private:
	enum class menuEnums { ADDCHARACTER = 1, REMOVECHARACTER = 2, RETURN = PreBattleMenuState::returnMenuVal };
	int upperBound = 2;

protected:
	void printMenuOptions() override;
	PreBattleMenuState* processUserSlection(PreBattleInit& preBattle, int selection) override;

public:
	PreBattleMenuState* enterState(PreBattleInit& preBattle) override;
};

