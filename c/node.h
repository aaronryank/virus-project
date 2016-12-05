typedef struct node {
    long val;
    struct node *next;
} node_t;

extern void print_list(node_t *);
extern void push(node_t *, long);
extern int pop(node_t **);
extern int remove_last(node_t *);
extern int remove_by_index(node_t **, int);
