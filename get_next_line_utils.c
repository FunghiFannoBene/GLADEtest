/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utilis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:41:44 by shhuang           #+#    #+#             */
/*   Updated: 2023/01/17 02:15:23 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	int		len2;
	char	*s;

	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	j = 0;
	s = (char *)malloc(len + len2 + 1);
	while (i < len)
	{
		s[i] = s1[i];
		i++;
	}
	free(s1);
	s1 = NULL;
	while (j < len2)
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = '\0';
	return (s);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s;
	int		len;
	int		len2;

	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	j = 0;
	s = (char *)malloc(len + len2 + 1);
	while (i < len)
	{
		s[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		s[i + j] = s2[j];
		j++;
	}
	free(s1);
	free(s2);
	s[i + j] = '\0';
	return (s);
}

int	ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (!c && s[i] == '\0')
		return (1);
	return (0);
}

char	*copyafter(int len, char *contusabile)
{
	char	*strmemory;
	int		i;
	int		len2;

	i = 0;
	len2 = ft_strlen(contusabile);
	strmemory = (char *)malloc(len2 - len + 1);
	while (i < len2 - len)
	{
		strmemory[i] = contusabile[i + len];
		i++;
	}
	strmemory[i] = '\0';
	return (strmemory);
}

void menoreditizzio(int **giorni)
{
	int i;
	i=0; //giorno da 1 a 7 lun mar mer gio ven sab dom
	int x;
	x = 0; //quantità di settimane
	int* giornisett;
	giornisett = malloc(sizeof(int)*7);
	int complessivo;

	while(i<7)
	{
		giornisett[i] = 0;
		i++;
	}
	i=0;
	while(i < 7)
	{
		while(x < 4)
		{
			giornisett[i] += giorni[x][i];
			x++;
		}
		x=0;
		i++;
	}
	printf("\n\n\nCALCOLO MENSILE DI 4 settimane(28 giorni)                         \n\n\n");
	while(x<4)
	{
		printf("Durante la %da settimana il totale è: %d€ \n",x+1, giorni[x][0]+giorni[x][1]+giorni[x][2]+giorni[x][3]+giorni[x][4]+giorni[x][5]+giorni[x][6]);
		x++;
	}
	x=0;
	printf("\n\n\n");
	complessivo = giornisett[0]+giornisett[1]+giornisett[2]+giornisett[3]+giornisett[4]+giornisett[5]+giornisett[6];
	printf("-------------------\n\n ENTRATE MENSILITà \n\n Complessivo di: %d€ \n\n -------------------- \n\n", complessivo);
	i=0;
	while(i < 7)
	{
		giornisett[i] /= 4;
		i++;
	}
	printf("Media dei giorni delle settimane è \n\n Lunedi: %d€ \n Martedì: %d€ \n Mercoledì: %d€ \n Giovedì: %d€ \n Venerdì %d€ \n Sabato: %d€ \n Domenica: %d€ \n\n --------------------\n",
	 giornisett[0],giornisett[1],giornisett[2],giornisett[3],giornisett[4],giornisett[5],giornisett[6]);

	 complessivo = (giornisett[0]+giornisett[1]+giornisett[2]+giornisett[3]+giornisett[4]+giornisett[5]+giornisett[6])/7;
	 printf("\n\n Media del tutto è di %d€ al giorno.\n", complessivo);

	 if(complessivo > 700)
	 	printf("\n Buona media");
	else
		printf("\n Non molto bene aumentare gli incassi! Inferiore a 700 giornalieri. \n\n");
	 free(giornisett);

}