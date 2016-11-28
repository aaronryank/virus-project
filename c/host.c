#include "node.h"
#include <stdio.h>
#include <stdlib.h>

#define START_CELLS 1

int main(void)
{
    node_t *head = NULL;
    head = malloc(sizeof(node_t));

    int i;
    for (i = 0; i < START_CELLS; i++)
        push(head, 111111111111L);
    pop(&head);

    print_list(head);
}
