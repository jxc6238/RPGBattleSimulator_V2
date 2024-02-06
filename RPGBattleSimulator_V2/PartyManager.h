#pragma once
#include "Character.h"
#include "CharacterPlayer.h"

class PartyManager
{
private:
	const int maxPartySize, minPartySize, returnValue;
	std::vector<CharacterPlayer*> availablePartyMembers;
	std::vector<CharacterPlayer*> currentParty;

	void resolveAddCharacterToParty(CharacterPlayer* character, const int& position);
	void resolveRemoveCharacterFromParty(const int& position);
	void modifyForSelectionForContainer(int& selection);
	void availablePartySorter();

public:
	PartyManager() : maxPartySize(3), minPartySize(1), returnValue(-1),
		availablePartyMembers(), currentParty(3) {};

	void addToAvailablePartyMembers(CharacterPlayer* character);

	void printCharacterParty();
	void printAvailablePartyMembers();

	void addCharacterToParty();
	void removeCharacterFromParty();

	CharacterPlayer* getPartyMember();

};

