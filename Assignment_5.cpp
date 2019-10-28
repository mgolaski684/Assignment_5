#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
#include<list>
using namespace std;

class Graph
{
	int V; // start vertice 
	map<pair<string, string>, int> city;//allows strings to be matched together
	vector<string> city1;
	vector<string> city2;
public:
	Graph(int start_V)
	{
		V = start_V;
	}
	void addEdge(string start, string end, int wt);
	void display_matrix();
};
void Graph::addEdge(string start, string end, int wt)//Adds starting and ending cities and connects them together
{
	city[make_pair(start, end)] = wt;
}
void Graph::display_matrix()//function that displays the matrix
{
	int flag = 0;
	for (auto it : city)
	{
		city1.push_back(it.first.first);
		city2.push_back(it.first.second);
	}
	sort(city1.begin(), city1.end());
	auto last = unique(city1.begin(), city1.end());
	city1.erase(last, city1.end());

	sort(city2.begin(), city2.end());
	auto last2 = unique(city2.begin(), city2.end());
	city2.erase(last2, city2.end());

	for (auto col : city2)
	{
		cout << "\t" << col;
	}
	cout << "\n";
	for (auto row : city1)
	{
		int flag = 0;   //for printing row for once 
		for (auto col : city2)
		{
			if (!flag)
				cout << row;
			cout << "\t" << city[make_pair(row, col)];
			flag = 1;
		}
		cout << "\n";
	}
}
int main()
{
	cout << "\nKey:\n1 means the Cities are connected\n0 means the Cities are not connected\n";
	Graph g(8);
	//San Jose connections
	g.addEdge("S_Jose", "S_Cruz", 1);
	g.addEdge("S_Jose", "Merced", 1);
	g.addEdge("S_Jose", "Redwood", 1);
	//Sonora Connections
	g.addEdge("Sonora", "M_posed", 1);
	g.addEdge("Sonora", "Jackson", 1);
	//Jackson Connections
	g.addEdge("Jackson", "Oakland", 1);
	g.addEdge("Jackson", "M_posed", 1);
	//Oakland Connections
	g.addEdge("Oakland", "M_posed", 1);
	g.addEdge("Oakland", "Jackson", 1);
	//Redwood City Connections
	g.addEdge("Redwood", "Merced", 1);
	g.addEdge("Redwood", "S_Cruz", 1);
	//Merced City Connections
	g.addEdge("Merced", "S_Jose", 1);
	g.addEdge("Merced", "M_posed", 1);
	//Santa Cruz City Connections 
	g.addEdge("S_Cruz", "S_Jose",1);
	g.addEdge("S_Cruz", "Redwood", 1);
	g.addEdge("S_Cruz", "M_posed", 1);
	//Mariposed City Connections
	g.addEdge("M_pose", "Merced", 1);
	g.addEdge("M_pose", "Sonora", 1);
	g.addEdge("M_pose", "Jackson", 1);
	g.addEdge("M_pose", "S_Cruz", 1);
	g.display_matrix();
	return 0;
}