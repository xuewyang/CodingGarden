//
//  LinkedLists.cpp
//  CTCI
//
//  Created by Xuewen on 9/27/17.
//  Copyright © 2017 Xuewen. All rights reserved.
//

#include "LinkedLists.hpp"

LinkedLists::LinkedLists(){}
LinkedLists::~LinkedLists(){}

struct Node* LinkedLists::threeNodes(int a, int b, int c) {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    head->data = a;
    head->next = second;
    second->data = b;
    second->next = third;
    third->data = c;
    third->next = NULL;
    
    return head;
}

void LinkedLists::printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void LinkedLists::push(struct Node** head, int new_data) {
    // add a node at the front of the LL
    struct Node* new_node = NULL;
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}

void LinkedLists::insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        cout << "The given node cannot be null.";
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void LinkedLists::append(struct Node** head, int new_data) {
    // insert the node at the end of the LL.
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head == NULL)  *head = new_node;
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}

void LinkedLists::deleteNode(struct Node **head, int key) {
    // delete the 1st occurence of key
    if (*head == NULL)
        cout << "LL cannot be NULL.";
    struct Node *temp = *head, *prev = NULL;
    // if head itself to be deleted.
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
    }
    
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

// recursive way to get # of elements in LL.
int LinkedLists::getCount(struct Node* head) {
    if (head == NULL)   return 0;
    return 1 + getCount(head->next);
}

// recursive way to search key in LL.
bool LinkedLists::search(struct Node *head, int key) {
    if (head == NULL)   return false;
    if (head->data == key)
        return true;
    return search(head->next, key);
}

// iterative way to reverse an LL.
void LinkedLists::reverse_iterative(struct Node **head) {
    struct Node *prev = NULL;
    struct Node *curr = *head;
    struct Node *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

// recursive way to reverse LL.
void LinkedLists::reverse_recursive(struct Node **head) {
    struct Node *first = *head;
    struct Node *rest = first->next;
    
    if (rest == NULL)
        return;
    reverse_recursive(&rest);
    first->next->next = first;
    first->next = NULL;
    *head = rest;
}

/* move_node() function takes the node from the front of the
 source, and move it to the front of the dest.
 It is an error to call this with the source list empty.
 
 Before calling MoveNode():
 source == {1, 2, 3}
 dest == {1, 2, 3}
 
 Affter calling MoveNode():
 source == {2, 3}
 dest == {1, 1, 2, 3} */

void LinkedLists::move_node(struct Node **dest, struct Node **source) {
    struct Node *new_node = *source;
    *source = new_node->next;
    new_node->next = *dest;
    *dest = new_node;
}

// merge two sorted LLs.
//The strategy here uses a temporary dummy node as the start of the result list. The pointer Tail always points to the last node in the result list, so appending new nodes is easy.
//The dummy node gives tail something to point to initially when the result list is empty. This dummy node is efficient, since it is only temporary, and it is allocated in the stack. The loop proceeds, removing one node from either ‘a’ or ‘b’, and adding it to tail. When
//we are done, the result is in dummy.next.
struct Node *LinkedLists::merge_sorted(struct Node *a, struct Node *b) {
    // struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    // this works too:
    struct Node temp;
    struct Node *tail = &temp;
    // struct Node *tail = &temp;
    temp.next = NULL;
    while (1) {
        if (a == NULL) {
            tail->next = b;
            break;
        }
        if (b == NULL) {
            tail->next = a;
            break;
        }
        if (a->data <= b->data)
            move_node(&(tail->next), &a);
        else
            move_node(&(tail->next), &b);
        tail = tail->next;
    }
    return temp.next;
}

//Method 2 (Using Local References)
//This solution is structurally very similar to the above, but it avoids using a dummy node. Instead, it maintains a struct node** pointer, lastPtrRef, that always points to the last pointer of the result list. This solves the same case that the dummy node did — dealing with the result list when it is empty. If you are trying to build up a list at its tail, either the dummy node or the struct node** “reference” strategy can be used (see Section 1 for details).
struct Node *LinkedLists::merge_sorted2(struct Node *a, struct Node *b) {
    struct Node *res = NULL;
    struct Node **lastPtr = &res;
    
    while (1) {
        if (a == NULL) {
            *lastPtr = b;
            break;
        }
        if (b == NULL) {
            *lastPtr = a;
            break;
        }
        if (a->data <= b->data)
            move_node(lastPtr, &a);
        else
            move_node(lastPtr, &b);
        // *lastPtr = (*lastPtr)->next; // The whole struct is changed from *lastPtr to next. Thus res changed its object too to make it same with lastPtr.
        lastPtr = &((*lastPtr)->next);  // Only make lastPtr point to the next one. But res still point to the original address. // cannot write *lastPtr = (*lastPtr)->next;
        //**lastPtr = &((*lastPtr)->next);
    }
    return res;
}

//Method 3 (Using Recursion)
//Merge is one of those nice recursive problems where the recursive solution code is much cleaner than the iterative code. You probably wouldn’t want to use the recursive version for production code however, because it will use stack space which is proportional to the length of the lists.
struct Node *LinkedLists::merge_sorted_recursive(struct Node *a, struct Node *b) {
    struct Node *res = NULL;
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    if (a->data <= b->data) {
        res = a;
        res->next = merge_sorted_recursive(a->next, b);
    } else {
        res = b;
        res->next = merge_sorted_recursive(a, b->next);
    }
    return res;
}

//Given a pointer to a node to be deleted, delete the node. Note that we don’t have pointer to head node.
void LinkedLists::deleteNode(struct Node *nodePtr) {
//    struct Node *temp = nodePtr->next;
//    nodePtr->data = temp->data;
//    nodePtr->next = temp->next;
//    free(temp);
    nodePtr->data = nodePtr->next->data;
    nodePtr->next = nodePtr->next->next;
    free(nodePtr->next);
}

//Given a sorted linked list and a value to insert, write a function to insert the value in sorted way.
void LinkedLists::insertSorted(struct Node **head, int data) {
    if (head == NULL) {
        (*head)->data = data;
        (*head)->next = NULL;
    }
    if ((*head)->data > data) {
        struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = *head;
        *head = new_node;
    }
    struct Node *temp = *head;
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    while (temp->next != NULL) {
        if (temp->next->data > data) {
            new_node->next = temp->next;
            temp->next = new_node;
            break;
        }
        temp = temp->next;
    }
}

//Write a removeDuplicates() function which takes a list sorted in non-decreasing order and deletes any duplicate nodes from the list. The list should only be traversed once.
void LinkedLists::removeDuplicates(struct Node *head) {
    if (head == NULL)
        return;
    if (head->next == NULL)
        return;
    struct Node *current = head;
    struct Node *temp;
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            temp = current->next->next;
            free(current->next);
            current->next = temp;
        } else {
            current = current->next;
        }
    }
}

