#include <iostream>
using namespace std;
int count(char* a)
{
    int i;
    for (i = 0; a[i] != 0 ; ++i);
    return i;
}
char * adamSaz(char *a, int n){
    for (int i = 0; i < n; ++i)
        if ('A' <= a[i] && a[i] <= 'Z')
            a[i] -= 'A' - 'a';
    a[0] += 'A' - 'a';
    for (int i = 2; i < n; ++i)
        if (a[i-1] == ' ')
            a[i] += 'A' - 'a';
    return a;
}
bool avvaliKuchiktare(char *a,char *b)
{
    while (*a != 0 && *b != 0)
    {
        if (*a < *b)
            return true;
        else if (*a > *b)
            return false;
        else{
            a++;
            b++;
        }
    }
    return *a == 0;
}
void insertionSort(char** arr, int n)
{
    char *key;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && avvaliKuchiktare(key,arr[j])) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main() {
    int n;
    cin >> n;
    char *a = new char[n];
    char ashghal[51];
    cin.getline(ashghal,50);
    for (int i = 0; i < n; ++i) {
        a[i] = *new char[51];
        cin.getline(reinterpret_cast<char *>(a[i]), 50);
        int n = count(reinterpret_cast<char *>(a[i]));
        a[i] = *adamSaz(&a[i],n);
    }
    insertionSort(&a,n);
    for (int i = 0; i < n; ++i)
        cout << a[i] << endl;

    return 0;
}