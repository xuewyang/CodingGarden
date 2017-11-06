//
//  BinarySearchTree.cpp
//  CTCI
//
//  Created by Xuewen on 10/13/17.
//  Copyright © 2017 Xuewen. All rights reserved.
//

#include "BinarySearchTree.hpp"

BinarySearchTree::BinarySearchTree() {}
BinarySearchTree::~BinarySearchTree(){}

struct BSTNode *BinarySearchTree::newBSTNode(int x) {
    struct BSTNode *temp = (struct BSTNode *)malloc(sizeof(struct BSTNode));
    temp->left = NULL;
    temp->right = NULL;
    temp->value = x;
    return temp;
}

void BinarySearchTree::insert(struct BSTNode **root, int x) {
    if (!(*root))
        *root = newBSTNode(x);
    else {
        if (x < (*root)->value)
            insert(&((*root)->left), x);
        else
            insert(&((*root)->right), x);
    }
}

void BinarySearchTree::printInOrder(struct BSTNode *root) {
    if (!root)
        return;
    printInOrder(root->left);
    printf("%d ", root->value);
    printInOrder(root->right);
}

void BinarySearchTree::printPostOrder(struct BSTNode *root) {
    if (!root)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->value);
}

void BinarySearchTree::printPreOrder(struct BSTNode *root) {
    if (!root)
        return;
    printf("%d ", root->value);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int BinarySearchTree::size(struct BSTNode *root) {
    if (!root)
        return 0;
    else
        return 1 + size(root->left) + size(root->right);
}

int BinarySearchTree::depth(struct BSTNode *root) {
    if (!root)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    else
        return 1+depth(root->left) > 1+depth(root->right) ? 1+depth(root->left) :1+ depth(root->right) ;
    
}

int BinarySearchTree::minValue(struct BSTNode *root) {
    if (root->left == NULL)
        return root->value;
    else
        return minValue(root->left);
}

int BinarySearchTree::maxValue(struct BSTNode *root) {
    if (root->right == NULL)
        return root->value;
    else
        return maxValue(root->right);
}

/*
 Given a tree and a sum, return true if there is a path from the root
 down to a leaf, such that adding up all the values along the path
 equals the given sum.
 Strategy: subtract the node value from the sum when recurring down,
 and check to see if the sum is 0 when you run out of tree.
 */
bool BinarySearchTree::hasSum(struct BSTNode *root, int x) {
    if (!root)
        return x == 0;
    else {
        int xx = x - root->value;
        return hasSum(root->left, xx) || hasSum(root->right, xx);
    }
}

void printarray(int paths[], int length) {
    for (int i = 0; i < length; i++)
        printf("%d ", paths[i]);
    printf("\n");
}

void printPathsHelper(struct BSTNode *node, int paths[], int length) {
    if (node == NULL)
        return;
    paths[length++] = node->value;
    if (node->left == NULL && node->right == NULL)
        printarray(paths, length);
    else {
        printPathsHelper(node->left, paths, length);
        printPathsHelper(node->right, paths, length);
    }
}

//Given a binary tree, print out all of its root-to-leaf paths as defined above. This problem is a little harder than it looks, since the "path so far" needs to be communicated between the recursive calls. Hint: In C, C++, and Java, probably the best solution is to create a recursive helper function printPathsRecur(node, int path[], int pathLen), where the path array communicates the sequence of nodes that led up to the current call.
void BinarySearchTree::printPaths(struct BSTNode *root) {
    int paths[1000];
    printPathsHelper(root, paths, 0);
}

/*
 Change a tree so that the roles of the
 left and right pointers are swapped at every node.
 So the tree...
   4
  / \
 2   5
/ \
1 3
 
 is changed to...
    4
   / \
  5   2
 / \
3   1
 */
void BinarySearchTree::mirror(BSTNode *root) {
    if (!root)
        return;
    // do the subtrees
    mirror(root->left);
    mirror(root->right);
    // swap the pointers in this node
    BSTNode *temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

/*
 For each node in a binary search tree,
 create a new duplicate node, and insert
 the duplicate as the left child of the original node.
 The resulting tree should still be a binary search tree.
 So the tree...
  2
 / \
1   3
 
 Is changed to...
     2
    / \
   2   3
  /   /
 1   3
/
1
 */

void BinarySearchTree::doubleTree(struct BSTNode *root) {
    if (!root)
        return;
    doubleTree(root->left);
    doubleTree(root->right);
    BSTNode *oldleft = NULL;
    oldleft = root->left;
    root->left = newBSTNode(root->value);
    root->left->left = oldleft;
}

bool BinarySearchTree::isSameTree(struct BSTNode *a, struct BSTNode *b) {
    if (a == NULL && b == NULL)
        return true;
    if (a && b)
        return a->value == b->value && isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
    else
        return false;
}

bool isBSThelper(struct BSTNode *root, int min, int max) {
    if (!root)
        return true;
    if (root->value < min || root->value > max)
        return false;
    else {
        return isBSThelper(root->left, min, root->value) && isBSThelper(root->right, root->value+1, max);
    }
}

bool BinarySearchTree::isBST(struct BSTNode *root) {
    return isBSThelper(root, INT_MIN, INT_MAX);
}

// Searching a key
struct BSTNode *BinarySearchTree::search(struct BSTNode *root, int key) {
    if (!root)
        return NULL;
    if (root->value == key)
        return root;
    else {
        if (key < root->value)
            return search(root->left, key);
        else
            return search(root->right, key);
    }
}

// print at a given level
void printGivenLevel(struct BSTNode *root, int level) {
    if (!root)
        return;
    if (level == 1)
        printf("%d ", root->value);
    else {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}

// level order traversal / Breadth first search
// Time Complexity: O(n^2) in worst case. For a skewed tree, printGivenLevel() takes O(n) time where n is the number of nodes in the skewed tree. So time complexity of printLevelOrder() is O(n) + O(n-1) + O(n-2) + .. + O(1) which is O(n^2).
void BinarySearchTree::printLevelOrder(struct BSTNode *root) {
    int depth = this->depth(root);
    for (int i = 1; i <= depth; i++)
        printGivenLevel(root, i);
}

/* Given a binary tree, print its nodes in level order
 using array for implementing queue */
void BinarySearchTree::printLevelOrderQueue(struct BSTNode *root) {
    std::queue<struct BSTNode *> que;
    struct BSTNode *temproot = root;
    while (temproot) {
        printf("%d ", temproot->value);
        if (temproot->left)
            que.push(temproot->left);
        if (temproot->right)
            que.push(temproot->right);
        if (!que.empty()) {
            temproot = que.front();
            que.pop();
        } else
            break;
    }
}





