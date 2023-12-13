#include "Day4.h"

static bool isInt(const char& c) {
	return c >= '0' && c <= '9';
}
static std::vector<int> getWinningNumbers(const std::string& card) {
	std::vector<int> winningNums;
	int start = card.find(':'), sep = card.find('|');
	std::string num = "", myNums = card.substr(start + 2, sep - start);

	for (const auto& let : myNums) {
		if (isInt(let)) {
			num += let;
		}
		else if (let == ' ' && !num.empty())
		{
			winningNums.emplace_back(std::stoi(num));
			num = "";
		}
	}
	if(!num.empty())
		winningNums.emplace_back(std::stoi(num));

	return winningNums;
}

static std::vector<int> getMyNumbers(const std::string& card) {
	std::vector<int> myNumbers;
	int sep = card.find('|');
	std::string num = "", myNums = card.substr(sep + 2, card.size() - sep);

	for (const auto& let : myNums) {
		if (isInt(let)) {
			num += let;
		}
		else if (let == ' ' && !num.empty())
		{
			myNumbers.emplace_back(std::stoi(num));
			num = "";
		}
	}
	if (!num.empty())
		myNumbers.emplace_back(std::stoi(num));
	return myNumbers;
}

// part 1
int Day4::scratchOff(const std::string& card) {
	std::vector<int> winningNums, myNums;
	int val = 0;
	myNums = getMyNumbers(card);
	winningNums = getWinningNumbers(card);
	
	std::set<int> winningNumbers(winningNums.begin(), winningNums.end());

	for (const auto& num : myNums) {
		if (winningNumbers.count(num)) {
			if (val == 0)
				val++;
			else
				val *= 2;
		}
	}

	return val;
}

// part 2
int Day4::pileOfScratchOff(const std::vector<std::string>& cards){
	std::vector<int> winningNums, myNums, numCards(int(cards.size()), 0);
	int currPos = 0;
	for (const auto& card : cards) {
		myNums = getMyNumbers(card);
		winningNums = getWinningNumbers(card);
		numCards[currPos]++;
		int count = 1;
		for (int pos = 0; pos < winningNums.size(); pos++) {
			if (std::find(myNums.cbegin(), myNums.cend(), winningNums[pos]) != myNums.cend()) {
				numCards[currPos + count] += numCards[currPos];
				count++;
			}
		}
		currPos++;
	}

	return std::accumulate(numCards.begin(), numCards.end(), 0);
}
