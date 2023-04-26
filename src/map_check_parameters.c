/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_parameters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:50:11 by glodi             #+#    #+#             */
/*   Updated: 2023/04/26 17:31:05 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/*** Vérification si map est entouré de '1' : haut  */
void	ft_check_surrounded_by_one_up(t_data *data) // ? v3
{
    int x;

    x = 0;
    while (data->generate.string_map_ber_tab[0][x])
    {
        if (data->generate.string_map_ber_tab[0][x] != '1')
            ft_message_error("ft_check_surrounded_by_one_up : The top side of the map isn't a wall of '1'", data);
        x++;
    }
    // printf("UP OK !\n"); // ! a supprimer
}

/*** Vérification si map est entouré de '1' : bas  */
void	ft_check_surrounded_by_one_down(t_data *data) // ? v2
{
    int x;

    x = 0;
    while (data->generate.string_map_ber_tab[data->row_size_map - 1][x])
    {
        if (data->generate.string_map_ber_tab[data->row_size_map - 1][x] != '1')
            ft_message_error("ft_check_surrounded_by_one_down : The bottom side of the map isn't a wall of '1'", data);
        x++;
    }
    // printf("DOWN OK !\n"); // ! a supprimer
}

/*** Vérification si map est entouré de '1' : gauche  */
void	ft_check_surrounded_by_one_left(t_data *data) // ? v2
{
    int y;

    y = 0;
    while (data->generate.string_map_ber_tab[y][0] && y < data->row_size_map - 1)
    {
        if (data->generate.string_map_ber_tab[y][0] != '1')
            ft_message_error("ft_check_surrounded_by_one_left : The left side of the map isn't a wall of '1'", data);
        y++;
    }
    // printf("LEFT OK !\n"); // ! a supprimer
}

/*** Vérification si map est entouré de '1' : droit  */
void	ft_check_surrounded_by_one_right(t_data *data) // ? v3
{
    int y;

    y = 0;

    if (!(data->generate.string_map_ber_tab[y][data->colomn_size_map - 1]))
        ft_message_error("ft_check_surrounded_by_one_right : The right side is smaller than the left side", data);
    while (data->generate.string_map_ber_tab[y][data->colomn_size_map] && y < data->row_size_map - 1)
    {
        if (data->generate.string_map_ber_tab[y][data->colomn_size_map] != '1')
            ft_message_error("ft_check_surrounded_by_one_right : The right side of the map isn't a wall of '1'", data);
        y++;
    }
    // printf("RIGHT OK !\n"); // ! a supprimer
}
