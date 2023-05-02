/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:38:54 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/02 19:55:15 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_data *data)
{
	if (data->win_p != NULL)
		ft_display_xpm(data);
	return (0);
}

/** Close the window when you click on red cross's bouton */
int	ft_bouton_red_cross(t_data *data)
{
	mlx_destroy_window(data->mlx_p, data->win_p);
	data->win_p = NULL;
	return (0);
}

/** Action when you tap bouton W,A,S or D */
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
	mlx_destroy_window(data->mlx_p, data->win_p);
	data->win_p = NULL;
}

void	ft_print_informations(t_data *data)
{
	ft_printf("-------------\n");
	ft_printf("Number of movements : %d\n", data->gen.man.nb_move);
	if (data->gen.number_of_c > 1)
		ft_printf("%d collectibles left\n", data->gen.number_of_c);
	else if (data->gen.number_of_c > 0)
		ft_printf("%d collectible left\n", data->gen.number_of_c);
	else
		ft_printf("Now, you can go :)\n");
	if (data->gen.man.y == data->gen.exit.y
		&& data->gen.man.x == data->gen.exit.x
		&& data->gen.number_of_c == 0)
		ft_printf("\n***\nYou finish !\n***\n\n");
}
