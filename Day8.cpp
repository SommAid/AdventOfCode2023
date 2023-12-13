#include "Day8.h"

// Part 1
unsigned Day8::SumNumberInstructions(const std::string& instructions, const std::map<std::string, std::pair<std::string, std::string>>& map) {
	unsigned numInstructions = 0;
	std::string curr = "AAA", end = "ZZZ";
	auto currInst = instructions.cbegin();
	while (curr != end) {
		for (currInst = instructions.cbegin(); currInst != instructions.cend() && curr != "ZZZ"; currInst++) {
			if (*currInst == 'R')
				curr = map.at(curr).second;
			else
				curr = map.at(curr).first;
			numInstructions++;
		}
	}
	return numInstructions;
}

// Part 2
unsigned Day8::SumNumberInstructionsP2(const std::string& instructions, std::vector<std::tuple<std::string, int, int>>& start, const std::map<std::string, std::pair<std::string, std::string>>& map) {
	unsigned numInstructions;
	
	int countNumInZ = 0, numStartPos = start.size(), numToZ = 0, numRot = 0;

	for(auto& curr : start){
		numInstructions = 0;
		auto currInst = instructions.cbegin();
		while (std::get<1>(curr) == 0 && std::get<2>(curr) == 0)
		{
			while (std::get<0>(curr)[2] != 'Z') {
				if(currInst == instructions.cend())
					currInst = instructions.cbegin();
				for (; currInst != instructions.cend() && std::get<0>(curr)[2] != 'Z'; currInst++) {
					if (*currInst == 'R')
						std::get<0>(curr) = map.at(std::get<0>(curr)).second;
					else
						std::get<0>(curr) = map.at(std::get<0>(curr)).first;
					numInstructions++;
				}
			}
			std::get<1>(curr) = numInstructions;

			numInstructions = 0;
			
			if (currInst == instructions.cend())
				currInst = instructions.cbegin();
			if (*currInst == 'R')
				std::get<0>(curr) = map.at(std::get<0>(curr)).second;
			else
				std::get<0>(curr) = map.at(std::get<0>(curr)).first;
			currInst++;
			numInstructions++;
			while (std::get<0>(curr)[2] != 'Z')
			{
				if (currInst == instructions.cend())
					currInst = instructions.cbegin();
				for (; currInst != instructions.cend() && std::get<0>(curr)[2] != 'Z'; ++currInst) {
					if (*currInst == 'R')
						std::get<0>(curr) = map.at(std::get<0>(curr)).second;
					else
						std::get<0>(curr) = map.at(std::get<0>(curr)).first;
					numInstructions++;
				}
			} 
			std::get<2>(curr) = numInstructions;
		}
	}
	

	return numInstructions;
}