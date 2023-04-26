/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:48:39 by glodi             #+#    #+#             */
/*   Updated: 2023/04/26 17:26:45 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Récupère les coordonnés de 'E' et 'P' */
void	ft_parsing(t_data *data, int letter)
{
	int	x;
	int y;

	data->generate.number_of_C_pathfinding = data->generate.number_of_C;
	y = 0;
	while (data->generate.string_map_ber_tab[y])
	{
		x = 0;
		while (data->generate.string_map_ber_tab[y][x])
		{
			if (data->generate.string_map_ber_tab[y][x] == 'E')
			{
				data->generate.player.pos_exit_y = y;
				data->generate.player.pos_exit_x = x;
			}
			else if (data->generate.string_map_ber_tab[y][x] == 'P')
			{
				data->generate.player.pos_y = y; // ? v2
				data->generate.player.pos_x = x; // ? v2
			}
			x++;
		}
		y++;
	}
	printf("PLAYER POSITION : [%d][%d]\nEXIT POSITION : [%d][%d]\n", data->generate.player.pos_y, data->generate.player.pos_x, data->generate.player.pos_exit_y, data->generate.player.pos_exit_x); // ! a supprimer
	ft_pathfinding_check(data);
}

/* Place des '2' partouts */
void    ft_pathfinding_flood(t_data *data, int y, int x) // ? v2
{
        ft_pathfinding_flood_y(data, y, x);
        ft_pathfinding_flood_x(data, y, x);
}

/* Place des '2' partouts : y */
void    ft_pathfinding_flood_y(t_data *data, int y, int x)
{
    if (data->generate.string_map_pathfinding[y - 1][x] == '0' || data->generate.string_map_pathfinding[y - 1][x] == 'C')
    {
        if (data->generate.string_map_pathfinding[y - 1][x] == 'C')
            data->generate.number_of_C_pathfinding--;
        data->generate.string_map_pathfinding[y - 1][x] = '2';
        ft_pathfinding_flood_y(data, y - 1, x);
    }
    if (data->generate.string_map_pathfinding[y + 1][x] == '0' || data->generate.string_map_pathfinding[y + 1][x] == 'C')
    {
        if (data->generate.string_map_pathfinding[y + 1][x] == 'C')
            data->generate.number_of_C_pathfinding--;
        data->generate.string_map_pathfinding[y + 1][x] = '2';
        ft_pathfinding_flood_y(data, y + 1, x);
    }
}

/* Place des '2' partouts : x */
void    ft_pathfinding_flood_x(t_data *data, int y, int x)
{
    if (data->generate.string_map_pathfinding[y][x - 1] == '0' || data->generate.string_map_pathfinding[y][x - 1] == 'C')
    {
        if (data->generate.string_map_pathfinding[y][x - 1] == 'C')
            data->generate.number_of_C_pathfinding--;
        data->generate.string_map_pathfinding[y][x - 1] = '2';
        ft_pathfinding_flood_x(data, y, x - 1);
    }
    if (data->generate.string_map_pathfinding[y][x + 1] == '0' || data->generate.string_map_pathfinding[y][x + 1] == 'C')
    {
        if (data->generate.string_map_pathfinding[y][x + 1] == 'C')
            data->generate.number_of_C_pathfinding--;
        data->generate.string_map_pathfinding[y][x + 1] = '2';
        ft_pathfinding_flood_x(data, y, x + 1);
    }
}

/* Regarde si entourer de 1 + si collectibles sont à 0 */
void    ft_pathfinding_check(t_data *data)
{
    int i = 0; // ! a supprimer

    if (data->generate.string_map_ber_tab[data->generate.player.pos_exit_y + 1][data->generate.player.pos_exit_x] == '1'
     && data->generate.string_map_ber_tab[data->generate.player.pos_exit_y - 1][data->generate.player.pos_exit_x] == '1'
     && data->generate.string_map_ber_tab[data->generate.player.pos_exit_y][data->generate.player.pos_exit_x + 1] == '1'
     && data->generate.string_map_ber_tab[data->generate.player.pos_exit_y][data->generate.player.pos_exit_x - 1] == '1')
             ft_message_error("No solution to exit !", data);


    printf("ft_pathfinding_check : %i AVANT\n", data->generate.number_of_C_pathfinding);

    ft_pathfinding_flood(data, data->generate.player.pos_y, data->generate.player.pos_x);

    printf("\n****\tMAP PATHFINDING\t****\n\n"); // ! a supprimer
    while (data->generate.string_map_pathfinding[i]) // ! a supprimer
        printf("%s\n", data->generate.string_map_pathfinding[i++]); // ! a supprimer
    printf("\n********************\n\n"); // ! a supprimer

    i = 0; // ! a supprimer
    printf("ft_pathfinding_check : %i APRES\n", data->generate.number_of_C_pathfinding); // ! a supprimer

     if (data->generate.number_of_C_pathfinding != 0)
        ft_message_error("No solution to exit : all of collectibles are not consume !", data);
    printf("ft_pathfinding_check : OK !\n"); // ! a supprimer


}
