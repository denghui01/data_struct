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
    ptr_node node = find_node(0, list->first);
    ptr_node a = make_node(11);
    if(node)
    {
        insert_before(a, node, list);
    }
    print_list(list->first);

    node = find_node(10, list->first);
    if(node == NULL)
    {
        printf("Can't find 10 in the list\n");
    }
    delete_node(find_node(1, list->first), list);
    print_list(list->first);

    for (int i = 0; i < 3; ++i)
    {
        ptr_node node = make_node(i);   
        append_node(node, list);
    }
    print_list(list->first);  

    // Test delete the second node with the specific data
    delete_node(find_node(2, find_node(2, list->first)->next), list);
    print_list(list->first);


    // 206. Reverse Linked List
    print_list(reverse(list)->first);

    delete_list(list);

    // 876. Middle of the Linked List
    int i = 1;
    while (i < 4)
    {
        ptr_node node = make_node(i);   
        append_node(node, list); // [1,2,3]
        ++i;
    }
    print_list(list->first);    
    print_list(middle_node(list->first)); // [2,3]

    while(i < 9)
    {
        ptr_node node = make_node(i);   
        append_node(node, list); // [1,2,3,4,5,6,7,8]
        ++i;
    }
    print_list(list->first);
    print_list(middle_node(list->first)); //[5,6,7,8]
    
    // 92. Reverse Linked List II
    //print_list(reverse_between(3, 4, list)->first);
    print_list(reverseBetween(list->first, 3, 4));

    delete_list(list);
    free(list);

    //21. Merge Two Sorted Lists
    ptr_list list1 = make_empty();
    ptr_list list2 = make_empty();
    append_node(make_node(1), list1);
    append_node(make_node(2), list1);
    append_node(make_node(4), list1);

    append_node(make_node(1), list2);
    append_node(make_node(3), list2);
    append_node(make_node(4), list2);    
    print_list(mergeTwoLists(list1->first, list2->first));

    //83. Remove Duplicates from Sorted List
    ptr_list list3 = make_empty();
    append_node(make_node(1), list3);
    append_node(make_node(2), list3);
    append_node(make_node(2), list3);
    append_node(make_node(2), list3);
    append_node(make_node(3), list3);

    print_list(deleteDuplicates(list3->first));

    return EXIT_SUCCESS;
}