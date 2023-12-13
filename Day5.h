#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iterator>

class Day5
{
	

public:
	unsigned long LowestLocation(const std::vector < std::vector<std::vector <long long> >>& maps);

	unsigned long LowestLocation(const std::vector < std::vector<std::vector <long long> >>& maps, bool part2);

};

