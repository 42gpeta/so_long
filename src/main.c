/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:01:22 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/15 19:15:05 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/so_long.h"
#include "so_long.h"


int main(int ac, char **av)		// v2 : avec structure
{
	t_data	data;
	// t_data	img;

/* Initialisation du programme */
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		(ft_message_error_mlx_init("MLX_INIT FAIL"));

/* Ouverture de la fenêtre en affichant le nom du programme en haut */
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDHT, WINDOW_HEIGHT, av[0]);
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		(ft_message_error_mlx_init("MLX_NEW_WINDOW FAIL"));
	}

/* Création d'une image */
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDHT, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);

/* Permet de arrêter le programme si on ne met pas de 'mlx_loop_hook'  */
	// mlx_loop_hook(data.mlx_ptr, &ft_no_event, &data);

/* Print d'un pixel */
	mlx_loop_hook(data.mlx_ptr, &render, &data);

/* Bouton croix pour fermer la fenêtre */
	mlx_hook(data.win_ptr, ClientMessage, StructureNotifyMask, &ft_close_red_cross, &data);

/* Touche echap pour fermer la fenêtre */
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &ft_close_keypress, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &ft_close_release, &data);

/* Boucle infini qui attend des actions */
	mlx_loop(data.mlx_ptr);

/* Fermeture fenêtre */
	// mlx_destroy_image(data.mlx_ptr, img.img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);


	return (0);
}


/* int main(void)		// v1 : sans structure
{
	void	*mlx_ptr;
	void	*win_ptr;

// ** Initialisation du programme **
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);

// ** Ouverture de la fenêtre **
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "first_windows");
	if (!win_ptr)
		return (1);

// ** Nettoyage de fenêtre **
	



// ** Boucle infini qui attend des actions **
	mlx_loop(mlx_ptr);

	// printf("cool\n");
	return (0);
} */