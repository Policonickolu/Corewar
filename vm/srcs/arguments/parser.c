/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 08:03:31 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/24 10:09:46 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

static int	parse_dump(t_vm *vm, int *ac, char ***av)
{
	--*ac;
	++*av;
	if (!*ac || !ft_isbase(10, **av))
		return (dump_arg_error());
	vm->dump = ft_atoi(**av);
	return (0);
}

static int	parse_n(t_vm *vm, int *ac, char ***av)
{
	int	id;

	--*ac;
	++*av;
	if (!*ac || !ft_isbase(10, **av))
		return (n_arg_error());
	id = ft_atoi(**av);
	--*ac;
	++*av;
	if (!*ac)
		return (missing_champion_error());
	return (parse_champion(vm, id, **av));
}

int		parse_arguments(t_vm *vm, int ac, char **av)
{
	int ret;

	ret = 0;
	while (ac)
	{
		if (**av == '-')
		{
			if (ft_strequ(*av + 1, "dump"))
				ret = parse_dump(vm, &ac, &av);
			else if (ft_strequ(*av + 1, "n"))
				ret = parse_n(vm, &ac, &av);
			else
				ret = parse_options(&vm->options, *av);
		}
		else
			ret = parse_champion(vm, -1, *av);
		if (vm->n_champ > MAX_PLAYERS)
			return (too_many_champions_error());
		if (ret)
			return (1);
		--ac;
		++av;
	}
	return (0);
}
