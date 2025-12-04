#include <stdio.h>
#include "list.h"

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode hp = {0};
    struct ListNode *p = &hp;
    
    if (NULL == list1) return list2;
    if (NULL == list2) return list1;

    while (list1 && list2)
    {
        // printf("%p %p\n", list1, list2);
        if (list1->val > list2->val)
        {
            p->next = list2;
            p = p->next;
            list2 = list2->next;
        }
        else
        {
            p->next = list1;
            p = p->next;
            list1 = list1->next;
        }
    }

    p->next = list1 ? list1 : list2;

    return hp.next;
}

int main(void)
{
    struct ListNode node_0 = {
        .val = 0,
    };
    struct ListNode node_1 = {
        .val = 2,
    };
    struct ListNode node_2 = {
        .val = 4,
    };
    struct ListNode node_3 = {
        .val = 1,
    };
    struct ListNode node_4 = {
        .val = 3,
    };
    struct ListNode node_5 = {
        .val = 5,
    };

    node_0.next = &node_1;
    node_1.next = &node_2;

    node_3.next = &node_4;
    node_4.next = &node_5;

    struct ListNode *p = mergeTwoLists(&node_0, &node_3);

    while (p)
    {
        printf("p: %p\n", p);
        printf("val: %d\n", p->val);
        p = p->next;
    }

    return 0;
}
