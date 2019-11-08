#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"

int main()
{
    ptr_head list = make_empty();
    for (int i = 0; i < 10; ++i)
    {
        append_node(i, list);
    }
    print_list(list->next);

    // Test insert_node and find_node, delete_list
    ptr_node node = find_node(5, list);
    link_node a;
    a.d = 11;
    insert_node(&a, node);
    print_list(list->next);
    delete_list(list);

    // Test leetcode: middleNode
    list = make_empty();
    for (int i = 0; i < 1; ++i)
    {
        append_node(i, list);
    }    
    print_list(middleNode(list));

    for (int i = 1; i < 4; ++i)
    {
        append_node(i, list);
    }
    print_list(list->next);
    print_list(middleNode(list));
    
    return EXIT_SUCCESS;
}