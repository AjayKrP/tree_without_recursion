#include<iostream>
#include<string>
#include<queue>
#include<stack>
#define NULL __null
using namespace std;

class node{
public:
	node* create_node(int data);
	void insert_node(node** root, int data);
	void print_node(node* root);
	bool search_node(node* root,int data);
	void modify_node(node* root, int data);
	void delete_node(node* root, int data);
	void inorder_without_recursion(node* root);
	void pre_order_without_recursion(node* root);
	void post_order_without_recursion(node* root);
	int find_maximum(node* root);
	int find_minimum(node* root);
	void print_DFS(node* root);
	//virtual ~node();
private:
	int data;
	node* left,*right;
};

node* node::create_node(int data){
	node* temp = new node();
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void node::insert_node(node** root, int data){
	node* temp = *root;
	node *parrent = *root;
	if(*root == NULL){
		*root = create_node(data);
	}
	else{
		while(temp!=NULL){
			if(data > temp->data){
				parrent = temp;
				temp = temp->right;
			}
			else{
				parrent = temp;
				temp=temp->left;
			}
		}
		temp = create_node(data);

		if(data >= parrent->data){
			parrent->right = temp;
		}
		else{
			parrent->left = temp;
		}
	}
}

bool node::search_node(node* root,int data){
	while(root!=NULL){
		if(data > root->data){
			root = root->right;
		}
		else if(data < root->data){
			root = root->left;
		}
		else{
			return true;
		}
	}
	return false;
}


void node::inorder_without_recursion(node* root){
	stack<node*>s;
	while(true){
		while(root != NULL){
			s.push(root);
			root= root->left;
		}
		if(s.empty()){
			return;
		}
		else{
		root = s.top();
		s.pop();
		cout<<root->data<<" ";
		root = root->right;
		}
	}
}

void node::pre_order_without_recursion(node* root){
	stack<node*>s;
	while(true){
		while(root!=NULL){
			cout<<root->data<< " ";
			s.push(root);
			root = root->left;
		}
		if(s.empty()){
			return;
		}
		else{
			root = s.top();
			s.pop();
			root = root->right;
		}
	}
}


void node::post_order_without_recursion(node* root){
	if(!root){
		return;
	}
	stack<node*>s;
	s.push(root);
	node* prev = NULL;
	while(!s.empty()){
		node* curr = s.top();
		if(!prev || prev->left ==curr || prev->right == curr){
			if(curr->left){
				s.push(curr->left);
			}
			else if(curr->right){
				s.push(curr->right);
			}
			else{
				cout<<curr->data<<" ";
				s.pop();
			}
		}
		else if(curr->left == prev){
			if(curr->right){
				s.push(curr->right);
			}
			else{
				cout<<curr->data<<" ";
				s.pop();
			}
		}
		else if(curr->right == prev){
			cout<<curr->data<<" ";
			s.pop();
		}
		prev = curr;
	}
}


void node::print_node(node* root){
	if(root==NULL){
		return;
	}
	if(root!=NULL){
		cout<<root->data<<" ";
		print_node(root->left);
		print_node(root->right);
	}
}

void node::print_DFS(node* root){
	queue<node*>q;
	if(root){
		q.push(root);
		cout<<root->data<<" ";
	}
	while(!q.empty()){
		const node* const temp = q.front();
		q.pop();
		if(temp->left){
			q.push(temp->left);
			cout<<temp->left->data<<" ";
		}
		if(temp->right){
			q.push(temp->right);
			cout<<temp->right->data<<" ";
		}
	}
}


int main(){
	node* root = NULL,b;
	int n,m;
	cout<<"Enter n?";cin>>n;
	while(n--){
		cout<<"Enter m?";cin>>m;
		b.insert_node(&root,m);
	}
	cout<<"Data in tree is :";
	//b.print_node(root);
	//b.inorder_without_recursion(root);
	//b.post_order_without_recursion(root);
	b.print_DFS(root);

}

