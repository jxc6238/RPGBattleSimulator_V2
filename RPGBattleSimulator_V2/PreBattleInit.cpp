#include "PreBattleInit.h"
#include "GameObjectBuilder.h"
#include "NamespaceMenuHeader.h"
#include "NamespaceUserSelection.h"
#include <iostream>
#include <fstream>
#include <sstream>
using json = nlohmann::json;

void PreBattleInit::initializeGame() {
	initializePlayerCharacters();
	initializeItems();
	startMenuStateMachine();
	std::cout << "done";
}

void PreBattleInit::initializePlayerCharacters() {
	std::ifstream ifs("PartyMembers.json");
	json partyMemJson = json::parse(ifs);
	for (auto& partyMember : partyMemJson["PartyMembers"]) {
		CharacterPlayer* tmp = GameObjectBuilder::buildCharacter(partyMember);
		partyManager.addToAvailablePartyMembers(tmp);
		for (auto& item : partyMember["StartingItems"]) {
			tmp->equipItem(GameObjectBuilder::buildItemEquipped(item));			
		}
	}
}

void PreBattleInit::initializeItems() {
	std::ifstream ifs("ItemEquipped.json");
	json equippedItemJson = json::parse(ifs);
	ItemEquipped* tmpItem;
	for (auto& item : equippedItemJson["Equiptment"]) {
		tmpItem = GameObjectBuilder::buildItemEquipped(item);
		partyInventory.addItemToEquippedInventory(tmpItem);
	}
}

void PreBattleInit::startMenuStateMachine() {
	while (menus != nullptr) {
		PreBattleMenuState* tmpState = menus;
		menus = menus->enterState((*this));
		delete tmpState;
	}
}

void PreBattleInit::printCharacterParty() {
	MenuHeader::printMenuHeader("Current Party");
	for (unsigned int i = 0; i < currentParty.size(); i++) {
		currentParty[i]->printCharacterStatsBase();
	}
}

void PreBattleInit::printAvailablePartyMembers() {
	MenuHeader::printMenuHeader("Available Party Members");
	for (unsigned int i = 0; i < availablePartyMembers.size(); i++) {
		availablePartyMembers[i]->printCharacterStatsBase();
	}
}

void PreBattleInit::addCharacterToParty() {
	partyManager.addCharacterToParty();
	//remove after testing
	partyManager.printCharacterParty();
	partyManager.printAvailablePartyMembers();
}

void PreBattleInit::removeCharacterFromParty() {
	partyManager.removeCharacterFromParty();
	//remove after testing
	partyManager.printCharacterParty();
	partyManager.printAvailablePartyMembers();
}

void PreBattleInit::equipItem() {
	CharacterPlayer* tmpCharacter = partyManager.getPartyMember();
	if (tmpCharacter == nullptr) { return; }
	std::string strSlot = partyInventory.printAndGetItemSlotOptions();
	if (strSlot == "") { return; }
	auto itemIT = StringToItemSlot.find(strSlot);
	strSlot = strSlot + " Slot Items";
	MenuHeader::printMenuHeader(strSlot);
	ItemEquipped* tmpItem = partyInventory.getItemToEquip(itemIT->second);
	if (tmpItem == nullptr) { return; }
	tmpCharacter->equipItem(tmpItem);
}

void PreBattleInit::viewEquipment(){
	std::string strSlot = partyInventory.printAndGetItemSlotOptions();
	if (strSlot == "") { return; }
	auto itemIT = StringToItemSlot.find(strSlot);
	strSlot = strSlot + " Slot Items";
	MenuHeader::printMenuHeader(strSlot);
	partyInventory.printItems(itemIT->second);
}