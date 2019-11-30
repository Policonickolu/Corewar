/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:26:48 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/30 12:27:46 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_type_size(int type)
{
	if (type == REG_CODE)
		return (REG_SIZE);
	else if (type == DIR_CODE)
		return (DIR_SIZE);
	else if (type == IND_CODE)
		return (IND_SIZE);
	return (0);
}
