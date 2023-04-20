/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:48:39 by glodi             #+#    #+#             */
/*   Updated: 2023/04/21 00:26:00 by glodi            ###   ########.fr       */
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

