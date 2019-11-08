typedef int data_t;
typedef struct link_node
{
    data_t d;
    struct link_node *next;
}link_node, *ptr_node, *ptr_head;

ptr_head make_empty();
int is_empty(ptr_head list);
void print_list(ptr_node list);
void delete_list(ptr_head head);
ptr_node find_node(data_t x, ptr_head head);
int delete_node(ptr_node target, ptr_head phead);
void append_node(data_t x, ptr_head head);
ptr_node tail_list(ptr_head head);
void insert_node(ptr_node target, ptr_node pos);

// Leetcode
ptr_node middleNode(ptr_head head);