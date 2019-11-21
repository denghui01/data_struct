typedef int data_t;
typedef struct ListNode
{
    data_t val;
    struct ListNode *next;
}ListNode, *ptr_node;

ptr_node make_node(data_t x);
void print_list(ptr_node head);
int list_len(ptr_node head);
ptr_node list_tail(ptr_node head);
void delete_list(ptr_node head);
ptr_node find_node(data_t x, ptr_node head);
ptr_node delete_node(ptr_node target, ptr_node head);
ptr_node append_node(ptr_node target, ptr_node head);
ptr_node insert_before(ptr_node target, ptr_node pos, ptr_node head);


