#include <stdio.h>

// %[flags][width][.precision][length]specifier
// can specify width before flag but it doesnt work as intended
// if zero == true then hyphen == true return errstr
// if width == true then hyphen == true return errstr
// if precision == true then hyphen == true return errstr
// if precision != 0 and width != 0 then take max(precision, width)
int main()
{
	printf("test width x precision: %10.5d\n", 42);		// test width x precision:      00042 width > precision
	printf("test width x precision: %3.5d\n", 42);		// test width x precision: 00042 precision > width
	printf("test hyphen x precision: %-10.5d\n", 42);	// test hyphen x precision: 00042 precision > hyphen
	printf("test alternative: %.10-5d\n", 42);			// test alternative: %.10-5d
	printf("test zero x precision: %010.5d\n", 42);		// test zero x precision:      00042 ? idk why
	printf("test alternative: %.1005d\n", 42);			// test alternative:
	printf("test hypen x zero: %-1005d\n", 42);			// test hypen x zero: 42                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
	printf("test alternative: %010-5d\n", 42);			// test alternative: %010-5d
	printf("test width x hyphen: %10-5dx\n", 42);		// test width x hyphen: %10-5dx
	printf("test width x zero: %1005d\n", 42);			// test width x zero:                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            42
	printf("test width x char: %5c\n", 'a');			// test width x char:     a// works :x
	printf("test precision x char: %.5c\n", 'a');		// test precision x char: a
	printf("test plus x char: %+c\n", 'a');				// test plus x char: a
	printf("test hash x char: %#c\n", 'a');				// test hash x char: a
	printf("test zero x char: %05c\n", 'a');			// test zero x char:     a// :D? feels buggy
	printf("test hyphen x char: %-5cx\n", 'a');			// test hyphen x char: a    x
}