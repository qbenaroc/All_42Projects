/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_define.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbenaroc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 22:14:37 by qbenaroc          #+#    #+#             */
/*   Updated: 2019/03/05 23:18:40 by qbenaroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DEFINE_H
# define FDF_DEFINE_H

/*
** Screen
*/

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define ORT 0
# define ISO 1

# define FALSE 0
# define TRUE 1

/*
** Inputs
*/

# define ESC 53
# define SPACE 49
# define W 13
# define A 0
# define S 1
# define D 2
# define Q 12
# define E 14
# define R 15
# define P 35
# define M 46
# define L 37
# define H 4
# define MORE 69
# define LESS 78
# define UP_A 126
# define DWN_A 125
# define L_A 123
# define R_A 124
# define ONE 18
# define TWO 19
# define THREE 20
# define FOUR 21
# define FIVE 23
# define SIX 22
# define SEVEN 26
# define EIGHT 28
# define NINE 25
# define ZERO 29

# define KEY_NBR 18 || 19 || 20 || 21 || 23 || 22 || 26 || 28 || 25 || 29

/*
** Basic colors
*/

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define ORANGE 0xFFA500
# define LIME 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define SILVER 0xC0C0C0
# define GRAY 0x808080
# define MAROON 0x800000
# define OLIVE 0x808000
# define GREEN 0x008000
# define PURPLE 0x800080
# define TEAL 0x008080
# define NAVY 0x000080

/*
** More awesome colors!
*/

# define CRIMSON 0xDC143C
# define CORAL 0xFF7F50
# define INDIAN_RED 0xCD5C5C
# define SALMON 0xFA8072
# define ORANGE_RED 0xFF4500
# define GOLD 0xFFD700
# define GOLDEN_ROD 0xDAA520
# define SADDLEBROWN 0x8B4513
# define LAWN_GREEN 0x7CFC00
# define DARK_GREEN 0x006400
# define FOREST_GREEN 0x228B22
# define PALE_GREEN 0x98FB98
# define SPRING_GREEN 0x00FF7F
# define SEA_GREEN 0x2E8B57
# define LIGHT_SEA_GREEN 0x20B2AA
# define DARK_SLATE_GRAY 0x2F4F4F
# define POWDER_BLUE 0xB0E0E6
# define AQUA_MARINE 0x7FFFD4
# define STEEL_BLUE 0x4682B4
# define SKY_BLUE 0x87CEEB
# define MIDNIGHT_BLUE 0x191970
# define INDIGO 0x4B0082
# define DARK_MAGENTA 0x8B008B
# define DEEP_PINK 0xFF1493
# define HOT_PINK 0xFF69B4
# define ORCHID 0xFF83FA
# define BEIGE 0xF5F5DC
# define ANTIQUE_WHITE 0xFAEBD7
# define WHEAT 0xF5DEB3
# define CORN_SILK 0xFFF8DC
# define LAVENDER 0xE6E6FA
# define FLORAL_WHITE 0xFFFAF0
# define ALICE_BLUE 0xF0F8FF
# define GHOST_WHITE 0xF8F8FF
# define HONEYDEW 0xF0FFF0
# define IVORY 0xFFFFF0
# define AZURE 0xF0FFFF
# define SNOW 0xFFFAFA
# define MISTY_ROSE 0xFFE4E1
# define DARK_GRAY 0x696969
# define GAINSBORO 0xDCDCDC
# define WHITE_SMOKE 0xF5F5F5

/*
** Points Index
*/

# define INDEX_PT (fdf->map.y * fdf->map.nbcol + fdf->map.x)
# define NEXT_PT_L (fdf->map.y * fdf->map.nbcol + fdf->map.x + 1)
# define NEXT_PT_C ((fdf->map.y + 1) * fdf->map.nbcol + fdf->map.x)

#endif
