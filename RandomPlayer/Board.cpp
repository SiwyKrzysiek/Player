#include "Board.h"

using namespace std;

Board::Board(const int size) : size(size)
{
	fields.resize(size);
	for (auto &row : fields)
	{
		row.resize(size);
	}
}

Board::Board(const Board& board) : Board(board.getSize())
{
	for (int r = 0; r < size; r++)
	{
		for (int c=0; c < size; c++)
		{
			if (board.fields[r][c])
				this->fields[r][c] = true;
		}
	}
}

void Board::takeSpot(const int x, const int y)
{
	if (x < 1 || y < 1 || x > size || y > size)
		throw invalid_argument("Point with given coordinates doesn't exist");

	if (fields[y-1][x-1])
		throw invalid_argument("This spot is already taken");

	fields[y-1][x-1] = true;
}

void Board::takeManySpots(const std::vector<std::pair<int, int>> points)
{
	for (const auto &point : points)
	{
		takeSpot(point);
	}
}

bool Board::checkSpot(int x, int y)
{
	if (x == 0)
		x = size;
	if (y == 0)
		y = size;

	return fields.at(y - 1).at(x - 1);
}

std::string Board::toString() const
{
	stringstream result;

	for (const auto &row : fields)
	{
		for (const bool field : row)
		{
			result << (field ? 'X' : 'O');
		}
		result << '\n';
	}

	return move(result.str());
}

Board Board::clone() const
{
	Board copy(size);
	copy.fields = vector<vector<bool>>(this->fields);

	return copy;
}
