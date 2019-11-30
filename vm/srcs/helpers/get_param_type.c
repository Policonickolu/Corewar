/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:26:38 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/30 12:27:30 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_param_type(unsigned char ocp, int param)
{
	if (param == 1)
		return ((ocp >> 6) & 3);
	if (param == 2)
		return ((ocp >> 4) & 3);
	if (param == 3)
		return ((ocp >> 2) & 3);
	if (param == 4)
		return (ocp & 3);
	return (0);
}
