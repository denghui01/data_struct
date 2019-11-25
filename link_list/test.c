#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"
#include "sim_stack.h"
#include "sim_queue.h"
int main()
{
    
    // Test:
    // make_node, append_node, print_list
    // list_tail
    ptr_node list1 = NULL;
    for(int i = 1; i < 9; ++i)
    {
        list1 = append_node(make_node(i), list1);
    }
    print_list(list1);
    printf("List1 length = %d\n", list_len(list1));

    // Test:
    // find_node, insert_before
    ptr_node new_node = make_node(5);
    insert_before(new_node, find_node(5, list1), list1);
    print_list(list1);

    // Test:
    // delete_node, delete_list
    delete_node(find_node(4, list1), list1);  // delete the first 5
    delete_node(find_node(5, find_node(5, list1)->next), list1);  // delete the second 5
    print_list(list1);

    new_node = find_node(10, list1);
    if(new_node == NULL)
    {
        printf("Can't find 10 in the list\n");
    }
    delete_list(list1);

    // Test stack_push, stack_pop, stack_top
    ptr_node stack1 = NULL;
    stack1 = stack_push(make_node(1), stack1);
    stack1 = stack_push(make_node(2), stack1);
    stack1 = stack_push(make_node(3), stack1);
    stack1 = stack_push(make_node(4), stack1);        
    while(stack_top(stack1))
    {
        printf("%d ", stack_top(stack1)->val);
        stack1 = stack_pop(stack1);
    }
    printf("\n");

    // Test queue_push, queue_pop, queue_front, queue_back
    ptr_node queue1 = NULL;
    queue1 = queue_push(make_node(1), queue1);
    queue1 = queue_push(make_node(2), queue1);
    queue1 = queue_push(make_node(3), queue1);
    queue1 = queue_push(make_node(4), queue1); 
    while(queue_front(queue1))
    {
        printf("%d ", queue_front(queue1)->val);
        queue1 = queue_pop(queue1);
    }           
    printf("\n");
    return EXIT_SUCCESS;
}