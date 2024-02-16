#include "../push_swap.h"

static float calculate_average(t_stack *head)
{
    int sum;
    t_stack *current = head;

    sum = 0;
    current = head;
    while (current != NULL) 
    {
        sum += current->num;
        current = current->next;
    }
    return (float)sum / stack_size(head);
}

void divide_num(t_stack **a, t_stack **b)
{
    t_stack *current;
    float average;

    current = *a;
    average = calculate_average(*a);
    set_index_median(*a);
    if (current->num > average)
        pb(a, b);
    else
        ra(a);
    current = current->next;
    while (current->index != 0 && current != NULL)
    {
        if (current->num > average)
            pb(a, b);
        else
            ra(a);
        current = current->next;
    }
}