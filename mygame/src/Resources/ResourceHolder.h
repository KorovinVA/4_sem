#pragma once

#include <map>
#include <SFML/Graphics.hpp>

namespace Textures
{
	enum ID { Landscape, MainMenu,
		Knight_Idle_1_000, Knight_Idle_1_001, Knight_Idle_1_002,
		Knight_Idle_1_003, Knight_Idle_1_004, Knight_Idle_1_005,
		Knight_Idle_1_006,
		Knight_Run_1_000, Knight_Run_1_001 ,Knight_Run_1_002, 
		Knight_Run_1_003, Knight_Run_1_004, Knight_Run_1_005, 
		Knight_Run_1_006,
		Knight_Attack_1_000, Knight_Attack_1_001, Knight_Attack_1_002,
		Knight_Attack_1_003, Knight_Attack_1_004, Knight_Attack_1_005,
		Knight_Attack_1_006, Knight_Attack_1_007,
		Golem_Idle_1_000, Golem_Idle_1_001, Golem_Idle_1_002,
		Golem_Idle_1_003, Golem_Idle_1_004, Golem_Idle_1_005,
		Golem_Idle_1_006, Golem_Idle_1_007, Golem_Idle_1_008,
		Golem_Idle_1_009, Golem_Idle_1_010, Golem_Idle_1_011,
		Golem_Idle_1_012, Golem_Idle_1_013, Golem_Idle_1_014,
		Golem_Idle_1_015, Golem_Idle_1_016, Golem_Idle_1_017
	};
}

namespace Fonts
{
	enum ID { 
		MainMenu, GameName
	};
}

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	Resource & get(Identifier id);
	const Resource & get(Identifier id) const;

	template<typename Parameter>
	void load(Identifier id, const std::string & filename, const Parameter & ShaderParam); //Overloading for shaders
	void load(Identifier id, const std::string & filename);

private:
	std::map<Identifier,
		std::unique_ptr<Resource>> Resourcemap;
};


typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID>	FontHolder;


template<typename Resource, typename Identifier>
Resource & ResourceHolder<Resource, Identifier>::get(Identifier id)
{
	auto found = Resourcemap.find(id);
	return *found->second;
}

template<typename Resource, typename Identifier>
const Resource & ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
	auto found = Resourcemap.find(id);
	return *found->second;
}

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string & filename)
{
	std::unique_ptr<Resource> resource(new Resource());
	resource->loadFromFile(filename);
	//Exceptions are comming soon...
	Resourcemap.insert(std::make_pair(id, std::move(resource)));
}

template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string & filename, const Parameter& ShaderParam) {
	std::unique_ptr<Resource> resource(new Resource());
	resource->loadFromFile(filename, ShaderParam);

	Resourcemap.insert(std::make_pair(id, std::move(resource)));
}