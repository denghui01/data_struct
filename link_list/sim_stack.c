#include "link_list.h"
#include "sim_stack.h"

// return the new head
ptr_node push(ptr_node node, ptr_node head)
{
    return insert_before(node, head, head);
}

// return the new head
ptr_node pop(ptr_node head)
{
    return delete_node(head, head);
}