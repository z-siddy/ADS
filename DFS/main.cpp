// DFS Algorithm task for ADS lecture of Vilnius University
// By Žygimantas Sideravičius ISI
#include<iostream> 
#include<list> 
using namespace std; 

class Graph 
{ 
	int V;
	list<int> *adj; 
	void DFSUtil(int v, bool visited[]); 
  public: 
    Graph(int V);
    void addEdge(int v, int w); 
    void DFS(int v); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w);
} 

void Graph::DFSUtil(int v, bool visited[]) 
{ 
	// Pažymime esamą mazgą "aplankytas" ir jį atspausdinam
	visited[v] = true; 
	cout << v << " "; 

	list<int>::iterator i; 
	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
		if (!visited[*i]) 
			DFSUtil(*i, visited); 
} 

void Graph::DFS(int v) 
{ 
	// Viršūnių žymėjimas "neaplankytos"
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	DFSUtil(v, visited); 
} 

int main() 
{ 
	// Grafo taškai 
	Graph g(5); //0,1,2,3,4 (viršūnės)
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(0, 3);
  g.addEdge(1, 0);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 1);
  g.addEdge(2, 4);
  g.addEdge(3, 0);
  g.addEdge(4, 2);
	
	cout << "DFS Algoritmas (Nuo 0 taško pradžia)" << endl; 
	g.DFS(0); 

	return 0; 
} 
