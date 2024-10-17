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

	printf("test double zero: %00d\n", 42);				// test double zero: 42
	printf("test double dot: %..5d\n", 42);				// test double dot: %.0.5d
	printf("test double hyphen: %--d\n", 42);			// test double hyphen: 42

	printf("test double dot: %010.5d\n", 42);				// 

	printf("test double dot: %.10-5d\n", 42);
	printf("test double dot: %010-5d\n", 42);

	printf("test double hash: %##f\n", 42.0);
	printf("test double dot: %# f\n", 42.0);
	printf("test double dot: %#+ f\n", 42.0);

	printf("test double space: %  f\n", 42.0);
	printf("test double dot: % #f\n", 42.0);
	printf("test double dot: % + f\n", 42.0);
	printf("test double dot: % +#f\n", 42.0);
	printf("test double dot: %+d\n", 42);

	printf("test percent1: %.5%\n", 42);
	printf("test percent2: %05%\n", 42);
	printf("test percent3: %-5%x\n", 42);
	printf("test percent4: %#%\n", 42);
	printf("test percent5: %+%\n", 42);
	printf("test percent6: % %\n", 42);

	printf("test percent1: %.5c\n", 'f');
	printf("test percent2: %05c\n", 'f');
	printf("test percent3: %-5cx\n", 'f');
	printf("test percent4: %#c\n", 'f');
	printf("test percent5: %+c\n", 'f');
	printf("test percent6: % c\n", 'f');
	printf("test percent1: %5c\n", 'f');

	printf("test str1: %.5s\n", "duck");
	printf("test str2: %05s\n", "duck");
	printf("test str3: %-5sx\n", "duck");
	printf("test str4: %#s\n", "duck");
	printf("test str5: %+5s\n", "duck");
	printf("test str6: % 5s\n", "duck");
	printf("test str7: %3s\n", "duck");
	printf("test str1: %0-5sx\n", "duck");
}