// unsorted LL
void LinkedLists::removeDuplicatesUnsorted(struct Node *head) {
    if (head == NULL)
        return;
    if (head->next == NULL)
        return;
    struct Node *n1 = head;
    struct Node *n2 = head;
    while (n1 && n1->next) {
        n2 = n1;
        while (n2->next) {
            if (n1->data == n2->next->data) {
                struct Node *temp = n2->next->next;
                free(n2->next);
                n2->next = temp;
            } else
                n2 = n2->next;
        }
        n1 = n1->next;
    }
}

void LinkedLists::removeDupsUnsortedHash(struct Node *head) {
    unordered_set<int> seen;
    struct Node *prev = NULL, *curr = head;
    while (curr != NULL) {
        if (seen.find(curr->data) != seen.end()) {
            prev->next = curr->next;
            free(curr);
        } else {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
}

//Use Hashing:
//Traverse the list one by one and keep putting the node addresses in a Hash Table. At any point, if NULL is reached then return false and if next of current node points to any of the previously stored nodes in Hash then return true.
bool LinkedLists::detectLoop(struct Node *head) {
    unordered_set<struct Node *> um;
    while (head != NULL) {
        if (um.find(head) != um.end())
            return true;
        um.insert(head);
        head = head->next;
    }
    return false;
}

//Floyd’s Cycle-Finding Algorithm:
//This is the fastest method. Traverse linked list using two pointers.  Move one pointer by one and other pointer by two.  If these pointers meet at some node then there is a loop.  If pointers do not meet then linked list doesn’t have loop.
bool LinkedLists::detectLoopFloyd(struct Node *head) {
    struct Node *slow = head, *fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow->data == fast->data)
            return true;
    }
    return false;
}

