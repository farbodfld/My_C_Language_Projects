#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class RangeTree {
    struct node {
        double point;
        node *left;
        node *right;
        int height;
    };

    node *root;
    node *root2;
    bool identifier = true;

    pair<node *, node *> insert(double x, double y, node *pointX, node *pointY) {
        if (identifier) {
            if (pointX == NULL) {
                pointX = new node;
                pointX->point = x;
                pointX->height = 0;
                pointX->left = pointX->right = NULL;
            } else if (x < pointX->point) {
                pointX->left = insert(x, y, pointX->left, pointY).first;
                if (height(pointX->left) - height(pointX->right) == 2) {
                    if (x < pointX->left->point)
                        pointX = singleRightRotate(pointX);
                    else
                        pointX = doubleRightRotate(pointX);
                }
            } else if (x > pointX->point) {
                pointX->right = insert(x, y, pointX->right, pointY).first;
                if (height(pointX->right) - height(pointX->left) == 2) {
                    if (x > pointX->right->point)
                        pointX = singleLeftRotate(pointX);
                    else
                        pointX = doubleLeftRotate(pointX);
                }
            }

            pointX->height = max(height(pointX->left), height(pointX->right)) + 1;
        }
        if (!identifier) {
            if (pointY == NULL) {
                pointY = new node;
                pointY->point = y;
                pointY->height = 0;
                pointY->left = pointY->right = NULL;
            } else if (y < pointY->point) {
                pointY->left = insert(x, y, pointX, pointY->left).second;
                if (height(pointY->left) - height(pointY->right) == 2) {
                    if (y < pointY->left->point)
                        pointY = singleRightRotate(pointY);
                    else
                        pointY = doubleRightRotate(pointY);
                }
            } else if (y > pointY->point) {
                pointY->right = insert(x, y, pointX, pointY->right).second;
                if (height(pointY->right) - height(pointY->left) == 2) {
                    if (y > pointY->right->point)
                        pointY = singleLeftRotate(pointY);
                    else
                        pointY = doubleLeftRotate(pointY);
                }
            }

            pointY->height = max(height(pointY->left), height(pointY->right)) + 1;
        }

        return {pointX, pointY};
    }

    node *singleRightRotate(node *&t) {
        node *u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right)) + 1;
        u->height = max(height(u->left), t->height) + 1;
        return u;
    }

    node *singleLeftRotate(node *&t) {
        node *u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right)) + 1;
        u->height = max(height(t->right), t->height) + 1;
        return u;
    }

    node *doubleLeftRotate(node *&t) {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    node *doubleRightRotate(node *&t) {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    node *findMin(node *t) {
        if (t == NULL)
            return NULL;
        else if (t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node *findMax(node *t) {
        if (t == NULL)
            return NULL;
        else if (t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }


    int height(node *t) {
        return (t == NULL ? -1 : t->height);
    }

    int getBalance(node *t) {
        if (t == NULL)
            return 0;
        else
            return height(t->left) - height(t->right);
    }

    void inorder(node *t) {
        if (t == NULL)
            return;
        inorder(t->left);
        cout << t->point << " ";
        inorder(t->right);
    }

public:
    RangeTree() {
        root = NULL;
        root2 = NULL;

    }

    void insert(double x, double y) {
        identifier = true;
        root = insert(x, y, root, root2).first;
        identifier = false;
        root2 = insert(x, y, root, root2).second;
    }

    void display() {
        inorder(root);
        cout << endl;
        inorder(root2);
    }
};

int main() {
    RangeTree t;

    t.insert(20.5, 9);
    t.insert(25, 8);
    t.insert(12, 7);
    t.insert(10, 6);
    t.insert(30, 5);
    t.insert(5, 12);
    t.insert(35, 26);
    t.insert(67, 17);
    t.insert(43, 89);
    t.insert(21, 75);
    t.insert(13, 35);
    t.insert(89, 92);
    t.insert(38, 0);
    t.insert(69, 1);
    t.display();
    return 0;
}