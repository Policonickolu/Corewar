/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_address.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:09:41 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/24 17:09:56 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		get_address(t_process *ps, int modify, int *address)
{
	*address = ps->pc + modify;
	if (*address > 0)
		*address %= MEM_SIZE;
	else if (*address < 0)
		*address = (*address % MEM_SIZE) + MEM_SIZE;
}
