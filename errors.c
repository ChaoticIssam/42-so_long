/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iszitoun <iszitoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:12:59 by iszitoun          #+#    #+#             */
/*   Updated: 2023/02/14 20:36:01 by iszitoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lines_error(void)
{
	ft_printf("\nERROR: Lines are not equal!!!\n");
	exit(1);
}

void	sides_error(void)
{
	ft_printf("\nERROR: Check your map's *VERTICAL WALLS* !!!\n");
	exit(1);
}

void	horinzontal_error(void)
{
	ft_printf("\nERROR: Check your map's *HORINZONTAL WALLS* !!!\n");
	exit (1);
}

void	invalid_item_error(void)
{
	ft_printf("\nERROR: You entered an Invalid symbole in your map!!!\n");
	exit (1);
}

void	item_needed_error(void)
{
	ft_printf("\nERROR: Not enough items in your map!!!\n");
	exit (1);
}

void	duplicated_player_error(void)
{
	ft_printf("\nERROR: Player's symbole (duplicated or missing)!!!");
	exit (1);
}

void	duplicated_exit_error(void)
{
	ft_printf("\nERROR: Exit's symbole (duplicated or missing)!!!");
	exit (1);
}
