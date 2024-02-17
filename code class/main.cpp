/*
#include <iostream>
#include <stack>

int main() {
    long int store[5000];
    std::stack<long int > s;

    for (int i = 1; i <= 5000; ++i) {
        while (i > 0){
            s.push(i % 10);
            i = i / 10;
        }
        while (!s.empty()){
           store[i] = s.top();
           s.pop();
        }
    }

    int k;
    std::cin >> k;

    std::cout << store[k] << std::endl;
    return 0;
}*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
class Solution {
public:
    int findNthDigit(int n) {
        lli len = 1;
        lli cnt = 9;
        lli start = 1;
        while(n > len * cnt){
            n -= len * cnt;
            cnt *= 10;
            start *= 10;
            len++;
        }
        start += (n - 1) / len;
        string s = to_string(start);
        return s[(n - 1) % len] - '0';
    }
};
int main(){
    Solution ob;
    int n;
    cin>>n;
    cout << (ob.findNthDigit(n));
}