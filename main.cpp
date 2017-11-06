//
//  main.cpp
//  CTCI
//
//  Created by Xuewen on 9/24/17.
//  Copyright © 2017 Xuewen. All rights reserved.
//

#include <iostream>
#include "ArraysStrings.hpp"
#include "LinkedLists.hpp"
#include "StacksQueues.hpp"
#include "Tree.hpp"
#include "BinarySearchTree.hpp"
#include "DynamicProgramming.hpp"

//void reverse(char array[]) {
//    int len = int(strlen(array));
//    std::stack <char> s;
//    for (int i = 0; i < len; i++)
//        s.push(array[i]);
//    int j = 0;
//    while (!s.empty()) {
//        array[j++] = s.top();
//        s.pop();
//    }
//}
//
//void reverse_queue(queue<int> &que) {
//    stack<int> s;
//    while (!que.empty()) {
//        s.push(que.front());
//        que.pop();
//    }
//    while (!s.empty()) {
//        que.push(s.top());
//        s.pop();
//    }
//}



int main(int argc, const char * argv[]) {
//    // insert code here...
//    ArraysandStrings as;
//    string str1 = "abvmsdfg";
//    //cout << as.IsUnique(str1) << endl;
//    string str2 = "bavsmfgd";
//    //cout << as.IsPermutation0(str1, str2) << endl;
//    string str3 = "Mr John Smith          ";
//    //int truelen = 13;
//    //as.URLify(str3, truelen);
//    cout << str3 << endl;
//    string str4 = "Tact coa";
//    //cout << as.IsPalinPerm(str4) << endl;
//    int arr[] = {1, 5, 2, 7, 9, 0, 3, 6};
//    int n = sizeof(arr) / sizeof(arr[0]);
//    //as.mergeSort(arr, 0, n-1);
//    for (int i = 0; i < n; i++)
//        cout << arr[i] << ", ";
//    cout << endl;
//    
//    // test for LinkedLists
//    int a = 3, b = 4, c = 9;
//    LinkedLists ll;
//    struct Node* head;
//    head = ll.threeNodes(a, b, c);
//    //ll.printList(head);
//    int new_data = 10;
//    ll.push(&head, new_data);
//    //ll.printList(head);
//    ll.insertAfter(head->next, 2);
//    //ll.printList(head);
//    ll.append(&head, 12);
//    //ll.printList(head);
//    cout << endl;
//    ll.deleteNode(&head, 4);
//    //ll.printList(head);
//    //cout << ll.getCount(head) << endl;
//    //cout << ll.search(head, 12) << endl;
//    cout << endl;
//    //ll.reverse_iterative(&head);
//    //ll.printList(head);
//    cout << endl;
//    ll.reverse_recursive(&head);
//    //ll.printList(head);
//    cout << endl;
//    int d = 2, e = 3, f = 20;
//    struct Node *new_head;
//    new_head = ll.threeNodes(d, e, f);
//    //ll.move_node(&head, &new_head);
//    //ll.printList(head);
//    int h = 25, i = 10, j = 15;
//    struct Node *new_head2;
//    new_head2 = ll.threeNodes(h, i, j);
//    //ll.printList(ll.merge_sorted_recursive(new_head, new_head2));
//    ll.deleteNode(new_head->next);
//    //ll.printList(new_head);
//    cout << endl;
//    ll.insertSorted(&new_head2, 8);
//    ll.insertSorted(&new_head2, 8);
//    ll.printList(new_head2);
//    ll.removeDupsUnsortedHash(new_head2);
//    cout << endl;
//    ll.printList(new_head2);
//    cout << endl;
//    //new_head2->next->next = new_head2;
//    // cout << ll.detectLoopFloyd(new_head2) << endl;
//    ll.mergeSort(&new_head2);
//    ll.printList(new_head2);
//    int k = 1, l = 3, m = 1;
//    struct Node *new_head3;
//    new_head3 = ll.threeNodes(k, l, m);
//    new_head3->next->next = new_head2->next;
//    cout << ll.isIntersect(new_head2, new_head3) << endl;
//    cout << ll.isPalindromeReverse(new_head3) << endl;
//    Stack s;
//    s.push(10);
//    s.push(20);
//    s.push(30);
//    while (!s.isEmpty())
//        cout << s.pop() << " ";
//    cout << endl;
//    StackLL sll;
//    struct StackNode *root = NULL;
//    sll.push(&root, 10);
//    sll.push(&root, 20);
//    sll.push(&root, 30);
//    while (!sll.isEmpty(root))
//        cout << sll.pop(&root) << " ";
//    cout << endl;
//    Que que;
//    struct Queue *rootQ;
//    rootQ = que.createQueue(100);
//    que.enqueue(rootQ, 1);
//    que.enqueue(rootQ, 2);
//    que.enqueue(rootQ, 3);
//    printf("%d \n", que.dequeue(rootQ));
//    printf("front: %d \n", que.front(rootQ));
//    printf("rear: %d \n", que.rear(rootQ));
//    QueLL que;
//    struct QueueLL *queue = que.createQueue();
//    que.enqueue(queue, 1);
//    que.enqueue(queue, 2);
//    que.enqueue(queue, 3);
//    que.enqueue(queue, 4);
//    struct QNode *qn = que.dequeue(queue);
//    cout << "dequeue: " << qn->key << endl;
//    char str[] = "geeks";
//    reverse(str);
//    for (int i = 0; i < int(strlen(str)); i++)
//        cout << str[i] << " ";
//    cout << endl;
    
//    Tree tree;
//    int a = 1, b =2, c = 3, d = 4, e = 5;
//    struct node *root = tree.newNode(a);
//    root->left = tree.newNode(b);
//    root->right = tree.newNode(c);
//    root->left->left = tree.newNode(d);
//    root->left->right = tree.newNode(e);
////    tree.printLevelOrderQueue(root);
//    tree.printInOrder(root);
  
//    BinarySearchTree bst;  // instantiating a dynamically allocated node with new, the LHS should be a pointer
//    BSTNode *root = bst.newBSTNode(4);
//    bst.insert(&root, 8);
//    bst.insert(&root, 1);
//    bst.insert(&root, -4);
//    bst.insert(&root, 7);
//    bst.insert(&root, 5);
//    bst.insert(&root, 3);
//    bst.insert(&root, 10);
//    bst.insert(&root, 2);
//    printf("In Order traversal: ");
//    bst.printInOrder(root);
//    printf("\n");
//    printf("Post Order traversal: ");
//    bst.printPostOrder(root);
//    printf("\n");
//    printf("Pre Order traversal: ");
//    bst.printPreOrder(root);
//    printf("\n");
//    printf("size of tree is %d.\n", bst.size(root));
//    printf("depth of tree is %d.\n",bst.depth(root));
//    printf("min value of tree is %d.\n", bst.minValue(root));
//    printf("max value of tree is %d.\n", bst.maxValue(root));
//    int s = 24  ;
//    printf("paths of tree has sum %d ? %d", s, bst.hasSum(root, s));
//    printf("all paths: \n");
//    bst.printPaths(root);
//    BSTNode *root = bst.newBSTNode(4);
//    bst.insert(&root, 2);
//    bst.insert(&root, 5);
//    bst.insert(&root, 1);
//    bst.insert(&root, 3);
//    bst.mirror(root);
//    BSTNode *root = bst.newBSTNode(2);
//    bst.insert(&root, 1);
//    bst.insert(&root, 3);
////    bst.doubleTree(root);
//    BSTNode *root2 = bst.newBSTNode(2);
//    bst.insert(&root2, 1);
//    bst.insert(&root2, 3);
//    bst.insert(&root2, 4);
////    printf("%d \n", bst.isSameTree(root, root2));
//    bst.printLevelOrderQueue(root2);
    DP dp;
//    printf("%d \n", dp.binomialCoeffDPMem(5,2));
//    int array[] = {10, 22, 9};  // , 33, 21, 50, 41, 60
//    int n = sizeof(array)/sizeof(array[0]);
//    printf("lis of array is %d.", dp.lis(array, n));
//    std::string str1 = "sunday", str2 = "saturday";
//    printf("edit distance is: %d", dp.editDistanceDP(str1, str2, int(str1.length()), int(str2.length())));
//    printf("distance steps: %d", dp.printCountDP(1));
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    
    int m = int(strlen(X));
    int n = int(strlen(Y));
    
    printf("Length of LCS is %dn", dp.lcs_dp( X, Y, m, n ));
    
    return 0;
}
