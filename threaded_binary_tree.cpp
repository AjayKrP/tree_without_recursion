					#include<iostream>
					#include<queue>
					#include<stack>

					using namespace std;

					class bstNode{
					public:
					    int data;
					    bool lthread = false;
					    bool rthread = false;
					    bstNode* left;
					    bstNode* right;

					    bstNode(int data){
						this->data = data;
						left = NULL;
						right = NULL;
						lthread = false;
						rthread = false;
					    }
					    int GetData();
					    void SetLeft(bstNode* l);
					    void  SetRight(bstNode* r);
					    bstNode* GetLeft();
					    bstNode* GetRight();

					    void SetLeftThread(bool value);

					    void SetRightThread(bool value);
					    bool GetLeftThread();
					    bool GetRightThread();
					    bool IsLeft(){
						return (left == nullptr);
					    }
					    bool IsRight(){
						return (right == nullptr);
					    }
					};

					int bstNode::GetData(){ return data;}
					void bstNode::SetLeft(bstNode* l){
					    left = l;
					}
					bstNode* bstNode::GetLeft(){
					    return left;
					}
					bstNode* bstNode::GetRight(){
					    return right;
					}

					void bstNode::SetRight(bstNode* r){
					    right = r;
					}

					void bstNode::SetLeftThread(bool value) {
					    lthread = value;
					}

					void bstNode::SetRightThread(bool value) {
					    rthread = value;
					}

					bool bstNode::GetLeftThread() {
					    return lthread;
					}
					bool bstNode::GetRightThread() {
					    return rthread;
					}

					class BinarySearchTree{
					public:
					    BinarySearchTree(){root == nullptr;}
					    void Insert(int);
					    void Display();
					    bstNode* search(int key);
					    bstNode* root;
					    bstNode* current;
					};

					void BinarySearchTree::Insert(int value) {
					    bstNode* node = new bstNode(value);
					    if(root == nullptr){
						root = node;
						return;
					    }

					    bstNode* ptr = root,*parrent = nullptr;

					    while (ptr != nullptr){
						if(value == ptr->GetData()){
						    std::cout<<"Attempt to insert duplicate value: "<<value<<"--------ignored."<<std::endl;
						    delete node;
						    return;
						}
						parrent = ptr;
						if(value < ptr->GetData()){
						    if(ptr->GetLeftThread()){
							break;
						    } else{
							ptr = ptr->GetLeft();
						    }
						} else{
						    if(ptr->GetRightThread()){
							break;
						    } else{
							ptr = ptr->GetRight();
						    }
						}
					    }
					    if( ptr == nullptr){
						if(value < parrent->GetData()){
						    parrent->SetLeft(node);
						    node->SetRight(parrent);
						    node->SetRightThread(true);
						} else{
						    parrent->SetRight(node);
						    node->SetLeft(parrent);
						    node->SetLeftThread(true);
						}
					    } else{
						if(value < ptr->GetData()){
						    if(ptr->GetLeft() != nullptr) {
							node->SetLeft(ptr->GetLeft());
							node->SetLeftThread(true);
						    }
						    node->SetRight(ptr);
						    node->SetRightThread(true);
						    ptr->SetLeft(node);
						    ptr->SetLeftThread(false);
						} else{
						    if(ptr->GetRight() != nullptr) {
							node->SetRight(ptr->GetRight());
							node->SetRightThread(true);
						    }
						    node->SetLeft(ptr);
						    node->SetLeftThread(true);
						    ptr->SetRight(node);
						    ptr->SetRightThread(false);
						}
					    }
					    return;
					}

					void BinarySearchTree::Display() {
					    if(root == nullptr){
						std::cout<<"Empty"<<std::endl;
						return;
					    }
					    bstNode* p,*q;

					    p = root;
					    do{
						while (p != nullptr){
						    q = p;
						    if(p->GetLeftThread()){
							break;
						    } else{
							p = p->GetLeft();
						    }
						}
						std::cout<<q->data<<"s right thread is "<<q->right->data<< std::endl;
						p = p->GetRight();

						while (q->GetRightThread()){
						    std::cout<<p->data <<" s left thread is "<<p->left->data<<std::endl;
						    q = p;
						    p = q->GetRight();
						}
					    }while (p != nullptr);
					}

					bstNode* BinarySearchTree::search(int value) {
					    bstNode* current = root;
					    while (current){
						if(current->data == value){
						    std::cout<<current->data<<" does exist."<<std::endl;
						    return current;
						}
						else if(value < current->data){
						    current = current->left;
						} else{
						    current = current->right;
						}
					    }
					    cout<<"No "<<value<<std::endl;
					    return NULL;
					}

					auto main() ->int {
					    BinarySearchTree b;
					    int n,m;
					    std::cout<<"How many number ?";
					    std::cin>>n;
					    while (n--){
						std::cout<<"Enter data ?";
						std::cin>>m;
						b.Insert(m);
					    }
					    b.Display();
					    std::cout<<"Enter number to be search ?";
					    std::cin>>m;
					    b.search(m);
					}


