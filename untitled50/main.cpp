#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/////////////////////////////////////////////////
bool check_is_yes_or_no(char parantez[], int n) {
    if (n == 0) {
        return true;
    }
    if (n == 1) {
        return false;
    }
    if (parantez[0] == ')' || parantez[0] == '}' || parantez[0] == ']') {
        return false;
    }
    char p2;
    if (parantez[0] == '(') {
        p2 = ')';
    } else if (parantez[0] == '{') {
        p2 = '}';
    } else if (parantez[0] == '[') {
        p2 = ']';
    } else {
        p2 = -1;
    }
    int i, count = 0;
    for (i = 1; i < n; i++) {
        if (parantez[i] == parantez[0]) {
            count++;
        }
        if (parantez[i] == p2) {
            if (count == 0)
                break;
            count--;
        }
    }
    if (i == n) {
        return false;
    }

    if (i == 1) {
        return check_is_yes_or_no(parantez + 2, n - 2);
    } else {
        return check_is_yes_or_no(parantez + 1, i - 1) && check_is_yes_or_no(parantez + i + 1, n - i - 1);
    }
}
////////////////////////////////////////////////////////

struct Stack {
    int *a;
    int top;
    unsigned c;
};

struct Stack *create(unsigned c) {
    struct Stack *s;

    s = (struct Stack *) malloc(sizeof(struct Stack));

    if (!s) return NULL;

    s->top = -1;

    s->c = c;

    s->a = (int *) malloc(s->c * sizeof(int));

    if (!s->a) return NULL;

    return s;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

char peek(struct Stack *s) {
    return s->a[s->top];
}

int peek2(struct Stack *s) {
    return s->top;
}

char pop(struct Stack *s) {
    if (!isEmpty(s))
        return s->a[s->top--];
    return '$';
}

int pop2(struct Stack *s) {
    if (!isEmpty(s))
        return s->a[s->top--];
    return '$';
}

void push(struct Stack *s, char op) {
    s->a[++s->top] = op;
}

void push2(struct Stack *s, int op) {
    s->a[++s->top] = op;
}

///////////////////////////////////////////////////
struct Queue {
    int *a;
    int front;
    int rear;
    int size;
    unsigned c;    // capacity
};

struct Queue *create2(unsigned c) {
    struct Queue *q;
    q = (struct Queue *) malloc(sizeof(struct Queue));

    q->c = c;
    q->front = 0;
    q->rear = c - 1;
    q->size = 0;
    q->a = (int *) malloc(q->c * 4);

    return q;
}

int isEmpty(struct Queue *q) {
    return (q->size == 0);
}

int isFull(struct Queue *q) {
    return (q->size == q->c);
}

void add(struct Queue *q, int item) {
    if (isFull(q))
        return;
    q->rear = (q->rear + 1) % q->c;
    int i;
    i = q->rear;
    q->a[i] = item;
    q->size = q->size + 1;
    cout << item << "  add" << endl;
}

int del(struct Queue *q) {
    if (isEmpty(q))
        return INT_MIN;
    int item, i;
    i = q->front;
    item = q->a[i];
    q->front = (q->front + 1) % q->c;
    q->size = q->size - 1;
    return item;
}

///////////////////////////////////////
class K_Stacks_with_three_Stacks {
    struct Stack *all = create(100);
    struct Stack *sizes = create(100);
    struct Stack *tmp = create(100);
    int k;

public:
    K_Stacks_with_three_Stacks(int x) {
        k = x;
        for (int i = 0; i < k; ++i) {
            push2(sizes, 0);
        }
    }

    void push(int x, int n) {
        int SumOfSize = 0;

        for (int i = k; k > n; k--) {
            push2(tmp, peek(sizes));
            SumOfSize += pop2(sizes);
        }

        push2(sizes, pop2(sizes) + 1);

        while (!isEmpty(tmp)) {
            push2(sizes, pop2(tmp));
        }

        for (int j = SumOfSize; j > 0; --j) {
            push2(tmp, pop2(all));
        }

        push2(all, x);

        while (!isEmpty(tmp)) {
            push2(all, pop2(tmp));
        }
    }

    int pop(int n) {
        if (isEmpty(all))
            return -1;
        int SumOfSize = 0;
        for (int i = k; i > n; --i) {
            push2(tmp, peek2(sizes));
            SumOfSize += pop2(sizes);
        }

        push2(sizes, pop2(sizes) - 1);

        while (!isEmpty(tmp)) {
            push2(sizes, pop2(tmp));
        }

        for (int j = SumOfSize; j > 0; --j) {
            push2(tmp, pop2(all));
        }

        int x = pop2(all);

        while (!isEmpty(tmp)) {
            push2(all, pop2(tmp));
        }

        return x;
    }
};

///////////////////////////////////////
struct Queue_new {
    // stack<int> s1, s2;
    struct Stack *s1 = create(50);
    struct Stack *s2 = create(50);

