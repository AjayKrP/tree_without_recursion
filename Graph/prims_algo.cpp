#include <limits.h>
#include <iostream>
#define V 10
using namespace std;
int minCost = 0;

int minKey(int key[], bool mstSet[], int n) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < n; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

int printMST(int parent[], int n, int graph[V][V]) {
    cout<<"Edge   Weight\n";
    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << std::endl;
}

void printGraph(int n, int graph[V][V]){
    std::cout << "Original Graph :=> \n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            std::cout << graph[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void primMST(int n, int graph[V][V]) {
    int parent[V];
    int key[V];
    bool mstSet[V];
    for (int i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;
        for (int v = 0; v < n; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u, key[v] = graph[u][v];
                cout << u << " ";
            }
    }
    for(int i = 1; i < n; ++i){
        minCost += graph[i][parent[i]];
    }
    printMST(parent, n, graph);
}

int main() {
    int graph[V][V];
    for(int i = 0; i < V; ++i){
        for(int j = 0; j  <V; ++j){
            graph[i][j] = 0;
        }
    }

    int n;
    cout << "Enter order of the graph? ";std::cin >> n;
    cout << "Enter weights in the graph =>\n ";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> graph[i][j];
        }
    }
    printGraph(n, graph);
    primMST(n, graph);
    std::cout << "Total cost of the tree is: " << minCost << std::endl;
    return 0;
}


/*#include <iostream>
#define V 10
using namespace std;

int minWeight = 0;
int findMin(int key[], bool mstSet[], int n){
    int min = INT8_MAX, min_index = -1;
    for(int i = 0; i < n; ++i ){
        if(!mstSet[i] && key[i] < min){
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void printMst(int parent[], int n, int graph[V][V]){
    for(int i = 1; i < n; ++i){
        std::cout << parent[i] << " -> " << i << " := " << graph[i][parent[i]] << endl;
    }
}

void primsMST(int graph[V][V], int n){
    int key[V];
    bool mstSet[V];
    int parent[V];
    for(int i = 0; i < n; ++i){
        key[i] = INT8_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for(int i = 0; i < n-1; ++i){
        int u = findMin(key, mstSet, n);
        mstSet[u] = true;
        for(int v = 0; v < n; ++v){
            if(graph[u][v] && !mstSet[v] &&  graph[u][v] < key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    for(int i = 1; i < n; ++i){
        minWeight += graph[i][parent[i]];
    }
    printMst(parent, n, graph);
}

int main(){
    int graph[V][V];
    for(int i = 0; i < V; ++i){
        for(int j = 0; j  <V; ++j){
            graph[i][j] = 0;
        }
    }
    int cost;
    int n;
    cout << "Enter order of the graph? ";std::cin >> n;
    cout << "Enter weights in the graph =>\n ";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> cost;
            graph[i][j] = cost;
        }
    }
    primsMST (graph,n);
    std::cout << "Total cost of the tree is: " << minWeight << std::endl;
    return 0;
}


0 4 0 3
4 0 2 0
0 2 0 1
3 0 1 0
 */
