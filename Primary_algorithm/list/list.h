#ifndef __LIST_H
#define __LIST_H

#ifdef __cplusplus
extern "C" {
#endif

struct ListNode
{
    int val;
    struct ListNode *next;
};

#ifdef __cplusplus
}
#endif

#endif /* __LIST_H */