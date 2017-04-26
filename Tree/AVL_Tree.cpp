
#include<iostream>
//#define nullptr __null
class AVL_Tree{
public:
    AVL_Tree():left(nullptr), right(nullptr), root(nullptr){}
    int height(AVL_Tree* );
    int Balence_Factor(AVL_Tree*);
    AVL_Tree* RR_Rotaion(AVL_Tree*);
    AVL_Tree* LL_Rotaion(AVL_Tree*);
    AVL_Tree* LR_Rotaion(AVL_Tree*);
    AVL_Tree* RL_Rotaion(AVL_Tree*);
    AVL_Tree* Balance(AVL_Tree*);
    AVL_Tree* Insert(AVL_Tree*, const std::string&, const std::string& key);
    void displayTree(AVL_Tree*, int);
    void Inorder(AVL_Tree*);
    void PreOrder(AVL_Tree*);
    void PostOrder(AVL_Tree*);
    AVL_Tree* deleteNode(AVL_Tree* root, std::string meaning, std::string& key);
    AVL_Tree* minValueNode(AVL_Tree* root);
    AVL_Tree* removeMin(AVL_Tree* root);
private:
    std::string _meaning;
    std::string _key;
    AVL_Tree* left;
    AVL_Tree* right;
    AVL_Tree* root;
};


int AVL_Tree::height(AVL_Tree* temp){
    int ht = 0;
    if(temp != nullptr){
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = std::max(l_height, r_height);
        ht = max_height + 1;
    }
    return ht;
}

int AVL_Tree::Balence_Factor(AVL_Tree* temp){
    int l_height = 0;
    int r_height = 0;
    int b_factor = 0;
    if(temp != nullptr) {
        l_height = height(temp->left);
        r_height = height(temp->right);
        b_factor = l_height - r_height;
    }
    return b_factor;
}

AVL_Tree* AVL_Tree::LL_Rotaion(AVL_Tree* parent){
    AVL_Tree* temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

AVL_Tree* AVL_Tree::RR_Rotaion(AVL_Tree* parent){
    AVL_Tree* temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

AVL_Tree* AVL_Tree::LR_Rotaion(AVL_Tree* parent){
    AVL_Tree* temp;
    temp = parent->left;
    parent->left = RR_Rotaion(temp);
    return LL_Rotaion(parent);
}

AVL_Tree* AVL_Tree::RL_Rotaion(AVL_Tree* parent){
    AVL_Tree* temp;
    temp = parent->right;
    parent->right = LL_Rotaion(temp);
    return RR_Rotaion(parent);
}

AVL_Tree* AVL_Tree::Balance(AVL_Tree* temp){
    int bal_factor = Balence_Factor(temp);
    if(bal_factor > 1){
        if(Balence_Factor(temp->left) > 0){
            temp = LL_Rotaion(temp);
        }
        else{
            temp = LR_Rotaion(temp);
        }
    }
    else if( bal_factor < -1){
        if(Balence_Factor(temp->right) > 0){
            temp = RL_Rotaion(temp);
        }
        else{
            temp = RR_Rotaion(temp);
        }
    }
    return temp;
}

AVL_Tree* AVL_Tree::Insert(AVL_Tree* root,const std::string& meaning, const std::string& key){
    if(root == nullptr){
        root = new AVL_Tree;
        root->_meaning = meaning;
        root->_key = key;
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }
    else if(meaning < root->_meaning){
        root->left = Insert(root->left, meaning, key);
        root = Balance(root);
    }
    else if(meaning >= root->_meaning){
        root->right = Insert(root->right, meaning, key);
        root = Balance(root);
    }
    return root;
}

void AVL_Tree::displayTree(AVL_Tree* ptr, int level){
    int i;
    if(ptr != nullptr){
        displayTree(ptr->right, level+1);
        std::cout << std::endl;
        if(ptr == root)
            std::cout << "root -> ";
        for( i = 0; i < level && ptr != root ; ++i){
            std::cout << " " << ptr->_meaning << std::endl;
        }
        displayTree(ptr->left, level+1);
    }
}

void AVL_Tree::Inorder(AVL_Tree* temp){
    if(temp == nullptr){
        return;
    }
    else{
        Inorder(temp->left);
        std::cout << temp->_key << " -> " << temp->_meaning << " ";
        Inorder(temp->right);
    }
    std::cout << std::endl;
}

void AVL_Tree::PostOrder(AVL_Tree* temp){
    if(temp == nullptr){
        return;
    }
    else{
        std::cout << temp->_key << " -> " << temp->_meaning << " ";
        PostOrder(temp->left);
        PostOrder(temp->right);
    }
    std::cout << std::endl;
}

void AVL_Tree::PreOrder(AVL_Tree* temp){
    if(temp == nullptr){
        return;
    }
    else{
        PreOrder(temp->left);
        PreOrder(temp->right);
        std::cout << temp->_key << " -> " << temp->_meaning << " ";
    }
    std::cout << std::endl;
}

AVL_Tree* AVL_Tree::minValueNode(AVL_Tree* node){
    AVL_Tree* current = node;
    if(current != nullptr) {
        while (current->left != nullptr) {
            current = current->left;
        }
    }
    return current;
}

AVL_Tree* AVL_Tree::removeMin(AVL_Tree *root) {
    if( root == nullptr) { return nullptr;}
        if (root->left == nullptr) {
            return root->right;
        }
    root->left = removeMin(root->left);
    root = Balance(root);
    return root;
}

AVL_Tree* AVL_Tree::deleteNode(AVL_Tree *root, std::string meaning, std::string& key) {
    if(root == nullptr){
        return root;
    }
    if(meaning < root->_meaning){
        root->left = deleteNode(root->left, meaning, key);
    }
    else if(meaning > root->_meaning){
        root->right = deleteNode(root->right, meaning, key);
    } else{
        AVL_Tree* Left  = root->left;
        AVL_Tree* Right = root->right;
        delete root;
        if(Right  == nullptr){
            return Left;
        }
        root = minValueNode(Right);
        root->left = Left;
        root->right = removeMin(Right);
        return root;
    }
    root = Balance(root);
    return root;
}

int main(){
    AVL_Tree *root = nullptr, a;

    std::string meaning, key;
    char ch = 'y';
    do{
        std::cout << "Enter key?" ;std::cin >> key;
        std::cout << "Enter meaning?";
        std::cin >> meaning;
        root = a.Insert(root, meaning, key);
        std::cout << "Do you want to enter more (y/n)?";
        std::cin >> ch;
    }while(ch != 'n');
    // std::cout << "Height is " << a.height(root) << "\n";
    a.Inorder(root);
    a.PreOrder(root);
    a.PostOrder(root);
    std::cout << "Enter key? ";std::cin >> key;
    std::cout << "Enter meaning to be deleted? ";std::cin >> meaning;
    root = a.deleteNode(root, meaning, key);
    a.Inorder(root);
}
