#include "monty.h"

/**
 * f_push - function to push new element to the stack
 * @stack: pointer to our stack
 * @counter: line number
 * Return: it's a void
 */

void f_push(stack_t **stack, unsigned int counter) {
    char *arg = Taxi.arg;
    int value;
    stack_t *new_node;

    if (arg != NULL) {
        if (is_valid_integer(arg)) {
            value = atoi(arg);
            new_node = malloc(sizeof(stack_t));

            if (new_node == NULL) {
                fprintf(stderr, "L%d: malloc failed\n", counter);
                fclose(Taxi.filehold);
                free_stack(*stack);
                exit(EXIT_FAILURE);
            }

            new_node->n = value;
            new_node->next = NULL;
            new_node->prev = NULL;

            if (*stack == NULL) {
                *stack = new_node;
            } else {
                new_node->next = *stack;
                (*stack)->prev = new_node;
                *stack = new_node;
            }
        } else {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(Taxi.filehold);
            free_stack(*stack);
            exit(EXIT_FAILURE);
        }
    }
}

