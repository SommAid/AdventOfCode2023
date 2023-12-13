#include "Day5.h"

std::vector<long long> seeds = { 1636419363, 608824189, 3409451394, 227471750, 12950548, 91466703, 1003260108, 224873703, 440703838, 191248477, 634347552, 275264505, 3673953799, 67839674, 2442763622, 237071609, 3766524590, 426344831, 1433781343, 153722422 };
//std::vector<long long> seeds = { 79, 14, 55, 13 };

unsigned long Day5::LowestLocation(const std::vector < std::vector < std::vector<long long>>>& maps) {
	unsigned long destination, source, length;
	
	int count = 0;
	for (const auto& currMap : maps) {
		count++;
		for (auto& seed : seeds) {

			for (const auto& currConvert : currMap) {

				destination = currConvert[0];
				source = currConvert[1];
				length = currConvert[2];

				if (seed >= source && seed < source + length) {
					seed = destination + (seed - source);
					break;
				}
			}

		}
	}
	return *std::min_element(seeds.begin(), seeds.end());
}

static void allSeeds(std::vector<unsigned long>& a) {
	long long length, curr, start = 0;
	for (int i = 0; i < seeds.size(); i++) {
		curr = seeds[i];
		if (i % 2 == 0)
		{
			start = curr;
		}
		else {
			length = curr;
			std::vector<int> v(length);
			std::iota(v.begin(), v.end(), start);
			a.insert(a.end(), std::make_move_iterator(v.begin()), std::make_move_iterator(v.end()));
		}
	}
}

// part 2
unsigned long Day5::LowestLocation(const std::vector < std::vector<std::vector <long long> >>& maps, bool part2) {
	unsigned long destination, source, length;

	if (!part2)
		return -1;
	
	std::vector<unsigned long> trueSeeds;
	allSeeds(trueSeeds);


	int count = 0;
	for (const auto& currMap : maps) {
		count++;
		for (auto& seed : trueSeeds) {

			for (const auto& currConvert : currMap) {

				destination = currConvert[0];
				source = currConvert[1];
				length = currConvert[2];

				if (seed >= source && seed < source + length) {
					seed = destination + (seed - source);
					break;
				}
			}
		}
	}
	return *std::min_element(trueSeeds.begin(), trueSeeds.end());
}


//for part 2 what I was thinking about doing that could probably speed it up quickly was instead of brute forcing what I would do is :
//
//*keep all the seeds in a pair <start, end>
//* then depending on what the map says I add modify the current pair to the first pair first set of destination coordinates(trying to keep the range) then append more pairs to the end and once I have finished going through all the seeds go to the next map
//
//Example
//
//seeds : 10 5 20 5
//seed to soil : 4 8 5
//			 : 0 13 4
//seeds = { {10, 14}, {20, 24} }
//seed to soil = { {4, 8} /* ending locations */, {8, 12} /*start location that where the position is the end location 8 in pos 0 = end location in pos 0 or the value 4*/ }
//			 = {{1, 2}, {11, 16}}
//What happens :
//seeds[0] = { 10, 14 } the number {10, 11, 12} exist on the rang of 8-12 thus we need to modify 
//seeds[0] = {6, 8} // and we need to append {13, 14}
//seeds = { {6, 8}, {20, 24}, {13, 14} }
//seeds[1] = {20, 24} // None of these numbers exist in any of the ranges of the current map
//seeds = { {6, 8}, {20, 24}, {13, 14} }
//seeds[2] = { 11, 12 } // {13, 14} exist in the range {11, 16}
//seeds[2] = {0, 1}
//seeds = { {6, 8}, {20, 24}, {0, 1} }
//
//then repeat for soil to whatever, then whatever to whatever ... to ... and ...

