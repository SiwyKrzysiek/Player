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

void Board::takeSpot(const int row, const int column)
{
	if (row >= size && column >= size)
		throw invalid_argument("Point with given coordinates doesn't exist");

	if (fields[row][column])
		throw invalid_argument("This spot is already taken");

	fields[row][column] = true;
}

void Board::takeSpot(const std::pair<int, int> point)
{
	takeSpot(point.first, point.second);
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
