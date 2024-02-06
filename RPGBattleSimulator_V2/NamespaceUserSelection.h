#pragma once
#include <string>

namespace UserSelection {
	const int returnValue = -1; //for returning from menus 

	int getUserSelection(const std::string& message, const int& upperBound);
	int returnUserSelection(const std::string& message);
}
