#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> myHeap;

    int n, input, stone1, stone2, result, out;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        myHeap.push(input);
    }

    while (myHeap.size() > 1) {
        stone1 = myHeap.top();
        myHeap.pop();
        stone2 = myHeap.top();
        myHeap.pop();
        result = abs(stone1 - stone2);
        myHeap.push(result);
    }

    if (myHeap.empty())
        cout << myHeap.size();
    else{
        out = myHeap.top();
        cout << out;
    }
    return 0;
}