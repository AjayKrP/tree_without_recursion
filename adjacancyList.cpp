#include<iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;
class adjList{
public:
    void insertData(int src, int dest);
    void printData();
    bool inList(int data);
    void printDFS(int startV);
    bool inLists(int data);
    void printBFS(int startV);
private:
    list<int>head[10];
    vector<int>dfs;
    vector<int>bfs;
};

bool adjList::inList(int data) {
    for(int i = 0; i < dfs.size(); ++i){
        if(dfs[i] == data){
            return true;
        }
    }
    return false;
}
bool adjList::inLists(int data) {
    for(int i = 0; i < bfs.size(); ++i){
        if(bfs[i] == data){
            return true;
        }
    }
    return false;
}
void adjList::insertData(int src, int dest) {
    head[src].push_back(dest);
    head[dest].push_back(src);
}

void adjList::printData() {
    for(int i = 0; i < 10; ++i){
        if(head[i].size() == 0){
            continue;
        }
        cout << i << " -> ";
        list<int>::const_iterator itr;
        for(itr = head[i].begin(); itr != head[i].end(); ++itr){
            cout << *itr << " ";
        }
        std::cout << std::endl;
    }
}

void adjList::printBFS(int startV) {
    queue<int>queue1;
    queue1.push(startV);
    while(!queue1.empty()){
        int temp = queue1.front();
        dfs.push_back(temp);
        cout << temp << " ";
        queue1.pop();
        if(head[temp].size() != 0){
            list<int>::const_iterator itr;
            for(itr = head[temp].begin(); itr != head[temp].end(); ++itr){
                if(!(inList(*itr))) {
                    queue1.push(*itr);
                }
            }
        }
    }
}

void adjList::printDFS(int startV) {
    stack<int>stack1;
    stack1.push(startV);
    while(!stack1.empty()){
        int temp = stack1.top();
        bfs.push_back(temp);
        cout << temp << " ";
        stack1.pop();
        if(head[temp].size() != 0){
            list<int>::const_iterator itr;
            for(itr = head[temp].begin(); itr != head[temp].end(); ++itr){
                if(!inLists(*itr)){
                    stack1.push(*itr);
                }
            }
        }
    }
}

int main(){
    adjList p;
    int startV;
    char ch = 'y';
    int src, dest;
    do{
        cout << "Enter src? ";std::cin >> src;
        cout << "Enter dest? ";std::cin >> dest;
        p.insertData(src, dest);
        cout << "Do you want to continue(y/n): ";
        std::cin >> ch;
    }while(ch != 'n');
    p.printData();
    cout << "Enter starting vertex: ";std::cin >> startV;
    cout << "BFS traversal: " ;
    p.printBFS(startV);
    cout << "\nEnter starting vertex: ";std::cin >> startV;
    cout << "DFS traversal: " ;
    p.printDFS(startV);
}
