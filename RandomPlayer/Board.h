#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <exception>
#include <utility>

class Board
{
private:
	const int size;
	std::vector<std::vector<bool>> fields;

public:
	Board(const int size);

	void takeSpot(const int row, const int column);
	void takeSpot(const std::pair<int, int> point);
	std::string toString() const;
};
