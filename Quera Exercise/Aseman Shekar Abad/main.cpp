#include <iostream>

int main() {
    int n, m, counter = 0;
    char input;
    std::cin >> n >> m;
    char mySkye[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> input;
            mySkye[i][j] = input;
            if (mySkye[i][j] == '*')
                counter++;
        }
    }

    std::cout << counter;
    return 0;
}
