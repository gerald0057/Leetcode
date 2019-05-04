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

struct ListNode *detectCycle(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return NULL;

    struct ListNode* pslow = head;
    struct ListNode* pfast = head;

    while(pfast && pfast->next){
        pfast = pfast->next->next;
        pslow = pslow->next;

        if (pslow == pfast) {
            struct ListNode* pTest_1 = head;
            struct ListNode* pTest_2 = pslow;

            while(pTest_1 != pTest_2){
                pTest_1 = pTest_1->next;
                pTest_2 = pTest_2->next;
            }
    
            return pTest_1;
        }            
    }
    
    return NULL;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL)
        return NULL;
    ListNode* cur = headA;
    while (cur->next)
    {
        cur = cur->next;
    }
    cur->next = headB;
    return detectCycle(headA);
}

int main(void) {
    MyLinkedList* objA = myLinkedListCreate();
    MyLinkedList* objB = myLinkedListCreate();
    ListNode* cur = NULL;
    ListNode* intersectNode = NULL;

    myLinkedListAddAtTail(objA, 0);
    myLinkedListAddAtTail(objA, 9);
    myLinkedListAddAtTail(objA, 1);
    myLinkedListAddAtTail(objA, 2);
    myLinkedListAddAtTail(objA, 4);

    myLinkedListAddAtTail(objB, 3);
    // myLinkedListAddAtTail(objB, 0);
    // myLinkedListAddAtTail(objB, 1);
    
    //make objA and objB intersect at index objA[2]
    intersectNode = objA->head;
    int inter_pos = 3;
    while (inter_pos)
    {
        intersectNode = intersectNode->next;
        --inter_pos;
    }
    cur = objB->head;
    while (cur->next)
    {
        cur = cur->next;
    }
    cur->next = intersectNode;
    
//result test: show the list
    int param = 0;
    cur = objA->head;
    puts("[Linked list (objA)]:");
    for (int i = 0; i < 10; ++i) {
        if (cur == NULL){
            printf("NULL\n");
            break;
        }            
        param = cur->val;
        cur = cur->next;
        printf("%d->", param);
    }
    cur = objB->head;
    puts("[Linked list (objB)]:");
    for (int i = 0; i < 10; ++i) {
        if (cur == NULL){
            printf("NULL\n");
            break;
        }            
        param = cur->val;
        cur = cur->next;
        printf("%d->", param);
    }

    param = getIntersectionNode(objA->head, objB->head)->val;
    printf("both list intersect at value: %d\n", param);

    return 0;
}