/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_champ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 09:08:56 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 09:10:35 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_champ	*get_champ(t_vm *vm, int number)
{
	t_champ		*champ;

	champ = vm->champ;
	while (champ)
	{
		if (champ->number == number)
			return (champ);
		champ = champ->next;
	}
	return (NULL);
}
