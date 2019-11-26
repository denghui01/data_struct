#ifndef BTREE_H
#define BTREE_H
typedef int data_t;
typedef struct BtreeNode
{
    data_t val;
    struct BtreeNode* left;
    struct BtreeNode* right;
}BtreeNode, *ptr_btnode;

// create a new node with data x
ptr_btnode make_btnode(data_t x);
// insert a new node into the bst
ptr_btnode insert_bstnode(data_t x, ptr_btnode top);
// delete the node with data x
ptr_btnode delete_bstnode(data_t x, ptr_btnode top);
// return the minimum data node
ptr_btnode min_bstnode(ptr_btnode top);
// return the maximum data node
ptr_btnode max_bstnode(ptr_btnode top);
// find the node with data x, if not return NULL
ptr_btnode find_bstnode(data_t x, ptr_btnode top);
// print tree
void print_btree(ptr_btnode top);
#endif