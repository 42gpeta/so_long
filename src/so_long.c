/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:42:12 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/02 20:32:04 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(t_data *data)
{
	data->path_xpm0 = "maps/xpm/forest_floor.xpm";
	data->path_xpm1 = "maps/xpm/tree.xpm";
	data->path_xpmc = "maps/xpm/raspberry.xpm";
	data->path_xpme = "maps/xpm/exit.xpm";
	data->path_xpmp = "maps/xpm/player.xpm";
	data->gen.fd = 0;
	data->str_map = 0;
	data->mlx_p = 0;
	data->gen.man.move = 0;
	data->gen.man.nb_move = 0;
	data->gen.str_tab = 0;
	data->gen.str_map_pathfinding = 0;
	data->gen.number_of_c = 0;
}

void	ft_start(t_data *data, char *argv, int ac)
{
	ft_init(data);
	ft_map_control_extention(data, argv, ac);
	ft_map_check_extention(data);
	ft_generate_string_map(data);
	// print_map(data); // ! a supprimer
	ft_check_map_is_an_rectangle(data);
	ft_check_surrounded_by_one(data);
	ft_check_content(data);
}

void	ft_mlx(t_data *data)
{
	data->mlx_p = mlx_init();
	if (data->mlx_p == NULL)
		(ft_message_error("MLX_INIT FAIL", data));
	data->win_p = mlx_new_window(data->mlx_p,
			data->colomn_size_win, data->row_size_win, "So_long_gpeta - 2023");
	if (data->win_p == NULL)
	{
		free(data->win_p);
		ft_message_error("MLX_NEW_WINDOW FAIL", data);
	}
	ft_xpm_to_img(data);
	mlx_loop_hook(data->mlx_p, &render, data);
	mlx_hook(data->win_p, ClientMessage, StructureNotifyMask,
		&ft_bouton_red_cross, data);
	mlx_hook(data->win_p, KeyPress, KeyPressMask, &ft_key_hook, data);
	mlx_loop(data->mlx_p);
}

void	ft_stop(t_data *data)
{
	int		element;

	element = 0;
	mlx_destroy_image(data->mlx_p, data->gen.mlx_img0);
	mlx_destroy_image(data->mlx_p, data->gen.mlx_img1);
	mlx_destroy_image(data->mlx_p, data->gen.mlx_imgc);
	mlx_destroy_image(data->mlx_p, data->gen.mlx_imge);
	mlx_destroy_image(data->mlx_p, data->gen.mlx_imgp);
	mlx_destroy_display(data->mlx_p);
	while (data->gen.str_tab[element])
		free(data->gen.str_tab[element++]);
	element = 0;
	while (data->gen.str_map_pathfinding[element])
		free(data->gen.str_map_pathfinding[element++]);
	free(data->gen.str_tab);
	free(data->gen.str_map_pathfinding);
	free(data->str_map);
	free(data->mlx_p);
}
