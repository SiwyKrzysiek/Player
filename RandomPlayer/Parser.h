#pragma once

#include <vector>
#include <utility>
#include <regex>
#include <exception>
#include <iostream>
#include <sstream>

class Parser
{
public:
	static std::vector<std::pair<int, int>> parseObstacleList(const std::string &list);
	static std::pair<int, int> parsePoint(const std::string &point);
	static std::pair<std::pair<int, int>, std::pair<int, int>> parseMove(const std::string& move);
	static std::string pointToString(const std::pair<int, int> &point);
	static std::string moveToString(const std::pair<std::pair<int, int>, std::pair<int, int>> &move);
};
