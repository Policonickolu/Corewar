/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 08:44:47 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 09:15:23 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	read_field(t_vm *vm, t_process *ps, int *dst, size_t size)
{
	int		val;

	val = 0;
	while (size--)
	{
		move_oc(ps, 1);
		val = (val << 8) | vm->field[ps->oc];
	}
	*dst = val;
}