/* Split the nodes of the given list into front and back halves,
 and return the two lists using the reference parameters.
 If the length is odd, the extra node should go in the front list.
 Uses the fast/slow pointer strategy.  */
void frontBackSplit(struct Node *source, struct Node **frontRef, struct Node **backRef) {
    struct Node *fast, *slow;
    if (source == NULL || source->next == NULL)
        *frontRef = source;
    else {
        slow = source;
        fast = source->next;
        while (fast != NULL) {
            fast = fast->next;
            while (fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
}

/* sorts the linked list by changing next pointers (not data) */
void LinkedLists::mergeSort(struct Node **headRef) {
    struct Node *head = *headRef;
    struct Node *a, *b;
    /* base case -- length 0 or 1 */
    if (head == NULL || head->next == NULL)
        return;
    frontBackSplit(head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *headRef = merge_sorted(a, b);
}

//Given a singly linked list, find middle of the linked list. For example, if given linked list is 1->2->3->4->5 then output should be 3.
//
//If there are even nodes, then there would be two middle nodes, we need to print second middle element. For example, if given linked list is 1->2->3->4->5->6 then output should be 4.
void LinkedLists::printMiddle(struct Node *head) {
    struct Node *slow = head, *fast = head;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    printf("The middle element is: %d.", slow->data);
}

//Given a singly linked list of characters, write a function that returns true if the given list is palindrome, else false.
bool LinkedLists::isPalindromeStack(struct Node *head) {
    stack<int> st;
    struct Node *headRef = head;
    while (headRef != NULL) {
        st.push(headRef->data);
        headRef = headRef->next;
    }
    headRef = head;
    while (headRef != NULL && st.empty() != true) {
        if (st.top() != headRef->data)
            return false;
        else {
            st.pop();
            headRef = headRef->next;
        }
    }
    return true;
}

bool compareLists(struct Node *node1, struct Node *node2) {
    if (node1 == NULL && node2 == NULL)
        return true;
    while (node1 && node2) {
        if (node1->data != node2->data)
            return false;
        else {
            node1 = node1->next;
            node2 = node2->next;
        }
    }
    return true;
}

//(By reversing the list)
//This method takes O(n) time and O(1) extra space.
//1) Get the middle of the linked list.
//2) Reverse the second half of the linked list.
//3) Check if the first half and second half are identical.
//4) Construct the original linked list by reversing the second half again and attaching it back to the first half
//
//To divide the list in two halves, method 2 of this post is used.
//When number of nodes are even, the first and second half contain exactly half nodes. The challenging thing in this method is to handle the case when number of nodes are odd. We don’t want the middle node as part of any of the lists as we are going to compare them for equality. For odd case, we use a separate variable ‘midnode’.
bool LinkedLists::isPalindromeReverse(struct Node *head) {
    bool res = false;
    struct Node *fast = head, *slow = head;
    struct Node *midpoint = NULL, *secondhalf, *prevslow = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        prevslow = slow;
        slow = slow->next;
    }
    // if odd number, fast != NULL, fast->next == NULL
    if (fast != NULL) {
        midpoint = slow;
        slow = slow->next;
    }
    // Now reverse the second half and compare it with first half
    secondhalf = slow;
    prevslow->next = NULL;
    reverse_iterative(&secondhalf);
    res =  compareLists(head, secondhalf);
    /* Construct the original list back */
    reverse_iterative(&secondhalf);
    // If there was a mid node (odd size case) which
    // was not part of either first half or second half.
    if (midpoint) {
        prevslow->next = midpoint;
        midpoint->next = secondhalf;
    } else
        prevslow->next = secondhalf;
    return res;
}

struct Node *LinkedLists::sortedIntersect(struct Node *a, struct Node *b) {
    struct Node dummy;
    struct Node *tail = &dummy;
    dummy.next = NULL;
    while ((!a) && (!b)) {
        if (a->data == b->data) {
            push(&(tail->next), a->data);
            a = a->next;
            b = b->next;
            tail = tail->next;
        } else if (a->data < b->data)
            a = a->next;
        else
            b = b->next;
    }
    return (dummy.next);
}

bool LinkedLists::isIntersect(struct Node *a, struct Node *b) {
    unordered_set<Node *> us;
    while (a) {
        us.insert(a);
        a = a->next;
    }
    while (b) {
        if (us.find(b) != us.end())
            return true;
        else
            b = b->next;
    }
    return false;
}














