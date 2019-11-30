/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_address.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:09:41 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/30 10:41:25 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_rel_address(t_process *ps, int move)
{
	move += ps->pc;
	return ((move % MEM_SIZE) + (move < 0 ? MEM_SIZE : 0));
}
