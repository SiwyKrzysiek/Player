#include <iostream>
#include <vector>
#include <utility>

#include "Board.h"
#include "Parser.h"
#include "Player.h"

using namespace std;

int main()
{
	Board board(5);
	//vector<pair<int, int>> taken = { {0,0}, {1,2}, {3,3} };
	//board.takeManySpots(taken);

	const string obstacleList("{1;2},{3;3},{3;4},{5;5}");
	board.takeManySpots(Parser::parseObstacleList(obstacleList));

	//cout << board.toString();

	Player player(board);
	player.registerMove("{1;1},{2;1}");

	cout << player.getBoard().toString() << endl;

	try
	{
		while (true)
		{
			cout << Parser::moveToString(player.generateMove()) << endl;

			cout << player.getBoard().toString() << endl;
			getchar();
		}
	}
	catch (NoMovePossible e)
	{
		cout << "No more moves possible" << endl;
	}
	

	


	return 0;
}