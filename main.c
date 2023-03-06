/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:01:22 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/06 17:54:09 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"
// #include "mlx.h"
#include "/mnt/nfs/homes/gpeta/Documents/CURSUS/PROJECT_so_long/so_long/minilibx-linux/mlx.h"


int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "first_windows");
	mlx_loop(mlx_ptr);

	// printf("cool\n");
	return (0);
}