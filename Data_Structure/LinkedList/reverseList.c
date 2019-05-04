#include <stdio.h>
#include "MyList.h"

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    ListNode *pA = head;
    ListNode *pB = pA->next;
    ListNode *pC = pB->next;

    while (pC) {
        pB->next = pA;
        pA = pB;
        pB = pC;
        pC = pC->next;        
    }
    pB->next = pA;
    head->next = NULL;
    head = pB;

    return head;
}

int main(void) {
    MyLinkedList *obj = myLinkedListCreate();
    ListNode *cur = NULL;

//generate the list
    int i = 0;
    for (i = 0; i < 1; ++i) {
        myLinkedListAddAtTail(obj, i + 1);
    }

//result test: show the linked list
    printf("[Original list]: ");
    cur = obj->head;
    while (cur) {
        printf("%d->", cur->val);
        cur = cur->next;
    }
    printf("NULL\n");

    //reverse the list
    cur = reverseList(obj->head);

//result test: show the linked list
    printf("[Current list]: ");
    int cnt = 10;
    while (cur && cnt) {
        cnt--;
        printf("%d->", cur->val);
        cur = cur->next;
    }
    printf("NULL\n");

    return 0;
}