/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:30:29 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 11:40:51 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	kill_process(t_vm *vm, t_process **ps, t_process *prev)
{
	if (!prev)
	{
		vm->process = (*ps)->next;
		ft_memdel((void*)ps);
		*ps = vm->process;
	}
	else
	{
		prev->next = (*ps)->next;
		ft_memdel((void*)ps);
		*ps = prev->next;
	}
}

void		check_processes(t_vm *vm)
{
	t_process	*prev;
	t_process	*ps;

	ps = vm->process;
	prev = NULL;
	while (ps)
	{
		if (ps->live_calls == 0)
		{
			ft_strnbr("Les processus ", ps->number,
				" n'a pas donné signe de vie\n");
			kill_process(vm, &ps, prev);
		}
		else
		{
			ps->live_calls = 0;
			prev = ps;
			ps = ps->next;
		}
	}
}

