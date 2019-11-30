/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_field_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 08:44:47 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/30 12:56:01 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	write_field_at(t_vm *vm, t_process *ps, intmax_t i, intmax_t val)
{
	int			size;
	
	size = DIR_SIZE;
	while (size--)
		vm->field[get_rel_address(ps, i++)] = (val >> (size * 8)) & 0xFF;
}
