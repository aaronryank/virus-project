#include "node.h"
#include "extern.h"
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_START_CELLS 1

int Total_cells;

int main(int argc, char *argv[])
{
    node_t *head = NULL;
    int healthy_cells;

    /* set cell size */
    if (argc < 2)
        printf("Starting host with default cells %d...\n", (Total_cells = DEFAULT_START_CELLS));
    else
        printf("Starting host with %d cells...\n", (Total_cells = atoi(argv[1])));

    /* allocate memory for linked list */
    head = malloc(sizeof(node_t));

    /* all cells begin healthy */
    healthy_cells = Total_cells;

    /* initialize linked list with default cell code */
    int i;
    for (i = 0; i < Total_cells; i++)
        push(head, "ACGT");

    /* for some reason, every list starts with '0'.
     * this fixes it.                               */
    pop(&head);

    /* 1. print simulation data
       2. check for infection
       3. run cell functions    */
    while (healthy_cells > 0) {
        healthy_cells = run_simulation(&head);
        cell_parse(head);
    }
    return 0;
}
