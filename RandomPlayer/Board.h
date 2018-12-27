#pragma once

#include <vector>
#include <string>
#include <sstream>

class Board
{
private:
	const int size;
	std::vector<std::vector<bool>> fields;

public:
	Board(const int size);

	void takeSpot(const int row, const int column);
	std::string toString() const;
};
