#include "Parser.h"

using namespace std;

std::vector<std::pair<int, int>> Parser::parseObstacleList(const std::string &list)
{
	vector<pair<int, int>> result;

	const regex fullPattern("(\\{[[:digit:]];[[:digit:]]\\},){0,}\\{[[:digit:]];[[:digit:]]\\}");

	if (!regex_match(list, fullPattern))
		throw invalid_argument("Wrong format");

	const regex pointPattern("\\{[[:digit:]];[[:digit:]]\\}");

	smatch match;
	string::const_iterator searchStart(list.cbegin());
	while (regex_search(searchStart, list.cend(), match, pointPattern))
	{
		const string &pointString = match[0];
		result.push_back(parsePoint(pointString));
		
		searchStart = match.suffix().first;
	}

	return result;
}

std::pair<int, int> Parser::parsePoint(const std::string& point)
{
	pair<int, int> result;

	stringstream stream;
	stream << point;

	if (stream.get() != '{')
		throw invalid_argument("{ expected");

	stream >> result.first;

	if (stream.get() != ';')
		throw invalid_argument("; expected");

	stream >> result.second;

	if (stream.get() != '}')
		throw invalid_argument("} expected");

	//if (!stream.eof())
	//	throw invalid_argument("Encountered characters after }");

	return result;
}
