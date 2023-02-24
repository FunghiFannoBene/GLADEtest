/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#+
#+     Glade / Gtk Programming
#+
#+     Copyright (C) 2019 by Kevin C. O'Kane
#+
#+     Kevin C. O'Kane
#+     kc.okane@gmail.com
#+     https://www.cs.uni.edu/~okane
#+     http://threadsafebooks.com/
#+
#+ This program is free software; you can redistribute it and/or modify
#+ it under the terms of the GNU General Public License as published by
#+ the Free Software Foundation; either version 2 of the License, or
#+ (at your option) any later version.
#+
#+ This program is distributed in the hope that it will be useful,
#+ but WITHOUT ANY WARRANTY; without even the implied warranty of
#+ MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#+ GNU General Public License for more details.
#+
#+ You should have received a copy of the GNU General Public License
#+ along with this program; if not, write to the Free Software
#+ Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#+
#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include <windows.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
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

// Make them global

GtkWidget	*window;
GtkWidget	*layout;
GtkWidget	*image;
GtkWidget	*fixed1;
GtkWidget	*button1;
GtkWidget	*button2;
GtkWidget	*label1;

GtkBuilder	*builder; 

int main(int argc, char *argv[]) {

	gtk_init(&argc, &argv); // init Gtk

//---------------------------------------------------------------------
// establish contact with xml code used to adjust widget settings
//---------------------------------------------------------------------
 
	builder = gtk_builder_new_from_file ("2.glade");
 
	window = GTK_WIDGET(gtk_builder_get_object(builder, "MeseCalc"));

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_window_fullscreen(GTK_WINDOW(window));
        gtk_builder_connect_signals(builder, NULL);

	fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
	button1 = GTK_WIDGET(gtk_builder_get_object(builder, "Calcola"));
	button2 = GTK_WIDGET(gtk_builder_get_object(builder, "Calcola2"));
	label1 = GTK_WIDGET(gtk_builder_get_object(builder, "Label"));
	

	gtk_widget_show(window);

	gtk_main();

	return EXIT_SUCCESS;
	}



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


G_MODULE_EXPORT void	on_Calcola_clicked (GtkButton *b) 
	{
		char    *line;
     	int             i = 0;
		static int conta;
		if(!conta)
			{conta = 0;}
     	static int             fileid;
		if(!fileid)
			fileid = open("mese.txt", O_RDONLY);
		while(i < 1)
     	{
        line = get_next_line(fileid);
		gtk_label_set_text (GTK_LABEL(label1), (const gchar* )line);
		WinExec("\"C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe\"", SW_HIDE);
        free(line);
        i++;
     	}
	}

G_MODULE_EXPORT void	on_Calcola2_clicked (GtkButton *b) 
	{
		WinExec("\"C:\\Riot Games\\League of Legends\\LeagueClient.exe\"", SW_HIDE);
	}