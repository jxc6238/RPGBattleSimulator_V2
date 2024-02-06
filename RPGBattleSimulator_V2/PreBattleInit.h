#pragma once
#include "CharacterPlayer.h"
#include "Character.h"
#include "EnumItemSlots.h"
#include "PreBattleMenuState.h"
#include "PreBattleMenuStateMain.h"
#include "PartyManager.h"
#include <nlohmann/json.hpp>
#include <vector>
#include <string>
using json = nlohmann::json;

class PreBattleMenuState;

class PreBattleInit
{
private:
	const int maxPartySize;
	std::vector<CharacterPlayer*> availablePartyMembers;
	std::vector<CharacterPlayer*> currentParty;
	PartyManager partyManager;
	PartyInventory partyInventory;
	PreBattleMenuState* menus;

public:
	PreBattleInit() : maxPartySize(3), availablePartyMembers(), 
		currentParty(), partyManager(), partyInventory(),
	menus(new PreBattleMenuStateMain()) {};

	void initializeGame();
	void initializePlayerCharacters();
	void initializeItems();
	void startMenuStateMachine();

	void printCharacterParty();
	void printAvailablePartyMembers();

	void addCharacterToParty();
	void removeCharacterFromParty();

	void equipItem();
	void viewEquipment(); //to print party inventory by slot

	void closeGame();
};

