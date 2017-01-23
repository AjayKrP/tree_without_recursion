#include <iostream>
#include <vector>
#include <algorithm>
int graph[5][5];
int find_minimum(int row, int n){
    std::vector<int >vec(n);
    for(int i = 0;i<n;++i){
        if(graph[row][i] != 0) {
            vec.push_back(graph[row][i]);
        }
    }
    std::sort(vec.begin(),vec.end());
    return vec[0];
}

int find_position(int row, int n, int weight){
    for(int i=0;i<n;++i){
        if(graph[row][i] == weight){
            return i;
        }
    }
}
int minimum_St(int n){
    int totalCount = 0;
    for(int i =0;i<n-1 ;++i){
        int weight = find_minimum(i, n);
        totalCount += weight;
        int k = find_position(i, n, weight);
        graph[i][k] = 0;
        graph[k][i] = 0;
    }
}
int main(){
    int vertices;
    std::cout<<"How many vertices ?";std::cin>>vertices;

    for(int i = 0; i < vertices; ++i){
        for (int j = 0; j < vertices; ++j) {
            graph[i][j] = 0;
        }
    }
    int edges;
    std::cout<<"How many edges ?";std::cin>>edges;
    int src, dest, weight;
    for(int i = 0;i < edges; ++i){
        std::cout<<"Enter src: ";std::cin>>src;
        std::cout<<"Enter dest :";std::cin>>dest;
        std::cout<<"Enter weight :";std::cin>>weight;
        graph[src][dest] = weight;
        graph[dest][src] = weight;
    }
    std::cout<<"Minimum weight :"<<minimum_St(edges)<<std::endl;
}
