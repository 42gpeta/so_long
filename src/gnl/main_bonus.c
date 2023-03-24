/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:50:28 by gpeta             #+#    #+#             */
/*   Updated: 2023/02/22 18:05:26 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	// int		fd[2];
	int		fd1;
	int		fd2;
	int		index;
	char	*line1;
	char	*line2;

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
	// fd = open("./fichiers/alternate_line_nl_with_nl", O_RDONLY);
	fd1 = open("./fichiers/file1", O_RDONLY);
	fd2 = open("./fichiers/file2", O_RDONLY);

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

	line1 = 0;
	line1 = get_next_line(fd1);

	line2 = 0;
	line2 = get_next_line(fd2);

	if (line1 == NULL)
	{
		// line = get_next_line(fd);
		printf("line1 : c'est NULL 1\n");
	}
	if (line2 == NULL)
	{
		// line = get_next_line(fd);
		printf("line2 : c'est NULL 1\n");
	}
	while (line1 || line2 /* && index < 1 */)
	{
		printf("line1 [%da] : %s\n", index, line1);
		free(line1);
		line1 = get_next_line(fd1);
		if (line1 == NULL)
		{
			// line = get_next_line(fd);
			printf("line1 : c'est NULL 2\n");
			// break;
		}

		printf("line2 [%db] : %s\n", index, line2);
		free(line2);
		line2 = get_next_line(fd2);
		if (line2 == NULL)
		{
			// line = get_next_line(fd);
			printf("line2 : c'est NULL 2\n");
			break;
		}
		index++;
	}
	free(line1);
	free(line2);

	if (close(fd1) == -1)
	{
		printf("close() fail : %d\n", fd1);
		return (1);
	}
	else
		printf("close() succes : %d\n", fd1);
	
	if (close(fd2) == -1)
	{
		printf("close() fail : %d\n", fd2);
		return (1);
	}
	else
		printf("close() succes : %d\n", fd2);
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
