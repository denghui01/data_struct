#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
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

int is_empty(ptr_node head)
{
    return head == NULL;
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

// Note: use ptr_node instead of ptr_list
ptr_node find_node(data_t x, ptr_node head)
{
    if(head == NULL) return NULL;
    ptr_node node = head;
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

void append_node(ptr_node node, ptr_list list)
{
    assert(list);
    if(is_empty(list->first))
    {
        list->first = node;
    }    
    else
    {
        ptr_node tail = list_tail(list->first);
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

// Leetcode questions
// 206. Reverse Linked List
ptr_list reverse(ptr_list list)
{
    assert(list);
    ptr_node head, new_head;
    head = list->first;
    new_head = NULL;

    while(head)
    {
        ptr_node temp = head;
        head = head->next;
        temp->next = new_head;
        new_head = temp;
    }
    list->first = new_head;
    return list;
}

// Leetcode questions
// 876. Middle of the Linked List
ptr_node middle_node(ptr_node head)
{
    ptr_node one_step = head;
    if(one_step == NULL) return NULL; // Empty

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

//92. Reverse Linked List II
// m, n should be 1-based
ptr_list reverse_between(int m, int n, ptr_list list)
{
    assert(list);
    assert(m > 0 && n > 0); 
    assert(m <= list_len(list->first));
    assert(n <= list_len(list->first));
    assert(n >= m);
    if(m == n) return list; 

    ptr_node head = list->first;
    ptr_node new_head = NULL;
    ptr_node tail1 = NULL;
    ptr_node tail2 = head;

    while(head)
    {
        if(--m > 0)
        {
            tail1 = head;
            new_head = head;
            head = head->next;
            tail2 = head;
            --n;
        }
        else // start to reverse
        {
            if(--n >= 0)
            {
                ptr_node temp = head;
                head = head->next;
                temp->next = new_head;
                new_head = temp;
            }
            else // finished
            {
                break;
            }            
        }        
    }

    if(tail1)
    {
        tail1->next = new_head;
    }
    else
    {
        list->first = new_head;
    }
    tail2->next = head;
    return list;
}

// Another version for the web site of leetcode
//typedef struct ListNode *ptr_node;
ptr_node reverseBetween(ptr_node head, int m, int n)
{    
    assert(m > 0 && n > 0); 
    assert(n >= m);
    if(m == n) return head; 

    ptr_node new_head = NULL;
    ptr_node tail1 = NULL;
    ptr_node tail2 = head;
    ptr_node old_head = head;
    while(head)
    {
        if(--m > 0)
        {
            tail1 = head;
            new_head = head;
            head = head->next;
            tail2 = head;
            --n;
        }
        else // start to reverse
        {
            if(--n >= 0)
            {
                ptr_node temp = head;
                head = head->next;
                temp->next = new_head;
                new_head = temp;
            }
            else // finished
            {
                break;
            }            
        }        
    }
    
    tail2->next = head;
    if(tail1)
    {
        tail1->next = new_head;
        return old_head;
    }
    else
    {
        return new_head;
    }
}

//21. Merge Two Sorted Lists
ptr_node mergeTwoLists(ptr_node l1, ptr_node l2)
{
    ptr_node head1, head2, head;
    if(!l1) return l2;
    if(!l2) return l1;    
    if(l2->d >= l1->d)
    {
        head1 = l1;
        head = l1;
        head2 = l2;        
    }
    else
    {
        head1 = l2;
        head = l2;
        head2 = l1;
    }
    ptr_node tail = head1;
    while(head1 && head2)
    {
        while(head1 && head2->d >= head1->d)
        {
            tail = head1;
            head1 = head1->next;
        }
        tail->next = head2;

        if(head1)
        {
            while(head2 && head2->d < head1->d)
            {
                tail = head2;
                head2 = head2->next;
            }
            tail->next = head1;
        }
    }
    return head;
}

//83. Remove Duplicates from Sorted List
ptr_node deleteDuplicates(ptr_node head)
{
    if(!head) return head;

    ptr_node node1, node2;
    node1 = head;
    node2 = head;
    while(node1)
    {
        while(node2 && node2->d == node1->d)
        {
            node2 = node2->next;
        }
        node1->next = node2;
        node1 = node2;        
    }
    return head;
}

//82. Remove Duplicates from Sorted List II
ptr_node deleteDuplicates2(ptr_node head)
{
    if(!head) return head;

    ptr_node new_head, node1, node2;
    new_head = NULL;
    node1 = head;
    node2 = head->next;
    while(node1)
    {
        while(node2 && node2->d == node1->d)
        {
            node2 = node2->next;
        }
        node1->next = node2;
        node1 = node2;        

    }
}
