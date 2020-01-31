#include <stdio.h>
#include <stdlib.h>
#include "MyList.h"

int myLinkedGetSizeFromHeadNode(struct ListNode *head) {
    int count  = 0;
    ListNode *cur = head;
    while (cur) {
        ++count;
        cur = cur->next;
    }
    return count;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    MyLinkedList *obj_sum = myLinkedListCreate();
    ListNode *obj_1 = l1;
    ListNode *obj_2 = l2;

    unsigned int carryFlag = 0;
    int tempSum = 0;
    while (obj_1 && obj_2) {
        tempSum = obj_1->val + obj_2->val;
        if (carryFlag) {
            ++tempSum;
            carryFlag = 0;
        }
        if (tempSum > 9)
            carryFlag = 1;
        myLinkedListAddAtTail(obj_sum, tempSum % 10);
        
        obj_1 = obj_1->next;
        obj_2 = obj_2->next;
        if (obj_1 == NULL){
            obj_1 = obj_2;
            break;
        }            
    }
    
    while (obj_1) {
        tempSum = obj_1->val;        
        if (carryFlag) {
            carryFlag = 0;
            ++tempSum;
        }
        if (tempSum > 9)
            carryFlag = 1;
        myLinkedListAddAtTail(obj_sum, tempSum % 10);
        obj_1 = obj_1->next;
    }

    if (carryFlag) {
        myLinkedListAddAtTail(obj_sum, 1);
        carryFlag = 0;
    }

    return obj_sum->head;
}

int main(void) {
    int val_l1[] = {9, 9};
    int val_l2[] = {1};
    MyLinkedList *obj_1 = myLinkedListCreate();
    MyLinkedList *obj_2 = myLinkedListCreate();

    int i = 0;
    for (i = 0; i < sizeof(val_l1) / sizeof(int); ++i)
        myLinkedListAddAtTail(obj_1, val_l1[i]);        
    for (i = 0; i < sizeof(val_l2) / sizeof(int); ++i)
        myLinkedListAddAtTail(obj_2, val_l2[i]);

    ShowList_DONOT_Have_Cycle(obj_1->head, "obj_1");
    ShowList_DONOT_Have_Cycle(obj_2->head, "obj_2");

    ListNode *SumList = addTwoNumbers(obj_1->head, obj_2->head);
    ShowList_DONOT_Have_Cycle(SumList, "SumList");

    return 0;
}