/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 15:26:34 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/05 09:32:03 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	insert_process(t_vm *vm, t_process *new)
{
	t_process	*ps;

	ps = vm->process;
	while (ps)
	{
		if (ps->number == new->number)
		{
			while (ps->next && ps->next->number == new->number)
				ps = ps->next;
			new->next = ps->next;
			ps->next = new;
			++vm->n_process;
			break ;
		}
		ps = ps->next;
	}
}
