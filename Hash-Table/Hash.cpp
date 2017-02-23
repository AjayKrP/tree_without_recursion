#include <iostream>
#include <vector>
int hashFunction(int key, int table_size){
    return key % table_size;
}

void initializeArr(int *arr, int n){
    for(int i = 0; i < n; ++i){
        arr[i] = -1;
    }
}

bool isTableFull(int *arr, int n){
    for(int i = 0;i < n; ++i){
        if(arr[i] == -1){
            return false;
        }
    }
    return true;
}

int findNextEmptyPosition(int* arr, int n, int k){
    for(int i = k; i < n; ++i){
        if(arr[i] != -1){
            return i;
        } else if(i == n-1){
            i = 0;
        } else if(n / i == 1){
            break;
        }
    }
}

void enterElement(int *arr, int n){
    int m, k, np;
    char  ch ='y';
    do{
        if(!isTableFull(arr, n)){
            std::cout << "Enter element: ";
            std::cin >> m;
            k = hashFunction(m, n);
            if(arr[k] == -1){
                arr[k] = m;
            } else{
                np = findNextEmptyPosition(arr, n, k);
                arr[np] = m;
            }
            std::cout << "Do you want more (y/n): ";
            std::cin >> n;
        } else{
            exit(0);
        }

    }while (ch != 'n');
}
void printElement(int *arr, int n){
for(int i = 0; i < n; ++i){
    std::cout << arr[i] << " ";
}
    std::cout << std::endl;
}

bool searchElement(int arr[], int n, int key){
    int k = hashFunction(n, key);
    while (k < n) {
        if (arr[k] == key) {
            return true;
        } else {
            k = findNextEmptyPosition(arr, n, key);
        }
    }
    return false;
}
int main(){
    unsigned int n, element;
    int search_element;
    std::cout << "Enter size of array: ";
    std::cin >> n;
    int arr[n];
    initializeArr(arr, n);
    enterElement(arr, n);
    printElement(arr, n);
    std::cout << "Enter element which you want to search ?";
    std::cin >> search_element;
    if(!searchElement(arr, n, search_element)){
        std::cout << "Element not Found!" << std::endl;
    } else{
        std::cout << "Element found!" << std::endl;
    }
}
