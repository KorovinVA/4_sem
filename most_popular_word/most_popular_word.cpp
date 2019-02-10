#include "pch.h"
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

constexpr auto ADD_WORD = 1;

std::string prepare(const std::string & s);
bool cmp(std::pair<std::string, int> const & a, std::pair<std::string, int> const & b);

int main()
{
	std::ifstream file("text.txt", std::ifstream::in);
	if (file.is_open() == 0) {
		std::cout << "Can't open the file" << std::endl;
		std::abort();
	}

	std::map<std::string, int> map_storage;
	std::string word;

	for (file >> word; !file.eof(); file >> word) {
		word = prepare(word);
		if (map_storage.find(word) == map_storage.end()) {
			map_storage[word] = ADD_WORD;
		}
		else ++map_storage[word];
	}

	std::vector<std::pair<std::string, int>> vec(map_storage.begin(), map_storage.end());
	std::sort(vec.begin(), vec.end(), cmp);

	unsigned int popular_words;

	std::cout << "Enter the number of most used words you want see:" << std::endl;
	std::cin >> popular_words;

	for (auto it = vec.begin(); it != vec.begin() + popular_words; it++) {
		std::cout << it->first << " : " << it->second << std::endl;
	}
}

std::string prepare(const std::string & s) {
	std::string result;
	result = s;
	std::transform(result.begin(), result.end(), result.begin(), ::tolower);
	if (std::ispunct(result.back())) result.pop_back();
	return result;
}

bool cmp(std::pair<std::string, int> const & a, std::pair<std::string, int> const & b) {
	if (a.second > b.second) return true;
	else return false;
}