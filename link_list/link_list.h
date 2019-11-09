typedef int data_t;
typedef struct link_node
{
    data_t d;
    struct link_node *next;
}link_node, *ptr_node;

typedef struct link_list
{
    struct link_node *first;
}link_list, *ptr_list;

// All the APIs that might change the content of list will use list as input
// others use head node as input
ptr_list make_empty();
ptr_node make_node(data_t x);
int is_empty(ptr_node head);
void print_list(ptr_node head);
ptr_node find_node(data_t x, ptr_node head);
ptr_node list_tail(ptr_node head);

int delete_node(ptr_node target, ptr_list list);
void append_node(ptr_node node, ptr_list list);
void insert_before(ptr_node target, ptr_node pos, ptr_list list);
void delete_list(ptr_list list);
ptr_list reverse(ptr_list list);

// Leetcode
ptr_node middle_node(ptr_node head);