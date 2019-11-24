/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 08:00:36 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/24 12:46:36 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vm.h"

void	champ_lst_rev(t_champ **alst)
{
	t_champ	*prev;
	t_champ	*cur;
	t_champ	*next;

	cur = *alst;
	prev = NULL;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alst = prev;
}

int		check_vm(t_vm *vm)
{
	t_champ *champ;
	int		number;

	if (!vm->champ)
		return (no_champion_error());
	champ_lst_rev(&vm->champ);
	champ = vm->champ;
	number = 1;	
	while (champ)
	{
		if (champ->number == -1)
		{
			while (check_champion_number(vm, number))
				++number;
			champ->number = number++;
		}
		champ = champ->next;
	}
	champ_lst_rev(&vm->champ);
	return (0);
}

int		handle_arguments(t_vm *vm, int ac, char **av)
{
	return (parse_arguments(vm, ac, av) || check_vm(vm));
}