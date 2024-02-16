/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 09:14:40 by dabae             #+#    #+#             */
/*   Updated: 2023/12/28 09:14:42 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


long    ft_atol(const char *nptr)
{
	int	sign;
	long	res;
	int	i;

	sign = 1;
	res = 0;
	i = 0;
	while (nptr[i] && (nptr[i] == '\t' || nptr[i] == '\n'
			|| nptr[i] == '\v' || nptr[i] == '\f'
			|| nptr[i] == '\r' || nptr[i] == ' '))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (res * sign);
}

void    init_stack(t_stack **a, char **av)
{
    int i;

    i = 0;
    if (check_num(av) && check_int(av) && check_double(av))
    {
        while (av[i])
        {
            add_node_end(a, (int)ft_atol(av[i]));
            i++;
        }
    }
    else
    {
        free_stack(a);
        write(1, "Error\n", 6);
        exit(1);
    }
}
