#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"

int main()
{
    ptr_list list = make_empty();
    
    // Test:
    // append_node, print_list
    for (int i = 0; i < 10; ++i)
    {
        ptr_node node = make_node(i);
        append_node(node, list);
    }
    print_list(list->first);

    // Test:
    // find_node, insert_before
    // delete_node, delete_list
    ptr_node node = find_node(0, list);
    ptr_node a = make_node(11);
    if(node)
    {
        insert_before(a, node, list);
    }
    print_list(list->first);

    node = find_node(10, list);
    if(node == NULL)
    {
        printf("Can't find 10 in the list\n");
    }
    delete_node(find_node(1, list), list);
    print_list(list->first);
    delete_list(list);

    // Test leetcode: middleNode
    for (int i = 0; i < 3; ++i)
    {
        ptr_node node = make_node(i);   
        append_node(node, list); // [0,1,2]
    }
    print_list(list->first);    
    print_list(middle_node(list)); // [1,2]

    for (int i = 1; i < 4; ++i)
    {
        ptr_node node = make_node(i);   
        append_node(node, list); // [0,1,2,1,2,3]
    }
    print_list(list->first);
    print_list(middle_node(list)); //[1,2,3]
    
    return EXIT_SUCCESS;
}