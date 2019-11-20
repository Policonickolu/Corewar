/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 08:13:53 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/20 11:29:09 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

#include "lemin.h"
#include "libft.h"

static int	parse_options(int *options, char *arg)
{
	int index;

	if (*arg == '-')
		++arg;
	while (*arg)
	{
		if ((index = ft_indexof(*arg, VM_OPTIONS)) == -1 || index == 0)
		{
			if (index != 0)
				invalid_option_error(*arg);
			else
				put_usage();
			return (1);
		}
		*options |= 1 << index;
		++arg;
	}
	return (0);
}

static int	parse_dump(t_vm *vm, int *ac, char ***av)
{
	--*ac;
	++*av;
	if (!ft_isbase(10, **av))
		return (1);
	vm->dump = ft_atoi(**av);
	return (0);
}

static int	parse_n(t_vm *vm, int *ac, char ***av)
{
	int	id;
	char *file;

	--*ac;
	++*av;
	if (!ac || !ft_isbase(10, **av))
		return (1);
	id ft_atoi(**av);
	--*ac;
	++*av;
	if (!ac)
		return (1);
	parse_champion(vm, id, char **av)
	return (0);
}

static int	parse_champion(t_vm *vm, int id, char *file)
{
	t_champ	*champ;

	if (!(champ = (t_champ *)malloc(sizeof(t_champ))))
		vm_exit(vm, "error malloc: parse champion");
	champ->id = num;
	champ->file = file;
	champ->next = vm->champ;
	vm->champ = champ;
}

int			parse_args(t_vm *vm, int *ac, char ***av)
{
	int ret;

	if (*ac < 2)
	{
		put_usage();
		return (1);
	}
	while (*ac)
	{
		if (***av == '-')
		{
			if (ft_strequ(**av + 1, "dump"))
				parse_dump(vm, ac, av);
			else if (ft_strequ(**av + 1, "n"))
				parse_n(vm, ac, av);
			else
				parse_options(&vm->options, **av);
		}
		else
			parse_champion(vm, ac, av);
		--*ac;
		++*av;
	}
	return (0);
}
