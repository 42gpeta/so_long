/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:20:36 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/18 16:48:44 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "math.h"

/* Replace mlx_pixel_put */
void	img_pix_put(t_img *img, int x, int y, int color) // v1
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

// void	img_pix_put(t_img *img, int x, int y, int color) // v2
// {
// 	char	*pixel;
// 	int		i;

// 	i = img->bpp - 8;
// 	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
// 	while (i >= 0)
// 	{
// 		if (img->endian != 0)
// 			*pixel++ = (color >> i) & 0xFF;
// 		else
// 			*pixel++ = (color >> (img ->bpp - 8 - i)) & 0xFF;
// 		i-= 8;
// 	}
// }

/* int	color_map_2(unsigned char *data,int bpp,int sl,int w,int h,int endian, int type) // originale
{
  int	x;
  int	y;
  int	opp;
  int	dec;
  int	color;
  int	color2;
  unsigned char *ptr;

  opp = bpp/8;
  printf("(opp : %d) ",opp);
  y = h;
  while (y--)
    {
      ptr = data+y*sl;
      x = w;
      while (x--)
        {
	  if (type==2)
	    color = (y*255)/w+((((w-x)*255)/w)<<16)
	      +(((y*255)/h)<<8);
	  else
	    color = (x*255)/w+((((w-x)*255)/w)<<16)+(((y*255)/h)<<8);
          color2 = mlx_get_color_value(mlx,color);
	  dec = opp;
	  while (dec--)
	    if (endian==local_endian)
	      {
		if (endian)
		  *(ptr+x*opp+dec) = ((unsigned char *)(&color2))[4-opp+dec];
		else
		  *(ptr+x*opp+dec) = ((unsigned char *)(&color2))[dec];
	      }
	    else
	      {
		if (endian)
		  *(ptr+x*opp+dec) = ((unsigned char *)(&color2))[opp-1-dec];
		else
		  *(ptr+x*opp+dec) = ((unsigned char *)(&color2))[3-dec];
	      }
        }
    }

} */

/* int	color_map_2(unsigned char *data,int bpp,int sl,int w,int h,int endian, int type) // custom
{
  int	x;
  int	y;
  int	opp;
  int	dec;
  int	color;
  int	color2;
  unsigned char *ptr;

  opp = bpp/8;
  printf("(opp : %d) ",opp);
  y = h;
  while (y--)
    {
      ptr = data+y*sl;
      x = w;
      while (x--)
        {
	  if (type==2)
	    color = (y*255)/w+((((w-x)*255)/w)<<16)
	      +(((y*255)/h)<<8);
	  else
	    color = (x*255)/w+((((w-x)*255)/w)<<16)+(((y*255)/h)<<8);
          color2 = mlx_get_color_value(mlx,color);
	  dec = opp;
	  while (dec--)
	    if (endian==local_endian)
	      {
		if (endian)
		  *(ptr+x*opp+dec) = ((unsigned char *)(&color2))[4-opp+dec];
		else
		  *(ptr+x*opp+dec) = ((unsigned char *)(&color2))[dec];
	      }
	    else
	      {
		if (endian)
		  *(ptr+x*opp+dec) = ((unsigned char *)(&color2))[opp-1-dec];
		else
		  *(ptr+x*opp+dec) = ((unsigned char *)(&color2))[3-dec];
	      }
        }
    }

} */
