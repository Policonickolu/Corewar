/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 08:36:37 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/24 09:57:27 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vm.h"
#include "libft.h"

int		check_champion_number(t_vm *vm, int number)
{
	t_champ	*champ;

	champ = vm->champ;
	while (champ)
	{
		if (champ->number >= 0 && champ->number == number)
			return (1);
		champ = champ->next;
	}
	return (0);
}

int		parse_champion(t_vm *vm, int number, char *file)
{
	t_champ	*champ;

	if (check_champion_number(vm, number))
		return (already_attributed_number_error());
	if (!(champ = (t_champ *)ft_memalloc(sizeof(t_champ))))
		vm_exit(vm, "error malloc: parse champion");
	if (!(champ->file = ft_strdup(file)))
		vm_exit(vm, "error malloc: parse champion dup file name");
	champ->number = number;
	champ->next = vm->champ;
	vm->champ = champ;
	++vm->n_champ;
	return (0);
}
