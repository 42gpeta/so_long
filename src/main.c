/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:01:22 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/04 14:21:17 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	ft_start(&data, av[1], ac);
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