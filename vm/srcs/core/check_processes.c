/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:30:29 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/05 11:26:20 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

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
	--vm->n_process;
}

void		check_processes(t_vm *vm)
{
	t_process	*prev;
	t_process	*ps;

	ps = vm->process;
	prev = NULL;
	while (ps)
	{
		if (ps->lives)
		{
			ps->lives = 0;
			prev = ps;
			ps = ps->next;
		}
		else
		{
			if (vm->options & VM_OP_C)
			{
				put_dead_process(vm, ps->number);
				write_val(vm, ps->pc, ps->number, 0);
			}
			else
				ft_putstrnbr("Le processus ", ps->number,
					" n'a plus donné signe de vie\n");
			kill_process(vm, &ps, prev);
		}
	}
}
