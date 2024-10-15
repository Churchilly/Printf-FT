#include <stdio.h>
# include <stdarg.h>
#include "printf.h"

static void	ft_init_flags(t_flags *f)
{
	f->hyphen = false;
	f->zero = false;
	f->dot = false;
	f->hash = false;
	f->space = false;
	f->plus = false;
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	t_print_data	p;
	t_flags			f;

	if (!format || !(*format))
		return (NULL);
	va_start(args, format);
	ft_init_flags(&f);
	if (!get_printlen(format, args, &p))
		return (0);
}
