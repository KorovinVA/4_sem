#include "..\headers\DataTables.h"
#include "..\headers\Warrior.h"

WarriorData::WarriorData(int type_, TextureHolder * textures):
bounds(type_, textures)
{
	switch (type_)
	{
	case Warrior::Knight:
		hitpoints = 150;
		damage = 40;
		speed = 100.f;
		getTextures(Warrior::Knight);

		fullAttackTime = sf::seconds(1.f);
		fullDieTime = sf::seconds(1.f);
		AttackFrequency = 0.1f;
		AttackTextureNumber = 5;
		break;
	case Warrior::Golem:
		hitpoints = 100;
		damage = 20;
		speed = 100.f;
		getTextures(Warrior::Golem);

		fullAttackTime = sf::seconds(1.3f);
		fullDieTime = sf::seconds(1.5f);
		AttackFrequency = 0.1f;
		AttackTextureNumber = 6;
		break;
	}
}

void WarriorData::getTextures(size_t type)
{
	switch (type)
	{
	case Warrior::Knight:
		idleTextPtr.push_back(Textures::Knight_Idle_1_000);
		idleTextPtr.push_back(Textures::Knight_Idle_1_001);
		idleTextPtr.push_back(Textures::Knight_Idle_1_002);
		idleTextPtr.push_back(Textures::Knight_Idle_1_003);
		idleTextPtr.push_back(Textures::Knight_Idle_1_004);
		idleTextPtr.push_back(Textures::Knight_Idle_1_005);
		idleTextPtr.push_back(Textures::Knight_Idle_1_006);

		runTextPtr.push_back(Textures::Knight_Run_1_000);
		runTextPtr.push_back(Textures::Knight_Run_1_001);
		runTextPtr.push_back(Textures::Knight_Run_1_002);
		runTextPtr.push_back(Textures::Knight_Run_1_003);
		runTextPtr.push_back(Textures::Knight_Run_1_004);
		runTextPtr.push_back(Textures::Knight_Run_1_005);
		runTextPtr.push_back(Textures::Knight_Run_1_006);

		attackTextPtr.push_back(Textures::Knight_Attack_1_000);
		attackTextPtr.push_back(Textures::Knight_Attack_1_001);
		attackTextPtr.push_back(Textures::Knight_Attack_1_002);
		attackTextPtr.push_back(Textures::Knight_Attack_1_003);
		attackTextPtr.push_back(Textures::Knight_Attack_1_004);
		attackTextPtr.push_back(Textures::Knight_Attack_1_005);
		attackTextPtr.push_back(Textures::Knight_Attack_1_006);
		attackTextPtr.push_back(Textures::Knight_Attack_1_007);

		dieTextPtr.push_back(Textures::Knight_Die_1_000);
		dieTextPtr.push_back(Textures::Knight_Die_1_001);
		dieTextPtr.push_back(Textures::Knight_Die_1_002);
		dieTextPtr.push_back(Textures::Knight_Die_1_003);
		dieTextPtr.push_back(Textures::Knight_Die_1_004);
		dieTextPtr.push_back(Textures::Knight_Die_1_005);
		dieTextPtr.push_back(Textures::Knight_Die_1_006);
		break;
	case Warrior::Golem:
		idleTextPtr.push_back(Textures::Golem_Idle_1_000);
		idleTextPtr.push_back(Textures::Golem_Idle_1_001);
		idleTextPtr.push_back(Textures::Golem_Idle_1_002);
		idleTextPtr.push_back(Textures::Golem_Idle_1_003);
		idleTextPtr.push_back(Textures::Golem_Idle_1_004);
		idleTextPtr.push_back(Textures::Golem_Idle_1_005);
		idleTextPtr.push_back(Textures::Golem_Idle_1_006);
		idleTextPtr.push_back(Textures::Golem_Idle_1_007);
		idleTextPtr.push_back(Textures::Golem_Idle_1_008);
		idleTextPtr.push_back(Textures::Golem_Idle_1_009);
		idleTextPtr.push_back(Textures::Golem_Idle_1_010);
		idleTextPtr.push_back(Textures::Golem_Idle_1_011);
		idleTextPtr.push_back(Textures::Golem_Idle_1_012);
		idleTextPtr.push_back(Textures::Golem_Idle_1_013);
		idleTextPtr.push_back(Textures::Golem_Idle_1_014);
		idleTextPtr.push_back(Textures::Golem_Idle_1_015);
		idleTextPtr.push_back(Textures::Golem_Idle_1_016);
		idleTextPtr.push_back(Textures::Golem_Idle_1_017);

		runTextPtr.push_back(Textures::Golem_Run_1_000);
		runTextPtr.push_back(Textures::Golem_Run_1_001);
		runTextPtr.push_back(Textures::Golem_Run_1_002);
		runTextPtr.push_back(Textures::Golem_Run_1_003);
		runTextPtr.push_back(Textures::Golem_Run_1_004);
		runTextPtr.push_back(Textures::Golem_Run_1_005);
		runTextPtr.push_back(Textures::Golem_Run_1_006);
		runTextPtr.push_back(Textures::Golem_Run_1_007);
		runTextPtr.push_back(Textures::Golem_Run_1_008);
		runTextPtr.push_back(Textures::Golem_Run_1_009);
		runTextPtr.push_back(Textures::Golem_Run_1_010);
		runTextPtr.push_back(Textures::Golem_Run_1_011);

		attackTextPtr.push_back(Textures::Golem_Attack_1_000);
		attackTextPtr.push_back(Textures::Golem_Attack_1_001);
		attackTextPtr.push_back(Textures::Golem_Attack_1_002);
		attackTextPtr.push_back(Textures::Golem_Attack_1_003);
		attackTextPtr.push_back(Textures::Golem_Attack_1_004);
		attackTextPtr.push_back(Textures::Golem_Attack_1_005);
		attackTextPtr.push_back(Textures::Golem_Attack_1_006);
		attackTextPtr.push_back(Textures::Golem_Attack_1_007);
		attackTextPtr.push_back(Textures::Golem_Attack_1_008);
		attackTextPtr.push_back(Textures::Golem_Attack_1_009);
		attackTextPtr.push_back(Textures::Golem_Attack_1_010);
		attackTextPtr.push_back(Textures::Golem_Attack_1_011);

		dieTextPtr.push_back(Textures::Golem_Die_1_000);
		dieTextPtr.push_back(Textures::Golem_Die_1_001);
		dieTextPtr.push_back(Textures::Golem_Die_1_002);
		dieTextPtr.push_back(Textures::Golem_Die_1_003);
		dieTextPtr.push_back(Textures::Golem_Die_1_004);
		dieTextPtr.push_back(Textures::Golem_Die_1_005);
		dieTextPtr.push_back(Textures::Golem_Die_1_006);
		dieTextPtr.push_back(Textures::Golem_Die_1_007);
		dieTextPtr.push_back(Textures::Golem_Die_1_008);
		dieTextPtr.push_back(Textures::Golem_Die_1_009);
		dieTextPtr.push_back(Textures::Golem_Die_1_010);
		dieTextPtr.push_back(Textures::Golem_Die_1_011);
		dieTextPtr.push_back(Textures::Golem_Die_1_012);
		dieTextPtr.push_back(Textures::Golem_Die_1_013);
		dieTextPtr.push_back(Textures::Golem_Die_1_014);
		break;
	}
}
