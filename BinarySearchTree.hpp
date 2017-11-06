//
//  BinarySearchTree.hpp
//  CTCI
//
//  Created by Xuewen on 10/13/17.
//  Copyright © 2017 Xuewen. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <queue>

struct BSTNode {
    int value;
    struct BSTNode *left;
    struct BSTNode *right;
};

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();
    struct BSTNode *newBSTNode(int);
    void insert(struct BSTNode **, int);
    void printInOrder(struct BSTNode *);
    void printPostOrder(struct BSTNode *);
    void printPreOrder(struct BSTNode *);
    int size(struct BSTNode *);
    int depth(struct BSTNode *);
    int minValue(struct BSTNode *);
    int maxValue(struct BSTNode *);
    bool hasSum(struct BSTNode *, int);
    void printPaths(struct BSTNode *);
    void mirror(struct BSTNode *);
    void doubleTree(struct BSTNode *);
    bool isSameTree(struct BSTNode *, struct BSTNode *);
    bool isBST(struct BSTNode *);
    struct BSTNode *search(struct BSTNode *, int);
    void printLevelOrder(struct BSTNode *);  // BSF
    void printLevelOrderQueue(struct BSTNode *); // Queue BSF
};


#endif /* BinarySearchTree_hpp */
