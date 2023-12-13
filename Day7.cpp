#include "Day7.h"

static int getVal(const char& card) {
	switch (card) {
		case 'A': return 14;
		case 'K': return 13;
		case 'Q': return 12;
		//case 'J': return 11; // Jack 
		case 'J': return 0; // Joker
		case 'T': return 10;
		default: return card - '0';
	}
}

// returns true if a is better than b given that they have the same 
static bool isHandABetter(const std::string& a, const std::string& b) {
	auto iterA = a.cbegin();
	auto iterB = b.cbegin();
	for (; iterA != a.cend() && iterB != b.cend(); iterA++, iterB++) {
		if (getVal(*iterA) > getVal(*iterB) )
			return true;
		else if (getVal(*iterA) < getVal(*iterB) )
			return false;
	}
	return false;
}

static int getHandType(const std::string& hand) {
	std::vector<std::pair<char, int>> cardsInHand = {};
	std::set<char> cards(hand.cbegin(), hand.cend());
	int numJacks = std::count(hand.cbegin(), hand.cend(), 'J');
	if (cards.size() == 1)
		return 7;
	for (const auto& i : cards) {
		if(i != 'J')
			cardsInHand.push_back({ i, std::count(hand.cbegin(), hand.cend(), i) });
	}
	auto largestNumCards = std::max_element(cardsInHand.cbegin(), cardsInHand.cend(), [](auto a, auto b) {return a.second < b.second; });
	int pos = std::distance(cardsInHand.cbegin(), largestNumCards);
	cardsInHand[pos].second += numJacks;

	// Now determine the type of hand we have
	int checkHandType = -1, numCardsInHand = cardsInHand.size();
	if (numCardsInHand == 5) // High Card
		checkHandType = 1;
	else if (numCardsInHand == 4) // One Pair
		checkHandType = 2;
	else if (numCardsInHand == 3) // Two Pair or Three of a Kind
	{
		bool isThree = (*std::max_element(cardsInHand.cbegin(), cardsInHand.cend(), [](auto a, auto b) {return a.second < b.second; }) ).second == 3;
		if (!isThree)
			checkHandType = 3;
		else
			checkHandType = 4;
	}
	else if (numCardsInHand == 2) // Full house or Four of a kind
	{
		bool isFour = (*std::max_element(cardsInHand.cbegin(), cardsInHand.cend(), [](auto a, auto b) {return a.second < b.second; })).second == 4;
		if (!isFour)
			checkHandType = 5;
		else
			checkHandType = 6;
	}
	else // 5 of a kind
		checkHandType = 7;
	return checkHandType;
}

static void setAllScores(std::vector < std::tuple < std::string, int, int> >& handBetValue) {
	std::string hand;
	for (auto& player : handBetValue) {
		// gets the players hand
		hand = std::get<0>(player);
		int handType = getHandType(hand);
		//(void)checkHandType(hand, handType);
		std::get<2>(player) = handType;
	}
}

long long Day7::SumBets(std::vector < std::tuple < std::string, int, int> >& handBetValue) {
	setAllScores(handBetValue);
	long long sum = 0;
	bool c;
	std::sort(handBetValue.begin(), handBetValue.end(), [&](const auto a, const auto b) {
		if (std::get<2>(a) != std::get<2>(b))
			return std::get<2>(a) < std::get<2>(b);
		c = isHandABetter(std::get<0>(b), std::get<0>(a));
		return c;
		});
	for (int pos = 0; pos < handBetValue.size(); pos++) {
		sum += (pos+1) * std::get<1>(handBetValue[pos]);
	}

	// Print the sorted hands
	//for (const auto& i : handBetValue)
	//	std::cout << std::get<0>(i) << "\n";
	return sum;
}