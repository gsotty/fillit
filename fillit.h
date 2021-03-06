/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:25:48 by tapperce          #+#    #+#             */
/*   Updated: 2017/01/11 11:22:19 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "Libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

# define BUF_SIZE 21

void	ft_exit(int err, char *msg);
char	*creat_board(int size);
char	*ft_board(int ***pieces, char *board, int size);
int		**check_exist_0(int **pieces);
int		check_syntax(char *buf);
int		***get_pieces(int fd, int ***pieces);
int		***p_malloc(int ***pieces);
int		store_piece(char *buf, int **pieces);
int		test(int ***pieces);
int		fillit(int ***pieces, char *board, int size, int nbr_pieces);

#endif
