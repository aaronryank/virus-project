#include "node.h"
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_START_CELLS 4

int main(int argc, char *argv[])
{
    node_t *head = NULL;
    int cells;

    if (argc < 2)
        printf("Starting host with default cell size %d.\n", (cells = DEFAULT_START_CELLS));
    else
        printf("Starting host with %d cells.\n", (cells = atoi(argv[1])));

    head = malloc(sizeof(node_t));

    int i;
    for (i = 0; i < cells; i++)
        push(head, 111111111111L);
    pop(&head);

    print_list(head);
    return 0;
}
