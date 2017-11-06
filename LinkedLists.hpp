//
//  LinkedLists.hpp
//  CTCI
//
//  Created by Xuewen on 9/27/17.
//  Copyright © 2017 Xuewen. All rights reserved.
//

#ifndef LinkedLists_hpp
#define LinkedLists_hpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_set>
#include <stack>

using namespace std;
struct Node {
    int data;
    Node* next;
};
class LinkedLists {
public:
    LinkedLists();
    ~LinkedLists();
    struct Node* threeNodes(int, int, int);
    void printList(struct Node*);
    void push(struct Node**, int);
    void insertAfter(struct Node*, int);
    void append(struct Node**, int);
    void deleteNode(struct Node**, int);
    int getCount(struct Node*);
    bool search(struct Node*, int key);
    void reverse_iterative(struct Node**);
    void reverse_recursive(struct Node**);
    void move_node(struct Node **, struct Node **);
    struct Node *merge_sorted(struct Node *, struct Node *);
    struct Node *merge_sorted2(struct Node *, struct Node *);
    struct Node *merge_sorted_recursive(struct Node *, struct Node *);
    void deleteNode(struct Node *);
    void insertSorted(struct Node **, int);
    void removeDuplicates(struct Node *);
    void removeDuplicatesUnsorted(struct Node *);
    void removeDupsUnsortedHash(struct Node *);
    bool detectLoop(struct Node *);
    bool detectLoopFloyd(struct Node *);
    void mergeSort(struct Node **);
    void printMiddle(struct Node *);
    bool isPalindromeStack(struct Node *);
    bool isPalindromeReverse(struct Node *);
    struct Node *sortedIntersect(struct Node *, struct Node *);
    bool isIntersect(struct Node *, struct Node *);
};

#endif /* LinkedLists_hpp */
