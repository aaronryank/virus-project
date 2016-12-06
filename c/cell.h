#include <string.h>

// Total number of rounds run and total number of "live" cells
extern int Total_rounds, Total_cells;

/* Yes, this is temporary.
 * In the future there'll be some constant macros about healthy DNA.
 */
#define healthy(val) !strcmp(val, "ACGT")
