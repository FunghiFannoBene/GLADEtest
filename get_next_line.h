/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:41:44 by shhuang           #+#    #+#             */
/*   Updated: 2023/01/17 02:15:23 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*trova_nl(char *contenitore);
char	*copyafter(int len, char *contusabile);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(const char *s, int c);
char	*ft_strjoin2(char *s1, char *s2);
char	*crea_contusabile(char *contusabile, int fd);
char	*size_1mem(char *c);
void	getfree(char **ptr);
void menoreditizzio(int **giorni);
#endif