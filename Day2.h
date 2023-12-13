#pragma once

#include <string>
#include <vector>
#include <algorithm>

class Day2
{
	int min_red;
	int min_green;
	int min_blue;

	bool setValid(std::string set);
	void fromSet(std::string set);

public:
	Day2() : min_red(0), min_green(0), min_blue(0){}


	bool isValidGame(std::string game);

	// accessors
	int powerFromGame(std::string game);

};

