#include<iostream>
#define SIZE 10

class HashTable{
public:
    HashTable(): _meaning(""){}
    HashTable (const HashTable& h) = delete;
    HashTable& operator = (HashTable& sh) = delete;
    HashTable(const HashTable&& ha) = delete;
    int hashFunction(char key);
    HashTable* createNode(const std::string& str);
    void insertData(char key, const std::string& str);
    void printData();
    bool searchMeaning(char key, const std::string& str);
    int keyGenerate(const std::string& str);
    void updateMeaning(char key,const std::string& str);
    void deleteMeaning(const std::string& str);
    //virtual ~HashTable();
private:
    std::string _meaning;
    HashTable* next;
    HashTable *_header[10]={nullptr,};
    HashTable* tail[10] = {nullptr,};
};

int HashTable::hashFunction(char key){
    return int(key) % SIZE ;
}

int HashTable::keyGenerate(const std::string& str){
    int sum = 0;
    for(unsigned int i = 0; i < str.size(); ++i){
        sum += str[i];
    }
    return sum;
}

HashTable* HashTable::createNode(const std::string& meaning){
    HashTable* temp = new HashTable();
    temp->_meaning = meaning;
    temp->next = nullptr;
    return temp;
}


void HashTable::insertData(char key, const std::string& meaning){
    //int key = keyGenerate(meaning);
    int k = hashFunction(key);
    HashTable* temp = createNode(meaning);
    if(_header[k] == nullptr){
        _header[k] = temp;
        tail[k] = _header[k];
    }
    else{
        tail[k]->next = temp;
        tail[k] = temp;
    }
}

void HashTable::printData(){
    for(int i = 0;i < SIZE; ++i)	{
        HashTable* temp = _header[i];
        while(temp != nullptr){
            std::cout << temp->_meaning << " ";
            temp = temp->next;
            if(temp == nullptr){
                std::cout << std::endl;
            }
        }
    }
}

bool HashTable::searchMeaning(char key, const std::string& str) {
    int m_index = hashFunction(key);
    HashTable* temp = _header[m_index];
    while (temp != nullptr) {
        if (temp->_meaning == str) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void HashTable::updateMeaning(char key, const std::string &str) {
    std::string n_meaning;
    int k = hashFunction(key);
    if(searchMeaning(key, _meaning)){
        std::cout << "Enter new meaning? ";
        std::cin >> n_meaning;
        HashTable* temp = _header[k];
        while(temp != nullptr){
            if(temp->_meaning == _meaning){
                temp->_meaning= n_meaning;
            }
            temp = temp->next;
        }
    }
}

int main(){

    HashTable h;
    std::string meaning, s_meaning;
    char key;
    int choise;
    char ch = 'y';
    do{
        std::cout << "\n1.Insert\n2.Display\n3.Search\n4.Update\n";
        std::cout << "Enter your choice? ";
        std::cin >> choise;
        switch (choise){
            case 1:
                do{
                    std::cout << "Enter key? ";
                    std::cin >> key;
                    std::cout << "Enter meaning? ";
                    std::cin >> meaning;
                    h.insertData(key, meaning);
                    std::cout << "Do you want to enter more meaning(y/n) ?";
                    std::cin >> ch;
                }while (ch != 'n');
                break;
            case 2:
                h.printData();
                break;
            case 3:

                std::cout << "Enter key? ";std::cin >> key;
                std::cout << "Enter meaning which you want to search?";std::cin >> s_meaning;
                if(h.searchMeaning(key, s_meaning)){
                    std::cout << "meaning found!!";
                }
                else{
                    std::cout << "Meaning not found!";
                }
                break;
            case 4:
            std::cout << "Enter key? ";
            std::cin >> key;
            std::cout << "Enter meaning which you want to update? ";
            std::cin >> meaning;
                h.updateMeaning(key, meaning);
                break;
            default:
                break;
        }
        ch = 'y';
        std::cout << "Do you want to continue(y/n)? ";
        std::cin >> ch;
    }while (ch != 'n');
}
