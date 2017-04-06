#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>

// -std=c++11
//compile by using g++ -std=c++11 filename.cpp
using namespace std;
class DataBase {
public:
    DataBase():name(""), roll_number(""), division(""), address(""){}
    DataBase(const DataBase&) = delete;
    void constantMessage();
    void writingData();
    void searchingData();
    void deletingData();
    void displayData();
    virtual ~DataBase(){}
private:
    string name;
    string roll_number;
    string division;
    string address;
};

void DataBase::constantMessage() {
    cout << "Please Enter an option number to continue:\n ";
    cout << "\n1: for New Record insertion";
    cout << "\n2: for Record Deletion";
    cout << "\n3: for Searching a Record";
    cout << "\n4: for Updating a Record";
    cout << "\n5: for display all record" << std::endl;
}

void DataBase::writingData() {
    std::cout << "Enter name? ";std::cin >> name;
    std::cout << "Enter roll number? ";std::cin >> roll_number;
    std::cout << "Enter division? ";std::cin >> division;
    std::cin.ignore();
    std::cout << "Enter address? ";getline(std::cin, address);
    ofstream file;
    file.open("record.txt", ios::app | ios::out);
    file << std::endl <<name << std::endl;
    file << roll_number << std::endl;
    file << division << std::endl;
    file << address;
    file.close();
}

void DataBase::deletingData() {
    string line, name;
    cout << "Please Enter the name of record you want to delete: ";
    cin >> name;
    ifstream myfile;
    ofstream temp;
    myfile.open("record.txt");
    temp.open("temp.txt");
    int skip = 0;
    while (getline(myfile, line)) {
        if ((line != name) && (skip <= 0)) {
            temp << line << endl;
        }
        else {
            if(skip == 0) {
                skip = 3; // Skip the next three lines also
            }
            else {
                --skip;
            }
        }
    }
    cout << "The record with the name " << name << " has been deleted if it existed" << endl;
    myfile.close();
    temp.close();
    remove("record.txt");
    rename("temp.txt", "record.txt");
}


void DataBase::searchingData() {
    ifstream fileInput;
    fileInput.open("record.txt");
    string line, search;
    cout << "Please enter the term to search: ";
    cin >> search;
    for (size_t curLine = 0; getline(fileInput, line); curLine++)
    {
        if (line.find(search) != string::npos)
        {
            cout << "found: " << search << " on line: " << curLine << endl;
        }
    }
    fileInput.close();
}

void DataBase::displayData(){
    string line;
    ifstream file;
    file.open("record.txt", ios::in);
    if(!file.is_open()){
        std::cout << "can't open the file!!\n" << std::endl;
    }
    else{
        while(std::getline(file, line)){
            std::cout << line << std::endl;
        }
        file.close();
}
}

int main(){
    int opt;
    DataBase d;
    char ch = 'y';

    do {
        d.constantMessage();
        try{
        cout << "\nEnter option Number: ";
        cin >> opt;
        }catch (std::exception& e){
            std::cout << e.what() << std::endl;
        }
        switch (opt) {
            case 1: {
                d.writingData();
                break;
            }
            case 2: {
                d.deletingData();
                break;
            }
            case 3: {
                d.searchingData();
                break;
            }
            case 4: {
                d.deletingData();
                d.writingData();
                cout << "Record has been updated! ";
                break;
            }
            case 5:
                d.displayData();
                break;
            default:
                break;

        }
        try {
            std::cout << "Do you want to continue(y/n) ?";
            std::cin >> ch;
        }catch (std::exception& e){
            std::cout << e.what() << std::endl;
        }
    }while( ch != 'n');
}

