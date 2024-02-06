#pragma once
#include <string>

class PreBattleInit;

class PreBattleMenuState
{
private:
	const std::string selectionString = "Selection: ";
protected:
	const int spacing = 40;
	const char spaceFillerCharacter = '-';
	static const int returnMenuVal = -1;

	virtual void printMenuOptions() = 0;
	virtual PreBattleMenuState* processUserSlection(PreBattleInit& preBattle, int selection) = 0;
	int getUserSelection(const int& upperBound);
	void printMenuHeader(std::string header);
public:
	virtual PreBattleMenuState* enterState(PreBattleInit& preBattle) = 0;
};

