#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "link_list.h"

ptr_list make_empty()
{
    ptr_list list = malloc(sizeof(link_list));
    list->first = NULL;
    return list;
}

ptr_node make_node(data_t x)
{
    ptr_node node = malloc(sizeof(link_node));
    node->d = x;
    node->next = NULL;
    return node;
}

int is_empty(ptr_list list)
{
    assert(list);    
    return list->first == NULL;
}

// Don't use list head as input, instead, use the head node
void print_list(ptr_node head)
{
    ptr_node node = head;
    while(node)
    {
        printf("%d->", node->d);
        node = node->next;
    }
    printf("NULL\n");
}

// delete whole list
void delete_list(ptr_list list)
{
    assert(list);
    ptr_node node = list->first;
    while(node)
    {
        ptr_node t = node->next;
        free(node);
        node = t;
    }
    list->first = NULL; // empty it again!
}

ptr_node find_node(data_t x, ptr_list list)
{
    assert(list);
    ptr_node node = list->first;
    while(node && node->d != x)
    {
        node = node->next;
    }
    return node;
}

// Since the target may be the first node, the list has to be input
int delete_node(ptr_node target, ptr_list list)
{
    if(target == NULL || list == NULL) return EXIT_FAILURE;
    if(target == list->first)
    {
        list->first = list->first->next;
    }
    else
    {
        ptr_node node = list->first->next;
        ptr_node prev = list->first;
        while(node && node != target)
        {
            prev = node;
            node = node->next;
        }
        if(node)
        {
            prev->next = node->next;
        }        
    }    
    free(target);
    return EXIT_SUCCESS;
}

ptr_node list_tail(ptr_list list)
{
    assert(list);
    if(list->first == NULL) return NULL; // Empty

    ptr_node node = list->first;
    while(node->next)
    {
        node = node->next;
    }
    return node;
}

void append_node(ptr_node node, ptr_list list)
{
    assert(list);
    if(is_empty(list))
    {
        list->first = node;
    }    
    else
    {
        ptr_node tail = list_tail(list);
        if(tail)
        {
            tail->next = node;
        }
    }    
}

// Insert BEFORE specific position
void insert_before(ptr_node target, ptr_node pos, ptr_list list)
{
    assert(target);
    assert(pos);
    assert(list);
    if(list->first == pos) // Insert to the first node
    {
        target->next = pos;
        list->first = target;
        return;
    }
    else
    {
        ptr_node prev = list->first;
        while(prev->next && prev->next != pos)
        {
            prev = prev->next;
        }
        if(prev->next != NULL)
        {
            target->next = pos;
            prev->next = target;
        }
    }    
}

/*
void reverse1(ptr_head head)
{
    assert(head);
    if(head->next == NULL) return; // Empty

    ptr_node a = head->next;

    while(a)
    {
        if(a->next == NULL) return; // One node

        ptr_node b = a->next;
        if(b->next == NULL)
        {
            head->next = b;
            b->next = a;
            a->next = NULL;
        }

        ptr_node c = b->next;

    }
}
*/

// Leetcode questions
// 876. Middle of the Linked List
ptr_node middle_node(ptr_list list)
{
    assert(list);
    ptr_node one_step = list->first;
    if(one_step == NULL) return one_step; // Empty
    ptr_node two_step = one_step->next;
    while(two_step)
    {
        one_step = one_step->next;
        two_step = two_step->next;
        if(two_step == NULL) break;
        two_step = two_step->next;
    }
    return one_step; // Return only the real node, not the head of list
}



