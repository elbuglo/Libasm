/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 00:04:40 by lulebugl           #+#    #+#            */
/*   Updated: 2020/05/07 01:09:23 by lulebugl          ###   ########.fr  	  */
/*                                                                            */
/* ************************************************************************** */

# define GREEN   "\033[32m"
# define BLUE	 "\033[34m"
# define RESET   "\033[0m"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

# define	STRLEN(X)		printf("str: %s // ft_strlen: %lu // strlen: %lu\n", X, ft_strlen(X), strlen(X))
# define	STRCMP(X, Y)	printf("s1: %s // s2: %s // ft_strcmp: %d // strcmp: %d\n", X, Y, ft_strcmp(X, Y), strcmp(X, Y))
# define 	FTWRITE(X, Y)	printf("\nbuf: %s // count: %d // ft_write: %lu // errno: %d // strerror: %s\n", X, Y, ft_write(STDOUT_FILENO, X, Y), errno, strerror(errno));
# define 	WRITE(X, Y)		printf("\nbuf: %s // count: %d // write: %lu // errno: %d // strerror: %s\n", X, Y, write(STDOUT_FILENO, X, Y), errno, strerror(errno));
# define 	TESTSTRDUP(X)		str = ft_strdup(X); printf("str = ft_strdup(\"%s\") // str: %s // errno: %d // strerror: %s\n", X, str, errno, strerror(errno)); free(str); str = NULL;

ssize_t ft_read(int fd, void *buf, size_t count);
ssize_t ft_write(int fd, void *buf, size_t count);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);

int		main()
{
	printf(BLUE"\n----- Tests for the libasm project @ 42 -----\n\n"RESET);

	printf(BLUE"testing strlen :\n\n"RESET);
		STRLEN("Ca marche?");
		STRLEN("Il semblerait");
		STRLEN("0123456789ABCDEF");
		STRLEN("");

	char s[1024] = {0};

	printf(BLUE"\nTesting ft_strcpy with char s[1024] = {0}:\n\n"RESET);
	printf("	ft_strcpy:\n");
	printf("Copying 'Bonjour!' // s: %s\n", ft_strcpy(s, "Bonjour!"));
	printf("Copying 'Bonjour 0123456789' // s: %s\n", ft_strcpy(s, "Bonjour 0123456789"));
	printf("Copying '0123456789' // s: %s\n", ft_strcpy(s, "0123456789"));
	printf("Copying '' // s: %s\n", ft_strcpy(s, ""));
	printf("\n");
	memset((char *)s, 0, sizeof(s));
	printf("	strcpy:\n");
	printf("Copying 'Bonjour!' // s: %s\n", strcpy(s, "Bonjour!"));
	printf("Copying 'Bonjour 0123456789' // s: %s\n", strcpy(s, "Bonjour 0123456789"));
	printf("Copying '0123456789' // s: %s\n", strcpy(s, "0123456789"));
	printf("Copying '' // s: %s\n", strcpy(s, ""));
	printf("\n");

	printf(BLUE"	Testing ft_strcmp:\n\n"RESET);
	STRCMP("", "Bonjour!");
	STRCMP("Bonjour!", "");
	STRCMP("Bonjour! 0123456789", "Bonjour! 0123456789");
	STRCMP("", "");
	STRCMP("Bonjour!", "Salut!");
	STRCMP("Salut!", "Bonjour!");
	STRCMP("01234", "56789");
	printf("\n");

	int fd = 0;
	printf(BLUE"	Testing ft_write:\n\n"RESET);
	printf("--------------------\n");
	FTWRITE("Bonjour!", 2);
	FTWRITE("Salut!", 7);
	FTWRITE("A", 2);
	FTWRITE("", 0);
	FTWRITE("0123456789", 11);
	FTWRITE("Bonjour 0123456789", 19);
	printf("\n--------------------\n");
	printf("write:\n\n");
	WRITE("Bonjour!", 2);
	WRITE("Salut!", 7);
	WRITE("A", 2);
	WRITE("", 0);
	WRITE("0123456789", 11);
	WRITE("Bonjour 0123456789", 19);
	printf("\n--------------------\n");
	printf("Testing ft_write and write with a negative fd:\n\n");
	errno = 0;
	printf("ft_write returns: %ld // errno: %d // strerror: %s\n", ft_write(-1, "Bonjour!", 9), errno, strerror(errno));
	errno = 0;
	printf("write returns: %ld // errno: %d // strerror: %s\n", write(-1, "Bonjour!", 9), errno, strerror(errno));
	printf("\n");

	fd = 0;
	char buffer[2048] = {0};
	long	r = 0;
	int c;

	if ((fd = open("./Makefile", O_RDONLY)) == -1)
	{
		printf("Error opening Makefile to test ft_read, please try again\n");
		return (-1);
	}
	printf(BLUE"Testing ft_read:\n");
	printf("--------------------\n\n"RESET);
	printf("ft_read with ./Makefile, and buffer of 1024\n");
	r = ft_read(fd, buffer, 2047);
	printf("ft_read returned: %ld\n\n", r);
	buffer[r] = 0;
	printf("buffer:\n%s", buffer);
	if ((c = close(fd)) == 1)
	{
		printf("Close error\n");
		return (-1);
	}

	if ((fd = open("./Makefile", O_RDONLY)) == -1)
	{
		printf("Error opening Makefile to test read, please try again\n");
		return (-1);
	}
	printf("\n--------------------\n");
	printf("read with ./Makefile, and buffer of 1024\n");
	r = ft_read(fd, buffer, 2047);
	printf("read returned: %ld\n\n", r);
	buffer[r] = 0;
	printf("buffer:\n%s", buffer);
	if ((c = close(fd)) == 1)
	{
		printf("Close error\n");
		return (-1);
	}
	printf("\n--------------------\n");

	printf("Testing read and ft_read with a negative fd:\n");
	errno = 0;
	printf("ft_read returns: %ld // errno: %d // strerror: %s\n", ft_read(-1, buffer, 2047), errno, strerror(errno));
	errno = 0;
	printf("read returns: %ld // errno: %d // strerror: %s\n", read(-1, buffer, 2047), errno, strerror(errno));
	errno = 0;
	printf(BLUE"\nTesting ft_strdup\n\n"RESET);
	char *str = 0;
	TESTSTRDUP("Salut!");
	TESTSTRDUP("");
	TESTSTRDUP("Bonjour 0123456789");
	printf(GREEN"\n----- Thank you for your time ! -----\n"RESET);
}
