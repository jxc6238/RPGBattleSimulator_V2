#include "NamespaceUserSelection.h"
#include <iostream>

int UserSelection::getUserSelection(const std::string& message, const int& upperBound) {
	int selection = INT_MIN;
	while (selection < returnValue || selection > upperBound || selection == 0) {
		std::cout << message;
		selection = returnUserSelection(message);
	}
	return selection;
}

int UserSelection::returnUserSelection(const std::string& message) {
	int selection;
	std::cin >> selection;
	while (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cout << message;
		std::cin >> selection;
	}
	return selection;
}