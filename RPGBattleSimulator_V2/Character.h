#pragma once
#include <string>

class Character
{
protected:
	std::string characterName;
	int maxHealth, health, maxMana, mana;
	double baseSpeed, currentSpeed;
	double basePhysDamage, currentPhysDamage;
	double baseMagicDamage, currentMagicDamage;
	double basePhysDefense, currentPhysDefense;
	double baseMagicResist, currentMagicResist;
	bool KO;
	const char spacing = ' ';
public:
	Character(std::string characterName, int health, int mana, double baseSpeed,
		double basePhysDamage, double baseMagicDamage,
		double basePhysDefense, double baseMagicResist) : characterName(characterName),
		maxHealth(health), health(health), maxMana(mana), mana(mana),
		baseSpeed(baseSpeed), currentSpeed(baseSpeed),
		basePhysDamage(basePhysDamage), currentPhysDamage(basePhysDamage),
		baseMagicDamage(baseMagicDamage), currentMagicDamage(baseMagicDamage),
		basePhysDefense(basePhysDefense), currentPhysDefense(basePhysDefense),
		baseMagicResist(baseMagicResist), currentMagicResist(baseMagicResist),
		KO(false) {};

	void setHealth(int updatedHealth);
	void setMana(int updatedMana);
	void setSpeed(double updatedSpeed);
	void setPhysDamage(double updatedPhysDamage);
	void setMagicDamage(double updatedMagicDamage);
	void setPhysDefense(double updatedPhysDefense);
	void setMagicResist(double updatedMagicResist);

	std::string getName();
	int getHealth();
	int getMana();
	double getSpeed();
	double getPhysDamage();
	double getMagicDamage();
	double getPhysDefense();
	double getMagicResist();
	bool getKOStatus();

	void printCharacterStatsBase();
	void printCharacterStatsBattle();
};

