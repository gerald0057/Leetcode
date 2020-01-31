#include "MyDoubleList.h"
#include <stdio.h>
#include <stdlib.h>

/** Initialize your data structure here. */
MyDulLinkedList* myDulLinkedListCreate(void) {
    MyDulLinkedList *ret = (MyDulLinkedList*)malloc(sizeof(MyDulLinkedList));
    if (ret == NULL) {
        perror("Head node malloc error");
        exit(0);
    }
    ret->head = NULL;
    return ret;
}

/** Get the size of the linked list, if the head node points to NULL, return 0*/
int myDulLinkedListGetSize(MyDulLinkedList* obj) {
    int count = 0;
    DulListNode *cur = obj->head;
    while (cur) {
        ++count;
        cur = cur->next;
    }
    return count;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myDulLinkedListGet(MyDulLinkedList* obj, int index) {
    //too small
    if (index < 0)
        return -1;

    DulListNode *cur = obj->head;
    while (cur)
    {
        if (index == 0)
            return cur->val;
        cur = cur->next;
        --index;
    }

    //too large
    return -1;
}

/** Add a node of value val before the first element of the linked list. 
 * After the insertion, the new node will be the first node of the linked list. */
void myDulLinkedListAddAtHead(MyDulLinkedList* obj, int val) {
    if (obj == NULL) return;
    DulListNode *HeadNode = (DulListNode*)malloc(sizeof(DulListNode));
    if(HeadNode == NULL) {
        perror("new headnode malloc error");
        exit(1);
    }

    HeadNode->val = val;
	HeadNode->next = obj->head;
    HeadNode->prev = NULL;

	if (obj->head != NULL) {
		obj->head->prev = HeadNode;
	}	
	obj->head = HeadNode;
}

/** Append a node of value val to the last element of the linked list. */
void myDulLinkedListAddAtTail(MyDulLinkedList* obj, int val) {
    if (obj == NULL) return;
    DulListNode *TailNode = (DulListNode*)malloc(sizeof(DulListNode));
    if (TailNode == NULL) {
        perror("new tailnode malloc error");
        exit(2);
    }

    TailNode->val = val;
    TailNode->next = NULL;

    if (obj->head == NULL) {
        obj->head = TailNode;
        TailNode->prev = NULL;
        return;
    }
    DulListNode *cur = obj->head;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = TailNode;
    TailNode->prev = cur;
    return;
}

/** Add a node of value val before the index-th node in the linked list. 
 * If index equals to the length of linked list, the node will be appended to the end of linked list. 
 * If index is greater than the length, the node will not be inserted. */
void myDulLinkedListAddAtIndex(MyDulLinkedList* obj, int index, int val) {
    int len = myDulLinkedListGetSize(obj);
    if (index < 0 || index > len) return;
    if (index == 0) {
        myDulLinkedListAddAtHead(obj, val);
        return;
    }
    if (index == len) {
        myDulLinkedListAddAtTail(obj, val);
        return;
    }

    DulListNode *cur = obj->head;
    while (--index) {
        cur = cur->next;
    }
    DulListNode *InsertNode = (DulListNode*)malloc(sizeof(DulListNode));
    if (InsertNode == NULL) {
        perror("new insertnode malloc error");
        exit(3);
    }
    InsertNode->prev = cur;
    InsertNode->next = cur->next;
    InsertNode->val = val;
    cur->next->prev = InsertNode;
    cur->next = InsertNode;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myDulLinkedListDeleteAtIndex(MyDulLinkedList* obj, int index) {
    if (obj == NULL || obj->head == NULL) return;
    int len = myDulLinkedListGetSize(obj);
    if (index < 0 || index >= len) return;

    DulListNode *cur = obj->head;
    DulListNode *pDel = cur;

    if (index == 0) {
        obj->head = cur->next;
        free(pDel);
        pDel = NULL;
        return;
    }

    while (--index) {
        cur = cur->next;
    }
    
    pDel = cur->next;
    cur->next = pDel->next;
    if (pDel->next != NULL) {
        pDel->next->prev = cur;
    }
    free(pDel);
    pDel = NULL;
}

/** Free my linked list*/
void myDulLinkedListFree(MyDulLinkedList* obj) {
    free(obj);
    obj = NULL;
}

/** check if all nodes connect correctly (postive order or reverse order)*/
void myDulLinkedListShowDulOrder_DONOT_Have_Cycle(MyDulLinkedList* obj) {
    int count = 100;
    if (obj == NULL || obj->head == NULL)
        return;
    int param = 0;
    printf("[Double Linked List Postive Order]: obj->");
    DulListNode *cur = obj->head;
    while (cur->next)
    {
        param = cur->val;
        cur = cur->next;
        printf("%d->", param);
        if (!--count) {
            puts("may be CYCLE");
            return;
        }
    }
    param = cur->val;
    printf("%d->NULL\n", param);

    count = 100;
    printf("[Double Linked List Reverse Order]: ");
    while (cur->prev)
    {
        param = cur->val;
        cur = cur->prev;
        printf("%d->", param);
        if (!--count) {
            puts("may be CYCLE");
            return;
        }
    }
    param = cur->val;
    printf("%d->obj", param);    
}