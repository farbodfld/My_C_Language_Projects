#include <bits/stdc++.h>

using namespace std;

string checkingSubstring(string temp) {
    string result1, result2, a1_OR_b1, a2_OR_b2;

    if (temp.length() % 2 != 1) {
        string leftSubstring;
        string rightSubstring;

        leftSubstring = temp.substr(0, temp.size() / 2);
        rightSubstring = temp.substr(temp.size() / 2);

        a1_OR_b1 = checkingSubstring(leftSubstring);
        a2_OR_b2 = checkingSubstring(rightSubstring);

        result1 = a1_OR_b1 + a2_OR_b2;
        result2 = a2_OR_b2 + a1_OR_b1;
    } else
        return temp;

    if (result1 < result2)
        return result1;
    else
        return result2;
}

bool finish(const string& result1 , const string& result2){
    return result1 == result2;
}

bool equal(const string &s1, const string &s2) {
    if (s1.size() != s2.size())
        return false;
    else if ((s1.size() % 2 == 1)) {
        return s1 == s2;
    } else if ((s1.size() % 2 == 0)) {
        string result_s1, result_s2;
        result_s1 = checkingSubstring(s1);
        result_s2 = checkingSubstring(s2);
        return finish(result_s1 , result_s2);
        //return result_s1 == result_s2;

        /*string a1 = s1.substr(0, s1.size() / 2);
        string a2 = s1.substr(s1.size() / 2);

        string b1 = s2.substr(0, s2.size() / 2);
        string b2 = s2.substr(s2.size() / 2);

        if (a1.size() == a2.size() && b1.size() == b2.size()) {
            bool bool1 = equal(a1, b1);
            bool bool2 = equal(a2, b2);
            bool bool3 = equal(a1, b2);
            bool bool4 = equal(a2, b1);

            return (bool1 && bool2) || (bool3 && bool4);
        } else
            return false;*/

    }
    return false;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    if (equal(s1, s2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
