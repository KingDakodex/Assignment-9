#include "Header.h"

// Map Class Definitions

// constructor, makes initial map using AddCity
Map::Map()
{
	// size the list too 13, only 12 cities but enum starts at 1 so the 0'th spot will be left empty
	adjList.resize(13);

	// add all cities
	AddCity(Seattle, Chicago, 2097);
	AddCity(Chicago, Boston, 983);
	AddCity(Boston, NewYork, 214);
	AddCity(NewYork, Chicago, 787);
	AddCity(Chicago, Denver, 1003);
	AddCity(Denver, Seattle, 1331);
	AddCity(Seattle, SanFrancisco, 807);
	AddCity(Chicago, KansasCity, 533);
	AddCity(KansasCity, Denver, 599);
	AddCity(KansasCity, LosAngeles, 1663);
	AddCity(KansasCity, Dallas, 496);
	AddCity(KansasCity, Atlanta, 864);
	AddCity(KansasCity, NewYork, 1260);
	AddCity(SanFrancisco, Denver, 1267);
	AddCity(SanFrancisco, LosAngeles, 381);
	AddCity(LosAngeles, Denver, 1015);
	AddCity(LosAngeles, Dallas, 1435);
	AddCity(Atlanta, Dallas, 781);
	AddCity(Atlanta, NewYork, 888);
	AddCity(Atlanta, Houston, 810);
	AddCity(Atlanta, Miami, 661);
	AddCity(Miami, Houston, 1187);
	AddCity(Houston, Dallas, 239);
}

// adds a SINGLE pair of cities and the distance between them. must be repeated for each edge
void Map::AddCity(int nameCityOne, int nameCityTwo, int distance)
{
	// add the first city and its distance too the second
	adjList[nameCityOne].push_back({ nameCityTwo, distance });
	// add the second city and its distance too the first
	adjList[nameCityTwo].push_back({ nameCityOne, distance });
}

// passed a number to decode will return the correct name for that number
string Map::CityDecoder(int toDecode)
{
	// initlize as an error code, if it ISN'T replaced something is wrong
	string toReturn = "WRONG VALUE FED";

	// Assign the correct name to return
	switch (toDecode)
	{
	case Seattle:
		toReturn = "Seattle";
		break;
	case Chicago:
		toReturn = "Chicago";
		break;
	case Boston:
		toReturn = "Boston";
		break;
	case SanFrancisco:
		toReturn = "San Francisco";
		break;
	case Denver:
		toReturn = "Denver";
		break;
	case NewYork:
		toReturn = "New York";
		break;
	case LosAngeles:
		toReturn = "Los Angeles";
		break;
	case KansasCity:
		toReturn = "Kansas City";
		break;
	case Atlanta:
		toReturn = "Atlanta";
		break;
	case Dallas:
		toReturn = "Dallas";
		break;
	case Houston:
		toReturn = "Houston";
		break;
	case Miami:
		toReturn = "Miami";
		break;
	}

	// return the correct name
	return toReturn;
}

void Map::DisplayMap()
{
	for (int i = 1; i < adjList.size(); i++)
	{
		cout << CityDecoder(i) << ": ";
		for (auto& j : adjList[i])
		{
			cout << "{" << CityDecoder(j.first) << ", " << j.second << "} ";
		}
		cout << endl;
	}
}
