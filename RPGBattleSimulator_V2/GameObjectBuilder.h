#pragma once
#include "CharacterPlayer.h"
#include "ItemEquipped.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

/**
used, for now, to build Character and item objects.
theya re built this way so logic not trapped in prebattleinit and
can be used elsewhere for when item drops are added to the game
along with new characters joining party after specific events
**/

namespace GameObjectBuilder {
	CharacterPlayer* buildCharacter(const json& partyMember);
	ItemEquipped* buildItemEquipped(const json& item);
}

