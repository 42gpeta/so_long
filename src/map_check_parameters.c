/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_parameters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:50:11 by glodi             #+#    #+#             */
/*   Updated: 2023/04/01 18:56:12 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_surrounded_by_one_up(t_generate *generate, t_data *data)
{
    int x;

    x = 0;
    while (generate->string_map_ber_tab[0][x])
    {
        if (generate->string_map_ber_tab[0][x] != '1')
            ft_message_error("The top side of the map isn't a wall of '1'", data, generate);
        x++;   
    }
    printf("UP OK !\n");
}


void	ft_check_surrounded_by_one_down(t_generate *generate, t_data *data)
{
    int x;

    x = 0;
    while (generate->string_map_ber_tab[data->row_size_map - 1][x])
    {
        if (generate->string_map_ber_tab[data->row_size_map - 1][x] != '1')
            ft_message_error("The bottom side of the map isn't a wall of '1'", data, generate);
        x++;
    }
    printf("DOWN OK !\n");
}


void	ft_check_surrounded_by_one_left(t_generate *generate, t_data *data)
{
    int y;

    y = 0;
    while (generate->string_map_ber_tab[y][0] && y < data->row_size_map - 1)
    {
        if (generate->string_map_ber_tab[y][0] != '1')
            ft_message_error("The left side of the map isn't a wall of '1'", data, generate);
        y++;
    }
    printf("LEFT OK !\n");
}


void	ft_check_surrounded_by_one_right(t_generate *generate, t_data *data)
{
    int y;

    y = 0;
    printf("ft_check_surrounded_by_one_right :\ndernier élément : %d\n", data->colomn_size_map - 1);
    printf("ft_check_surrounded_by_one_right :\n%s\ndernier élément : %ld\n", generate->string_map_ber_tab[1] ,ft_strlen(generate->string_map_ber_tab[1]));
    printf("ft_check_surrounded_by_one_right :\ndernier char : %c\n", generate->string_map_ber_tab[1][36]);
    while (generate->string_map_ber_tab[y][data->colomn_size_map - 2] && y < data->row_size_map - 1)
    {
        if (generate->string_map_ber_tab[y][data->colomn_size_map - 2] != '1')
            ft_message_error("The right side of the map isn't a wall of '1'", data, generate);
        y++;
    }
    printf("RIGHT OK !\n");
}

