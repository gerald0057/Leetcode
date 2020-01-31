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

struct ListNode *detectCycle(struct ListNode* head, struct ListNode* meetPoint) {
    ListNode* pTest_1 = head;
    ListNode* pTest_2 = meetPoint;

    while(pTest_1 != pTest_2){
        pTest_1 = pTest_1->next;
        pTest_2 = pTest_2->next;
    }
    
    return pTest_1;
}

bool hasCycle(struct ListNode* head, struct ListNode** meetPoint) {
    *meetPoint = NULL;
    if (head == NULL || head->next == NULL)
        return false;

    ListNode* pslow = head;
    ListNode* pfast = head;

    while(pfast && pfast->next){
        pfast = pfast->next->next;
        pslow = pslow->next;

        if (pslow == pfast) {
            //return the meet node of pfast and pslow for detect
            *meetPoint = pslow;
            return true;
        }            
    }

    return false;
}

int main(void) {
    MyLinkedList* obj = myLinkedListCreate();
    ListNode* cur = NULL;
    ListNode* meetPoint = NULL;

    int i = 0;
    for (; i < 2; ++i) {
        myLinkedListAddAtTail(obj, i);
    }
    
    //make it cycle
    cur = obj->head;
    while(cur->next){
        cur = cur->next;
    }
    cur->next = obj->head;

//result test: show the list
    int param = 0;
    cur = obj->head;
    bool hascycle = true;
    puts("[Linked list]:");
    for (int i = 0; i < 16; ++i) {
        if (cur == NULL){
            printf("NULL\n");
            hascycle = false;
            break;
        }            
        param = cur->val;
        cur = cur->next;
        printf("%d->", param);
    }
    if (hascycle)
        printf("__CYCLE__\n");    

//function test: hasCycle()
    if (hasCycle(obj->head, &meetPoint)) {
            printf("has cycle, ");
            ListNode* p = detectCycle(obj->head, meetPoint);
            printf("cycle at val: %d", p->val);
    }
    else
        printf("do not have\n");

    myLinkedListFree(obj);

    return 0;
}