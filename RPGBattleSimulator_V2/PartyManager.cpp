#include "PartyManager.h"
#include "NamespaceMenuHeader.h"
#include "NamespacePartyPrinter.h"
#include "NamespaceCharacterSorter.h"
#include "NamespaceUserSelection.h"
#include <iostream>

void PartyManager::addToAvailablePartyMembers(CharacterPlayer* character) { availablePartyMembers.push_back(character); }

void PartyManager::printCharacterParty() {
	MenuHeader::printMenuHeader("Current Party");
	std::cout << returnValue << " . Return" << std::endl;
	PartyPrinter::printPartyPreBattle(currentParty);
}

void PartyManager::printAvailablePartyMembers() {
	MenuHeader::printMenuHeader("Available Party Members");
	std::cout << returnValue << " . Return" << std::endl;
	PartyPrinter::printPartyPreBattle(availablePartyMembers);
}

void PartyManager::addCharacterToParty() {
	printAvailablePartyMembers();
	int selection = UserSelection::getUserSelection("Select party member: ", availablePartyMembers.size());
	if (selection == -1) { return; }
	modifyForSelectionForContainer(selection);
	printCharacterParty();
	int position = UserSelection::getUserSelection("Select position: ", maxPartySize);
	if (position == -1) { addCharacterToParty(); return; }
	modifyForSelectionForContainer(position);
	CharacterPlayer* tmpCharacter = availablePartyMembers[selection];
	availablePartyMembers.erase(availablePartyMembers.begin() + selection);
	if (currentParty[position] != nullptr) { resolveRemoveCharacterFromParty(position); }
	resolveAddCharacterToParty(tmpCharacter, position);
	tmpCharacter = nullptr;
}

void PartyManager::resolveAddCharacterToParty(CharacterPlayer* character, const int& position) {
	currentParty[position] = character;
}

void PartyManager::removeCharacterFromParty() {
	printCharacterParty();
	int selection = UserSelection::getUserSelection("Select party member: ", currentParty.size());
	if (selection == -1) { return; }
	modifyForSelectionForContainer(selection);
	resolveRemoveCharacterFromParty(selection);
}

void PartyManager::resolveRemoveCharacterFromParty(const int& position) {
	CharacterPlayer* tmpCharacter = currentParty[position];
	if (tmpCharacter == nullptr) { return; }
	currentParty[position] = nullptr;
	availablePartyMembers.push_back(tmpCharacter);
	availablePartySorter();
	tmpCharacter = nullptr;
}

void PartyManager::availablePartySorter() {
	CharacterContainerSorter::sortAlphabetically(availablePartyMembers);
}

//need to subtract to get right container index
void PartyManager::modifyForSelectionForContainer(int& selection) {
	if (selection != -1) { selection--; }
}

CharacterPlayer* PartyManager::getPartyMember() {
	int upperBound = 2, partyDecision = INT_MIN;
	const int currentPartyMembers = 1, availableMembers = 2;
	std::cout
		<< "-1. Return" << std::endl
		<< "1. Current Party" << std::endl
		<< "2. Available Characters" << std::endl;
	int selection = UserSelection::getUserSelection("Select: ", upperBound);
	if (selection == UserSelection::returnValue) { return nullptr; }
	switch (selection) {
	case currentPartyMembers: {
		partyDecision = currentPartyMembers;
		printCharacterParty();
		selection = UserSelection::getUserSelection("Select: ", currentParty.size());
		break;
	}
	case availableMembers: {
		partyDecision = availableMembers;
		printAvailablePartyMembers();
		selection = UserSelection::getUserSelection("Select: ", availablePartyMembers.size());
		break;
	}
	}
	if (selection == -1) { return getPartyMember(); }
	selection--;
	if (partyDecision == currentPartyMembers) { return currentParty[selection]; }
	else { return availablePartyMembers[selection]; }
}