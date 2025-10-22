#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <fcntl.h>
#include "libft.h"
#include <bsd/string.h>

int main()
{
	char str[] = "hello world";
	char dest[6];
	char dest2[6];
	int n = 12;

	printf("%ld\n", ft_strlcpy(dest, str, n));
	printf("%ld\n", strlcpy(dest2, str, n));

	printf(":%s:\n", dest);
	printf("after\n:%s:\n", dest2);

}
