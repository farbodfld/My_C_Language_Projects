#include <iostream>

using namespace std;

void enqueue(char *&queue, int &n, char data) {
    char *p = new char[n + 1];
    for (int i = 0; i < n; ++i) {
        p[i] = queue[i];

    }
    p[n] = data;
    ++n;
    delete[] queue;
    queue = p;
}

char dequeue(char *&queue, int &n) {
    char *p = new char[n - 1];
    for (int i = 1; i < n; ++i) {
        p[i - 1] = queue[i];

    }
    char res = queue[0];
    --n;
    delete[] queue;
    queue = p;
    return res;
}

void print_queue(char *queue, int n) {
    if (n == 0) {
        cout << "empty" << endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        cout << queue[i] << ' ';
    }
    cout << endl;
}

int main() {
    int n = 0;
    char *p = new char[n];
    char l, c;
    cin >> l;
    while (l != 'F') {
        if (l == 'S') {
            cout << n << endl;
        } else if (l == 'E') {
            cin >> c;
            enqueue(p, n, c);
        } else if (l == 'D') {
            if (n == 0)
                cout << "empty";
            else
                cout << dequeue(p, n);
            cout << endl;
        } else if (l == 'P')
            print_queue(p, n);
        cin >> l;
    }
    return 0;
}
