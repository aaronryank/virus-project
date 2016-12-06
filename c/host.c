#include "node.h"
#include "extern.h"
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_START_CELLS 1

int Total_cells;

int main(int argc, char *argv[])
{
    node_t *head = NULL;

    /* set cell size */
    if (argc < 2)
        printf("Starting host with default cell size %d.\n", (Total_cells = DEFAULT_START_CELLS));
    else
        printf("Starting host with %d cells.\n", (Total_cells = atoi(argv[1])));

    /* allocate memory for linked list */
    head = malloc(sizeof(node_t));

    /* initialize linked list with default cell code */
    int i;
    for (i = 0; i < Total_cells; i++)
        push(head, 111111111111L);

    /* for some reason, every list starts with '0'.
     * fix this.                                     */
    pop(&head);

    /* whole thing (currently, print the list) */
    run_simulation(&head);
    return 0;
}
