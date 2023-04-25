/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:36:58 by gpeta             #+#    #+#             */
/*   Updated: 2023/04/25 14:45:30 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	ft_message_error(char *message) // ? v1
// {
// 	write(1, "Error\n", 6);
// 	write(1, message, ft_strlen(message));
// 	write(1, "\n", 1);
// 	exit(EXIT_FAILURE);
// }

// void	ft_message_error(char *message, t_data *data, t_generate *generate) // ? v2
// {
// 	int	i = 0;
// 	write(1, "Error\n", 6);
// 	write(1, message, ft_strlen(message));
// 	write(1, "\n", 1);
// 	if (generate->map.up)
// 		free(generate->map.up);
// 	// if (generate->map.down)
// 		// free(generate->map.down);
// 	// while (generate->string_map_ber_tab[i])
// 	// 	free(generate->string_map_ber_tab[i++]);
// 	// if (generate->string_map_ber_tab)
// 	// 	free(generate->string_map_ber_tab);
// 	if (data->string_map/*  != NULL */)
// 		free(data->string_map);
// 	if (data->mlx_ptr/*  != NULL */)
// 		free(data->mlx_ptr);
// 	exit(EXIT_FAILURE);
// }

// void	ft_message_error(char *message, t_data *data, t_generate *generate) // ? v3
// {
// 	int	i = 0;

// 	i = 0;
// 	write(1, "Error\n", 6);
// 	write(1, message, ft_strlen(message));
// 	write(1, "\n\n", 2);
// 	if (generate->fd > 0 && generate->fd < 1024)
// 	{
// 		while (generate->string_map_ber_tab && generate->string_map_ber_tab[i] != NULL)
// 			free(generate->string_map_ber_tab[i++]);
// 			// free(generate->string_map_ber_tab[++i]);
// 		if (generate->string_map_ber_tab)
// 			free(generate->string_map_ber_tab);
// 	}
// 	// if (generate->string_map_ber_tab && generate->string_map_ber_tab[0][0] == '1'/*  != NULL */)
// 	// 	free(generate->string_map_ber_tab);
// 	// while (generate->string_map_ber_tab && generate->string_map_ber_tab[i] != NULL)
// 	// 	free(generate->string_map_ber_tab[i++]);	
	
// 	i = 0;
// 	// if (data->string_map[0] != '1')
// 	if (data->string_map)
// 	{
// 		free(data->string_map);
// 		// data->string_map = 0;
// 		// free(data);
// 	}
// 	// free(data->string_map);
	
// 	if (data->mlx_ptr/*  != NULL */)
// 		free(data->mlx_ptr);
// 	exit(EXIT_FAILURE);
// }

void	ft_message_error(char *message, t_data *data) // ? v5
{
	int	i = 0;

	i = 0;
	write(1, "Error\n", 6);
	write(1, message, ft_strlen(message));
	write(1, "\n\n", 2);
	if (data->generate.fd > 0 && data->generate.fd < 1024)
	{
		while (data->generate.string_map_ber_tab && data->generate.string_map_ber_tab[i] != NULL)
			free(data->generate.string_map_ber_tab[i++]);
			// free(data->generate.string_map_ber_tab[++i]);
		if (data->generate.string_map_ber_tab)
			free(data->generate.string_map_ber_tab);
		i = 0;
		while (data->generate.string_map_pathfinding && data->generate.string_map_pathfinding[i] != NULL)
			free(data->generate.string_map_pathfinding[i++]);
			// free(data->generate.string_map_pathfinding[++i]);
		if (data->generate.string_map_pathfinding)
			free(data->generate.string_map_pathfinding);
	}
	if (data->string_map)
	{
		free(data->string_map);
	}

	if (data->mlx_ptr/*  != NULL */)
		free(data->mlx_ptr);
	exit(EXIT_FAILURE);
}