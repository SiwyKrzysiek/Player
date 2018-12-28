#pragma once

#include <string>

#include "Board.h"
#include "Parser.h"

class Player
{
	Board board;
public:
	Player(const Board &board);

	void registerMove(const std::string& move);
	Board& getBoard() { return board; }
};
