#include "node.h"
#include "cell.h"
#include "defs.h"
#include "extern.h"
#include <stdio.h>
#include <unistd.h>

int Total_rounds = 0;

/* display stats about simulation */
void print_data(node_t *cells)
{
    node_t *current = cells;
    int healthy_cells, infected_cells;

    /* update healthy and infected cell counts */
    while (current != NULL) {
        if (healthy(current->val))
            healthy_cells++;
        else
            infected_cells++;
	current = current->next;
    }

    /* display data */
    clear_screen();
    printf("Round %d (%d Cell%s)\n", Total_rounds, Total_cells, (Total_cells == 1) ? "" : "s");
    printf("Healthy: %d Infected: %d\n", healthy_cells, infected_cells);

#ifdef __TEST__
    print_list(*cells);
#endif

    /* wait, check if 'i' is pressed
     * if so, begin infection        */
    sleep(1);
    if (_kbhit() == 'i') {
        /* add infect() function */
    }

}

/* self-explanatory; run the simulation */
void run_simulation(node_t **cells)
{
    Total_rounds++;
    print_data(*cells);
}
