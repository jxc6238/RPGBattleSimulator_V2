#include "Character.h"
#include <iostream>

void Character::setHealth(int updatedHealth) {
	if (updatedHealth <= 0) { health = 0; KO = true; }
	else if (updatedHealth > maxHealth) { health = maxHealth; }
	else { health = updatedHealth; }
}

void Character::setMana(int updatedMana) {
	if (updatedMana <= 0) { mana = 0; }
	else if (updatedMana > maxMana) { mana = maxMana; }
	else { mana = updatedMana; }
}

void Character::setSpeed(double updatedSpeed) { currentSpeed = updatedSpeed; }
void Character::setPhysDamage(double updatedPhysDamage) { currentPhysDamage = updatedPhysDamage; }
void Character::setMagicDamage(double updatedMagicDamage) { currentMagicDamage = updatedMagicDamage; }
void Character::setPhysDefense(double updatedPhysDefense) { currentPhysDefense = updatedPhysDefense; }
void Character::setMagicResist(double updatedMagicResist) { currentMagicResist = updatedMagicResist; }

std::string Character::getName() { return characterName; }

int Character::getHealth() { return health; }
int Character::getMana() { return mana; }

double Character::getSpeed() { return currentSpeed; }
double Character::getPhysDamage() { return currentPhysDamage; }
double Character::getMagicDamage() { return currentMagicDamage; }
double Character::getPhysDefense() { return currentPhysDefense; }
double Character::getMagicResist() { return currentMagicResist; }

bool Character::getKOStatus() { return KO; }

void Character::printCharacterStatsBase() {
	std::cout
		<< "Name: " << characterName << spacing
		<< "Health: " << health << spacing
		<< "Mana: " << mana << spacing
		<< "Speed: " << currentSpeed << spacing
		<< "Damage: " << currentPhysDamage << spacing
		<< "Magic Damage: " << currentMagicDamage << spacing
		<< "Defense: " << currentPhysDefense << spacing
		<< "Magic Resist: " << currentMagicResist << spacing
		<< std::endl;
}