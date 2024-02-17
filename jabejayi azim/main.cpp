#include<iostream>
using namespace std;
void swap(char d, void* xp, void* yp)
{
    if(d == 'i'){
        int* temp =*(int**)xp;
        *(int**)xp = *(int**)yp;
        *(int**)yp = temp;}
    if(d == 'c'){
        char* temp =*(char**)xp;
        *(char**)xp = *(char**)yp;
        *(char**)yp = temp;}
    if(d == 'f'){
        float* temp =*(float**)xp;
        *(float**)xp = *(float**)yp;
        *(float**) yp = temp;}
}
/*************
implement swap function here
*************/

int main()
{
    int i1 = 111, i2 = 22;
    int *ip1 = &i1, *ip2 = &i2;
    swap('i', &ip1, &ip2);
    *ip1 *= 2;
    *ip2 += 7;
    cout << i1 << ' ' << i2 << '\n'; // 118 44

    char c1 = 'G', c2 = 'P';
    char *cp1 = &c1, *cp2 = &c2;
    swap('c', &cp1, &cp2);
    *cp2 += 5;
    cout << *cp1 << ' ' << *cp2 << '\n'; // P L

    float f1 = 2.86, f2 = 9.68;
    float *fp1 = &f1, *fp2 = &f2;
    swap('f', &fp1, &fp2);
    cout << *fp1 << ' ' << f1 << '\n'; // 9.68 2.86

    return 0;
}
