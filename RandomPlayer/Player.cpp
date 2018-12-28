#include "Player.h"

Player::Player(const Board &board) : board(board)
{

}

void Player::registerMove(const std::string& move)
{
	const auto moveDetails = Parser::parseMove(move);

	board.takeSpot(moveDetails.first);
	board.takeSpot(moveDetails.second);
}

void Player::registerMove(const Move& move)
{
	board.takeSpot(move.first);
	board.takeSpot(move.second);
}

Move Player::generateMove()
{
	for (int x = 1; x <= board.getSize(); x++)
	{
		for (int y = 1; y <= board.getSize(); y++)
		{
			if (!board.checkSpot(x, y))
			{
				//ToDo: Solid refactoring
				{
					int x2 = x;
					int y2 = y - 1;
					if (x2 == 0) x2 = board.getSize();
					if (x2 > board.getSize()) x2 = 1;
					if (y2 == 0) y2 = board.getSize();
					if (y2 > board.getSize()) y2 = 1;

					if (!board.checkSpot(x2, y2))
					{
						Move decision({ x, y }, { x2, y2 });
						registerMove(decision);

						return decision;
					}
				}
				{
					int x2 = x + 1;
					int y2 = y;
					if (x2 == 0) x2 = board.getSize();
					if (x2 > board.getSize()) x2 = 1;
					if (y2 == 0) y2 = board.getSize();
					if (y2 > board.getSize()) y2 = 1;

					if (!board.checkSpot(x2, y2))
					{
						Move decision({ x, y }, { x2, y2 });
						registerMove(decision);

						return decision;
					}
				}
				{
					int x2 = x;
					int y2 = y + 1;
					if (x2 == 0) x2 = board.getSize();
					if (x2 > board.getSize()) x2 = 1;
					if (y2 == 0) y2 = board.getSize();
					if (y2 > board.getSize()) y2 = 1;

					if (!board.checkSpot(x2, y2))
					{
						Move decision({ x, y }, { x2, y2 });
						registerMove(decision);

						return decision;
					}
				}
				{
					int x2 = x - 1;
					int y2 = y;
					if (x2 == 0) x2 = board.getSize();
					if (x2 > board.getSize()) x2 = 1;
					if (y2 == 0) y2 = board.getSize();
					if (y2 > board.getSize()) y2 = 1;

					if (!board.checkSpot(x2, y2))
					{
						Move decision({ x, y }, { x2, y2 });
						registerMove(decision);

						return decision;
					}
				}
			}
				
		}
	}

	throw NoMovePossible("Could not find possible move");
}
