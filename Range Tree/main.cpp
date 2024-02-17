#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int key;
    Node *left;
    Node *right;
    int height;
};

// A utility function to get maximum
// of two integers
int max(int a, int b);

// A utility function to get the
// height of the tree
int height(Node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum
// of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

/* Helper function that allocates a
   new node with the given key and
   NULL left and right pointers. */
Node *newNode(int key) {
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // new node is initially
    // added at leaf
    return (node);
}

// A utility function to right
// rotate subtree rooted with y
// See the diagram given above.
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;

    // Return new root
    return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(Node *N) {
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
Node *insert(Node *node, int key) {
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));

    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
int index = 0;
int* inOrder(Node *root , int arr[]) {
    if (root != NULL) {
        inOrder(root->left , arr);
        /*if ((root->key > y1 && root->key < y2) && (root->key > x1 && root->key < x2)) {
            cout << root->key << " ";
        } else {
            cout << "None" << endl;
        }*/
        arr[index++] = root->key;
        inOrder(root->right , arr);
    }
    return arr;
}


int main() {
    vector<int> X_List;
    vector<int> Y_List;

    int countOfInput;
    cin >> countOfInput;

    int xlist[countOfInput];
    int ylist[countOfInput];
    int X;
    int Y;

    for (int i = 0; i < countOfInput; ++i) {
        cin >> X;
        xlist[i] = X;
    }

    Node *node = NULL;
    int midDle_NODE_Pos_X = countOfInput / 2;
    int root_X = xlist[midDle_NODE_Pos_X];
    node = insert(node, root_X);
    for (int j = 0; j < countOfInput; ++j) {
        node = insert(node, xlist[j]);
    }

    for (int i = 0; i < countOfInput; ++i) {
        cin >> Y;
        ylist[i] = Y;
    }

    Node *node2 = NULL;
    int midDle_NODE_Pos_Y = countOfInput / 2;
    int root_Y = ylist[midDle_NODE_Pos_Y];
    node2 = insert(node2, root_Y);
    for (int j = 0; j < countOfInput; ++j) {
        node2 = insert(node2, ylist[j]);
    }

    int input_counter;
    cin >> input_counter;

    int size = input_counter*4;
    int crd[size];

    int coordinate;
    for (int k = 0; k < size; ++k) {
        cin >> coordinate;
        crd[k] = coordinate;
    }

    int y2 = 0, x2 = 0, y1 = 0, x1 = 0;
    for (int l = 0; l < size; l += 4) {
        y2 = crd[l + 0];
        x2 = crd[l + 1];
        y1 = crd[l + 2];
        x1 = crd[l + 3];

        /*inOrder(node, y2, x2, y1, x1);
        cout << endl;
        inOr
        der(node2, y2, x2, y1, x1);*/
    }
    int xarray[countOfInput];
    int yarray[countOfInput];
    for (int m = 0; m < countOfInput; ++m) {
        xarray[m] = reinterpret_cast<int>(inOrder(node , xarray));
        cout << xarray[m] << " ";
        cout << endl;
        yarray[m] = reinterpret_cast<int>(inOrder(node , yarray));
        cout << yarray[m] << " ";
    }

    return 0;
}