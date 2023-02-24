/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:41:44 by shhuang           #+#    #+#             */
/*   Updated: 2023/01/17 02:15:23 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*nuovalinea;
	static char	*strmemory;
	char		*contusabile;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &contusabile, 0) < 0)
		return (NULL);
	contusabile = size_1mem(contusabile);
	contusabile = crea_contusabile(contusabile, fd);
	if (contusabile[0] == '\0' && !strmemory)
	{
		getfree(&contusabile);
		return (NULL);
	}
	if (!strmemory)
		strmemory = size_1mem(strmemory);
	contusabile = ft_strjoin2(strmemory, contusabile);
	nuovalinea = trova_nl(contusabile);
	i = ft_strlen(nuovalinea);
	if (i != 0 && contusabile)
		strmemory = copyafter(i, contusabile);
	free(contusabile);
	if (strmemory[0] == '\0' || nuovalinea[0] == '\0')
		getfree(&strmemory);
	return (nuovalinea);
}

char	*trova_nl(char *contusabile)
{
	int		j;
	char	*nuovalinea;

	j = 0;
	while (contusabile[j] != '\n' && contusabile[j])
		j++;
	if (contusabile[j] == '\n')
		j++;
	nuovalinea = (char *)malloc(j + 1);
	j = 0;
	while (contusabile[j] != '\n' && contusabile[j])
	{
		nuovalinea[j] = contusabile[j];
		j++;
	}
	if (contusabile[j] == '\n')
	{
		nuovalinea[j] = contusabile[j];
		j++;
	}
	nuovalinea[j] = '\0';
	return (nuovalinea);
}

char	*crea_contusabile(char *contusabile, int fd)
{
	int		caratteriletti;
	char	*contenitore;

	caratteriletti = 1;
	while (caratteriletti)
	{
		contenitore = (char *)malloc(BUFFER_SIZE + 1);
		caratteriletti = read(fd, contenitore, BUFFER_SIZE);
		if (caratteriletti == -1)
		{
			free(contenitore);
			getfree(&contusabile);
			break ;
		}
		contenitore[caratteriletti] = '\0';
		contusabile = ft_strjoin(contusabile, contenitore);
		if (ft_strchr(contenitore, '\n'))
		{
			free(contenitore);
			break ;
		}
		free(contenitore);
	}
	return (contusabile);
}

char	*size_1mem(char *c)
{
	c = (char *)malloc(1);
	c[0] = '\0';
	return (c);
}

void	getfree(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return ;
}

int  main(void)
{
     char    *line;
     int             i = 0;
     int             fileid;
	 fileid = open("mese.txt", O_RDONLY);
	 int** mese;
	 int x;
	 x=0;
	 int z;
	 z=0;
	 mese=malloc(sizeof(int*) * 4);
	 while(i<4)
	 {
		mese[i] = (int*)malloc(sizeof(int) * 7);
		i++;
	 }
     i = 0;
     while (i < 28)
     {
			if(z % 7 == 0 && z != 0)
			{
				z=0;
				x++;
			}
            line = get_next_line(fileid);
			mese[x][z] = atoi(line);
            free(line);
             i++;
			 z++;
     }
	 menoreditizzio(mese);
	 free(mese);
    close(fileid);
     return (0);
}
