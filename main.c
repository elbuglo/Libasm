/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nine <nine@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 00:04:40 by lulebugl          #+#    #+#             */
/*   Updated: 2020/05/07 00:58:44 by nine             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

# define GREEN   "\033[32m"
# define RESET   "\033[0m"

# define STRLEN(x)		printf("`%s` = %d (%d)\n", x, ft_strlen(x), (int)strlen(x));
# define STRCMP(a, b)	printf("`%s`:`%s` = %d (%d)\n", a, b, ft_strcmp(a, b), strcmp(a, b));
// # define WRITE(s, x)	printf("%ld (`%s`:%ld)\n", ft_write(STDOUT_FILENO, s, x), s, x);
# define TESTFTWRITE(X, Y)	printf("\nbuf: %s // count: %d // ft_write: %lu // errno: %d // strerror: %s\n", X, Y, ft_write(STDOUT_FILENO, X, Y), errno, strerror(errno));
# define TESTWRITE(X, Y)		printf("\nbuf: %s // count: %d // write: %lu // errno: %d // strerror: %s\n", X, Y, write(STDOUT_FILENO, X, Y), errno, strerror(errno));
# define READ(b, x)		r = ft_read(STDIN_FILENO, buffer, x); printf("`%s`:%ld\n", buffer, r);
# define STRDUP(s)		tmp = ft_strdup(s); printf("`%s` (`%s`)\n", tmp, s);

int		ft_strlen(char const *str);
char	*ft_strcpy(char *dst, char const *src);
int		ft_strcmp(char const *s1, char const *s2);
ssize_t	ft_write(int fd, void const *buf, size_t nbyte);
ssize_t	ft_read(int fd, void *buf, size_t nbyte);
char	*ft_strdup(char const *s1);

int		main(void)
{
	char 		*str = "hell";
	char		buffer[42];
	char		*tmp;
	char		*tmp2;
	int			i;
	long		r;

	r = 0;
	i = -1;
	while (i < 42)
		buffer[++i] = 0;

	printf(GREEN"Start strlen :\n"RESET);
		STRLEN("Hello")
		STRLEN("Ca marche?")
		STRLEN("Il semblerait")
		STRLEN("0123456789ABCDEF")
		STRLEN("")
		STRLEN(str)		
	printf(GREEN"End strlen\n"RESET);

	printf(GREEN"\nStart strcpy :\n"RESET);
		printf("`%s` (`test`)\n", ft_strcpy(buffer, "test"));
		printf("`%s` ()\n", ft_strcpy(buffer, ""));
		printf("`%s` (str = `hell`)\n", ft_strcpy(buffer, str));
	printf(GREEN"End strcpy\n"RESET);

	printf(GREEN"\nStart strcmp :\n"RESET);
		STRCMP("", "")
		STRCMP("toto", "toto")
		STRCMP("", "toto")
		STRCMP("toto", "")
		STRCMP("toto", "totobar")
		STRCMP("ab", "bb")
		STRCMP("bb", "bb")
		STRCMP("bb", "ab")
	printf(GREEN"End strcmp\n"RESET);
	
	// printf(GREEN"\nStart ft_write :\n"RESET);
	// 	WRITE("Hello", 6L)
	// 	WRITE("Ca marche?", 12L)
	// 	WRITE("Il semblerait", 9L)
	// 	WRITE("0123456789ABCDEF", 16L)
	// 	WRITE("", 4L)
	// 	WRITE(str, 8L)
	// printf(GREEN"End ft_write\n"RESET);
	
	printf("Testing ft_write:\n");
	printf("--------------------\n");
	printf("ft_write:\n");
	TESTFTWRITE("Bonjour!", 2);
	TESTFTWRITE("Salut!", 7);
	TESTFTWRITE("A", 2);
	TESTFTWRITE("", 0);
	TESTFTWRITE("0123456789", 11);
	TESTFTWRITE("Bonjour 0123456789", 19);
	printf("--------------------\n");
	printf("write:\n");
	TESTWRITE("Bonjour!", 2);
	TESTWRITE("Salut!", 7);
	TESTWRITE("A", 2);
	TESTWRITE("", 0);
	TESTWRITE("0123456789", 11);
	TESTWRITE("Bonjour 0123456789", 19);
	printf("--------------------\n");
	printf("Testing ft_write and write with a negative fd:\n");
	errno = 0;
	printf("ft_write returns: %ld // errno: %d // strerror: %s\n", ft_write(-1, "Bonjour!", 9), errno, strerror(errno));
	errno = 0;
	printf("write returns: %ld // errno: %d // strerror: %s\n", write(-1, "Bonjour!", 9), errno, strerror(errno));
	printf("\n");
	
	printf(GREEN"\nStart ft_read :\n"RESET);
		READ(buffer, 25)
		READ(buffer, 4)
		READ(buffer, 26)
		READ(buffer, 14)
		READ(buffer, 0)
	printf(GREEN"End ft_read\n"RESET);

	printf(GREEN"\nStart ft_strdup :\n"RESET);
		tmp2 = NULL;
		tmp2 = ft_strdup("HEY"); 
		printf("%s\n", tmp2);
		STRDUP(tmp2)
		free(tmp2);
		STRDUP(" 1   1")
		STRDUP("   -  ")
		STRDUP("  ---")
	printf(GREEN"End ft_strdup\n"RESET);
	return (0);
}