#include <iostream>

using namespace std;

class Node {

public:
    Node *right;
    Node *left;
    int height;
    double data;

    Node(double data) {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
        this->height = 0;
    }
};

class RangeTree {
    Node *root_x;
    Node *root_y;
    bool detector = true;

    RangeTree() {
        root_x = NULL;
        root_y = NULL;
    }

    Node *singleRightRotate(Node *&t) {
        Node *u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right)) + 1;
        u->height = max(height(u->left), t->height) + 1;
        return u;
    }

    Node *singleLeftRotate(Node *&t) {
        Node *u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right)) + 1;
        u->height = max(height(t->right), t->height) + 1;
        return u;
    }

    Node *doubleLeftRotate(Node *&t) {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    Node *doubleRightRotate(Node *&t) {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    Node *findMin(Node *t) {
        if (t == NULL)
            return NULL;
        else if (t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    Node *findMax(Node *t) {
        if (t == NULL)
            return NULL;
        else if (t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }


    int height(Node *t) {
        return (t == NULL ? -1 : t->height);
    }

    pair<Node *, Node *> insert(Node *x, double data_x, Node *y, double data_y) {
        if (detector == true) {
            if (x == NULL) {
                x = new Node(data_x);
            } else if (data_x < x->data) {
                x->left = insert(x, data_x, y, data_y).first;
                if (height(x->left) - height(x->right) == 2) {
                    if (data_x < x->left->data)
                        x = singleRightRotate(x);
                    else
                        x = doubleRightRotate(x);
                }
            } else if (data_x > x->data) {
                x->right = insert(x, data_x, y, data_y).first;
                if (height(x->right) - height(x->left) == 2) {
                    if (data_x > x->right->data)
                        x = singleLeftRotate(x);
                    else
                        x = doubleLeftRotate(x);
                }
            }
            x->height = max(height(x->left), height(x->right)) + 1;
        }
        if (!detector) {
            if (y == NULL) {
                y = new Node(data_y);
            } else if (data_y < y->data) {
                y->left = insert(x , data_x , y->left , data_y).second;
                if (height(y->left) - height(y->right) == 2) {
                    if (data_y < y->left->data)
                        y = singleRightRotate(y);
                    else
                        y = doubleRightRotate(y);
                }
            } else if (data_y > y->data) {
                y->right = insert(x , data_x , y->right , data_y).second;
                if (height(y->right) - height(y->left) == 2) {
                    if (data_y > y->right->data)
                        y = singleLeftRotate(y);
                    else
                        y = doubleLeftRotate(y);
                }
            }

            y->height = max(height(y->left), height(y->right)) + 1;
        }
        return {x, y};
    }

    void inorder(Node *t) {
        if (t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    void insert(double x, double y) {
        detector = true;
        root_x = insert(root_x , x , root_y , y).first;
        detector = false;
        root_y = insert(root_x , x , root_y , y).second;
    }

    void display() {
        inorder(root_x);
        cout << endl;
        inorder(root_y);
    }
};

int main() {

    return 0;
}