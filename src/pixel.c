/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:09:45 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/15 15:44:03 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define RED_PIXEL 0xFF0000

int	render(t_vars *vars)
{
	/* verif sur la window n'est pas détruite */
	if (vars->win_ptr != NULL)
		mlx_pixel_put(vars->mlx_ptr, vars->win_ptr, WINDOW_WIDHT / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
	return (0);

}
