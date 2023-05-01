/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:38:54 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/01 17:05:45 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** Close the window when you click on red cross's bouton */
int	ft_bouton_red_cross(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	return (0);
}

/** Action when you tap bouton W,A,S and D */
int	ft_key_hook(int key_symbol, t_data *data)
{
	if (key_symbol == 65307)
		ft_escape_key(data);
	else if (key_symbol == XK_w)
		ft_move_up(data);
	else if (key_symbol == XK_a)
		ft_move_left(data);
	else if (key_symbol == XK_s)
		ft_move_down(data);
	else if (key_symbol == XK_d)
		ft_move_right(data);
	ft_print_informations(data);
	return (key_symbol);
}

/* Destroy window when you press 'esc' */
void	ft_escape_key(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
}

int	render_no_action(t_data *data)
{
	if (data->win_ptr != NULL)
	{
		// mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 50, WHITE_PIXEL, "TEST COMPTEUR"); // TODO afficher le compteur sur l'écran
		ft_generate_xpm(data);
	}
	return (0);
}

void	ft_print_informations(t_data *data)
{
	ft_printf("-------------\n");
	ft_printf("Number of movements : %d\n", data->gen.player.nb_move);
	if (data->gen.number_of_C > 0)
		ft_printf("%d collectibles left\n", data->gen.number_of_C);
	else
		ft_printf("Now, you can go :)\n");
	
	if (data->gen.player.pos_y == data->gen.player.pos_exit_y
		&& data->gen.player.pos_x == data->gen.player.pos_exit_x
		&& data->gen.number_of_C == 0)
		ft_printf("\n***\nYou finish !\n***\n\n");
}
