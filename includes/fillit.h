/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:20:57 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/09 14:03:15 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21
# include "../libft/libft.h"

typedef struct		s_board
{
	unsigned int	board;
	unsigned int	*board_tmp;
	unsigned int	*tab_piece;
}					t_board;

typedef struct		s_size_board
{
	int				size;
	int				size_base;
}					t_size_board;

typedef struct		s_all
{
	t_board			*board;
	t_size_board	*size_board;
}					t_all;

unsigned int		*ft_conv(char **tab);
unsigned int		ft_verif(unsigned int nbr);
unsigned int		ft_bits(char *tab);
char				*ft_printbit(const unsigned int n, const int nbbits,
		int place);
unsigned int		ft_remp(unsigned int dest, unsigned int src);
t_board				*browse(unsigned int bin_pieces, t_all *all, int count);
unsigned int		ft_swap_board_bit(unsigned int bit, t_size_board *size_board);
unsigned int		ft_fill(unsigned int dest, unsigned int src);
t_all				*ft_fillit(unsigned int *tab_int);
char				**bin_pieces(char **pieces);
char				**store(int fd);
char				*ft_print_bit(const unsigned int n, const int nbbits);

#endif
