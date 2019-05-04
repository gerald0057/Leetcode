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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    ListNode *pDel = NULL;
    if (head->next == NULL) {
        pDel = head;
        free(pDel);
        pDel = NULL;
        head = NULL;
        return NULL;
    }
    ListNode *pFormer = head;
    ListNode *pLatter = head;
    while (n)
    {
        pFormer = pFormer->next;
        --n;
    }
    if (pFormer == NULL) {
        pDel = pLatter;
        head = pDel->next;
        free(pDel);
        pDel = NULL;
        return head;
    }
    while (pFormer->next)
    {
        pFormer = pFormer->next;
        pLatter = pLatter->next;
    }
    
    pDel = pLatter->next;
    pLatter->next = pDel->next;
    free(pDel);
    pDel = NULL;

    return head;
}

int main(void) {
    MyLinkedList *obj = myLinkedListCreate();
    ListNode *cur = NULL;

    // int i = 0;
    // for (i = 0; i < 5; ++i) {
    //     myLinkedListAddAtTail(obj, i + 1);
    // }

    myLinkedListAddAtTail(obj, 1);
    myLinkedListAddAtTail(obj, 2);

    int param = 0;
    printf("[Linked list]: ");
    cur = obj->head;
    while (cur)
    {
        param = cur->val;
        cur = cur->next;
        printf("%d->", param);
    }
    printf("NULL\n");
    
    ListNode *new_head = removeNthFromEnd(obj->head, 2);
    param = 0;
    printf("[New linked list]: ");
    cur = new_head;
    while (cur)
    {
        param = cur->val;
        cur = cur->next;
        printf("%d->", param);
    }
    printf("NULL\n");

    return 0;
}