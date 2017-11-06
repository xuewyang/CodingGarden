//
//  StacksQueues.cpp
//  CTCI
//
//  Created by Xuewen on 10/7/17.
//  Copyright © 2017 Xuewen. All rights reserved.
//

#include "StacksQueues.hpp"

Stack::Stack() {};
Stack::~Stack() {};

bool Stack::push(int x) {
    if (top >= MAX) {
        printf("Overflow.");
        return false;
    }
    else {
        a[++top] = x;
        return true;
    }
}

int Stack::pop() {
    if (top == 0) {
        printf("Underflow.");
        return -1;
    } else {
        return a[top--];
    }
}

bool Stack::isEmpty() {
    return top == 0 ? true : false;
}

StackLL::StackLL(){};
StackLL::~StackLL(){};

StackNode *StackLL::newNode(int data) {
    struct StackNode *sn = (struct StackNode *)malloc(sizeof(struct StackNode));
    sn->data = data;
    sn->next = NULL;
    return sn;
}

bool StackLL::isEmpty(struct StackNode *root) {
    return !root;
}

void StackLL::push(struct StackNode **root, int data) {
    struct StackNode *nNode = newNode(data);
    nNode->next = *root;
    *root = nNode;
}

int StackLL::pop(struct StackNode **root) {
    if (isEmpty(*root))
        return INT_MIN;
    struct StackNode *temp = *root;
    *root = (*root)->next;
    int res = temp->data;
    free(temp);
    return res;
}

int StackLL::peek(struct StackNode *root) {
    if (isEmpty(root))
        return INT_MIN;
    else
        return root->data;
}

Que::Que() {}
Que::~Que() {}
Queue *Que::createQueue(unsigned capacity) {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int *)malloc(sizeof(queue->capacity * sizeof(int)));
    return queue;
}

bool Que::isFull(struct Queue *root) {
    return root->size == root->capacity;
}

bool Que::isEmpty(struct Queue *root) {
    return root->size == 0;
}

void Que::enqueue(struct Queue *root, int data) {
    if (isFull(root))
        return;
    root->rear = (root->rear + 1) % root->capacity;
    root->size += 1;
    root->array[root->rear] = data;
    printf("%d enqueued in queue.", data);
}

int Que::dequeue(struct Queue *root) {
    if (isEmpty(root))
        return INT_MIN;
    int item = root->array[root->front];
    root->front = (root->front + 1) % (root->capacity);
    root->size -= 1;
    return item;
}

int Que::front(struct Queue *root) {
    if (isEmpty(root))
        return INT_MIN;
    return root->array[root->front];
}

int Que::rear(struct Queue *root) {
    if (isEmpty(root))
        return INT_MIN;
    return root->array[root->rear];
}

QueLL::QueLL(){}
QueLL::~QueLL(){}

QNode *QueLL::newNode(int x) {
    struct QNode *nNode = (struct QNode *)malloc(sizeof(struct QNode));
    nNode->key = x;
    nNode->next = NULL;
    return nNode;
}

QueueLL *QueLL::createQueue() {
    struct QueueLL *q = (struct QueueLL *)malloc(sizeof(struct QueueLL));
    q->front = q->rear = NULL;
    return q;
}

void QueLL::enqueue(struct QueueLL *queue, int x) {
    struct QNode *qn = newNode(x);
    if (queue->rear == NULL) {
        queue->front = queue->rear = qn;
        return;
    }
    queue->rear->next = qn;
    queue->rear = qn;
}

QNode *QueLL::dequeue(struct QueueLL *root) {
    if (root->front == NULL)
        return NULL;
    QNode *temp = root->front;
    root->front = root->front->next;
    if (root->front == NULL)
        root->rear = NULL;
    return temp;
}










