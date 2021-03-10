#include <iostream>
#include <set>
#include <string>

int main() { 
	std::set<std::string> myset; 

	myset.emplace("foo");
	myset.emplace("bar");
	auto ret = myset.emplace("foo");

	if(!ret.second) std::cout<< *ret.first << " is already in myset\n";
	return 0;
}

//ret : pair <value,bool>