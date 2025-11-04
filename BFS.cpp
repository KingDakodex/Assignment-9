#include "Header.h"

// function to perform a BFS
vector<int> bfsTraversal(int v, vector<vector<int>>& edges, int start) 
{
	// initialize Adjacency Matrix structure
	vector<vector<int>> adjMatrix(v, vector<int>(v, 0));

	// use edges vector to input data in Adjacency Matrix
	for (auto& edge : edges) 
	{
		int a = edge[0];
		int b = edge[1];
		adjMatrix[a][b] = 1;
		adjMatrix[b][a] = 1;
	}

	// create vector to keep track of visited cities
	vector<bool> visited(v, false);
	
	// BFS order
	vector<int> bfsOrder;
	
	// create queue of cities to visit
	queue<int> cityQueue;

	// begin BFS at starting city
	visited[start] = true;
	cityQueue.push(start);

	// visit all cities and remove visited cities from queue
	while (!cityQueue.empty()) 
	{
		int curr = cityQueue.front();
		cityQueue.pop();
		
		// add visited city to vector with BFS order
		bfsOrder.push_back(curr);

		// visit unvisited cities
		for (int i = 0; i < v; i++) {
			if (adjMatrix[curr][i] == 1 && !visited[i]) {
				visited[i] = true;
				cityQueue.push(i);
			}
		}
	}

	return bfsOrder;
}

// function adds cities to Adjacency Matrix and performs BFS traversal
void BFS()
{
	// initialize size of vector
	int v = 13;
	
	// adds all edges of the map to vector
	vector<vector<int>> edges = { {Seattle, Chicago}, {Chicago, Boston}, {Boston, NewYork}, {NewYork, Chicago},
		{Chicago, Denver}, {Denver, Seattle}, {Seattle, SanFrancisco}, {Chicago, KansasCity}, {KansasCity, Denver},
		{KansasCity, LosAngeles}, {KansasCity, Dallas}, {KansasCity, Atlanta}, {KansasCity, NewYork}, {SanFrancisco, Denver},
		{SanFrancisco, LosAngeles}, {LosAngeles, Denver}, {LosAngeles, Dallas}, {Atlanta, Dallas}, {Atlanta, NewYork},
		{Atlanta, Houston}, {Atlanta, Miami}, {Miami, Houston}, {Houston, Dallas} };
	
	// initialize starting city
	int start = Denver;

	// call function to perform BFS traversal
	vector<int> traversal = bfsTraversal(v, edges, start);

	cout << endl << "BFS order:" << endl;

	// output BFS order
	for (int i : traversal) 
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
		}

		cout << cityName;

		if (i != traversal.size())
		{
			cout << ", ";
		}
	}
}