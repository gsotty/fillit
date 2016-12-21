/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:20:11 by gsotty            #+#    #+#             */
/*   Updated: 2016/12/21 16:49:59 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 20
# define BOARDTYPE unsigned __int128

typedef BOARDTYPE	t_boardtype;

typedef struct		s_board
{
	t_boardtype		board;
	t_boardtype		*tab_pieces;
	int				size;
	int				size_base;
}					t_board;

char				**ft_store(int fd, char **pieces);
char				**ft_bin_pieces(char **pieces);
t_boardtype			*ft_conv_board_to_bin(char **tab);
int					ft_fillit(t_boardtype *tab_pieces, t_boardtype
		*tab_pieces_finish, int nbr_pieces);
int					ft_bin_amp(t_boardtype tab_pieces, int size);
int					ft_nbr_line_bin(t_boardtype tab_pieces, int size);
t_boardtype			ft_verif(t_boardtype nbr);
t_boardtype			ft_char_to_bin(char *tab);
char				*ft_test_bin(const t_boardtype n, const int nbbits);
t_boardtype			ft_swap_board_bit(t_boardtype bit, int size);
int					ft_browse(t_boardtype *tab_pieces,
		t_boardtype tab_pieces_tmp, const int size);
int					ft_put_end_board(t_boardtype *tab_pieces_finish, int size);
char				*ft_bin_to_char(t_boardtype n, int nbbits, int place);
void				ft_exit(int err, char *msg);

#endif
