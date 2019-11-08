#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "link_list.h"

ptr_head make_empty()
{
    ptr_head head = malloc(sizeof(link_node));
    head->next = NULL;
    return head;
}

int is_empty(ptr_head head)
{
    assert(head);    
    return head->next == NULL;
}

// Don't use list head as input, instead, use the first node
void print_list(ptr_node list)
{
    ptr_node node = list;
    while(node)
    {
        printf("%d->", node->d);
        node = node->next;
    }
    printf("NULL\n");
}

void delete_list(ptr_head head)
{
    assert(head);
    ptr_node node = head->next;
    while(node)
    {
        ptr_node t = node->next;
        free(node);
        node = t;
    }
    free(head);
}

ptr_node find_node(data_t x, ptr_head head)
{
    assert(head);    
    ptr_node node = head->next;
    while(node)
    {
        if(node->d == x)
        {
            break;
        }
        node = node->next;
    }
    return node;
}

int delete_node(ptr_node target, ptr_head head)
{
    if(!(head && target)) return EXIT_FAILURE;
    ptr_node node = head->next;
    ptr_node prev = head;
    while(node)
    {
        if(node == target)
        {
            prev->next = node->next;
            break;
        }
        node = node->next;
        prev = prev->next;
    }
    free(target);
    return EXIT_SUCCESS;
}

// Insert AFTER specific position
void insert_node(ptr_node target, ptr_node pos)
{
    assert(target);
    assert(pos);
    target->next = pos->next;
    pos->next = target;
}

void append_node(data_t x, ptr_head head)
{
    assert(head);    
    ptr_node node = malloc(sizeof(link_node));
    node->d = x;
    node->next = NULL;
    ptr_node tail = tail_list(head);
    tail->next = node;
}

ptr_node tail_list(ptr_head head)
{
    assert(head);
    ptr_node node = head;
    while(node->next)
    {
        node = node->next;
    }
    return node;
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
ptr_node middleNode(ptr_head head)
{
    assert(head);
    ptr_node one_step = head->next;
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



