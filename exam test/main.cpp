#include <iostream>
using namespace std;
int count(char* s , char c){
    int i = 0 , num = 0;
    while(s[i] != '\0'){
        if(s[i++] == c)
            num++;
    }
    return num;
}

int words(char* s){
    if(*s == '\0')
        return 0;
    return count(s , ' ')+1;
}

int adad(int arr[] , int valiue , int size){
    int num = 0;
    for (int i = 0; i <size; ++i) {
        if(arr[i] == valiue)
            num++;
    }
    return num;
}

int main() {
    int a[]={1,2,1,3,4,3,4,4};
    std::cout <<adad(a , 1 , 8)<< std::endl;
    return 0;
}