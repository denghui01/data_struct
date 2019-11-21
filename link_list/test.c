#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"

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

    return EXIT_SUCCESS;
}