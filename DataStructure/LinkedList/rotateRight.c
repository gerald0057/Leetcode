#include <stdio.h>
#include "MyList.h"

int myLinkedListGetSizeFromHeadNode(struct ListNode *head) {
    int count  = 0;
    struct ListNode *cur = head;
    while (cur) {
        ++count;
        cur = cur->next;
    }
    return count;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || k < 0) return NULL;
    if (head->next == NULL || k == 0) return head;

    int len = myLinkedListGetSizeFromHeadNode(head);
    k %= len;

    ListNode *pEnd = head;
    ListNode *pTail = head;
    ListNode *pHead = NULL;
    while (k) {
        pTail = pTail->next;
        --k;
    }

    while (pTail->next) {
        pTail = pTail->next;
        pEnd = pEnd->next;        
    }
    pTail->next = head;

    pHead = pEnd->next;
    pEnd->next = NULL;

    return pHead;
}

int main(void) {
    int i = 0;
    MyLinkedList *obj = myLinkedListCreate();
    for (i = 1; i < 3; ++i)
        myLinkedListAddAtTail(obj, i);

    ShowList_DONOT_Have_Cycle(obj->head, "to Rotate");
    obj->head = rotateRight(obj->head, 2);
    ShowList_DONOT_Have_Cycle(obj->head, "Rotated");

    return 0;
}