    void enQueue(int x) {
        // Move all elements from s1 to s2
        while (!isEmpty(s1)) {
            push(s2, peek(s1));
            pop(s1);
        }

        // Push item into s1
        push(s1, x);

        // Push everything back to s1
        while (!isEmpty(s2)) {
            push(s1, peek(s2));
            pop(s2);
        }
    }

    // Dequeue an item from the queue
    int deQueue() {
        // if first stack is empty
        if (isEmpty(s1)) {
            cout << "Q is Empty";
            exit(0);
        }

        // Return top of s1
        int x = peek(s1);
        pop(s1);
        return x;
    }

    void enQueue2(int x)  // O(1)
    {
        // Push item into the first stack
        push(s1, x);
    }

    // Dequeue an item from the queue
    int deQueue2()   // O(N)
    {
        // if both stacks are empty
        if (isEmpty(s1) && isEmpty(s2)) {
            cout << "Q is empty";
            exit(0);
        }

        // if s2 is empty, move
        // elements from s1
        if (isEmpty(s2)) {
            while (!isEmpty(s1)) {
                push(s2, peek(s1));
                pop(s1);
            }
        }

        // return the top item from s2
        int x = peek(s2);
        pop(s2);
        return x;
    }
};

/////////////////////////////////////////////////
class Stack_new {
    // Two inbuilt queues
    // queue<int> q1, q2;
    struct Queue *q1 = create2(50);
    struct Queue *q2 = create2(50);

    // To maintain current number of
    // elements
    int curr_size;

public:
    Stack_new() {
        curr_size = 0;
    }

    void push(int x) {
        curr_size++;

        // Push x first in empty q2
        add(q2, x);

        // Push all the remaining
        // elements in q1 to q2.
        while (!isEmpty(q1)) {
            add(q2, q1->front);
            del(q1);
        }
    }

    void pop() {

        // if no elements are there in q1
        if (isEmpty(q1))
            return;
        del(q1);
        curr_size--;
    }

    void pop2()  // O(N)
    {
        if (isEmpty(q1))
            return;

        // Leave one element in q1 and
        // push others in q2.
        while (q1->size != 1) {
            add(q2, q1->front);
            del(q1);
        }

        // Pop the only left element
        // from q1
        del(q1);
        curr_size--;
    }

    void push2(int x) // O(1)
    {
        add(q1, x);
        curr_size++;
    }

    int top() {
        if (isEmpty(q1))
            return -1;
        return q1->front;
    }

    int size() {
        return curr_size;
    }
};

/////////////////////////////////////////////////
struct Node {
    int data;
    struct Node *link;
};

struct Node *top;

// Utility function to add an element
// data in the stack insert at the beginning
void push(int data) {

    // Create new node temp and allocate memory
    struct Node *temp;
    temp = new Node();

    // Check if stack (heap) is full.
    // Then inserting an element would
    // lead to stack overflow
    if (!temp) {
        cout << "\nHeap Overflow";
        exit(1);
    }

    // Initialize data into temp data field
    temp->data = data;

    // Put top pointer reference into temp link
    temp->link = top;

    // Make temp as top of Stack
    top = temp;
}

// Utility function to check if
// the stack is empty or not
int isEmpty() {
    return top == NULL;
}

// Utility function to return top element in a stack
int peek() {

    // Check for empty stack
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}

// Utility function to pop top
// element from the stack
void pop() {
    struct Node *temp;

    // Check for stack underflow
    if (top == NULL) {
        cout << "\nStack Underflow" << endl;
        exit(1);
    } else {

        // Top assign into temp
        temp = top;

        // Assign second node to top
        top = top->link;

        // Destroy connection between
        // first and second
        temp->link = NULL;

        // Release memory of top node
        free(temp);
    }
}

// Function to print all the
// elements of the stack
void display() {
    struct Node *temp;

    // Check for stack underflow
    if (top == NULL) {
        cout << "\nStack Underflow";
        exit(1);
    } else {
        temp = top;
        while (temp != NULL) {

            // Print node data
            cout << temp->data << "-> ";

            // Assign temp link to temp
            temp = temp->link;
        }
    }
}

/////////////////////////////////////////////////
bool isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
            return true;
    }
    return false;
}

