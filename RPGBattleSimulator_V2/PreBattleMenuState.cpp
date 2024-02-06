#include "PreBattleMenuState.h"
#include "NamespaceUserSelection.h"
#include "NamespaceMenuHeader.h"
#include <iostream>
#include <iomanip>

void PreBattleMenuState::printMenuHeader(std::string header) {
	MenuHeader::printMenuHeader(header);
}

int PreBattleMenuState::getUserSelection(const int& upperBound) {
	return UserSelection::getUserSelection(selectionString, upperBound);
}