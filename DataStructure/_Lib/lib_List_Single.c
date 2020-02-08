#include "lib_List_Single.h"

/* Std-Lib_Inc */
#include <stdio.h>
#include <stdlib.h>


void _list_clear(sList_t *list) {
  
}

sList_t *List_Init(void) {

  sList_t *ret_list = NULL;

  /* creat head */
  if (NULL == (ret_list = (sList_t *)malloc(sizeof(sList_t)))) {
    perror("Malloc Error --> List Node <HEAD> Create Error.");
    return ret_list;
  }

  ret_list->head = NULL;

  return ret_list;
}

unsigned int _list_get_length(sList_t *list) {

  unsigned int ret_len = 0;

  do {
    if (NULL == list) {
      break;

    } else {
      sListNode_t *p_node = list->head;
      while (NULL != p_node) {
        ++ret_len;
        p_node = p_node->next;
      }
    }
  } while (0);

  return ret_len;
}