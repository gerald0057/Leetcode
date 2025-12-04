#include <stdio.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    struct ListNode fake_head = {.next = head,};
    struct ListNode *p_head = &fake_head, *p_l = &fake_head, *p_r = &fake_head;
    for (int i = 0; i < n; ++i)
    {
        p_r = p_r->next;
        printf("pr->%p\n", p_r);
    }
    
    while (p_r->next)
    {
        p_l = p_l->next;
        p_r = p_r->next;
        printf("pl->%p\n", p_l);
        printf("pr->%p\n", p_r);
    }

    if (n != 1)
    {
        p_l->next = p_l->next->next;
    }
    else
    {
        p_l->next = NULL;
    }

    printf("pl %p %d %p\n", p_l, p_l->val, p_l->next);

    return p_head->next;
}

int main(void)
{
    struct ListNode node_0 = {
        .val = 0,
    };
    struct ListNode node_1 = {
        .val = 1,
    };
    struct ListNode node_2 = {
        .val = 2,
    };

    // node_0.next = &node_1;
    // node_1.next = &node_2;

    printf("nodes: %p\n", &node_0);
    printf("nodes: %p\n", &node_1);
    printf("nodes: %p\n", &node_2);

    struct ListNode *p = removeNthFromEnd(&node_0, 1);

    while (p)
    {
        printf("p: %p\n", p);
        printf("val: %d\n", p->val);
        p = p->next;
    }

    return 0;
}
