#include <stdio.h>
#include <stdlib.h>

// struct node
typedef struct ListNode {
    unsigned int val;
    struct ListNode* next;
} ListNode;

// struct single linked list
typedef struct MyLinkedList {
    struct ListNode* head;
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate(void) {
    MyLinkedList* ret = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    if (ret == NULL) {
        perror("head node malloc error");
        exit(1);
    }
    ret->head = NULL;
    
    return ret;
}

/** Get the size of the linked list, if the head node points to NULL, return 0*/
int myLinkedListGetSize(MyLinkedList* obj) {
    int count = 0;
    ListNode* cur = obj->head;
    while(cur) {
        ++count;
        cur = cur->next;
    }
    return count;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0)
        return -1;
    
    ListNode* cur = obj->head;
    while(cur){
        if (index == 0)
            return cur->val;
        cur = cur->next;
        --index;
    }

    return -1;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    //creat a new node
    ListNode* hNode = (ListNode*)malloc(sizeof(ListNode));
    if (hNode == NULL) {
        perror("new head node malloc error");
        exit(2);
    }

    hNode->val = val;
    hNode->next = obj->head;
    obj->head = hNode;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    ListNode* tNode = (ListNode*)malloc(sizeof(ListNode));
    if (tNode == NULL) {
        perror("new tail node malloc error");
        exit(3);
    }
    tNode->val = val;
    tNode->next = NULL;

    ListNode* pNode = obj->head;
    if (pNode == NULL) {
        obj->head = tNode;
        return;
    }

    while(pNode->next) {
        pNode = pNode->next;
    }
    pNode->next = tNode;    
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0)
        return;
    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    
    ListNode* nNode = (ListNode*)malloc(sizeof(ListNode));
    if (nNode == NULL) {
        perror("new node malloc error");
        exit(4);
    }
    nNode->val = val;
    nNode->next = NULL;

    ListNode* cur = obj->head;
    ListNode* pre = cur;
    while (cur) {
        if (index == 1) {
            nNode->next = cur->next;
            cur->next = nNode;
            return;
        }
        --index;
        cur = cur->next;        
    }
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    int list_len = myLinkedListGetSize(obj);
    ListNode* del = NULL;
    ListNode* cur = obj->head;

    if (index < 0 || index >= list_len || cur == NULL)
        return;
    
    if (index == 0) {
        obj->head = cur->next;
        free(cur);
        cur = NULL;
        return;
    }

    while(--index)
        cur = cur->next;
    del = cur->next;
    cur->next = del->next;
    free(del);
    del = NULL;    
}

/** Free my linked list*/
void myLinkedListFree(MyLinkedList* obj) {
    free(obj);
    obj = NULL;
}

int main(void) {
    MyLinkedList* mylist = myLinkedListCreate();

    myLinkedListAddAtHead(mylist, 2);
    myLinkedListAddAtHead(mylist, 3);
    myLinkedListAddAtTail(mylist, 6);

    int i = 0, param = 0;
    for (; i < 3; ++i) {
        param = myLinkedListGet(mylist, i);
        printf("%d ", param);
    }

    myLinkedListFree(mylist);

    return 0;
}