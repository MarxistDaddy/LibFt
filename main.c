#include "libft.h"
#include <bsd/string.h>
#include <ctype.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "hello world";
	char	dest[6];
	char	dest2[6];
	int		n;

	n = 12;
	printf("%ld\n", ft_strlcpy(dest, str, n));
	printf("%ld\n", strlcpy(dest2, str, n));
	printf(":%s:\n", dest);
	printf("after\n:%s:\n", dest2);
}
