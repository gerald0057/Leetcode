#ifndef __LIB_LIST_SINGLE_H__
#define __LIB_LIST_SINGLE_H__

/* Definition */
typedef struct sListNode sListNode_t;
struct sListNode {
  int val;
  sListNode_t *next;
};

typedef struct sList sList_t;
struct sList {
  /* List Head */
  sListNode_t *head;
  /* Functions */
  void (*clear)(sList_t *);
  unsigned int (*length)(sList_t *);
};



#endif