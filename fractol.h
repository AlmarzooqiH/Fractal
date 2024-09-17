/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:30:39 by h                 #+#    #+#             */
/*   Updated: 2024/09/17 22:59:57 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*                                                             
 mmmmmmmm  mmmmmm       mm        mmmm   mmmmmmmm    mmmm    mm       
 ##""""""  ##""""##    ####     ##""""#  """##"""   ##""##   ##       
 ##        ##    ##    ####    ##"          ##     ##    ##  ##       
 #######   #######    ##  ##   ##           ##     ##    ##  ##       
 ##        ##  "##m   ######   ##m          ##     ##    ##  ##       
 ##        ##    ##  m##  ##m   ##mmmm#     ##      ##mm##   ##mmmmmm 
 ""        ""    """ ""    ""     """"      ""       """"    """""""" 
*/

/*
Mandelbrot set fractal equation:

Z(n + 1) = (Z(n))^2 + C
Zn: Complex Number
C: Complex Number
Complex Number: a + bi

(Z(n))^2 = (a + bi)^2 = a^2 + 2abi - b^2
Final Equation: (a^2 +2abi - b^2) + C
But remmember Mandelbrot set starts at (Z(n))^2 = 0
*/

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft/libft.h"

# ifdef __linux__
#  include "minilibx-linux/mlx.h"
#  define ESC 65307
#  define LEFT 65361
#  define UP 65362
#  define RIGHT 65363
#  define DOWN 65364
#  define MINUS 45
#  define PLUS 61
#  define ZOOMIN 4
#  define ZOOMOUT 5
#  define R 114
#  define ONE 49
#  define TWO 50
#  define THREE 51
#  define FOUR 52
# endif
# ifdef APPLE
#  include "minilibx/mlx.h"
#  define ESC 27
#  define LEFT 37
#  define UP 38
#  define RIGHT 39
#  define DOWN 40
#  define MINUS 189
#  define PLUS 187
# endif

//Macros
# define FRACTOL "Fractol\0"
# define MANDELBROT "mandelbrot"
# define JULIA "julia\0"
# define WIDTH 800
# define HEIGHT 800
# define RPX 2
# define RNX -2
# define IPY 2.5
# define INY -2.5
# define RED 0xFF0000
# define GREEN 0x00BF00
# define BLUE 0x0000FF
# define BLACK 0x000000
# define ROYALE_BLUE 0x4169E1
# define ORANGE 0xc2772d
# define YELLOW 0xFFFF00

//Error Macros
# define INPUT_ERROR "Input Error\n\0"
# define SOMETHING_WENT_WRONG "Something went wrong\n\0"
# define WRONG_FRACTALS "Wrong fractal name chose\nMandelbrot, julia\n\0"
# define JULIA_WRONG_FORMAT "Wrong formatting of the julia set\n\0"

//Structs
/*
	@brief		This struct represents a complex number.
	@var	a	Represents the real part of the complex number.
	@var	b	Represents the imaginary part of the complex number.
*/
typedef struct s_complex
{
	double	a;
	double	b;
}	t_complex;

/*
	@brief 			This struct holds most of the program requirements.
	@var	mlx		This holds the mlx pointer.
	@var	win		This holds the window pointer.
	@var	img		This holds the image pointer.
	@var	imgd	This holds the image pixel data which will be used to mod-
					-ify the pixel values later on.

	@var	fractal	This will hold the type of fractal we will draw.			
	@var	x		The x position on the image.
	@var	y		The y position on the image.
	@var	bpp		Bits per pixel holds the number of bits per pixel.
	@var	sl		Size line will hold the number of bytes per line.

	@var	edn		The endian will store a value 1(Big endian) or 0 (Small e-
					-ndian) which tell's us how the data is stored in memory.

	@var	cycles	This will be the number of times we compute each point to
					ensure the accuracy of the fractal.

	@var	fc		This will hold the current point color of the fractal.
	@var	zoom	This will hold the zoom in/out factor of the fractal.
	@var	zoom_x	This will hold the X position of the mouse pointer.
	@var	zoom_y	This will hold the Y position of the mouse pointer.
	@var	move_x	This will be used to move around using the key arrows;
	@var	move_y	This will be used to move around using the key arrows;
	@var	range_x	This will hold the range of the real plane RPX - RNX.
	@var	range_y	This will hold the range of the complex plane IPY - INX.
	@var	zn		A complex number.
	@var	c		A complex number.
*/
typedef struct s_prog
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*imgd;
	char		fractal;
	int			x;
	int			y;
	int			bpp;
	int			sl;
	int			edn;
	int			cycles;
	int			fc;
	double		zoom;
	double		zoom_x;
	double		zoom_y;
	double		move_x;
	double		move_y;
	double		range_x;
	double		range_y;
	t_complex	zn;
	t_complex	c;
}	t_prog;

//Function Prototypes
int				close_program(void *param);
int				key_hook(int keycode, void *param);
int				mouse_hook(int button, int x, int y, void *param);
void			init(t_prog *p);
void			init_2(t_prog *p);
int				has_escaped(t_complex *zn);
double			getx(t_prog *p);
double			gety(t_prog *p);
void			hook(t_prog *p);
void			mandelbrot(t_prog *p);
void			julia(t_prog *p);
void			fractal(t_prog *p);
void			init_complex(t_complex *p, double a, double bi);
void			square_complex(t_complex *zn);
void			add_complex(t_complex *zn, t_complex c);
void			check_args(int ac, char **av);
void			check_fractal(t_prog *p, int ac, char **av);
void			doi(t_prog *p);
void			get_c(t_prog *p, int ac, char **av);
#endif
