#include<iostream>
#include <list>
#include<queue>


class AdjList{
public:
    AdjList(int V);
    void addEdge(int v, int w);
    void BFS(int s);
    void DFSRec(int v, bool visited[]);
    void DFS(int v);
private:
    int V;
    std::list<int> *adj;
};

AdjList::AdjList(int V)
{
    this->V = V;
    adj = new std::list<int>[V];
}

void AdjList::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void AdjList::BFS(int s)
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    std::queue<int> queue;

    visited[s] = true;
    queue.push(s);

    std::list<int>::const_iterator i;

    while(!queue.empty())
    {
        s = queue.front();
        std::cout << s << " ";
        queue.pop();

        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push(*i);
            }
        }
    }
}

void AdjList::DFSRec(int v, bool visited[])
{

    visited[v] = true;
    std::cout << v << " ";

    std::list<int>::const_iterator itr;
    for (itr = adj[v].begin(); itr != adj[v].end(); ++itr)
        if (!visited[*itr])
            DFSRec(*itr, visited);
}



void AdjList::DFS(int v)
{

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    DFSRec(v, visited);
}

int main()
{
    int n, src, dest, edge;
    int startVertex;
    std::cout << "How many vertices? ";
    std::cin >> n;
    std::cout << "How many edges? ";
    std::cin >> edge;
    AdjList aj(n);
    for(int i = 0;i < edge; ++i){
        std::cout << "Enter src ?";std::cin >> src;
        std::cout << "Enter dest ?";std::cin >> dest;
        aj.addEdge(src, dest);
    }
    std::cout << "Enter starting vertex ?";
    std::cin >> startVertex;
    std::cout << "BFS: ";
    aj.BFS(startVertex);
    std::cout << "\nDFS: ";
    aj.DFS(startVertex);
    return 0;
}
