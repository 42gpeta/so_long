/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:36:58 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/02 19:35:09 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_message_error(char *message, t_data *data)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	if (data->gen.fd > 0 && data->gen.fd < 1024)
	{
		while (data->gen.str_tab && data->gen.str_tab[i] != NULL)
			free(data->gen.str_tab[i++]);
		if (data->gen.str_tab)
			free(data->gen.str_tab);
		i = 0;
		while (data->gen.str_map_pathfinding
			&& data->gen.str_map_pathfinding[i] != NULL)
			free(data->gen.str_map_pathfinding[i++]);
		if (data->gen.str_map_pathfinding)
			free(data->gen.str_map_pathfinding);
		ft_destroy(data);
	}
	if (data->str_map)
		free(data->str_map);
	if (data->mlx_p)
		free(data->mlx_p);
	exit(EXIT_FAILURE);
}

void	ft_destroy(t_data *data)
{
	if (data->mlx_p && data->win_p)
	{
		ft_escape_key(data);
		if (data->gen.mlx_img0)
			mlx_destroy_image(data->mlx_p, data->gen.mlx_img0);
		if (data->gen.mlx_img1)
			mlx_destroy_image(data->mlx_p, data->gen.mlx_img1);
		if (data->gen.mlx_imgc)
			mlx_destroy_image(data->mlx_p, data->gen.mlx_imgc);
		if (data->gen.mlx_imge)
			mlx_destroy_image(data->mlx_p, data->gen.mlx_imge);
		if (data->gen.mlx_imgp)
			mlx_destroy_image(data->mlx_p, data->gen.mlx_imgp);
		mlx_destroy_display(data->mlx_p);
		if (data->gen.man.move)
			free(data->gen.man.move);
	}
}
