#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "link_list.h"

ptr_node make_node(data_t x)
{
    ptr_node node = malloc(sizeof(ListNode));
    node->val = x;
    node->next = NULL;
    return node;
}

void print_list(ptr_node head)
{
    ptr_node node = head;
    while(node)
    {
        printf("%d->", node->val);
        node = node->next;
    }
    printf("NULL\n");
}

int list_len(ptr_node head)
{
    int len = 0;
    ptr_node node = head;
    while(node)
    {
        len++;
        node = node->next;
    }
    return len;    
}

ptr_node list_tail(ptr_node head)
{
    if(head == NULL) return NULL; // Empty
    ptr_node node = head;
    while(node->next)
    {
        node = node->next;
    }
    return node;
}

// delete whole list
void delete_list(ptr_node head)
{
    assert(head);
    ptr_node node = head;
    while(node)
    {
        ptr_node t = node->next;
        free(node);
        node = t;
    }
}

ptr_node find_node(data_t x, ptr_node head)
{
    if(head == NULL) return NULL;
    ptr_node node = head;
    while(node && node->val != x)
    {
        node = node->next;
    }
    return node;
}

// return the new head
ptr_node delete_node(ptr_node target, ptr_node head)
{
    if(target == NULL || head == NULL) return head;
    ptr_node new_head = head;
    if(head == target)
    {
        new_head = head->next;
    }
    else
    {
        ptr_node prev = head;
        while((head = head->next) && (head != target))
        {
            prev = prev->next;
        }       
        if(head)
        {
            prev->next = head->next;
        }
    }
    free(target);
    return new_head;
}

ptr_node append_node(ptr_node node, ptr_node head)
{
    if(!head) // Empty
    {
        return node;
    }

    list_tail(head)->next = node;
    return head;
}

// Insert BEFORE specific position
ptr_node insert_before(ptr_node target, ptr_node pos, ptr_node head)
{
    assert(target);
    assert(pos);
    assert(head);
    ptr_node new_head = head;
    if(pos == head)
    {
        new_head = target;
        target->next = head;
    }
    else
    {
        ptr_node prev = head;
        head = head->next;
        while(head && (head != pos))
        {
            head = head->next;
            prev = prev->next;
        }       
        if(head)
        {
            prev->next = target;
            target->next = head;
        }
    }
    return new_head;
}

