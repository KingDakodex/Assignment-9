#include "Header.h"

// function to convert integers 1-12 to corresponding city name
string GetCityName(int i)
{
	string cityName = "";

	switch (i)
	{
	case Seattle:
		cityName = "Seattle";
		break;
	case Chicago:
		cityName = "Chicago";
		break;
	case Boston:
		cityName = "Boston";
		break;
	case SanFrancisco:
		cityName = "San Francisco";
		break;
	case Denver:
		cityName = "Denver";
		break;
	case NewYork:
		cityName = "New York";
		break;
	case LosAngeles:
		cityName = "Los Angeles";
		break;
	case KansasCity:
		cityName = "Kansas City";
		break;
	case Atlanta:
		cityName = "Atlanta";
		break;
	case Dallas:
		cityName = "Dallas";
		break;
	case Houston:
		cityName = "Houston";
		break;
	case Miami:
		cityName = "Miami";
		break;
	default:
		cityName = "Error - out of bounds";
		break;
	}

	return cityName;
}

// function to perform a BFS traversal
vector<int> bfsTraversal(int v, vector<vector<int>>& edges, int start) 
{
	// initialize Adjacency Matrix structure
	vector<vector<int>> adjMatrix(v, vector<int>(v, INT_MAX));

	// create discovery edge and cross edge vectors to store visited edges
	vector<vector<bool>> discovery(v, vector<bool>(v, false));
	vector<vector<bool>> cross(v, vector<bool>(v, false));

	// use edges vector to input data in Adjacency Matrix
	for (auto& edge : edges) 
	{
		int a = edge[0];
		int b = edge[1];
		int d = edge[2];

		// store distances between cities in Adjacency Matrix
		adjMatrix[a][b] = d;
		adjMatrix[b][a] = d;
	}

	// create vector to keep track of visited cities
	vector<bool> visited(v, false);
	
	// create vector to store BFS order
	vector<int> bfsOrder;
	
	// create queue of cities to visit
	queue<int> cityQueue;

	// begin BFS at starting city
	visited[start] = true;
	cityQueue.push(start);

	// initialize total discovery distance variable
	int discoveryDist = 0;

	// visit all cities and remove visited cities from queue
	while (!cityQueue.empty()) 
	{
		// remove current city from queue
		int curr = cityQueue.front();
		cityQueue.pop();
		
		// add visited city to vector with BFS order
		bfsOrder.push_back(curr);

		// insert all unvisited cities adjacent to current city in vector
		vector<pair<int, int>> adjCities;
		for (int i = 0; i < v; i++)
		{
			if (adjMatrix[curr][i] != INT_MAX)
			{
				if (!visited[i])
				{
					// update edge in discovery vector
					discovery[curr][i] = true;
					
					// output discovery edge
					cout << "Discovery Edge: " << GetCityName(curr) << " to " << GetCityName(i) << endl;
					
					// update total distance traveled on discovery edges
					discoveryDist += adjMatrix[curr][i];

					// add visited city to vector
					adjCities.push_back({ i, adjMatrix[curr][i] });
				}
				else if (!discovery[curr][i] && !cross[curr][i])
				{
					// update edge in cross vector
					cross[curr][i] = true;

					// output cross edge
					cout << "Cross Edge: " << GetCityName(curr) << " to " << GetCityName(i) << endl;
				}
			}
		}

		// sort adjacent cities by distance
		sort(adjCities.begin(), adjCities.end(), [](auto& a, auto& b) { return a.second < b.second; });

		// visit adjacent and unvisited cities, traveling to the closest city first
		for (auto& a : adjCities)
		{
			int nextCity = a.first;
			visited[nextCity] = true;
			cityQueue.push(nextCity);
		}
	}

	// output total distance traveled on discovery edges
	cout << endl << "Total distance traveled on discovery edges: " << discoveryDist << endl;

	return bfsOrder;
}

// function adds cities to Adjacency Matrix and calls BFS traversal function
void BFS()
{
	cout << endl << "Part B Programmed by Hailey Driscoll" << endl << endl;
	cout << "Performing BFS..." << endl;
	
	// initialize size of vector
	int v = 13;
	
	// adds all edges with distances to vector
	vector<vector<int>> edges = { {Seattle, Chicago, 2097}, {Chicago, Boston, 983}, {Boston, NewYork, 214}, {NewYork, Chicago, 787},
		{Chicago, Denver, 1003}, {Denver, Seattle, 1331}, {Seattle, SanFrancisco, 807}, {Chicago, KansasCity, 533}, {KansasCity, Denver, 599},
		{KansasCity, LosAngeles, 1663}, {KansasCity, Dallas, 496}, {KansasCity, Atlanta, 864}, {KansasCity, NewYork, 1260}, {SanFrancisco, Denver, 1267},
		{SanFrancisco, LosAngeles, 381}, {LosAngeles, Denver, 1015}, {LosAngeles, Dallas, 1435}, {Atlanta, Dallas, 781}, {Atlanta, NewYork, 888},
		{Atlanta, Houston, 810}, {Atlanta, Miami, 661}, {Miami, Houston, 1187}, {Houston, Dallas, 239} };

	// initialize starting city
	int start = Denver;

	// calls function to perform BFS traversal
	vector<int> traversal = bfsTraversal(v, edges, start);

	cout << endl << "BFS order:" << endl;

	// output BFS order
	for (int i : traversal) 
	{
		// use function to get city name
		string cityName = GetCityName(i);

		cout << cityName;

		if (i != traversal.size())
		{
			cout << ", ";
		}
	}
}