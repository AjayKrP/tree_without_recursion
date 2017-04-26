
#include <iostream>
#include <list>
#include <climits>
#include <vector>
#include <queue>

int minCost = 0;
using namespace std;

using iPair = std::pair<int, int>;

class Graph {
private:
    int vert;
    list< pair<int, int> > *adj;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void primMST();
};

Graph::Graph(int vert) {
    this->vert = vert;
    adj = new list< pair<int, int> > [vert];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::primMST() {
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    int src = 0;
    vector<int> key(vert, INT_MAX);

    vector<int> parent(vert, -1);

    vector<bool> inMST(vert, false);
    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty()) {

        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;
            if (inMST[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    for (int i = 1; i < vert; ++i)
        printf("%d - %d\n", parent[i], i);
   
    for (int i = 1; i < vert; ++i){
        list< pair<int, int> >::iterator j;
        for (j = adj[i].begin(); j != adj[i].end(); ++j) {
            minCost += (*j).second;
        }
    }
    cout << "Total cost is: " << minCost << endl;
}


int main()
{
    int V = 9;
    Graph g(V);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 3, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 1);
    g.primMST();
    return 0;
}
