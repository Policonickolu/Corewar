/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_field_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 08:44:47 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/30 12:23:32 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

intmax_t	read_field_at(t_vm *vm, t_process *ps, intmax_t i, size_t size)
{
	intmax_t	val;

	val = 0;
	while (size--)
		val = (val << 8) | vm->field[get_rel_address(ps, i++)];
	return (val);
}
