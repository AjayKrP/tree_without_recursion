#include<iostream>
#include<queue>
#define NULL __null

class SimpleTree{
public:
    SimpleTree* createNode(const int& data);
    void insertNode(SimpleTree** root, const int& data);
    void printDFS(SimpleTree* root);
    void printBFS(SimpleTree* root);
    void searchData(SimpleTree* root, const int& data);
private:
    std::queue<SimpleTree*>header;
    int data;
    SimpleTree* left;
    SimpleTree* right;
};

SimpleTree* SimpleTree::createNode(const int& data){
    SimpleTree* temp = new SimpleTree;
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

void SimpleTree::insertNode(SimpleTree** root, const int& data) {
    SimpleTree* temp = createNode(data);
    if(*root == nullptr){
        *root = temp;
        header.push(temp);
    } else{
        SimpleTree* foo = header.front();
        if(foo->left == nullptr){
            foo->left = temp;
            header.push(temp);
        }
        else if(foo->right == nullptr){
            foo->right = temp;
            header.push(temp);
        }
        if(foo->left != nullptr && foo->right != nullptr){
            header.pop();
        }
    }
}

void SimpleTree::printDFS(SimpleTree *root) {
    if(root == nullptr){
        return;
    } else{
        printDFS(root->left);
        std::cout << " " << root->data ;
        printDFS(root->right);
    }
}

void SimpleTree::printBFS(SimpleTree *root) {
    if(root == nullptr){
        return;
    } else{
        std::queue<SimpleTree*>bfs;
        bfs.push(root);
        while(!bfs.empty()){
            const SimpleTree* temp = bfs.front();
            if(temp->left != nullptr){
                bfs.push(temp->left);
            }
            if(temp->right != nullptr){
                bfs.push(temp->right);
            }
            std::cout << temp->data << " ";
            bfs.pop();
        }
    }
}
void  SimpleTree::searchData(SimpleTree *root, const int& data) {
    if(root == nullptr){
        return;
    } else{
        searchData(root->left, data);
        if(root->data == data){
            std::cout << "Data found in the tree.\n";
            return;
        }
        searchData(root->right, data);
    }
}

int main(){
    SimpleTree* root = nullptr, st;
    char ch = 'y';
    int data;
    do{
        std::cout << "Enter data? ";std::cin >> data;
        st.insertNode(&root, data);
        std::cout << "Do you want to continue(y/n) ?";
        std::cin >> ch;
    }while(ch != 'n');
    std::cout << "DFS: ";
    st.printDFS(root);
    std::cout << "\nBFS: ";
    st.printBFS(root);
    std::cout << "\nEnter data which you want to search ?";
    std::cin >> data;
    st.searchData(root, data);
}
<script src="https://gist.github.com/AjayKrP/ea8d9901d4868f52e059275e48fe3b12.js"></script>
