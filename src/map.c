/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:01:31 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/21 17:50:16 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// char	*ft_map_control_extention(char *filename, char *av)
void	ft_map_control_extention(char *filename, char **av)
{
	int i;
	int len;
	char *endfile;
	if (*av[1])
	{
		filename = av[1];
		printf("filename : OK\n");	
	}
	else
		printf("filename : EMPTY\n");	
	
	// len = ft_strlen(filename) - 4;
	// endfile = malloc(sizeof(char) * (4 + 1));
	// if (!endfile)
	// 	return (NULL);
	// i = 0;
	// while (filename[len] != '\0')
	// {
	// 	endfile[i] = filename[len];
	// 	i++;
	// 	len++;
	// }
	// endfile[i] = '\0';
	// // printf("Extension = %s", endfile);
	// return (endfile);
}
