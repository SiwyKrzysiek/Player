﻿#pragma once

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
};