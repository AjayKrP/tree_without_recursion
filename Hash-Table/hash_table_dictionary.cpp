#include <iostream>
using namespace std;

class Hash{
public:
    int hashFunction(int value);
    int calculateHashValue(string meaning);
    Hash*createNode(string meaning);
    void insertNode(string meaning);
    bool search(string name);
    void modifyNode(string name);
    void deleteNode(string meaning);
    void printNode();

private:
    string meaning;
    Hash* next;
    Hash* header[10] = {nullptr, };
    Hash* tail[10] = {nullptr, };
};

int Hash::hashFunction(int value) {
    return value%10;
}

int Hash::calculateHashValue(string meaning) {
    int len = 0;
    for(int i = 0; i < meaning.size(); ++i){
        len += meaning[i];
    }
    return len;
}

Hash* Hash::createNode(string meaning) {
    Hash* temp = new Hash;
    temp->meaning = meaning;
    temp->next = nullptr;
    return temp;
}

void Hash::insertNode(string meaning ){
    int k = hashFunction(calculateHashValue(meaning));
    Hash* temp = createNode(meaning);
    if(header[k] == nullptr){
        header[k] = temp;
        tail[k] = temp;
    } else{
        tail[k]->next = temp;
        tail[k] = temp;
    }
}


void Hash::printNode() {
    for(int i = 0; i < 10; ++i){
        if(header[i] != nullptr){
            cout << i << " -> ";
            Hash* temp = header[i];
            while(temp != nullptr){
                cout << temp->meaning << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
}

void Hash::deleteNode(string meaning) {
    int k = hashFunction(calculateHashValue(meaning));
    Hash* temp = header[k], *prev;
    if (temp != NULL && temp->meaning == meaning) {
        header[k] = temp->next;   
        delete (temp);           
        return;
    }
    
    while (temp != NULL && temp->meaning != meaning) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    
    prev->next = temp->next;
    delete(temp);  
}

bool Hash::search(string name) {
    int k = hashFunction(calculateHashValue(name));
    if(header[k] == nullptr){
        return false;
    }
    else{
        Hash* temp = header[k];
        while(temp != nullptr){
            if(temp->meaning == name){
                return true;
            }
            temp = temp->next;
        }
    }
    return false;
}

void Hash::modifyNode(string name) {
    int k = hashFunction(calculateHashValue(name));
    string n_meaning;
    Hash* temp = header[k];
    if(temp == nullptr){
        return;
    } else{
        while(temp != nullptr){
            if(temp->meaning == name){
                cout << "Enter new meaning? ";cin >> n_meaning;
                temp->meaning = n_meaning;
            }
            temp = temp->next;
        }
    }
    cout << "Node not found!!!\n";
}

int main() {
    Hash h;
    char ch = 'y';
    string meaning;
    do{
    cout << "Enter meaning:";
    cin >> meaning;
    h.insertNode(meaning);
    cout << "Do you want to continue(y/n)? ";
    cin >> ch;
    }while(ch == 'y');
    h.printNode();
   /* cout << "Enter meaning:";
    cin >> meaning;
    if(h.search(meaning)){
        cout << "Found!!!\n";
    } else{
        cout << "Not found!!!\n";
    }
    cout << "Enter meaning:";
    cin >> meaning;
    h.modifyNode(meaning);
    h.printNode();*/
    cout << "Enter meaning:";
    cin >> meaning;
    h.deleteNode(meaning);
    h.printNode();
}
