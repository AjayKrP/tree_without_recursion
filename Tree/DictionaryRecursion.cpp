#include<iostream>
#include<string>
#include<exception>
#include<queue>
#define NULL __null
using namespace std;

class node{
public:
	node* create_node(string key, string meaning);
	node* insert_node(node* root, string key, string meaning);
	void print_node(node* root);
	bool search_node(node* root, string key, string meaning);
	void modify_node(node* root, string key, string meaning);
	node* delete_node(node* root, string key, string meaning);
	node* find_maximum(node* root);
	node* find_minimum(node* root);
	void mirror_image(node* root);
	void print_DFS(node* root);
	//virtual ~node();
private:
	string key,meaning;
	node* left,*right;
};

node* node::create_node(string key, string meaning){
	node* temp = new node();
	temp->key = key;
	temp->meaning = meaning;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

node* node::insert_node(node* root,string key, string meaning){
	node* temp = create_node(key, meaning);
	if(root == NULL){
		root = temp;
	}
	else{
		if(root->key >= key && root->meaning >= meaning){
			root->left = insert_node(root->left,key,meaning);
		}
		else{
			root->right = insert_node(root->right,key,meaning);
		}
	}
	return root;
}

void node::print_node(node* root){
	if(root!=NULL){
		cout<<root->key<<" "<<root->meaning<<endl;
		print_node(root->left);
		print_node(root->right);
	}
}

bool node::search_node(node* root ,string key, string meaning){
	if(root==NULL){
		return false;
	}
	else{
		if(root->key == key && root->meaning == meaning){
			return true;
		}
		else if(root->key >= key && root->meaning >= meaning){
			search_node(root->left,key,meaning);
		}
		else{
			search_node(root->right,key,meaning);
		}
	}
	return false;
}

void node::modify_node(node* root, string key, string meaning){
	string n_meaning;
	if(root == NULL){
		return;
	}
	else{
		if(root->key == key && root->meaning == meaning){
			cout<<"Enter new meaning :" ;cin>>n_meaning;
			meaning = n_meaning;
		}
		else if(root->key >= key && root->meaning >= meaning){
			modify_node(root->left,key,meaning);
		}
		else{
			modify_node(root->right,key,meaning);
		}
	}
}

void node::mirror_image(node* root){
	if(root==NULL){
		return;
	}
	mirror_image(root->left);
	mirror_image(root->right);
	node* temp = root->left;
	root->left = root->right;
	root->right = temp;
}

void node::print_DFS(node* root){
	queue<node*>q;
	if(root){
		q.push(root);
		cout<<root->key<<" "<<root->meaning;
	}
	while(!q.empty()){
		const node* const temp = q.front();
		q.pop();
		if(temp->left){
			q.push(temp->left);
			cout<<temp->left->key<<" "<<root->left->meaning;
		}
		if(temp->right){
			q.push(temp->right);
			cout<<temp->right->key<<" "<<root->right->meaning;
		}
	}
}

node* node::find_minimum(node* root)
{
    if(root==NULL){
        return NULL ;
    }
    while(root->left!=NULL)
    {
        root=root->left;
   }
    return root;
 }

node* node::find_maximum(node* root){
	if(root == NULL){
		return NULL;
	}
	while(root->right != NULL){
		root = root->right;
	}
	return root;
}

node* node::delete_node(node* root, string key, string meaning){
	
 if(root==NULL)
    return root;
 else if(key < root->key)
    root->left = delete_node(root->left,key, meaning);
 else if(key > root->key)
    root->right = delete_node(root->right, key, meaning);
 else{
    if(root->left==NULL && root->right==NULL)
    {
        delete root;
        root=NULL;
    }
    else if(root->left == NULL)
    {
        struct Node* temp=root;
        root=root->right;
        delete temp;
    }
    else if(root->right == NULL)
    {
        struct Node* temp=root;
        root=root->left;
        delete temp;
    }
    else{
        struct node* temp = find_minimum(root->right);
        root->meaning = temp->meaning;
        root->right= delete_node(root->right,key, temp->meaning);
    }
 }
 return root;
}


int main(){
	node* root=NULL,b;
	int n;
	string key,meaning;
	cout<<"How many data ?";cin>>n;
	while(n--){
		cout<<"Enter key ?";
		cin>>key;
		cout<<"Enter Meaning ?";
		cin>>meaning;
		root = b.insert_node(root,key,meaning);
	}
	cout<<"Data contains in tree is :\n";
	//b.print_node(root);
	b.mirror_image(root);
	b.print_node(root);
	cout<<"Enter key to search?";cin>>key;
	cout<<"Enter meaning to search ?";cin>>meaning;
	if(b.search_node(root,key,meaning)==true){
		cout<<"Data found in tree.\n";
	}
	else{
		cout<<"Data not found in tree.\n";
	}
}

