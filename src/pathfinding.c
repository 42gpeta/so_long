/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:48:39 by glodi             #+#    #+#             */
/*   Updated: 2023/05/01 15:23:57 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Récupère les coordonnés de 'E' et 'P' */
void	ft_parsing(t_data *data, int letter)
{
	int	x;
	int y;

	data->gen.number_of_C_pathfinding = data->gen.number_of_C;
	y = 0;
	while (data->gen.str_tab[y])
	{
		x = 0;
		while (data->gen.str_tab[y][x])
		{
			if (data->gen.str_tab[y][x] == 'E')
			{
				data->gen.player.pos_exit_y = y;
				data->gen.player.pos_exit_x = x;
			}
			else if (data->gen.str_tab[y][x] == 'P')
			{
				data->gen.player.pos_y = y; // ? v2
				data->gen.player.pos_x = x; // ? v2
			}
			x++;
		}
		y++;
	}
	ft_pathfinding_check(data);
}

/* Place des '2' partouts */
void    ft_pathfinding_flood(t_data *data, int y, int x) // ? v2
{
    if (data->gen.str_map_pathfinding[y - 1][x] == '0' || data->gen.str_map_pathfinding[y - 1][x] == 'C')
    {
        ft_is_collectible2(data, y - 1, x);
        data->gen.str_map_pathfinding[y - 1][x] = '2';
        ft_pathfinding_flood(data, y - 1, x);
    }
    if (data->gen.str_map_pathfinding[y + 1][x] == '0' || data->gen.str_map_pathfinding[y + 1][x] == 'C')
    {
        ft_is_collectible2(data, y + 1, x);
        data->gen.str_map_pathfinding[y + 1][x] = '2';
        ft_pathfinding_flood(data, y + 1, x);
    }
    if (data->gen.str_map_pathfinding[y][x - 1] == '0' || data->gen.str_map_pathfinding[y][x - 1] == 'C')
    {
        ft_is_collectible2(data, y, x - 1);
        data->gen.str_map_pathfinding[y][x - 1] = '2';
        ft_pathfinding_flood(data, y, x - 1);
    }
    if (data->gen.str_map_pathfinding[y][x + 1] == '0' || data->gen.str_map_pathfinding[y][x + 1] == 'C')
    {
        ft_is_collectible2(data, y, x + 1);
        data->gen.str_map_pathfinding[y][x + 1] = '2';
        ft_pathfinding_flood(data, y, x + 1);
    }
}

/* Verifie si la position future est un 'C' pour str_tab */
void    ft_is_collectible1(t_data *data, int y, int x)
{
        if (data->gen.str_tab[y][x] == 'C')
            data->gen.number_of_C--;
}

/* Verifie si la position future est un 'C' pour string_map_ber_pathfinding */
void    ft_is_collectible2(t_data *data, int y, int x)
{
    if (data->gen.str_map_pathfinding[y][x] == 'C')
        data->gen.number_of_C_pathfinding--;
}

/* Regarde si entourer de 1 + si collectibles sont à 0 */
void    ft_pathfinding_check(t_data *data)
{
    int i = 0; // ! a supprimer

    if (data->gen.str_tab[data->gen.player.pos_exit_y + 1][data->gen.player.pos_exit_x] == '1'
     && data->gen.str_tab[data->gen.player.pos_exit_y - 1][data->gen.player.pos_exit_x] == '1'
     && data->gen.str_tab[data->gen.player.pos_exit_y][data->gen.player.pos_exit_x + 1] == '1'
     && data->gen.str_tab[data->gen.player.pos_exit_y][data->gen.player.pos_exit_x - 1] == '1')
             ft_message_error("No solution to exit !", data);


    // printf("ft_pathfinding_check : %i AVANT\n", data->gen.number_of_C_pathfinding);
    number_of_C_pathfinding(data, "AVANT", i); // ! a supprimer

    ft_pathfinding_flood(data, data->gen.player.pos_y, data->gen.player.pos_x);

    print_map_pathfinding(data, "ft_pathfinding_check"); // ! a supprimer

    i = 0; // ! a supprimer
    // printf("ft_pathfinding_check : %i APRES\n", data->gen.number_of_C_pathfinding); // ! a supprimer
    number_of_C_pathfinding(data, "APRES", i); // ! a supprimer


     if (data->gen.number_of_C_pathfinding != 0)
        ft_message_error("No solution to exit : all of collectibles are not consume !", data);
    printf("ft_pathfinding_check : OK !\n"); // ! a supprimer

}
