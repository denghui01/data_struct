#include "link_list.h"
#include "sim_queue.h"
//inserts element at the end
ptr_node queue_push(ptr_node node, ptr_node head)
{
    return append_node(node, head);
}
// removes the first element
ptr_node queue_pop(ptr_node head)
{
    return delete_node(head, head);
}
// access the first element
ptr_node queue_front(ptr_node head)
{
    return head;
}
// access the last element
ptr_node queue_back(ptr_node head)
{
    return list_tail(head);
}



