/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:01:22 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/10 17:16:05 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"


int main(void)		// v2 : avec structure
{
	t_vars	vars;

/* Initialisation du programme */
	vars.mlx_ptr = mlx_init();
	if (!vars.mlx_ptr)
		return (1);

/* Ouverture de la fenêtre */
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WINDOW_WIDHT, WINDOW_HEIGHT, "first_windows");
	if (!vars.mlx_ptr)
		return (1);

/* Touche echap pour fermer la fenêtre */

	mlx_hook(vars.win_ptr, KeyPress, KeyPressMask, ft_close, &vars);
	mlx_hook(vars.win_ptr, KeyRelease, KeyReleaseMask, ft_close2, &vars);

/* Bouton croix pour fermer la fenêtre */
	mlx_hook(vars.win_ptr, ClientMessage, KeyPressMask, ft_close, &vars);
	mlx_hook(vars.win_ptr, StructureNotifyMask, KeyReleaseMask, ft_close2, &vars);

/* Boucle infini qui attend des actions */
	mlx_loop(vars.mlx_ptr);

	// printf("PROG Shutdown !\n");
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