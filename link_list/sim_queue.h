#ifndef SIM_QUEUE_H
#define SIM_QUEUE_H
#include "link_list.h"
//inserts element at the end
ptr_node queue_push(ptr_node node, ptr_node head);
// removes the first element
ptr_node queue_pop(ptr_node head);
// access the first element
ptr_node queue_front(ptr_node head);
// access the last element
ptr_node queue_back(ptr_node head);

#endif