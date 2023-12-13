#include "Day2.h"

static bool isInt(const char& c) {
	return c >= '0' && c <= '9';
}

bool Day2::setValid(std::string set) {
	int red, green, blue, pos = set.find("red");
	if (pos != -1) {
		int j = pos - 2;
		for (; j >= 0 && isInt(set[j]); j--);
		int val = std::stoi(set.substr(j + 1, pos - 2 - j));
		if (val > 12)
			return false;
	}
	pos = set.find("green");
	if (pos != -1) {
		int j = pos - 2;
		for (; j >= 0 && isInt(set[j]); j--);
		int val = std::stoi(set.substr(j + 1, pos - 2 - j));
		if (val > 13)
			return false;
	}	
	pos = set.find("blue");
	if (pos != -1) {
		int j = pos - 2;
		for (; j >= 0 && isInt(set[j]); j--);
		int val = std::stoi(set.substr(j + 1, pos - 2 - j));
		if (val > 14)
			return false;
	}
	return true;
}

bool Day2::isValidGame(std::string game) {
	game += "; The End"; // To lazy to figure something else out
	int posStart = game.find(":");
	std::string mySub;
	while (posStart != -1) {
		posStart++;
		int posSemi = game.find(";", posStart);
		mySub = game.substr(posStart, posSemi - posStart);
		if (posSemi != -1 && !setValid(mySub)) {
			return false;
		}
		posStart = posSemi;
	}
	return true;
}

void Day2::fromSet(std::string set) {
	int red, green, blue, pos = set.find("red");
	if (pos != -1) {
		int j = pos - 2;
		for (; j >= 0 && isInt(set[j]); j--);
		int val = std::stoi(set.substr(j + 1, pos - 2 - j));
		if (val > min_red)
			min_red = val;
	}
	pos = set.find("green");
	if (pos != -1) {
		int j = pos - 2;
		for (; j >= 0 && isInt(set[j]); j--);
		int val = std::stoi(set.substr(j + 1, pos - 2 - j));
		if (val > min_green)
			min_green = val;
	}
	pos = set.find("blue");
	if (pos != -1) {
		int j = pos - 2;
		for (; j >= 0 && isInt(set[j]); j--);
		int val = std::stoi(set.substr(j + 1, pos - 2 - j));
		if (val > min_blue)
			min_blue = val;
	}
}

int Day2::powerFromGame(std::string game) {
	game += "; The End"; // To lazy to figure something else out
	int posStart = game.find(":");
	std::string mySub;
	while (posStart != -1) {
		posStart++;
		int posSemi = game.find(";", posStart);
		mySub = game.substr(posStart, posSemi - posStart);
		fromSet(mySub);
		//if (posSemi != -1 && !setValid(mySub)) {
		//	return false;
		//}
		posStart = posSemi;
	}

	return min_red * min_green * min_blue;
}