string postToPre(string post_exp) {
    // stack<string> s;

    struct Stack *s = create(100);

    // length of expression
    int length = post_exp.size();

    // reading from right to left
    for (int i = 0; i < length; i++) {

        // check if symbol is operator
        if (isOperator(post_exp[i])) {

            // pop two operands from stack
            string op1 = to_string(peek(s));
            pop(s);
            string op2 = to_string(peek(s));
            pop(s);

            // concat the operands and operator
            string temp = post_exp[i] + op2 + op1;

            // Push string temp back to stack
            stringstream stringstream(temp);
            int tmp = 0;
            stringstream >> tmp;
            push2(s, tmp);
        }

            // if symbol is an operand
        else {

            // push the operand to the stack
            stringstream stringstream1(string(1, post_exp[i]));
            int tmp2 = 0;
            stringstream1 >> tmp2;
            push(s, tmp2);
        }
    }

    string ans = "";
    while (!isEmpty(s)) {
        ans += peek(s);
        pop(s);
    }
    return ans;
}
/*
 * OLD VERSION
bool isOperator(char x) {
    switch (x) {
        case '+':
        case '-':
        case '/':
        case '*':
            return true;
    }
    return false;
}

string postToPre(string post_exp) {
    stack<string> s;

    struct Stack *s;
    s = create(post_exp.size());

    int length = post_exp.size();

    for (int i = 0; i < length; i++) {

        if (isOperator(post_exp[i])) {

            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            string temp = post_exp[i] + op2 + op1;

            s.push(temp);
        }
        else {

            s.push(string(1, post_exp[i]));
        }
    }

    string ans = "";
    while (!s.empty()) {
        ans += s.top();
        s.pop();
    }
    return ans;
}*/
//////////////////////////////////////////////////////

void InvertStack_FIFO(struct Stack *s) {
    struct Queue *q1 = create2(100);
    s = create(100);

    while (!isEmpty(s)) {
        add(q1, pop(s));
    }

    while (!isEmpty(q1)) {
        push(s, del(q1));
    }
    ////////////////////////
    //OLD VERSION
    /*string arr[s.size()];

    while (!isEmpty(s)) {

        for (int i = 0; i < arr->length(); ++i) {
            arr[i] = pop(s);
        }

        for (int j = 0; j < arr->length(); ++j) {
            push(s, arr[j]);
        }
    }*/
    /////////////////////////
}

void InvertStack_LIFO(struct Stack *s) {
    struct Stack *s1 = create(100);
    struct Stack *s2 = create(100);
    s = create(100);

    while (!isEmpty(s)) {

        push(s1, pop(s));
    }

    while (!isEmpty(s1)) {

        push(s2, pop(s1));
    }

    while (!isEmpty(s2)) {

        push(s, pop(s2));
    }
}

/////////////////////////////////////////////
class Queue_and_Stack {
    int n;
    int *arr = new int[n];
    int headOfQueue = n - 1;
    int endOfQueue = n - 1;
    int headOfStack = -1;

public:
    void push(int x) {
        if (headOfStack == endOfQueue + 1 && headOfQueue == n - 1) {
            cout << "FULL" << endl;
        }
        int helpingNUM = headOfQueue - (n - 1);
        if (headOfStack == endOfQueue + 1)
            for (int i = headOfQueue; i >= endOfQueue; i++) {
                arr[i + helpingNUM] = arr[i];
            }
        arr[headOfStack++] = x;
    }

    int pop() {
        if (headOfQueue == 0)
            cout << "EMPTY" << endl;
        return arr[headOfQueue--];
    }

    int top() {
        if (headOfQueue == 0)
            cout << "EMPTY" << endl;
        return arr[headOfQueue - 1];
    }

    void enqueue(int data) {
        if (headOfStack == endOfQueue + 1 && headOfQueue == n - 1) {
            cout << "FULL" << endl;
        }
        int helpingNUM = headOfQueue - (n - 1);
        if (headOfStack == endOfQueue + 1)
            for (int i = headOfQueue; i >= endOfQueue; i++) {
                arr[i + helpingNUM] = arr[i];
            }
        arr[endOfQueue - 1] = data;
    }

    int dequeue() {
        if (headOfQueue == endOfQueue)
            cout << "EPTY" << endl;
        return arr[headOfQueue--];
    }
};
/////////////////////////////////////////////

int main() {
    char p[7001];
    scanf("%s", &p);
    int n;
    for (int i = 0; p[i] != '\0'; i++) {
        n = i;
    }
    if (check_is_yes_or_no(p, n + 1)) {
        printf("YES");
    } else
        printf("NO");
    return 0;
}
