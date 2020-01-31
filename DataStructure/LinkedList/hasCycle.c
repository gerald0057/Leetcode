#include <stdio.h>
#include <stdbool.h>
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

/** Free my linked list*/
void myLinkedListFree(MyLinkedList* obj) {
    free(obj);
    obj = NULL;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL)
        return false;

    ListNode* pslow = head->next;
    ListNode* pfast = head->next->next;

    while(pfast && pfast->next){
        pfast = pfast->next->next;
        pslow = pslow->next;

        if (pslow == pfast)
            return true;
    }

    return false;
}

int main(void) {
    MyLinkedList* obj = myLinkedListCreate();
    ListNode* cur = NULL;

    int i = 0;
    for (; i < 5; ++i) {
        myLinkedListAddAtTail(obj, i);
    }

    //make it cycle
    cur = obj->head;
    while(cur->next){
        cur = cur->next;
    }
    cur->next = obj->head->next;
    
    printf("%s", hasCycle(obj->head) == true ? "True" : "False");

    myLinkedListFree(obj);

    return 0;
}