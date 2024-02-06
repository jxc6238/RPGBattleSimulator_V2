#include "NamespaceMenuHeader.h"
#include <iostream>
#include <iomanip>

void MenuHeader::printMenuHeader(std::string header) {
	std::cout << std::setfill(spaceFillerCharacter) << std::setw(spacing) <<
		spaceFillerCharacter << header << std::setfill(spaceFillerCharacter) << std::setw(spacing) <<
		spaceFillerCharacter << std::endl;
}