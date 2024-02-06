#pragma once
#include "Character.h"
#include "CharacterPlayer.h"
#include <vector>

namespace PartyPrinter {
	void printPartyPreBattle(const std::vector<CharacterPlayer*>& party);
	//void printPartyBattle(std::vector<Character*> party);
}

