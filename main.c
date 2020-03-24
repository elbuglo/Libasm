/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 00:04:40 by lulebugl          #+#    #+#             */
/*   Updated: 2020/03/24 02:15:58 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

# define GREEN   "\033[32m"
# define RESET   "\033[0m"

# define STRLEN(x)	printf("`%s` = %d (%d)\n", x, ft_strlen(x), (int)strlen(x));

int		ft_strlen(char const *str);
char	*ft_strcpy(char *dst, char const *src);

int		main(void)
{
	const char *str = "hell";

	printf(GREEN"Start strlen\n"RESET);
		STRLEN("Hello")
		STRLEN("Ca marche?")
		STRLEN("Il semblerait")
		STRLEN("0123456789ABCDEF")
		STRLEN("")
		STRLEN(str)		
	printf(GREEN"End strlen\n"RESET);

	printf(GREEN"Start strcpy\n"RESET);
	printf("`%s` (`toto`)\n", ft_strcpy("0000", "toto"));
	//printf("`%s` (empty)\n", ft_strcpy(buffer, ""));
	//printf("`%s` (`long message`)\n", ft_strcpy(buffer, "long message"));
	//printf("`%s` (NULL > not modified)\n", ft_strcpy(buffer, NULL));
	printf(GREEN"End strcpy\n"RESET);

	return (0);
}