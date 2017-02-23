
/*#include <iostream>
#include <vector>
#include <algorithm>


#define MAX 1000

using namespace std;
struct edge{
    int u, v, w;
};
typedef struct edge E;

int parent[MAX + 5];
vector<E> graph;
vector<E> selected_edge;

bool comp(const E& l, const E& r){
    return l.w < r.w;
}

int findParent(int r){
    if(r == parent[r])
        return r;
    return parent[r] = findParent(parent[r]);
}

void make_set(int nodes){
    for(int i=1; i<=nodes;++i){
        parent[i] == i;
    }
    return;
}

int Kuruskal_MST(int nodes){
    make_set(nodes);
    sort(graph.begin(), graph.end(), comp);
    int edgeCounter = 0,TotalCost = 0;
    unsigned long len = graph.size();

    for (int i = 0; i < len; ++i) {
        int parent_of_u = findParent( graph[i].u);
        int parent_of_v = findParent( graph[i].v);

        if(parent_of_u != parent_of_v){
            parent[ parent_of_u] = parent_of_v;
            TotalCost += graph[i].w;
            selected_edge.push_back(graph[i]);

            edgeCounter++;
            if(edgeCounter == nodes)
                break;
        }
    }
    return TotalCost;
}

int main(){
    E getEdge;
    int nodes, edges;

    cout<<"How many nodes ?";cin>>nodes;

    cout<<"How many edges ?";cin>>edges;

    cout<<"Enter nodes and their cost ?";
    for (int i = 1; i <= nodes ; ++i) {
        int u, v, w;
        cout<<"Edge :"<<i<<std::endl;
        cin>>u>>v>>w;
        getEdge.u = u;
        getEdge.v = v;
        getEdge.w = w;
        graph.push_back(getEdge);
    }
    int totalCost = Kuruskal_MST(nodes);
    cout<<"Selected edge and their cost :\n";
    for (int i = 0; i < selected_edge.size(); ++i){
        cout<<selected_edge[i].u<<" -> "<<selected_edge[i].v<<" -> "<<selected_edge[i].w<<std::endl;
    }
    std::cout<<"Total cost = "<<totalCost<<std::endl;
    return 0;
}
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <limits>
#include <utility>

#define forsn(i, s, n) for(int i = s; i < n; ++i)
#define forn(i, n) forsn(i, 0, n)

using std::vector;
using std::pair;
using std::list;
using std::make_pair;

typedef vector<int> vint;
typedef pair<double, pair<int, int>> edge;
typedef list<edge> edges;

vint rank;
vint parent;

void create_set(int x) {
    rank[x] = 0;
    parent[x] = x;
}

int find_set(int x) {
    if (x != parent[x]) parent[x] = find_set(parent[x]);
    return parent[x];
}

void merge_set(int x, int y) {
    if (rank[x] > rank[y]) parent[y] = x;
    else parent[x] = y;
    if (rank[x] == rank[y]) ++rank[y];
}

double kruskal(int n, edges& es) {
    rank.resize(n);
    parent.resize(n);
    double cost = 0;
    int remaining = n-1;
    forn(i, n) create_set(i);
    es.sort();
    for (auto& edge : es) {
        int u = find_set(edge.second.first);
        int v = find_set(edge.second.second);
        if (u == v) continue;
        merge_set(u, v);
        cost += edge.first;
        if (!--remaining) break;
    }

    if (remaining) return std::numeric_limits<double>::infinity();
    return cost;
}

int main() {
    int n, m;
    std::ifstream input("/home/ajay/ADS/kruskal.txt");
    //std::cin >> n >> m;
    input >> n >> m;
    //std::cout << n << m << std::endl;
    edges es;
    forn(i, m) {
        double weight;
        int u, v;
        //std::cin >> weight >> u >> v;
        input >> weight >> u >> v;
        //std::cout << weight << u << v << std::endl;
        es.push_back(make_pair(weight, make_pair(u, v)));
    }

    std::cout << "Cost of minimum spanning tree: " << kruskal(n, es) << std::endl;
}

