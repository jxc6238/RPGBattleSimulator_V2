#pragma once
#include <unordered_map>

enum class Buff
{
	PHYSICALDAMAGE,
	MAGICDAMAGE,
	SPEED,
	PHYSICALDEFENSE,
	MAGICRESIST
};

static std::unordered_map<Buff, std::string> BuffToString =
{
	{Buff::PHYSICALDAMAGE, "Physical Damage"},
	{Buff::MAGICDAMAGE, "Magic Damage"},
	{Buff::SPEED, "Speed"},
	{Buff::PHYSICALDEFENSE, "Physical Defense"},
	{Buff::MAGICRESIST, "Magic Resist"}
};

static std::unordered_map<std::string, Buff> StringToBuff =
{
	{"Physical Damage", Buff::PHYSICALDAMAGE},
	{"Magic Damage", Buff::MAGICDAMAGE},
	{"Speed", Buff::SPEED},
	{"Physical Defense", Buff::PHYSICALDEFENSE},
	{"Magic Resist", Buff::MAGICRESIST}
};