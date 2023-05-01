/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:42:12 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/01 17:45:35 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*** Structure initialisation  */
void	ft_init(t_data *data)
{
	data->path_xpm0 = "maps/xpm/sol_foret.xpm";
	data->path_xpm1 = "maps/xpm/tree.xpm";
	data->path_xpmC = "maps/xpm/framboise.xpm";
	data->path_xpmE = "maps/xpm/sortie_foret.xpm";
	data->path_xpmP = "maps/xpm/randonneur.xpm";
	data->gen.fd = 0;
	data->str_map = 0;
	data->mlx_ptr = 0;
	data->gen.player.nb_move = 0;
	// data->gen.player.move = ft_itoa(data->gen.player.nb_move);
	data->gen.str_tab = 0;
	data->gen.str_map_pathfinding = 0;
	data->gen.number_of_C = 0;
}

void	ft_start(t_data *data, char *argv)
{
	ft_init(data);

	ft_map_control_extention(data, argv);
	ft_map_check_extention(data, argv);
	ft_generate_string_map(data);

	print_map(data); // ! a supprimer

	ft_check_content(data);
	ft_check_surrounded_by_one(data);
	ft_check_map_is_an_rectangle(data);
}

/* Initialisation de MLX */
void	ft_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		(ft_message_error("MLX_INIT FAIL", data));
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->colomn_size_win, data->row_size_win, "So_long by gpeta - 2023"); // ? v2
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		ft_message_error("MLX_NEW_WINDOW FAIL", data);
	}
	ft_generate_path_file(data); // ? v2
	mlx_loop_hook(data->mlx_ptr, &render_no_action, data); // ? v2
	// mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 50, WHITE_PIXEL, "TEST COMPTEUR"); // TODO afficher le compteur sur l'écran
	mlx_hook(data->win_ptr, ClientMessage, StructureNotifyMask, &ft_bouton_red_cross, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &ft_key_hook, data);
	mlx_loop(data->mlx_ptr);
}

void	ft_stop(t_data *data)
{
	int		element;

	element = 0;
	mlx_destroy_image(data->mlx_ptr, data->gen.mlx_img0);
	mlx_destroy_image(data->mlx_ptr, data->gen.mlx_img1);
	mlx_destroy_image(data->mlx_ptr, data->gen.mlx_imgC);
	mlx_destroy_image(data->mlx_ptr, data->gen.mlx_imgE);
	mlx_destroy_image(data->mlx_ptr, data->gen.mlx_imgP);
	mlx_destroy_display(data->mlx_ptr);
	while (data->gen.str_tab[element])
		free(data->gen.str_tab[element++]);
	element = 0;
	while (data->gen.str_map_pathfinding[element])
		free(data->gen.str_map_pathfinding[element++]);
	free(data->gen.str_tab);
	free(data->gen.str_map_pathfinding);
	free(data->str_map);
	free(data->mlx_ptr);
}