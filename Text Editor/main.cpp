#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Stack {
    int *a;
    string *b;
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

bool isEmpty2(struct Stack *s) {
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

string pop3(struct Stack *s) {
    if (!isEmpty(s))
        return s->b[s->top--];
    return "$";
}

void push(struct Stack *s, char op) {
    s->a[++s->top] = op;
}

void push2(struct Stack *s, int op) {
    s->a[++s->top] = op;
}

void push3(struct Stack *s, string op) {
    s->b[++s->top] = op;
}
//////////////////////////////////////////////////////
void Text_Editor(string inputString) {

    struct Stack *stack1 = create(1000000);
    struct Stack *stack2 = create(1000000);
    string result;
    string help;

    char listing[1000000];
    int index = -1;

    for (char i : inputString) {
        if (i != '>' && i != '<' && i != '-') {
            push(stack1, i);
        } else if (i == '<') {
            if (!isEmpty(stack1)) {
                listing[++index] = pop(stack1);
            }
        } else if (i == '>') {
            if (!isEmpty(stack1) && index >= 0) {
                push(stack1, listing[index]);
                index--;
            }
        } else if (i == '-') {
            if (!isEmpty(stack1)) {
                pop(stack1);
            }
        }
    }
    for (int i = index; i >= 0; i--)
        push(stack1, listing[i]);

    while (!isEmpty2(stack1)) {
        push(stack2, pop(stack1));
    }

    if (isEmpty2(stack2))
        cout << "-1";

    while (!isEmpty2(stack2)) {
        cout << pop(stack2);
    }
}

int main() {
    string input;
    cin >> input;
    Text_Editor(input);
    return 0;
}















/*struct Queue {
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
}*/

//////////////////////////////////////////////////////
/*void InvertStack_FIFO(struct Stack *s) {
    struct Queue *q1 = create2(100);
    s = create(100);

    while (!isEmpty(s)) {
        add(q1, pop(s));
    }

    while (!isEmpty(q1)) {
        push(s, del(q1));
    }

    while (!isEmpty(q1)) {
        cout << del(q1);
    }
}*/