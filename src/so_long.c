/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:42:12 by gpeta             #+#    #+#             */
/*   Updated: 2023/04/27 15:01:28 by gpeta            ###   ########.fr       */
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
	data->generate.fd = 0;
	data->string_map = 0;
	data->mlx_ptr = 0;
	data->generate.player.mouvement = 0;
	data->generate.string_map_ber_tab = 0;
	data->generate.string_map_pathfinding = 0;
}

void	ft_start(t_data *data, char *argv)
{
	ft_init(data);

	/* extention */
	ft_map_control_extention(data, argv);
	ft_map_check_extention(data, argv);
	ft_generate_string_map(data);

	/* affichage de la MAP */
	printf("\n****\tMAP\t****\n\n%s\n\n********************\n\n", data->string_map);
	printf("x / widht = %d \ny / height = %d\n\n", data->colomn_size_win, data->row_size_win);

	/* map's content */
	ft_check_content(data);
	ft_check_surrounded_by_one(data);
	ft_check_map_is_an_rectangle(data);
}

void	ft_mlx(t_data *data)
{
/* Initialisation de MLX */
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		(ft_message_error("MLX_INIT FAIL", data));

/* Ouverture de la fenêtre en affichant le nom du programme en haut */
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->colomn_size_win, data->row_size_win, "So_long by gpeta - 2023"); // ? v2
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		ft_message_error("MLX_NEW_WINDOW FAIL", data);
	}

/* Affichage XPM selon chiffre de la map .ber */
	/* XPM */
	ft_generate_path_file(data); // ? v2

	mlx_loop_hook(data->mlx_ptr, &render_no_action, data); // ? v2

/* Bouton croix pour fermer la fenêtre */
	mlx_hook(data->win_ptr, ClientMessage, StructureNotifyMask, &ft_bouton_red_cross, data);

/* Gestion touche echap, W, A, S, D */
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &ft_key_hook, data);

/* Boucle infini qui attend des actions */
	mlx_loop(data->mlx_ptr);
}

void	ft_stop(t_data *data)
{
	int		element;

	element = 0;
	/* Fermeture fenêtre */

	mlx_destroy_image(data->mlx_ptr, data->generate.mlx_img0);
	mlx_destroy_image(data->mlx_ptr, data->generate.mlx_img1);
	mlx_destroy_image(data->mlx_ptr, data->generate.mlx_imgC);
	mlx_destroy_image(data->mlx_ptr, data->generate.mlx_imgE);
	mlx_destroy_image(data->mlx_ptr, data->generate.mlx_imgP);
	mlx_destroy_display(data->mlx_ptr);

	while (data->generate.string_map_ber_tab[element])
		free(data->generate.string_map_ber_tab[element++]);
	element = 0;
	while (data->generate.string_map_pathfinding[element])
		free(data->generate.string_map_pathfinding[element++]);
	free(data->generate.string_map_ber_tab);
	free(data->generate.string_map_pathfinding);
	free(data->string_map);
	free(data->mlx_ptr);
}