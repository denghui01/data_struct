#include "link_list.h"
#include "sim_stack.h"

// return the new head
ptr_node stack_push(ptr_node node, ptr_node head)
{
    return insert_before(node, head, head);
}

// return the new head
ptr_node stack_pop(ptr_node head)
{
    return delete_node(head, head);
}

ptr_node stack_top(ptr_node head)
{
    return head;
}