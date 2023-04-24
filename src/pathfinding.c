/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:48:39 by glodi             #+#    #+#             */
/*   Updated: 2023/04/24 20:37:07 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_flood_fill(t_data *data)
{
    
    t_data *actual;
    char **last;
    int i = 0;
    int d = 0;

    actual = data;

    last = actual->generate.string_map_ber_tab;

    last[data->generate.player.pos_y][data->generate.player.pos_x] = '2';

    // if (last[data->generate.player.pos_y - 1][data->generate.player.pos_x] == '0')
    // // || actual[actual->generate.player.pos_y + 1][actual->generate.player.pos_x] == 'C')
    // // // || actual[data->generate.player.pos_y + 1][data->generate.player.pos_x] == 'E')
    // {
    //     data->generate.player.pos_y -= 1;
    //     // data->generate.player.pos_x ;
    //     last[data->generate.player.pos_y - 1][data->generate.player.pos_x] = '2';
    //     d++;
    //     ft_flood_fill(data);
    // }
    if (last[data->generate.player.pos_y][data->generate.player.pos_x + 1] == '0')
    // || actual[actual->generate.player.pos_y + 1][actual->generate.player.pos_x] == 'C')
    // // || actual[data->generate.player.pos_y + 1][data->generate.player.pos_x] == 'E')
    {
        // data->generate.player.pos_y -= 1;
        data->generate.player.pos_x += 1;
        last[data->generate.player.pos_y][data->generate.player.pos_x + 1] = '2';
        d++;
        ft_flood_fill(data);
    }
    

    
    printf("\n****\tMAP 2\t****\n\n");
    while (last[++i])
        printf("%s\n", last[i]);
    printf("\n********************\n\n");    
}

/* Place des 2 partouts */
void    ft_pathfinding_flood(t_data *data, int y, int x)
{
    if (data->generate.string_map_pathfinding[y - 1][x] == '0' || data->generate.string_map_pathfinding[y - 1][x] == 'C')
    {
        if (data->generate.string_map_pathfinding[y - 1][x] == 'C')
            data->generate.number_of_C_pathfinding--;
        data->generate.string_map_pathfinding[y - 1][x] = '2';
        ft_pathfinding_flood(data, y - 1, x);
    }
    if (data->generate.string_map_pathfinding[y + 1][x] == '0' || data->generate.string_map_pathfinding[y + 1][x] == 'C')
    {
        if (data->generate.string_map_pathfinding[y + 1][x] == 'C')
            data->generate.number_of_C_pathfinding--;
        data->generate.string_map_pathfinding[y + 1][x] = '2';
        ft_pathfinding_flood(data, y + 1, x);
    }
    if (data->generate.string_map_pathfinding[y][x - 1] == '0' || data->generate.string_map_pathfinding[y][x - 1] == 'C')
    {
        if (data->generate.string_map_pathfinding[y][x - 1] == 'C')
            data->generate.number_of_C_pathfinding--;
        data->generate.string_map_pathfinding[y][x - 1] = '2';
        ft_pathfinding_flood(data, y, x - 1);
    }
    if (data->generate.string_map_pathfinding[y][x + 1] == '0' || data->generate.string_map_pathfinding[y][x + 1] == 'C')
    {
        if (data->generate.string_map_pathfinding[y][x + 1] == 'C')
            data->generate.number_of_C_pathfinding--;
        data->generate.string_map_pathfinding[y][x + 1] = '2';
        ft_pathfinding_flood(data, y, x + 1);
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
    
    printf("\n****\tMAP PATHFINDING\t****\n\n"); 
    while (data->generate.string_map_pathfinding[i])
        printf("%s\n", data->generate.string_map_pathfinding[i++]);
    printf("\n********************\n\n");
    
    i = 0;
    printf("ft_pathfinding_check : %i APRES\n", data->generate.number_of_C_pathfinding);
    
     if (data->generate.number_of_C_pathfinding != 0)
        ft_message_error("No solution to exit : all of collectibles are not consume !", data);
    printf("ft_pathfinding_check : OK !\n"); // ! a supprimer


}
