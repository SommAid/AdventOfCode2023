#include "Day1.h"

const std::vector<std::string> string_nums = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const std::vector<std::string> nums = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

int Day1::findNumsInstring(std::string a) {
	// std::vector<std::pair<posistion in a, value at a>>
	std::vector<std::pair<int, int>> num;

	std::string number;
	for (int i = 0; i < string_nums.size(); i++) {
		number = string_nums[i];
		int pos, left = 0;
		while (left != -1) {
			int pos = a.find(number, left);
			if (pos >= 0) {
				num.emplace_back(pos, i);
				left = pos + 1;
			}
			else
				left = pos;
		}
	}

	for (int i = 0; i < string_nums.size(); i++) {
		number = nums[i];
		int pos, left = 0;
		while (left != -1) {
			int pos = a.find(number, left);
			if (pos >= 0) {
				num.emplace_back(pos, i);
				left = pos + 1;
			}
			else
				left = pos;
		}
	}

	int min_pos = num[0].first;
	int max_pos = num[0].first;
	int min = num[0].second;
	int max = num[0].second;
	for (const auto myPair : num) 
	{
		if (myPair.first < min_pos) {
			min_pos = myPair.first;
			min = myPair.second;
		}
		else if (myPair.first > max_pos) {
			max_pos = myPair.first;
			max = myPair.second;
		}
	}
	
	int ret = min * 10 + max;
	return ret;
}

