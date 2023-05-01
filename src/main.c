/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:01:22 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/01 18:04:33 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	ft_start(&data, av[1]);
	ft_mlx(&data);
	ft_stop(&data);
	return (0);
}


void print_map_pathfinding(t_data * data, char *name) // ! a supprimer
{
    int i = 0; // ! a supprimer

	    printf("\n****\tMAP %s\t****\n\n", name); // ! a supprimer
    while (data->gen.str_map_pathfinding[i]) // ! a supprimer
        printf("%s\n", data->gen.str_map_pathfinding[i++]); // ! a supprimer
    printf("\n********************\n\n"); // ! a supprimer
}

void print_map(t_data * data) // ! a supprimer
{
	printf("\n****\tMAP\t****\n\n%s\n\n********************\n\n", data->str_map);
	printf("x / widht = %d \ny / height = %d\n\n", data->colomn_size_win, data->row_size_win);

}

void player_position(t_data *data) // ! a supprimer
{
	printf("PLAYER POSITION : [%d][%d]\n", data->gen.man.y, data->gen.man.x); // ! a supprimer
	printf("EXIT POSITION : [%d][%d]\n", data->gen.man.pos_exit_y, data->gen.man.pos_exit_x); // ! a supprimer
}

void number_of_C_pathfinding(t_data *data, char *time, int i) // ! a supprimer
{
    printf("number of C in ft_pathfinding_check : %i %s\n\n", data->gen.number_of_C_pathfinding, time);
}
