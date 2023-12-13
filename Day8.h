#pragma once

#include "includes.h"

class Day8
{

public:
	unsigned SumNumberInstructions(const std::string& instructions, const std::map<std::string, std::pair<std::string, std::string>>& map);

	unsigned SumNumberInstructionsP2(const std::string& instructions, std::vector<std::tuple<std::string, int, int>>& start, const std::map<std::string, std::pair<std::string, std::string>>& map);
};

