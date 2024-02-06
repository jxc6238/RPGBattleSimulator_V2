#include "NamespacePartyPrinter.h"
#include <iostream>

void PartyPrinter::printPartyPreBattle(const std::vector<CharacterPlayer*>& party) {
	int count = 1;
	for (auto& partyMember : party) {
		std::cout << count << " . ";
		if (partyMember == nullptr) { std::cout << "Empty" << std::endl; }
		else { partyMember->printCharacterStatsBase(); }
		count++;
	}
}