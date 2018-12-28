#pragma once

#include <string>
#include <exception>

#include "Board.h"
#include "Parser.h"

typedef std::pair<std::pair<int, int>, std::pair<int, int>> Move;

class Player
{
	Board board;
public:
	Player(const Board &board);

	void registerMove(const std::string& move);
	void registerMove(const Move &move);
	Move generateMove();
	Board& getBoard() { return board; }
};

class NoMovePossible : std::runtime_error
{
public:
	NoMovePossible(const std::string& what_arg) : runtime_error(what_arg) {}
};
