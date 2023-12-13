#include "Day3.h"

static const char GEAR = '*';

static bool isInt(const char& c) {
	return c >= '0' && c <= '9';
}

static bool isSpecial(const char& c) {
	return !isInt(c) && c != '.';
}

// part 1
static int isValid(const std::vector<std::string>& field, const std::pair<int, int>& coord) {
	std::string num = "";
	bool isValid = false;
	char currLet;

	for (int y = coord.first; y < field.size(); y++) {
		for (int x = coord.second; x < field[0].size(); x++) {
			currLet = field[y][x];
			if( !isInt(currLet))
				return std::stoi(num) * isValid;
			if ( isInt(currLet) ) {
				num += currLet;
				if (!isValid) {
					//// TODO : check top-left y-1 x-1
					if ((y > 0 && x > 0) && isSpecial(field[y - 1][x - 1]))
						isValid = true;
					//// TODO : check left x-1
					if ((x > 0) && isSpecial(field[y][x - 1]))
						isValid = true;
					//// TODO : check bottom-left y+1 x-1
					if ((y < field.size() - 1 && x > 0) && isSpecial(field[y + 1][x - 1]))
						isValid = true;
					//// TODO : check top y-1
					if ((y > 0) && isSpecial(field[y - 1][x]))
						isValid = true;
					//// TODO : check bottom y+1
					if ((y < field.size() - 1) && isSpecial(field[y + 1][x]))
						isValid = true;
					//// TODO : check top-right y-1 x+1
					if ((y > 0 && x < field[0].size() - 1) && isSpecial(field[y - 1][x + 1]))
						isValid = true;
					//// TODO : check right x+1
					if ((x < field[0].size() - 1) && isSpecial(field[y][x + 1]))
						isValid = true;
					//// TODO : check bottom-right y+1 x+1
					if ((y < field.size() - 1 && x < field[0].size() - 1) && isSpecial(field[y + 1][x + 1]))
						isValid = true;
				}

			}
		}
	}
	return std::stoi(num) * isValid;
}

// part 1
int Day3::sumBattleField(const std::vector<std::string> field) {
	int height = !field.empty() ? field.size() : 0;
	int len = (height && !field[0].empty()) ? field[0].size() : 0;

	int next, sum = 0;
	char currLet;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < len; col++) {
			currLet = field[row][col];
			if (isInt(currLet)) {
				sum += isValid(field, { row, col });

				// then I need to change pos to next '.' also beethoven symphony 7 goes hard!!
				for (; col < len && isInt(field[row][col]); col++);
			}
		}
	}

	return sum;
}

// part 3
static int getNum(const std::vector<std::string>& field, const std::pair<int, int>& coord) {
	int left = coord.second, right = coord.second;
	for (; left >= 0 && isInt(field[coord.first][left]); left--);
	for (; right < field[0].size() && isInt(field[coord.first][right]); right++);
	return std::stoi(field[coord.first].substr(left+1, right - (left+1)));
}

// part 2
static int gearRatio(const std::vector<std::string>& field, const std::pair<int, int>& coord) {
	std::string num = "";
	bool isValid = false;
	char currLet;
	int y = coord.first, x = coord.second, val;
	std::vector<int> foundNums;
	
	// TODO : check top
	if ( ((y > 0) && field[y - 1][x] == '.') && 
		(((y > 0 && x > 0) && isInt(field[y - 1][x - 1])) || ((y > 0 && x < field[0].size() - 1) && isInt(field[y - 1][x + 1]))) )
	{
		if ((y > 0 && x > 0) && isInt(field[y - 1][x - 1]))
			foundNums.emplace_back(getNum(field, { y - 1, x - 1 }));
		if ((y > 0 && x < field[0].size() - 1) && isInt(field[y - 1][x + 1]))
			foundNums.emplace_back(getNum(field, { y - 1, x + 1 }));
	}
	else
	{
		val = 0;
		// top
		// top left
		// top right
		if ((y > 0) && isInt(field[y - 1][x]))
			val = getNum(field, { y - 1, x });
		else if ((y > 0 && x > 0) && isInt(field[y - 1][x - 1]))
			val = getNum(field, { y - 1, x - 1 });
		else if ((y > 0 && x < field[0].size() - 1) && isInt(field[y - 1][x + 1]))
			val = getNum(field, { y - 1, x + 1 });
		if(val != 0)
			foundNums.emplace_back(val);
	}

	// TODO : check left
	//// TODO : check left x-1
	if ((x > 0) && isInt(field[y][x - 1]))
		foundNums.emplace_back(getNum(field, { y, x - 1 }));

	// TODO : check right
	//// TODO : check right x+1
	if ((x < field[0].size() - 1) && isInt(field[y][x + 1]))
		foundNums.emplace_back(getNum(field, { y, x + 1 }));

	// TODO : check bottom
	if ( ((y < field.size() - 1) && field[y + 1][x] == '.') &&
		(((x > 0) && isInt(field[y + 1][x - 1])) || ((x < field[0].size() - 1) && isInt(field[y + 1][x + 1]))) ) {
		//// TODO : check bottom-left y+1 x-1
		if ((y < field.size() - 1 && x > 0) && isInt(field[y + 1][x - 1]))
			foundNums.emplace_back(getNum(field, { y + 1, x - 1 }));
		//// TODO : check bottom-right y+1 x+1
		if ((y < field.size() - 1 && x < field[0].size() - 1) && isInt(field[y + 1][x + 1]))
			foundNums.emplace_back(getNum(field, { y + 1, x + 1 }));
	}
	else{
		val = 0;
		//// TODO : check bottom left y+1 x-1
		//// TODO : check bottom y+1
		//// TODO : check bottom-right y+1 x+1
		if ((y < field.size() - 1 && x > 0) && isInt(field[y + 1][x - 1]))
			val = getNum(field, { y + 1, x - 1 });
		else if ((y < field.size() - 1) && isInt(field[y + 1][x]))
			val = getNum(field, { y + 1, x });
		else if ((y < field.size() - 1 && x < field[0].size() - 1) && isInt(field[y + 1][x + 1]))
			val = getNum(field, { y + 1, x + 1 });
		if(val != 0)
			foundNums.emplace_back(val);
	}
	
	if (foundNums.size() == 2)
		return foundNums[0] * foundNums[1];
	else
		return 0;
}

// part 2
int Day3::sumGearRatio(std::vector<std::string> field) {
	int height = !field.empty() ? field.size() : 0;
	int len = (height && !field[0].empty()) ? field[0].size() : 0;

	int next, sum = 0;
	char currLet;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < len; col++) {
			currLet = field[row][col];
			if ( currLet == GEAR ){
				sum += gearRatio(field, { row, col });

				//beethoven symphony 7 goes hard!!
				//for (; col < len && isInt(field[row][col]); col++);
			}
		}
	}

	return sum;
}