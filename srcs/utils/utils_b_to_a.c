/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:30:25 by dabae             #+#    #+#             */
/*   Updated: 2024/02/15 16:30:29 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void  find_target_in_a(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *target;
    t_stack *curr;
    long bigger;

    while (stack_b)
    {
        bigger = LONG_MAX;
        curr = stack_a;
        while (curr)
        {
            if (curr->num > stack_b->num && curr->num < bigger)
            {
                bigger = curr->num;
                target = curr;
            }
            curr = curr->next;
        }
        if (bigger == LONG_MAX)
            stack_b->target = ft_min_node(stack_a);
        else
            stack_b->target = target;
        stack_b = stack_b->next;
    }
}
void    push_back_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
    to_top(stack_a, (*stack_b)->target, 'a');
    pa(stack_a, stack_b);
}
