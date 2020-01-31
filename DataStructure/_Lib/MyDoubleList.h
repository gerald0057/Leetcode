#ifndef __MyDoubleList_h__
#define __MyDoubleList_h__

// struct node
typedef struct DulListNode
{
    int val;
    struct DulListNode *prev;
    struct DulListNode *next;
} DulListNode;

// struct single linked list
typedef struct MyDulLinkedList
{
    struct DulListNode *head;
} MyDulLinkedList;

MyDulLinkedList* myDulLinkedListCreate(void);
int myDulLinkedListGetSize(MyDulLinkedList* obj);
int myDulLinkedListGet(MyDulLinkedList* obj, int index);
void myDulLinkedListAddAtHead(MyDulLinkedList* obj, int val);
void myDulLinkedListAddAtTail(MyDulLinkedList* obj, int val);
void myDulLinkedListAddAtIndex(MyDulLinkedList* obj, int index, int val);
void myDulLinkedListDeleteAtIndex(MyDulLinkedList* obj, int index);
void myDulLinkedListFree(MyDulLinkedList* obj);
void myDulLinkedListShowDulOrder_DONOT_Have_Cycle(MyDulLinkedList* obj);

#endif