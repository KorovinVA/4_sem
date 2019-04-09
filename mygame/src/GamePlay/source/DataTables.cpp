#pragma once
#include <functional>
#include "..\headers\DataTables.h"
#include "..\headers\Warrior.h"

std::vector<WarriorData> initializeWarriorData()
{
	std::vector<WarriorData> data(Warrior::TypeCount);

	data[Warrior::Knight].hitpoints = 100;
	data[Warrior::Knight].speed = 200.f;
	data[Warrior::Knight].getText(Warrior::Knight);

	data[Warrior::Golem].hitpoints = 100;
	data[Warrior::Golem].speed = 200.f;
	data[Warrior::Golem].getText(Warrior::Golem);

	return data;
}

void WarriorData::getText(size_t type)
{
	switch (type)
	{
	case Warrior::Knight:
		idleText.push_back(Textures::Knight_Idle_1_000);
		idleText.push_back(Textures::Knight_Idle_1_001);
		idleText.push_back(Textures::Knight_Idle_1_002);
		idleText.push_back(Textures::Knight_Idle_1_003);
		idleText.push_back(Textures::Knight_Idle_1_004);
		idleText.push_back(Textures::Knight_Idle_1_005);
		idleText.push_back(Textures::Knight_Idle_1_006);

		runText.push_back(Textures::Knight_Run_1_000);
		runText.push_back(Textures::Knight_Run_1_001);
		runText.push_back(Textures::Knight_Run_1_002);
		runText.push_back(Textures::Knight_Run_1_003);
		runText.push_back(Textures::Knight_Run_1_004);
		runText.push_back(Textures::Knight_Run_1_005);
		runText.push_back(Textures::Knight_Run_1_006);

		attackText.push_back(Textures::Knight_Attack_1_000);
		attackText.push_back(Textures::Knight_Attack_1_001);
		attackText.push_back(Textures::Knight_Attack_1_002);
		attackText.push_back(Textures::Knight_Attack_1_003);
		attackText.push_back(Textures::Knight_Attack_1_004);
		attackText.push_back(Textures::Knight_Attack_1_005);
		attackText.push_back(Textures::Knight_Attack_1_006);
		attackText.push_back(Textures::Knight_Attack_1_007);
		break;
	case Warrior::Golem:
		idleText.push_back(Textures::Golem_Idle_1_000);
		idleText.push_back(Textures::Golem_Idle_1_001);
		idleText.push_back(Textures::Golem_Idle_1_002);
		idleText.push_back(Textures::Golem_Idle_1_003);
		idleText.push_back(Textures::Golem_Idle_1_004);
		idleText.push_back(Textures::Golem_Idle_1_005);
		idleText.push_back(Textures::Golem_Idle_1_006);
		idleText.push_back(Textures::Golem_Idle_1_007);
		idleText.push_back(Textures::Golem_Idle_1_008);
		idleText.push_back(Textures::Golem_Idle_1_009);
		idleText.push_back(Textures::Golem_Idle_1_010);
		idleText.push_back(Textures::Golem_Idle_1_011);
		idleText.push_back(Textures::Golem_Idle_1_012);
		idleText.push_back(Textures::Golem_Idle_1_013);
		idleText.push_back(Textures::Golem_Idle_1_014);
		idleText.push_back(Textures::Golem_Idle_1_015);
		idleText.push_back(Textures::Golem_Idle_1_016);
		idleText.push_back(Textures::Golem_Idle_1_017);

		runText.push_back(Textures::Golem_Run_1_000);
		runText.push_back(Textures::Golem_Run_1_001);
		runText.push_back(Textures::Golem_Run_1_002);
		runText.push_back(Textures::Golem_Run_1_003);
		runText.push_back(Textures::Golem_Run_1_004);
		runText.push_back(Textures::Golem_Run_1_005);
		runText.push_back(Textures::Golem_Run_1_006);
		runText.push_back(Textures::Golem_Run_1_007);
		runText.push_back(Textures::Golem_Run_1_008);
		runText.push_back(Textures::Golem_Run_1_009);
		runText.push_back(Textures::Golem_Run_1_010);
		runText.push_back(Textures::Golem_Run_1_011);
		break;
	}
}
