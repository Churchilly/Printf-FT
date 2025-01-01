#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include "ft_printf.h"

int main()
{
	printf("[%d]\n", ft_printf("%%%%%%"));
	printf("[%d]\n", printf("%%%%%%"));
	printf("[%d]\n", ft_printf("%c%c%c", 'a', 'b', NULL));
	printf("[%d]\n", printf("%c%c%c", 'a', 'b', NULL));
	printf("[%d]\n", ft_printf("%sx%sxx%sasd", "test", "this", "is"));
	printf("[%d]\n", printf("%sx%sxx%sasd", "test", "this", "is"));
	printf("[%d]\n", ft_printf("%s%s%s", NULL, NULL, "hello"));
	printf("[%d]\n", printf("%s%s%s", NULL, NULL, "hello"));
	printf("[%d]\n", ft_printf("%d%d%d%d%d%d%d%d%d", NULL, 0, -42, 42, INT_MAX, INT_MIN, LONG_MAX, 12345, 67890));
	printf("[%d]\n", printf("%d%d%d%d%d%d%d%d%d", NULL, 0, -42, 42, INT_MAX, INT_MIN, LONG_MAX, 12345, 67890));
	printf("[%d]\n", ft_printf("%dthis%dis%da%dtest%dxd%d", NULL, 0, -42, 42, INT_MAX, INT_MIN, LONG_MAX, 12345, 67890));
	printf("[%d]\n", printf("%dthis%dis%da%dtest%dxd%d", NULL, 0, -42, 42, INT_MAX, INT_MIN, LONG_MAX, 12345, 67890));
	printf("[%d]\n", ft_printf("%u%u%u%u%u%u%u%u%u", NULL, 0, -42, 42, INT_MAX, INT_MIN, LONG_MAX, 12345, 67890));
	printf("[%d]\n", printf("%u%u%u%u%u%u%u%u%u", NULL, 0, -42, 42, INT_MAX, INT_MIN, LONG_MAX, 12345, 67890));
	printf("[%d]\n", ft_printf("%x%x%x%x%x%x%x%x%x%x", NULL, 0, -42, 42, INT_MAX, INT_MIN, LONG_MAX, 12345, 67890, LONG_MIN));
	printf("[%d]\n", printf("%x%x%x%x%x%x%x%x%x%x", NULL, 0, -42, 42, INT_MAX, INT_MIN, LONG_MAX, 12345, 67890, LONG_MIN));
	printf("[%d]\n", ft_printf("%X%X%X%X%X%X%X%X%X%X", NULL, 0, -42, 42, INT_MAX, INT_MIN, LONG_MAX, 12345, 67890, LONG_MIN));
	printf("[%d]\n", printf("%X%X%X%X%X%X%X%X%X%X", NULL, 0, -42, 42, INT_MAX, INT_MIN, LONG_MAX, 12345, 67890, LONG_MIN));
	printf("[%d]\n", ft_printf("%p%p%p%p%p%p%p%p%p%p", NULL, 0, -42, 42, INT_MAX, INT_MIN, LONG_MAX, 12345, 67890, LONG_MIN));
	printf("[%d]\n", printf("%p%p%p%p%p%p%p%p%p%p", NULL, 0, -42, 42, INT_MAX, INT_MIN, LONG_MAX, 12345, 67890, LONG_MIN));

}

   