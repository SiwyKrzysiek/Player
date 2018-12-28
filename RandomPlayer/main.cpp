#include <iostream>
#include <vector>
#include <utility>

#include "Board.h"
#include "Parser.h"
#include "Player.h"

using namespace std;

int main()
{
	int boardSize;
	cin >> boardSize;
	cout << "ok" << endl;

	string obstacles;
	cin >> obstacles;

	Board board(boardSize);
	board.takeManySpots(Parser::parseObstacleList(obstacles));
	Player player(board);

	cout << "ok" << endl;

	string firstMove;
	cin >> firstMove;

	if (firstMove != "start")
		player.registerMove(firstMove);

	try
	{
		while (true)
		{
			cout << Parser::moveToString(player.generateMove()) << endl;

			string enemyMove;
			cin >> enemyMove;
			player.registerMove(enemyMove);

			cout << player.getBoard().toString() << endl;
		}
	}
	catch (NoMovePossible e)
	{
		//cout << "No more moves possible" << endl;
		return 0;
	}

	//Board board(5);
	////vector<pair<int, int>> taken = { {0,0}, {1,2}, {3,3} };
	////board.takeManySpots(taken);

	//const string obstacleList("{1;2},{3;3},{3;4},{5;5}");
	//board.takeManySpots(Parser::parseObstacleList(obstacleList));

	////cout << board.toString();

	//Player player(board);
	//player.registerMove("{1;1},{2;1}");

	//cout << player.getBoard().toString() << endl;

	//try
	//{
	//	while (true)
	//	{
	//		cout << Parser::moveToString(player.generateMove()) << endl;

	//		cout << player.getBoard().toString() << endl;
	//		getchar();
	//	}
	//}
	//catch (NoMovePossible e)
	//{
	//	cout << "No more moves possible" << endl;
	//}
	

	


	return 0;
}