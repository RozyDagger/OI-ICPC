//Adjacency list:
class Graph {
    int V;
    vector<int> *adj;
    Graph(int V) {
	this->V=V;
	adj=new vector<int>[V];
    }
    void addEdge(int v, int w) { adj[v].push_back(w); }
};
//List of edges:
struct Edge{ int src, dst; };
class Graph{
	int V, E;
	struct Edge *edge;
	Graph(int V, int E){
		this->V=V;
		this->E=E;
		this->edge=new Edge[E];
	}
	void addEdge(int a, int b, int c){
		this->edge[a].src=b;
		this->edge[a].dst=c;
	}
}
