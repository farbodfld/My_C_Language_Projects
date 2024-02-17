#include<iostream>
#include<set>
#include<vector>

using namespace std;


int main() {
    int n;
    cin >> n;
    int h;
    cin >> h;
    vector<long long int> pts;
    for (int i = 0; i < n; i++) {
        long long int tmp;
        cin >> tmp;
        pts.push_back(tmp);
    }

    set<long long int> valids; // make std::set for saving numbers in sorted mode
    valids.insert(0LL); // initialize it with long long 0

    long long int fin = 0;
    long long int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += pts[i];
        auto it = valids.begin(); // iterator for getting the  set's values
        it = valids.lower_bound(sum - h);
        if (valids.lower_bound(sum - h) != valids.end()) {
            long long int tmp = *it;
            fin = fin > sum - tmp ? fin : sum - tmp;
        }
        valids.insert(sum);
    }
    cout << fin << endl;
}
