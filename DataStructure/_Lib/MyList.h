#ifndef __MyList_h__
#define __MyList_h__

// struct node
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

// struct single linked list
typedef struct MyLinkedList {
    struct ListNode* head;
} MyLinkedList;

MyLinkedList* myLinkedListCreate(void);
int myLinkedListGetSize(MyLinkedList* obj);
int myLinkedListGet(MyLinkedList* obj, int index);
void myLinkedListAddAtHead(MyLinkedList* obj, int val);
void myLinkedListAddAtTail(MyLinkedList* obj, int val);
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val);
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index);
void myLinkedListFree(MyLinkedList* obj);
struct ListNode* myLinkedListReverse(struct ListNode* head);
void ShowList_DONOT_Have_Cycle(ListNode *head, char *obj_name);
struct MyLinkedList* myLinkedListCreatRandomList(unsigned int length);

#endif