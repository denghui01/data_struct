#ifndef SIM_STACK_H
#define SIM_STACK_H
#include "link_list.h"

ptr_node stack_push(ptr_node node, ptr_node head);
ptr_node stack_pop(ptr_node head);
ptr_node stack_top(ptr_node head);
#endif