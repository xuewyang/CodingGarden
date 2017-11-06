//
//  StacksQueues.hpp
//  CTCI
//
//  Created by Xuewen on 10/7/17.
//  Copyright © 2017 Xuewen. All rights reserved.
//

#ifndef StacksQueues_hpp
#define StacksQueues_hpp

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stack>
#include <queue>

#define MAX 1000

class Stack {
private:
    int top;
public:
    int a[MAX];
    Stack();
    ~Stack();
    bool push(int);
    int pop();
    bool isEmpty();
};

struct StackNode {
    int data;
    struct StackNode *next;
};

class StackLL {
public:
    StackLL();
    ~StackLL();
    struct StackNode *newNode(int);
    bool isEmpty(struct StackNode *);
    void push(struct StackNode **,  int);
    int pop(struct StackNode **);
    int peek(struct StackNode *);
};

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int *array;
};

class Que {
public:
    Que();
    ~Que();
    struct Queue *createQueue(unsigned);
    bool isFull(struct Queue *);
    bool isEmpty(struct Queue *);
    void enqueue(struct Queue *, int);
    int dequeue(struct Queue *);
    int front(struct Queue *);
    int rear(struct Queue *);
};

struct QNode {
    int key;
    struct QNode *next;
};

struct QueueLL {
    struct QNode *front, *rear;
};

class QueLL {
public:
    QueLL();
    ~QueLL();
    struct QNode *newNode(int);
    struct QueueLL *createQueue();
    void enqueue(QueueLL *, int);
    struct QNode *dequeue(QueueLL *);
};

#endif /* StacksQueues_hpp */
