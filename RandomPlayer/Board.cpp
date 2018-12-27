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
