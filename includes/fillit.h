/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:20:57 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/11 16:26:02 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21
# include "../libft/libft.h"

typedef struct		s_board
{
	unsigned int	board;
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

char				*ft_bin_to_char(unsigned int n, int nbbits, int place);
char				*ft_test_bin(const unsigned int n, const int nbbits);
char				**ft_bin_pieces(char **pieces);
char				**ft_store(int fd);
int					ft_count_bit(unsigned int board, int nbbits);
int					ft_bin_amp(unsigned int bin_piece);
int					ft_nbr_line_bin(unsigned int bin_piece);
int					ft_put_end_board(t_all *all);
unsigned int		ft_char_to_bin(char *tab);
unsigned int		ft_verif(unsigned int nbr);
unsigned int		ft_swap_board_bit(unsigned int bit, t_size_board
		*size_board);
unsigned int		ft_fill(unsigned int dest, unsigned int src);
unsigned int		*ft_conv_board_to_bin(char **tab);
t_all				*ft_fillit(unsigned int *tab_piece);
t_all				*ft_browse(unsigned int bin_pieces, t_all *all, int count);

#endif
