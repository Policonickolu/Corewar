/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:52:45 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 12:19:30 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned char	check_ocp_type(unsigned char ocp, int param)
{
	if (param == 1)
		return ((ocp >> 6) & 3);
	if (param == 2)
		return ((ocp >> 4) & 3);
	if (param == 3)
		return ((ocp >> 2) & 3);
	if (param == 4)
		return (ocp & 3);
	return (0)
}

int		get_param_size(unsigned char type)
{
	if (type == REG_CODE)
		return (REG_SIZE);
	else if (type == DIR_CODE)
		return (DIR_SIZE);
	else if (type == IND_CODE)
		return (IND_SIZE);
	return (0);
}

void		operate_ld(t_vm *vm, t_process *ps)
{
	unsigned char	ocp;
	int				type;
	int				size;
	int				p1;
	int				p2;

	move_oc(ps, 1);
	ocp = vm->field[ps->oc];
	type = check_ocp_type(ocp, 1);
	size = get_param_size(type);

	read_field(vm, ps, &p1, size);
	read_field(vm, ps, &p2, REG_SIZE);

//t_process *ps, int reg, void *val, size_t size
	if (type == DIR_CODE)
		set_reg(ps, p2, p1, DIR_SIZE);
	else
	{
		p1 = get_new_address(ps, p1 % IDX_MOD);
		load_bytes(vm, ps, p2, p1);
		// read field at p1 and write in p2
	}
	toggle_carry(ps, ps->r[get_r(p2)]);
	move_pc_past_oc(ps);
}
