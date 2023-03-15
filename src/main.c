/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:01:22 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/15 14:53:51 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/so_long.h"
#include "so_long.h"


int main(int ac, char **av)		// v2 : avec structure
{
	t_vars	vars;
	t_data	img;

/* Initialisation du programme */
	vars.mlx_ptr = mlx_init();
	if (vars.mlx_ptr == NULL)
		(ft_message_error_mlx_init("MLX_INIT FAIL"));

/* Ouverture de la fenêtre en affichant le nom du programme en haut */
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WINDOW_WIDHT, WINDOW_HEIGHT, av[0]);
	if (vars.win_ptr == NULL)
	{
		free(vars.win_ptr);
		(ft_message_error_mlx_init("MLX_NEW_WINDOW FAIL"));
	}

/* Affichage d'un pixel */
	// img.img = mlx_new_image(vars.mlx_ptr, 1920, 1080);

	mlx_loop_hook(vars.mlx_ptr, &ft_no_event, &vars);
/* Bouton croix pour fermer la fenêtre */
	mlx_hook(vars.win_ptr, ClientMessage, StructureNotifyMask, &ft_close_red_cross, &vars);

/* Touche echap pour fermer la fenêtre */
	mlx_hook(vars.win_ptr, KeyPress, KeyPressMask, &ft_close_keypress, &vars);
	mlx_hook(vars.win_ptr, KeyRelease, KeyReleaseMask, &ft_close_release, &vars);

/* Boucle infini qui attend des actions */
	mlx_loop(vars.mlx_ptr);

/* Fermeture fenetre */
	// mlx_destroy_image(vars.mlx_ptr, img.img);
	mlx_destroy_display(vars.mlx_ptr);
	free(vars.mlx_ptr);


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