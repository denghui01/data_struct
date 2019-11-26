#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "btree.h"

// create a new node with data x
ptr_btnode make_btnode(data_t x)
{
    ptr_btnode node = malloc(sizeof(BtreeNode));
    if(node != NULL)
    {
        node->val = x;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}
// insert a new node into the bst
ptr_btnode insert_bstnode(data_t x, ptr_btnode top)
{
    if(!top) return make_btnode(x);
    ptr_btnode parent = top;
    ptr_btnode node = top;
    while(node)
    {
        parent = node;
        if(node->val > x)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }

    if(parent->val > x)
    {
        parent->left = make_btnode(x);
    }
    else
    {
        parent->right = make_btnode(x);
    }
    return top;
}
// delete the node with data x
ptr_btnode delete_bstnode(data_t x, ptr_btnode top)
{
    ptr_btnode node = find_bstnode(x, top);
    ptr_btnode new_head = top;
    
    if(node == NULL) return top;  // not found

    if(node->right == NULL)
    {
        return node->left;
    }
    else
    {
        if(node == top)
        {

        }
        ptr_btnode new_head = node->right;
        ptr_btnode new_tail = min_bsnode(node->right);
        new_tail->left = node->left;




        free(node);


    }
    

}
// return the minimum data node
ptr_btnode min_bstnode(ptr_btnode top)
{
    if(!top) return NULL;
    while(top->left)
    {
        top = top->left;
    }
    return top;
}
// return the maximum data node
ptr_btnode max_bstnode(ptr_btnode top)
{
    if(!top) return NULL;
    while(top->right)
    {
        top = top->right;
    }
    return top;
}
// find the node with data x, if not return NULL
ptr_btnode find_bstnode(data_t x, ptr_btnode top)
{
    ptr_btnode node = top;
    while(node)
    {
        if(node->val > x)
        {
            node = node->left;
        }
        else if(node->val < x)
        {
            node = node->right;
        }
        else
        {
            return node;
        }        
    }
    return node;
}
// print tree
void print_btree(ptr_btnode top);