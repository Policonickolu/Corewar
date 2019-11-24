/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:15:50 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/24 17:16:15 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			get_r(int reg)
{
	if (reg < 1 || reg > REG_NUMBER)
		return (0);
	return (reg);
}
