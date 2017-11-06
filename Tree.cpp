//
//  Tree.cpp
//  CTCI
//
//  Created by Xuewen on 10/8/17.
//  Copyright © 2017 Xuewen. All rights reserved.
//

#include "Tree.hpp"

Tree::Tree(){}
Tree::~Tree(){}

struct node *Tree::newNode(int x) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int Tree::height(struct node *root) {
    if (root == NULL)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    if (lheight > rheight)
        return 1 + lheight;
    else
        return 1 + rheight;
}

void Tree::printGivenLevel(struct node *root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    } else
        return;
}

// This method takes O(n^2) time
void Tree::printLevelOrder(struct node *root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printGivenLevel(root, i);
    }
}

void Tree::printLevelOrderQueue(struct node *root) {
    std::queue<struct node *> que;
    struct node *temp = root;
    while (temp) {
        printf("%d ", temp->data);
        if (temp->left)
            que.push(temp->left);
        if (temp->right)
            que.push(temp->right);
        if (!que.empty()) {
            temp = que.front();
            que.pop();
        } else
            break;
    }
}

void Tree::printPostOrder(struct node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf("%d ", root->data);
}

void Tree::printPreOrder(struct node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void Tree::printInOrder(struct node *root) {
    if (root == NULL)
        return;
    printInOrder(root->left);
    printf("%d", root->data);
    printInOrder(root->right);
}

void Tree::deleteTree(struct node *root) {
    if (root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    printf("deleting node: %d ", root->data);
    free(root);
}


