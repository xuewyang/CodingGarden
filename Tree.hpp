//
//  Tree.hpp
//  CTCI
//
//  Created by Xuewen on 10/8/17.
//  Copyright © 2017 Xuewen. All rights reserved.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

class Tree {
public:
    Tree();
    ~Tree();
    struct node *newNode(int );
    int height(struct node *);
    void printGivenLevel(struct node *, int);
    void printLevelOrder(struct node *);
    void printLevelOrderQueue(struct node *);
    void printPostOrder(struct node *);
    void printPreOrder(struct node *);
    void printInOrder(struct node *);
    void deleteTree(struct node *);
};
#endif /* Tree_hpp */










