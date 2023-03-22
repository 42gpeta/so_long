/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:01:31 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/22 16:03:56 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_map_control_extention(char *filename, char *filename_main)
{
	int i;
	int len;
	char *endfile;

	if (filename == NULL)
	{
		filename = filename_main;
		printf("** filename du main\n"); // a supprimer
	}

	len = ft_strlen(filename) - 4;
	endfile = malloc(sizeof(char) * (4 + 1));
	if (!endfile)
		return (NULL);
		// exit(EXIT_FAILURE);
	i = 0;

	printf("Filename = %s\n", filename);
	while (filename[len] != '\0')
	{
		endfile[i] = filename[len];
		i++;
		len++;
	}
	endfile[i] = '\0';
	return (endfile);
}

int	ft_map_check_extention(char *filename, char *filename_main)
{
	char	*file;
	char	*extension;
	int		result;

	extension = ".ber";
	file = ft_map_control_extention(filename, filename_main);
	result = ft_strncmp(extension, file, 4);

	if(result == 0)
		printf("STRNCMP s1 == s2 : (%d)\nextension : %s | file : %s\n", result, extension, file); // a supprimer
	else
		printf("STRNCMP s1 != s2 : (%d)\nextension : %s | file : %s\n", result, extension, file); // a supprimer

	free(file);
	return (1);
}
