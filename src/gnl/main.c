/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:50:28 by gpeta             #+#    #+#             */
/*   Updated: 2023/02/21 18:20:04 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		index;
	char	*line;

	// fd = open("./test/simple.txt", O_RDONLY);
	// fd = open("./test/lorem.txt", O_RDONLY);
	// fd = open("./test/biglorem.txt", O_RDONLY);

	// fd = open("./fichiers/41_no_nl", O_RDONLY);
	// fd = open("./fichiers/41_with_nl", O_RDONLY); // error : derniere ligne ne s'affiche pas
	// fd = open("./fichiers/42_no_nl", O_RDONLY);
	// fd = open("./fichiers/42_with_nl", O_RDONLY);
	// fd = open("./fichiers/43_no_nl", O_RDONLY);
	// fd = open("./fichiers/43_with_nl", O_RDONLY);

	// fd = open("./fichiers/alternate_line_nl_no_nl", O_RDONLY);
	fd = open("./fichiers/alternate_line_nl_with_nl", O_RDONLY);

	// fd = open("./fichiers/big_line_no_nl", O_RDONLY);
	// fd = open("./fichiers/big_line_with_nl", O_RDONLY);
	// fd = open("./fichiers/empty", O_RDONLY);
	// fd = open("./fichiers/multiple_line_no_nl", O_RDONLY);
	// fd = open("./fichiers/multiple_line_with_nl", O_RDONLY);
	// fd = open("./fichiers/multiple_nlx5", O_RDONLY);
	// fd = open("./fichiers/nl", O_RDONLY);

	// fd = 0;
	// if (fd == -1)
	// {
	// 	printf("open() fail\n");
	// 	return (1);
	// }

	index = 0;
	line = 0;
	line = get_next_line(fd);
	// line = get_next_line(fd);
	if (line == NULL)
	{
		// line = get_next_line(fd);
		printf("c'est NULL 1\n");
	}
	while (line /* && index < 1 */)
	{
		if (!line)
			break;
		printf("[%d] : %s\n", index, line);
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
		{
			// line = get_next_line(fd);
			printf("c'est NULL 2\n");
			break;
		}
		index++;
	}
	free(line);

	if (close(fd) == -1)
	{
		printf("close() fail : %d\n", fd);
		return (1);
	}
	else
		printf("close() succes : %d\n", fd);
	return (0);
}

// int main (void) // Aya
// {
// 	char	*str;
// 	int		fd;

// 	fd = open("./tripouille/files/41_with_nl", O_RDONLY);
// 	str = get_next_line(fd);
// 	while (str != NULL)
// 	{
// 		printf("%s\n", str);
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// 	close(fd);
// }
