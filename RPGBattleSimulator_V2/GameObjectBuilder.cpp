#include "GameObjectBuilder.h"

CharacterPlayer* GameObjectBuilder::buildCharacter(const json& partyMember) {
	return new CharacterPlayer(partyMember["Name"],
		partyMember["Health"],
		partyMember["Mana"],
		partyMember["BaseSpeed"],
		partyMember["BasePhysDamage"],
		partyMember["BaseMagicDamage"],
		partyMember["BasePhysDefense"],
		partyMember["BaseMagicResist"]);
}

ItemEquipped* GameObjectBuilder::buildItemEquipped(const json& item) {
	std::vector<std::pair<Buff, double>> tmpModifiers;
	for (auto& modifiers : item["Modifiers"]) {
		tmpModifiers.push_back(std::make_pair(StringToBuff.find(modifiers["Buff"])->second, modifiers["Modifier"]));
	}
	return new ItemEquipped(item["ItemName"], StringToItemSlot.find(item["Slot"])->second,
		tmpModifiers);
}