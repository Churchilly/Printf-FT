#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int *a;
	printf("return r:%d\n", ft_printf("r: %c", 'a'));
	printf("return o:%d\n", printf("o: %c", 'a'));
	printf("return r:%d\n", ft_printf("r: %s\n", "NULL"));
	printf("return o:%d\n", printf("o: %s\n", "NULL"));
	printf("return r:%d\n", ft_printf("r: %d\n", 42));
	printf("return o:%d\n", printf("o: %d\n", 42));
	printf("return r:%d\n", ft_printf("r: %u\n", 567));
	printf("return o:%d\n", printf("o: %u\n", 567));
	printf("return r:%d\n", ft_printf("r: %x\n", 43));
	printf("return o:%d\n", printf("o: %x\n", 43));
	printf("return r:%d\n", ft_printf("r: %X\n", 44));
	printf("return o:%d\n", printf("o: %X\n", 44));
	printf("return r:%d\n", ft_printf("r: %p\n", &a));
	printf("return o:%d\n", printf("o: %p\n", &a));
	printf("return r:%d\n", ft_printf("r: %k\n", "s"));
	printf("return o:%d\n", printf("o: %k\n", "s"));

	printf("return r:%d\n", ft_printf("r: %c", NULL));
	printf("return o:%d\n", printf("o: %c", NULL));
	printf("return r:%d\n", ft_printf("r: %s\n", NULL));
	printf("return o:%d\n", printf("o: %s\n", NULL));
	printf("return r:%d\n", ft_printf("r: %d\n", NULL));
	printf("return o:%d\n", printf("o: %d\n", NULL));
	printf("return r:%d\n", ft_printf("r: %u\n", NULL));
	printf("return o:%d\n", printf("o: %u\n", NULL));
	printf("return r:%d\n", ft_printf("r: %x\n", NULL));
	printf("return o:%d\n", printf("o: %x\n", NULL));
	printf("return r:%d\n", ft_printf("r: %X\n", NULL));
	printf("return o:%d\n", printf("o: %X\n", NULL));
	printf("return r:%d\n", ft_printf("r: %p\n", NULL));
	printf("return o:%d\n", printf("o: %p\n", NULL));
	printf("return r:%d\n", ft_printf("r: %k\n", NULL));
	printf("return o:%d\n", printf("o: %k\n", NULL));

	printf("return r:%d\n", ft_printf(NULL, NULL));
	printf("return o:%d\n", printf(NULL, NULL));
}