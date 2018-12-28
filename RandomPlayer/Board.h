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
	Board(const Board& board);

	int getSize() const { return size; }

	void takeSpot(const int row, const int column);
	void takeSpot(const std::pair<int, int> point) { takeSpot(point.first, point.second); }
	void takeManySpots(const std::vector<std::pair<int, int>> points);
	bool checkSpot(int x, int y);
	std::string toString() const;
	Board clone() const;
};
