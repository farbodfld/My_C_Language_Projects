// C++ program to merge k sorted arrays 
// of size n each. 
#include <bits/stdc++.h>

using namespace std;

// A pair of pairs, first element is going to 
// store value, second element index of array 
// and third element index in the array. 
typedef pair<int, pair<int, int> > ppi;
using arr = pair<int, int*>;

// This function takes an array of arrays as an 
// argument and all arrays are assumed to be 
// sorted. It merges them together and prints 
// the final sorted output. 
vector<int> mergeKArrays(vector<vector<int> > arr) {
    vector<int> output;

    // Create a min heap with k heap nodes. Every
    // heap node has first element of an array
    priority_queue<ppi, vector<ppi>, greater<ppi> > pq;

    for (int i = 0; i < arr.size(); i++)
        pq.push({arr[i][0], {i, 0}});

    // Now one by one get the minimum element
    // from min heap and replace it with next
    // element of its array
    while (pq.empty() == false) {
        ppi curr = pq.top();
        pq.pop();

        // i ==> Array Number
        // j ==> Index in the array number
        int i = curr.second.first;
        int j = curr.second.second;

        output.push_back(curr.first);

        // The next element belongs to same array as
        // current.
        if (j + 1 < arr[i].size())
            pq.push({arr[i][j + 1], {i, j + 1}});
    }

    return output;
}

// Driver program to test above functions 
int main() {
    int m , n;
    cin >> m;
    vector<vector<int>> arr;

    for (int i = 0; i < m; ++i) {
        cin >> n;
        //arr[0][0] = n;
        for (int j = 0; j < n; ++j) {
            cin >> arr[i+1][j+1];
        }
    }

    vector<int> output = mergeKArrays(arr);
    for (auto x : output)
        cout << x << " ";
    /*// Change n at the top to change number
    // of elements in an array
    vector<vector<int> > arr{ { 2, 6, 12 },
                              { 1, 9 },
                              { 23, 34, 90, 2000 } };

    vector<int> output = mergeKArrays(arr);

    cout << "Merged array is " << endl;
    for (auto x : output)
        cout << x << " ";*/

    return 0;
} 
