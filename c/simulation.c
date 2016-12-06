#include "node.h"
#include "cell.h"
#include "color.h"
#include <stdio.h>

int Total_rounds = 0;

void print_data(node_t *cells)
{
    node_t *current = cells;
    int healthy_cells, infected_cells;

    while (current != NULL) {
        if (healthy(current->val))
            healthy_cells++;
        else
            infected_cells++;
	current = current->next;
    }

    clear_screen();
    printf("Round %d (%d Cell%s)\n", Total_rounds, Total_cells, (Total_cells == 1) ? "" : "s");
    printf("Healthy: %d Infected: %d\n", healthy_cells, infected_cells);

#ifdef __TEST__
    print_list(*cells);
#endif // __TEST__

}

void run_simulation(node_t **cells)
{
    Total_rounds++;
    print_data(*cells);
}
