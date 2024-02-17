
#include <bits/stdc++.h>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>

using namespace std;
#define MAX_LEVEL 10
const float p = 0.25;

class Node {
public:
    int key;
    Node **forwardArray;

    Node(int key, int level) {
        this->key = key;

        forwardArray = new Node *[level + 1];

        memset(forwardArray, 0, sizeof(Node *) * (level + 1));
    }
};

class SkipList {
    int level;
    Node *header;

public:
    SkipList(int MAXLEVEL, float P) {

        level = 0;

        header = new Node(-1, MAX_LEVEL);
    };

    int randomLevel() {
        float r = (float) rand() / RAND_MAX;
        int lvl = 0;
        while (r < p && lvl < MAX_LEVEL) {
            lvl++;
            r = (float) rand() / RAND_MAX;
        }
        return lvl;
    };

    Node *createNode(int key, int level) {
        Node *n = new Node(key, level);
        return n;
    };


    void Delete(int key) {
        Node *current = header;

        Node *update[MAX_LEVEL + 1];
        memset(update, 0, sizeof(Node *) * (MAX_LEVEL + 1));


        for (int i = level; i >= 0; i--) {
            while (current->forwardArray[i] != NULL &&
                   current->forwardArray[i]->key < key)
                current = current->forwardArray[i];
            update[i] = current;
        }


        current = current->forwardArray[0];

        if (current != NULL and current->key == key) {

            for (int i = 0; i <= level; i++) {

                if (update[i]->forwardArray[i] != current)
                    break;

                update[i]->forwardArray[i] = current->forwardArray[i];
            }

            while (level > 0 &&
                   header->forwardArray[level] == 0)
                level--;
        } else
            cout << "error" << "\n";
    };

    bool Search(int key) {
        Node *current = header;

        for (int i = level; i >= 0; i--) {
            while (current->forwardArray[i] &&
                   current->forwardArray[i]->key < key)
                current = current->forwardArray[i];

        }
        current = current->forwardArray[0];

        if (current and current->key == key) {
            cout << "true" << "\n";
            return true;
        } else {
            cout << "false" << "\n";
            return false;
        }

    };

    void Insert(int key) {
        Node *current = header;

        Node *update[MAX_LEVEL + 1];
        memset(update, 0, sizeof(Node *) * (MAX_LEVEL + 1));

        for (int i = level; i >= 0; i--) {
            while (current->forwardArray[i] != NULL &&
                   current->forwardArray[i]->key < key)
                current = current->forwardArray[i];
            update[i] = current;
        }

        current = current->forwardArray[0];

        if (current == NULL || current->key != key) {
            int rlevel = randomLevel();

            if (rlevel > level) {
                for (int i = level + 1; i < rlevel + 1; i++)
                    update[i] = header;

                level = rlevel;
            }

            Node *n = createNode(key, rlevel);

            for (int i = 0; i <= rlevel; i++) {
                n->forwardArray[i] = update[i]->forwardArray[i];
                update[i]->forwardArray[i] = n;
            }
        }
    };

    void Print() {
        if (header->forwardArray[0] == NULL)
            cout << "empty";
        Node *node = header->forwardArray[0];
        while (node != NULL) {
            cout << node->key << " ";
            node = node->forwardArray[0];
        }
        cout << "\n";
    };
};

int main() {
    SkipList skipList(10, 0.25);

    string s;
    int data;
    while (cin >> s) {
        if (s == "Insert") {
            cin >> data;
            skipList.Insert(data);
        } else if (s == "Delete") {
            cin >> data;
            skipList.Delete(data);
        } else if (s == "Search") {
            cin >> data;
            cout << (skipList.Search(data) ? "true" : "false") << endl;
        } else if (s == "Print") {
            skipList.Print();
        }
    }
}