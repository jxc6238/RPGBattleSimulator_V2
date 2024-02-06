#include "NamespaceCharacterSorter.h"
#include <algorithm>

struct ComparatorAlphabet {
	bool operator()(Character* char1, Character* char2) {
		return char1->getName() < char2->getName();
	}
};

void CharacterContainerSorter::sortAlphabetically(std::vector<CharacterPlayer*>& party) {
	std::sort(party.begin(), party.end(), ComparatorAlphabet());
}
