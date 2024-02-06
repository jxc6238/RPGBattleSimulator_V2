#pragma once
#include <string>

class Item
{
private:
	std::string itemName;

public:
	Item(std::string itemName) : itemName(itemName) {};


	virtual void printItemInfo() = 0;
	std::string getName();
};

