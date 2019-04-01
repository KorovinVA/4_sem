#pragma once

#include <map>
#include <SFML/Graphics.hpp>

namespace Textures
{
	enum ID { Landscape, 
		Knight_Idle_1_000, Knight_Idle_1_001, Knight_Idle_1_002,
		Knight_Idle_1_003, Knight_Idle_1_004, Knight_Idle_1_005,
		Knight_Idle_1_006
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
		std::unique_ptr<Resource>> mResourcemap;
};





template<typename Resource, typename Identifier>
Resource & ResourceHolder<Resource, Identifier>::get(Identifier id)
{
	auto found = mResourcemap.find(id);
	return *found->second;
}

template<typename Resource, typename Identifier>
const Resource & ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
	auto found = mResourcemap.find(id);
	return *found->second;
}

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string & filename)
{
	std::unique_ptr<Resource> resource(new Resource());
	resource->loadFromFile(filename);
	//Exceptions are comming soon...
	mResourcemap.insert(std::make_pair(id, std::move(resource)));
}

template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string & filename, const Parameter& ShaderParam) {
	std::unique_ptr<Resource> resource(new Resource());
	resource->loadFromFile(filename, ShaderParam);

	mResourcemap.insert(std::make_pair(id, std::move(resource)));
}