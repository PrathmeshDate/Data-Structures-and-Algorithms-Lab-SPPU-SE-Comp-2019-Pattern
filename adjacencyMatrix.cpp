#include <iostream>
#include <queue>
#include <fstream>
using namespace std;

#define MAX 10

// class containing graph
class graph
{
	// data members
	int g[MAX][MAX];
	int n;
	string location[MAX];

public:
	// constructor
	graph()
	{
		// initialize every value in matrix as 0
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				g[i][j] = 0;
			}
		}
	}
	// member functions
	int readgraph();
	void displaygraph();
	void bfs(int v);
	void dfs(int v, int varr[]);
};

// function to read the no. of vertices and edges
int graph::readgraph()
{
	// accessing file to get edges
	ifstream f("ass7.dat");
	// getting no. of vertices
	f >> n;
	string loc;
	for (int i = 0; i < n; i++)
	{
		f >> loc;
		// inserting every location in the location array
		location[i] = loc;
	}
	int u, v;
	while (f)
	{
		f >> u;
		f >> v;
		// setting the edge value to 1
		g[u][v] = 1;
		g[v][u] = 1;
	}
	cout << "Graph Created Successfully" << endl;
	return n;
}

// function to display adjacancy matrix
void graph::displaygraph()
{
	cout << endl;
	cout << "Adjacancy Matrix of the graph : " << endl;
	cout << endl;
	// displaying the matrix
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "  " << g[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

// function to perform Breadth First Search
void graph::bfs(int v)
{
	int x;
	int varr[n];
	for (int i = 0; i < n; i++)
	{
		varr[i] = 0;
	}
	// using STL queue
	queue<int> Q;
	Q.push(v);
	varr[v] = 1;
	while (!Q.empty())
	{
		x = Q.front();
		Q.pop();
		// printing the location corresponding to x
		cout << "  ->  " << location[x];
		for (int j = 0; j < n; j++)
		{
			if (g[x][j] != 0 && !varr[j])
			{
				Q.push(j);
				varr[j] = 1;
			}
		}
	}
	cout << endl;
}

// function to perform Depth First Search
void graph::dfs(int v, int varr[])
{
	varr[v] = 1;
	// printing the location corresponding to v
	cout << "  ->  " << location[v];
	for (int j = 0; j < n; j++)
	{
		if (g[v][j] != 0 && !varr[j])
		{
			// recursive call for j
			dfs(j, varr);
		}
	}
}

// function to display menu
void menu()
{
	cout << endl;
	cout << "*** GRAPH ***" << endl;
	cout << "1. Read Graph" << endl;
	cout << "2. Display Graph" << endl;
	cout << "3. BFS" << endl;
	cout << "4. DFS" << endl;
	cout << "5. Exit" << endl;
	cout << endl;
}

int main()
{
	// creating object of graph class
	graph g;
	// variable to store no. of vertices outside class
	int nv;
	// driver code
	int choice;
	do
	{
		menu();
		cout << "Enter your choice : ";
		cin >> choice;
		// switch case for choosing operations
		switch (choice)
		{
		case 1:
		{
			nv = g.readgraph();
			break;
		}
		case 2:
		{
			g.displaygraph();
			break;
		}
		case 3:
		{
			int startvertex;
			cout << "Enter the starting vertex : ";
			cin >> startvertex;
			cout << "BFS ";
			g.bfs(startvertex);
			break;
		}
		case 4:
		{
			int startvertex;
			cout << "Enter the starting vertex : ";
			cin >> startvertex;
			cout << "DFS ";
			int varr[nv];
			for (int i = 0; i < nv; i++)
			{
				varr[i] = 0;
			}
			g.dfs(startvertex, varr);
			cout << endl;
			break;
		}
		}
	} while (choice < 5);
	cout << "Exited" << endl;
	return 0;
}