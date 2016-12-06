typedef struct node {
    char * val;
    struct node * next;
} node_t;

extern void print_list(node_t *);
extern void push(node_t *, char *);
extern node_t * pop(node_t **);
extern node_t * remove_last(node_t *);
extern node_t * remove_by_index(node_t **, int);
