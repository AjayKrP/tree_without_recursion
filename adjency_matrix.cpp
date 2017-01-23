#include <iostream>
#include <map>
#include <vector>
#include <stack>
using adj_list_DFS = std::multimap<std::pair<auto, auto >, std::pair<auto, bool >>;
using namespace std;
class graph{
public:
    void insert_element(std::multimap<int, int>&adj_mat, int src, int dest);
    void insert_with_weight(std::multimap<int,std::pair<int,int>>&adj_weight, int src, int dest, int weight);
    void print_element_by_weight(std::multimap<int, std::pair<int,int>>&adj_weight);
    void insert_by_vector(std::vector<std::vector<int>>&enter_val, int src, int dest);
    void print_element_by_vector(std::vector<std::vector<int>>&element);
    void print_element(std::multimap<int ,int>&adj_mat);
    void delete_node(std::multimap<int, std::pair<int,int>>& adj_weight, int weight);
    bool search_node(std::multimap<int, std::pair<int, int>>&adj_weight, int weight);
    void insert_DFS(adj_list_DFS);
    void print_DFS(adj_list_DFS &itr, auto src);
};

void graph::insert_DFS(adj_list_DFS) {
    adj_list_DFS.emplace((2,3),(33, false));
}

void graph::print_DFS(adj_list_DFS &itr, auto src) {
    adj_list_DFS::iterator it;
    if(!itr.empty()){
        if(itr->second.second == false){
            
        }
    }
}


void graph::insert_with_weight(std::multimap<int, std::pair<int, int>> &adj_weight, int src, int dest, int weight) {
    adj_weight.emplace(src,std::pair<int, int>(dest,weight));
    adj_weight.emplace(dest,std::pair<int, int>(src,weight));
}

void graph::print_element_by_weight(std::multimap<int, std::pair<int, int>> &adj_weight) {
    std::multimap<int, std::pair<int,int>>::iterator it;
    for(it = adj_weight.begin();it != adj_weight.end(); ++it){
        std::cout<<"  Sourse :"<<it->first;
        std::cout<<"  destination :"<<it->second.first<<"  weight :"<<it->second.second<<std::endl;
    }
}
void graph::insert_element(std::multimap<int, int> &adj_mat, int src, int dest) {
    //adj_mat.emplace(src, dest);
    //adj_mat.emplace(dest, src);
    adj_mat.insert(std::pair<int, int>(src, dest));
    adj_mat.insert(std::pair<int, int>(dest, src));
}


void graph::insert_by_vector(std::vector<std::vector<int>> &enter_val, int src, int dest) {

    enter_val.push_back(std::vector<int>());
    enter_val.push_back(std::vector<int>());
    enter_val[src].push_back(dest);
    /* enter_val.push_back(std::vector<int>());
     enter_val.push_back(std::vector<int>());
     enter_val[dest].push_back(src);*/
}

void graph::print_element_by_vector(std::vector<std::vector<int>> &element) {
    for(int i=0; i< element.size() ;++i){
        for(int j=0; j<element[i].size();++j){
            std::cout<<element[i][j]<<" "<<element[j][i]<<std::endl;
        }
    }
}
void graph::print_element(std::multimap<int, int> &adj_mat) {
    std::map<int ,int>::iterator it;
    for(it = adj_mat.begin(); it != adj_mat.end(); ++it){
        std::cout<<it->first<<" "<<it->second<<std::endl;
    }
}

bool graph::search_node(std::multimap<int, std::pair<int, int>> &adj_weight, int weight) {
    std::multimap<int, std::pair<int, int>>::iterator it;
    for(it = adj_weight.begin(); it != adj_weight.end(); ++it){
        if(it->second.second == weight){
            return true;
        }
    }
    return false;
}

void graph::delete_node(std::multimap<int, std::pair<int, int>> &adj_weight, int weight) {
    std::multimap<int, std::pair<int, int>>::iterator it;
    if (!search_node(adj_weight, weight)) {
        std::cout << "weight not found...";
    } else {
        for (it = adj_weight.begin(); it != adj_weight.end(); ++it) {
            if (it->second.second == weight) {
                adj_weight.erase(it->second.second);
            }
        }
    }
}

auto main() ->int {
    std::multimap<int ,std::pair<int,int>> map1;
    std::vector<std::vector<int>>vec{0,};
    graph g;
    int src, dest, weight;
    char ch ='y';
    do{
        std::cout<<"Enter src ?";std::cin>>src;
        std::cout<<"Enter dest ?";std::cin>>dest;
        std::cout<<"Enter weight?";std::cin>>weight;
        //g.insert_element(map1 , src, dest);
        //g.insert_by_vector(vec, src, dest);
        g.insert_with_weight(map1,src,dest,weight);
        std::cout<<"Do you want more ?";std::cin>>ch;
    }while (ch != 'n');
    //g.print_element(map1);
    // g.print_element_by_vector(vec);
    g.print_element_by_weight(map1);
    std::cout<<"Enter weight to search?";std::cin>>weight;
    if(g.search_node(map1, weight)){
        std::cout<<"Weight found.\n";
    } else{
        std::cout<<"Weight not found.\n";
    }
    std::cout<<"Enter weight to delete?";std::cin>>weight;
    g.delete_node(map1,weight);
    g.print_element_by_weight(map1);
}
