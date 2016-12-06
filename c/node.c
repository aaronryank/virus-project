#include "node.h"
#include <stdlib.h>
#include <stdio.h>

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%s\n", current->val);
        current = current->next;
    }
}

void push(node_t * head, char * val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = malloc(sizeof(node_t));
    current->next->val = malloc(sizeof(char*));
    current->next->val = val;
    current->next->next = NULL;
}

node_t * pop(node_t ** head) {
    node_t * retval = NULL;
    node_t * next_node = NULL;

    if (*head == NULL)
        return NULL;

    next_node = (*head)->next;
    retval = *head;
    free((*head)->val);
    free(*head);
    *head = next_node;

    return retval;
}

node_t * remove_last(node_t * head) {
    node_t * retval = NULL;
    /* if there is only one item in the list, remove it */
    if (head->next == NULL) {
        retval = head;
        free(head);
        return retval;
    }

    /* get to the last node in the list */
    node_t * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    /* now current points to the last item of the list, so let's remove current->next */
    retval = current->next;
    free(current->next);
    current->next = NULL;
    return retval;
}

node_t * remove_by_index(node_t ** head, int n) {
    int j;
    node_t * retval = NULL;
    node_t * current = *head;
    node_t * temp_node = NULL;

    if (n == 0)
        return pop(head);

    for (j = 0; j < n-1; j++) {
        if (current->next == NULL)
            return NULL;
        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node;
    current->next = temp_node->next;
    free(temp_node);

    return retval;
}
