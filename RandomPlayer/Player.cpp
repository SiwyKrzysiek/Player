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
