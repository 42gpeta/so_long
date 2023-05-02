/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:01:22 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/02 20:34:02 by gpeta            ###   ########.fr       */
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

void	print_map(t_data *data) // ! a supprimer
{
	printf("\n****\tMAP\t****\n\n%s\n\n********************\n\n", data->str_map);
	printf("x / widht = %d \ny / height = %d\n\n",
		data->colomn_size_win, data->row_size_win);
}

void	player_position(t_data *data) // ! a supprimer
{
	printf("PLAYER POSITION : [%d][%d]\n", data->gen.man.y, data->gen.man.x);
	printf("EXIT POSITION : [%d][%d]\n", data->gen.exit.y, data->gen.exit.x);
}

void	print_map_pathfinding(t_data *data, char *name) // ! a supprimer
{
	int	i;

	i = 0;
	printf("\n****\tMAP %s\t****\n\n", name);
	while (data->gen.str_map_pathfinding[i])
		printf("%s\n", data->gen.str_map_pathfinding[i++]);
	printf("\n********************\n\n");
}

void	print_nb_of_c_pathfinding(t_data *data, char *time, int i) // ! a supprimer
{
	i = 0;
	printf("number of C in ft_pathfinding_check : %i %s\n\n", data->gen.number_of_c_pathfinding, time);
}
