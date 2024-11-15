#include "ft_printf.h"
#include <stdio.h>

int main()
{
	printf("[%d]", ft_printf("r: %?\n", NULL));
	printf("[%d]", printf("o: %?\n", NULL));
}