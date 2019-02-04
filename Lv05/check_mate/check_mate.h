/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 06:44:21 by kibotrel          #+#    #+#             */
/*   Updated: 2019/02/01 07:03:28 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	parsing.c
*/

char	**parse(int size, char **av);
int		is_piece(char c, int num);

/*
**	solve.c
*/

int		solve(char **grid, int size);

/*
**	pieces.c
*/

int		pawn(char **grid, int y, int x, int size);
int		rook(char **grid, int y, int x, int size);
int		queen(char **grid, int y, int x, int size);
int		bishop(char **grid, int y, int x, int size);
