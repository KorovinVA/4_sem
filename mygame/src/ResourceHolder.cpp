#include "ResourceHolder.h"

template<typename Resource, typename Identifier>
Resource & ResourceHolder<Resource, Identifier>::get(Identifier id)
{
	auto found = mResourcemap.find(id);
	return *found->second;
}

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string & filename)
{
	std::unique_ptr<Resource> resourse(new Resource());
	resourse->loadFromFile(filename);

	mResourcemap.insert(std::make_pair(id, std::move(resourse)));
}