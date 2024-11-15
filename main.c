#include "ft_printf.h"
#include <stdio.h>

int main()
{

/*
	// test str
	printf("[%d]\n", ft_printf("%s", "duck1")); // %s
	printf("[%d]\n", printf("%s", "duck1"));
	printf("[%d]\n", ft_printf("%s", NULL)); // %s
	printf("[%d]\n", printf("%s", NULL)); // %s
	printf("[%d]\n", ft_printf("%.3s", "duck2")); // flag -> dot
	printf("[%d]\n", printf("%.3s", "duck2"));
	printf("[%d]\n", ft_printf("%.6s", "duck2")); // flag -> dot
	printf("[%d]\n", printf("%.6s", "duck2"));
	printf("[%d]\n", ft_printf("%05s", "duck3")); // flag -> zero
	printf("[%d]\n", printf("%05s", "duck3"));
	printf("[%d]\n", ft_printf("%03s", "duck4")); // flag -> zero 
	printf("[%d]\n", printf("%03s", "duck4"));
	printf("[%d]\n", ft_printf("%-7s", "duck5")); // flag -> hyphen
	printf("[%d]\n", printf("%-7s", "duck5"));
	printf("[%d]\n", ft_printf("%-2s", "duck6")); // flag -> hyphen
	printf("[%d]\n", printf("%-2s", "duck6")); 
	printf("[%d]\n", ft_printf("%6s", "duck7")); // flag -> only width
	printf("[%d]\n", printf("%6s", "duck7"));
	printf("[%d]\n", ft_printf("%2s", "duck8")); // flag -> only width
	printf("[%d]\n", printf("%2s", "duck8"));
	printf("[%d]\n", ft_printf("%#s", "duck9")); // flag -> only hash
	printf("[%d]\n", printf("%#s", "duck9"));
	printf("[%d]\n", ft_printf("% s", "duck10")); // flag -> only space
	printf("[%d]\n", printf("% s", "duck10"));
	printf("[%d]\n", ft_printf("%+s", "duck11")); // flag -> only plus
	printf("[%d]\n", printf("%+s", "duck11"));
	printf("[%d]\n", ft_printf("%0.7s", "duck12")); // flag -> zero + dot
	printf("[%d]\n", printf("%0.7s", "duck12"));
	printf("[%d]\n", ft_printf("%.07s", "duck13")); // flag -> dot + zero
	printf("[%d]\n", printf("%.07s", "duck13"));
	printf("[%d]\n", ft_printf("%.-7s", "duck14")); // flag -> dot + hyphen {fuck}
	printf("[%d]\n", printf("%.-7s", "duck14"));
	printf("[%d]\n", ft_printf("%-.7s", "duck15")); // flag -> hyphen + dot
	printf("[%d]\n", printf("%-.7s", "duck15"));
	printf("[%d]\n", ft_printf("%-07s", "duck16")); // flag -> hyphen + zero
	printf("[%d]\n", printf("%-07s", "duck16"));
	printf("[%d]\n", ft_printf("%0-7s", "duck17")); // flag -> zero + hyphen
	printf("[%d]\n", printf("%0-7s", "duck17"));
	printf("[%d]\n", ft_printf("%0-.7s", "duck18")); // flag -> zero + hyphen + dot
	printf("[%d]\n", printf("%0-.7s", "duck18"));
	printf("[%d]\n", ft_printf("%-.07s", "duck19")); // flag -> hyphen + dot + zero
	printf("[%d]\n", printf("%-.07s", "duck19"));
	printf("[%d]\n", ft_printf("%.0-7s", "duck20")); // flag -> dot + zero + hyphen {fuck}
	printf("[%d]\n", printf("%.0-7s", "duck20"));
	printf("[%d]\n", ft_printf("%.-07s", "duck21")); // flag -> dot + hyphen + zero {fuck}
	printf("[%d]\n", printf("%.-07s", "duck21"));

	// test char
	printf("[%d]\n", ft_printf("%c", 'd')); // %c
	printf("[%d]\n", printf("%c", 'd'));
	printf("[%d]\n", ft_printf("%c", NULL)); // %c
	printf("[%d]\n", printf("%c", NULL)); // %c
	printf("[%d]\n", ft_printf("%.0c", 'u')); // flag -> dot
	printf("[%d]\n", printf("%.0c", 'u'));
	printf("[%d]\n", ft_printf("%.6c", 'c')); // flag -> dot
	printf("[%d]\n", printf("%.6c", 'c'));
	printf("[%d]\n", ft_printf("%05c", 'k')); // flag -> zero
	printf("[%d]\n", printf("%05c", 'k'));
	printf("[%d]\n", ft_printf("%03c", 'i')); // flag -> zero 
	printf("[%d]\n", printf("%03c", 'i'));
	printf("[%d]\n", ft_printf("%-7c", 's')); // flag -> hyphen
	printf("[%d]\n", printf("%-7c", 's'));
	printf("[%d]\n", ft_printf("%-2c", 'c')); // flag -> hyphen
	printf("[%d]\n", printf("%-2c", 'c')); 
	printf("[%d]\n", ft_printf("%6c", 'o')); // flag -> only width
	printf("[%d]\n", printf("%6c", 'o'));
	printf("[%d]\n", ft_printf("%2c", 'l')); // flag -> only width
	printf("[%d]\n", printf("%2c", 'l'));
	printf("[%d]\n", ft_printf("%#c", 'b')); // flag -> only hash
	printf("[%d]\n", printf("%#c", 'b'));
	printf("[%d]\n", ft_printf("% c", 'u')); // flag -> only space
	printf("[%d]\n", printf("% c", 'u'));
	printf("[%d]\n", ft_printf("%+c", 't')); // flag -> only plus
	printf("[%d]\n", printf("%+c", 't'));
	printf("[%d]\n", ft_printf("%0.7c", 'n')); // flag -> zero + dot
	printf("[%d]\n", printf("%0.7c", 'n'));
	printf("[%d]\n", ft_printf("%.07c", 'o')); // flag -> dot + zero
	printf("[%d]\n", printf("%.07c", 'o'));
	printf("[%d]\n", ft_printf("%.-7c", 't')); // flag -> dot + hyphen {fuck}
	printf("[%d]\n", printf("%.-7c", 't'));
	printf("[%d]\n", ft_printf("%-.7c", 'e')); // flag -> hyphen + dot
	printf("[%d]\n", printf("%-.7c", 'e'));
	printf("[%d]\n", ft_printf("%-07c", 'n')); // flag -> hyphen + zero
	printf("[%d]\n", printf("%-07c", 'n'));
	printf("[%d]\n", ft_printf("%0-7c", 'o')); // flag -> zero + hyphen
	printf("[%d]\n", printf("%0-7c", 'o'));
	printf("[%d]\n", ft_printf("%0-.7c", 'u')); // flag -> zero + hyphen + dot
	printf("[%d]\n", printf("%0-.7c", 'u'));
	printf("[%d]\n", ft_printf("%-.07c", 'g')); // flag -> hyphen + dot + zero
	printf("[%d]\n", printf("%-.07c", 'g'));
	printf("[%d]\n", ft_printf("%.0-7c", 'h')); // flag -> dot + zero + hyphen {fuck}
	printf("[%d]\n", printf("%.0-7c", 'h'));
	printf("[%d]\n", ft_printf("%.-07c", 'f')); // flag -> dot + hyphen + zero {fuck}
	printf("[%d]\n", printf("%.-07c", 'f'));
*/
/*
	// test int
	printf("[%d]\n", ft_printf("%d", 42)); // %d
	printf("[%d]\n", printf("%d", 42));
	printf("[%d]\n", ft_printf("%d", NULL)); // %d
	printf("[%d]\n", printf("%d", NULL)); // %d
	printf("[%d]\n", ft_printf("%.0d", 43)); // flag -> dot
	printf("[%d]\n", printf("%.0d", 43));
	printf("[%d]\n", ft_printf("%.6d", 44)); // flag -> dot
	printf("[%d]\n", printf("%.6d", 44));
	printf("[%d]\n", ft_printf("%05d", 45)); // flag -> zero
	printf("[%d]\n", printf("%05d", 45));
	printf("[%d]\n", ft_printf("%03d", 46)); // flag -> zero 
	printf("[%d]\n", printf("%03d", 46));
	printf("[%d]\n", ft_printf("%-7d",47)); // flag -> hyphen
	printf("[%d]\n", printf("%-7d", 47));
	printf("[%d]\n", ft_printf("%-2d", 48)); // flag -> hyphen
	printf("[%d]\n", printf("%-2d", 48)); 
	printf("[%d]\n", ft_printf("%6d", 49)); // flag -> only width
	printf("[%d]\n", printf("%6d", 49));
	printf("[%d]\n", ft_printf("%2d", 50)); // flag -> only width
	printf("[%d]\n", printf("%2d", 50));
	printf("[%d]\n", ft_printf("%#d", 51)); // flag -> only hash
	printf("[%d]\n", printf("%#d", 51));
	printf("[%d]\n", ft_printf("% d", 1337)); // flag -> only space
	printf("[%d]\n", printf("% d", 1337));
	printf("[%d]\n", ft_printf("%+d", 1338)); // flag -> only plus
	printf("[%d]\n", printf("%+d", 1338));
	printf("[%d]\n", ft_printf("%0.7d", 1339)); // flag -> zero + dot
	printf("[%d]\n", printf("%0.7d", 1339));
	printf("[%d]\n", ft_printf("%.07d", 1340)); // flag -> dot + zero
	printf("[%d]\n", printf("%.07d", 1340));
	printf("[%d]\n", ft_printf("%.-7d", 1341)); // flag -> dot + hyphen {fuck}
	printf("[%d]\n", printf("%.-7d", 1341));
	printf("[%d]\n", ft_printf("%-.7d", 1342)); // flag -> hyphen + dot
	printf("[%d]\n", printf("%-.7d", 1342));
	printf("[%d]\n", ft_printf("%-07d", 1343)); // flag -> hyphen + zero
	printf("[%d]\n", printf("%-07d", 1343));
	printf("[%d]\n", ft_printf("%0-7d", 1344)); // flag -> zero + hyphen
	printf("[%d]\n", printf("%0-7d", 1344));
	printf("[%d]\n", ft_printf("%0-.7d", 1345)); // flag -> zero + hyphen + dot
	printf("[%d]\n", printf("%0-.7d", 1345));
	printf("[%d]\n", ft_printf("%-.07d", 1346)); // flag -> hyphen + dot + zero
	printf("[%d]\n", printf("%-.07d", 1346));
	printf("[%d]\n", ft_printf("%.0-7d", 1347)); // flag -> dot + zero + hyphen {fuck}
	printf("[%d]\n", printf("%.0-7d", 1347));
	printf("[%d]\n", ft_printf("%.-08d", 2222)); // flag -> dot + hyphen + zero {fuck}
	printf("[%d]\n", printf("%.-08d", 2222));
	return (1);
*/
/*
	// test uint
	printf("[%d]\n", ft_printf("%u", 42)); // %u
	printf("[%d]\n", printf("%u", 42));
	printf("[%d]\n", ft_printf("%u", NULL)); // %d
	printf("[%d]\n", printf("%u", NULL)); // %d
	printf("[%d]\n", ft_printf("%.0u", 43)); // flag -> uot
	printf("[%d]\n", printf("%.0u", 43));
	printf("[%d]\n", ft_printf("%.6u", 44)); // flag -> dot
	printf("[%d]\n", printf("%.6u", 44));
	printf("[%d]\n", ft_printf("%05u", 45)); // flag -> zero
	printf("[%d]\n", printf("%05u", 45));
	printf("[%d]\n", ft_printf("%03u", 46)); // flag -> zero 
	printf("[%d]\n", printf("%03u", 46));
	printf("[%d]\n", ft_printf("%-7u",47)); // flag -> hyphen
	printf("[%d]\n", printf("%-7u", 47));
	printf("[%d]\n", ft_printf("%-2u", 48)); // flag -> hyphen
	printf("[%d]\n", printf("%-2u", 48)); 
	printf("[%d]\n", ft_printf("%6u", 49)); // flag -> only width
	printf("[%d]\n", printf("%6u", 49));
	printf("[%d]\n", ft_printf("%2u", 50)); // flag -> only width
	printf("[%d]\n", printf("%2u", 50));
	printf("[%d]\n", ft_printf("%#u", 51)); // flag -> only hash
	printf("[%d]\n", printf("%#u", 51));
	printf("[%d]\n", ft_printf("% u", 1337)); // flag -> only space
	printf("[%d]\n", printf("% u", 1337));
	printf("[%d]\n", ft_printf("%+u", 1338)); // flag -> only plus
	printf("[%d]\n", printf("%+u", 1338));
	printf("[%d]\n", ft_printf("%0.7u", 1339)); // flag -> zero + uot
	printf("[%d]\n", printf("%0.7u", 1339));
	printf("[%d]\n", ft_printf("%.07u", 1340)); // flag -> dot + zero
	printf("[%d]\n", printf("%.07u", 1340));
	printf("[%d]\n", ft_printf("%.-7u", 1341)); // flag -> dot + hyphen {fuck}
	printf("[%d]\n", printf("%.-7u", 1341));
	printf("[%d]\n", ft_printf("%-.7u", 1342)); // flag -> hyphen + dot
	printf("[%d]\n", printf("%-.7u", 1342));
	printf("[%d]\n", ft_printf("%-07u", 1343)); // flag -> hyphen + zero
	printf("[%d]\n", printf("%-07u", 1343));
	printf("[%d]\n", ft_printf("%0-7u", 1344)); // flag -> zero + hyphen
	printf("[%d]\n", printf("%0-7u", 1344));
	printf("[%d]\n", ft_printf("%0-.7u", 1345)); // flag -> zero + hyphen + dot
	printf("[%d]\n", printf("%0-.7u", 1345));
	printf("[%d]\n", ft_printf("%-.07u", 1346)); // flag -> hyphen + uot + zero
	printf("[%d]\n", printf("%-.07u", 1346));
	printf("[%d]\n", ft_printf("%.0-7u", 1347)); // flag -> dot + zero + hyphen {fuck}
	printf("[%d]\n", printf("%.0-7u", 1347));
	printf("[%d]\n", ft_printf("%.-08u", 2222)); // flag -> dot + hyphen + zero {fuck}
	printf("[%d]\n", printf("%.-08u", 2222));
*/
/*
	// test hex (lower)
	printf("[%d]\n", ft_printf("%x", 42)); // %u
	printf("[%d]\n", printf("%x", 42));
	printf("[%d]\n", ft_printf("%x", NULL)); // %d
	printf("[%d]\n", printf("%x", NULL)); // %d
	printf("[%d]\n", ft_printf("%.1x", 43)); // flag -> uot
	printf("[%d]\n", printf("%.1x", 43));
	printf("[%d]\n", ft_printf("%.6x", 44)); // flag -> dot
	printf("[%d]\n", printf("%.6x", 44));
	printf("[%d]\n", ft_printf("%05x", 45)); // flag -> zero
	printf("[%d]\n", printf("%05x", 45));
	printf("[%d]\n", ft_printf("%03x", 46)); // flag -> zero 
	printf("[%d]\n", printf("%03x", 46));
	printf("[%d]\n", ft_printf("%-7x",47)); // flag -> hyphen
	printf("[%d]\n", printf("%-7x", 47));
	printf("[%d]\n", ft_printf("%-2x", 48)); // flag -> hyphen
	printf("[%d]\n", printf("%-2x", 48)); 
	printf("[%d]\n", ft_printf("%6x", 49)); // flag -> only width
	printf("[%d]\n", printf("%6x", 49));
	printf("[%d]\n", ft_printf("%2x", 50)); // flag -> only width
	printf("[%d]\n", printf("%2x", 50));
	printf("[%d]\n", ft_printf("%#x", 51)); // flag -> only hash
	printf("[%d]\n", printf("%#x", 51));
	printf("[%d]\n", ft_printf("% x", 1337)); // flag -> only space
	printf("[%d]\n", printf("% x", 1337));
	printf("[%d]\n", ft_printf("%+x", 1338)); // flag -> only plus
	printf("[%d]\n", printf("%+x", 1338));
	printf("[%d]\n", ft_printf("%0.7x", 1339)); // flag -> zero + uot
	printf("[%d]\n", printf("%0.7x", 1339));
	printf("[%d]\n", ft_printf("%.07x", 1340)); // flag -> dot + zero
	printf("[%d]\n", printf("%.07x", 1340));
	printf("[%d]\n", ft_printf("%.-7x", 1341)); // flag -> dot + hyphen {fuck}
	printf("[%d]\n", printf("%.-7x", 1341));
	printf("[%d]\n", ft_printf("%-.7x", 1342)); // flag -> hyphen + dot
	printf("[%d]\n", printf("%-.7x", 1342));
	printf("[%d]\n", ft_printf("%-07x", 1343)); // flag -> hyphen + zero
	printf("[%d]\n", printf("%-07x", 1343));
	printf("[%d]\n", ft_printf("%0-7x", 1344)); // flag -> zero + hyphen
	printf("[%d]\n", printf("%0-7x", 1344));
	printf("[%d]\n", ft_printf("%0-.7x", 1345)); // flag -> zero + hyphen + dot
	printf("[%d]\n", printf("%0-.7x", 1345));
	printf("[%d]\n", ft_printf("%-.07x", 1346)); // flag -> hyphen + uot + zero
	printf("[%d]\n", printf("%-.07x", 1346));
	printf("[%d]\n", ft_printf("%.0-7x", 1347)); // flag -> dot + zero + hyphen {fuck}
	printf("[%d]\n", printf("%.0-7x", 1347));
	printf("[%d]\n", ft_printf("%.-08x", 2222)); // flag -> dot + hyphen + zero {fuck}
	printf("[%d]\n", printf("%.-08x", 2222));
*/
/*
	// hex (upper)
	printf("[%d]\n", ft_printf("%X", 42)); // %u
	printf("[%d]\n", printf("%X", 42));
	printf("[%d]\n", ft_printf("%X", NULL)); // %d
	printf("[%d]\n", printf("%X", NULL)); // %d
	printf("[%d]\n", ft_printf("%.1X", 43)); // flag -> uot
	printf("[%d]\n", printf("%.1X", 43));
	printf("[%d]\n", ft_printf("%.6X", 44)); // flag -> dot
	printf("[%d]\n", printf("%.6X", 44));
	printf("[%d]\n", ft_printf("%05X", 45)); // flag -> zero
	printf("[%d]\n", printf("%05X", 45));
	printf("[%d]\n", ft_printf("%03X", 46)); // flag -> zero 
	printf("[%d]\n", printf("%03X", 46));
	printf("[%d]\n", ft_printf("%-7X",47)); // flag -> hyphen
	printf("[%d]\n", printf("%-7X", 47));
	printf("[%d]\n", ft_printf("%-2X", 48)); // flag -> hyphen
	printf("[%d]\n", printf("%-2X", 48)); 
	printf("[%d]\n", ft_printf("%6X", 49)); // flag -> only width
	printf("[%d]\n", printf("%6X", 49));
	printf("[%d]\n", ft_printf("%2X", 50)); // flag -> only width
	printf("[%d]\n", printf("%2X", 50));
	printf("[%d]\n", ft_printf("%#X", 51)); // flag -> only hash
	printf("[%d]\n", printf("%#X", 51));
	printf("[%d]\n", ft_printf("% X", 1337)); // flag -> only space
	printf("[%d]\n", printf("% X", 1337));
	printf("[%d]\n", ft_printf("%+X", 1338)); // flag -> only plus
	printf("[%d]\n", printf("%+X", 1338));
	printf("[%d]\n", ft_printf("%0.7X", 1339)); // flag -> zero + uot
	printf("[%d]\n", printf("%0.7X", 1339));
	printf("[%d]\n", ft_printf("%.07X", 1340)); // flag -> dot + zero
	printf("[%d]\n", printf("%.07X", 1340));
	printf("[%d]\n", ft_printf("%.-7X", 1341)); // flag -> dot + hyphen {fuck}
	printf("[%d]\n", printf("%.-7X", 1341));
	printf("[%d]\n", ft_printf("%-.7X", 1342)); // flag -> hyphen + dot
	printf("[%d]\n", printf("%-.7X", 1342));
	printf("[%d]\n", ft_printf("%-07X", 1343)); // flag -> hyphen + zero
	printf("[%d]\n", printf("%-07X", 1343));
	printf("[%d]\n", ft_printf("%0-7X", 1344)); // flag -> zero + hyphen
	printf("[%d]\n", printf("%0-7X", 1344));
	printf("[%d]\n", ft_printf("%0-.7X", 1345)); // flag -> zero + hyphen + dot
	printf("[%d]\n", printf("%0-.7X", 1345));
	printf("[%d]\n", ft_printf("%-.07X", 1346)); // flag -> hyphen + uot + zero
	printf("[%d]\n", printf("%-.07X", 1346));
	printf("[%d]\n", ft_printf("%.0-7X", 1347)); // flag -> dot + zero + hyphen {fuck}
	printf("[%d]\n", printf("%.0-7X", 1347));
	printf("[%d]\n", ft_printf("%.-08X", 2222)); // flag -> dot + hyphen + zero {fuck}
	printf("[%d]\n", printf("%.-08X", 2222));
*/
/*
	// address
	printf("[%d]\n", ft_printf("%p", 42)); // %u
	printf("[%d]\n", printf("%p", 42));
	printf("[%d]\n", ft_printf("%p", NULL)); // %d
	printf("[%d]\n", printf("%p", NULL)); // %d
	printf("[%d]\n", ft_printf("%.1p", 43)); // flag -> dot
	printf("[%d]\n", printf("%.1p", 43));
	printf("[%d]\n", ft_printf("%.6p", 44)); // flag -> dot
	printf("[%d]\n", printf("%.6p", 44));
	printf("[%d]\n", ft_printf("%05p", 45)); // flag -> zero
	printf("[%d]\n", printf("%05p", 45));
	printf("[%d]\n", ft_printf("%03p", 46)); // flag -> zero 
	printf("[%d]\n", printf("%03p", 46));
	printf("[%d]\n", ft_printf("%-7p",47)); // flag -> hyphen
	printf("[%d]\n", printf("%-7p", 47));
	printf("[%d]\n", ft_printf("%-2p", 48)); // flag -> hyphen
	printf("[%d]\n", printf("%-2p", 48)); 
	printf("[%d]\n", ft_printf("%6p", 49)); // flag -> only width
	printf("[%d]\n", printf("%6p", 49));
	printf("[%d]\n", ft_printf("%2p", 50)); // flag -> only width
	printf("[%d]\n", printf("%2p", 50));
	printf("[%d]\n", ft_printf("%#p", 51)); // flag -> only hash
	printf("[%d]\n", printf("%#p", 51));
	printf("[%d]\n", ft_printf("% p", 1337)); // flag -> only space
	printf("[%d]\n", printf("% p", 1337));
	printf("[%d]\n", ft_printf("%+p", 1338)); // flag -> only plus
	printf("[%d]\n", printf("%+p", 1338));
	printf("[%d]\n", ft_printf("%0.7p", 1339)); // flag -> zero + uot
	printf("[%d]\n", printf("%0.7p", 1339));
	printf("[%d]\n", ft_printf("%.07p", 1340)); // flag -> dot + zero
	printf("[%d]\n", printf("%.07p", 1340));
	printf("[%d]\n", ft_printf("%.-7p", 1341)); // flag -> dot + hyphen {fuck}
	printf("[%d]\n", printf("%.-7p", 1341));
	printf("[%d]\n", ft_printf("%-.7p", 1342)); // flag -> hyphen + dot
	printf("[%d]\n", printf("%-.7p", 1342));
	printf("[%d]\n", ft_printf("%-07p", 1343)); // flag -> hyphen + zero
	printf("[%d]\n", printf("%-07p", 1343));
	printf("[%d]\n", ft_printf("%0-7p", 1344)); // flag -> zero + hyphen
	printf("[%d]\n", printf("%0-7p", 1344));
	printf("[%d]\n", ft_printf("%0-.7p", 1345)); // flag -> zero + hyphen + dot
	printf("[%d]\n", printf("%0-.7p", 1345));
	printf("[%d]\n", ft_printf("%-.07p", 1346)); // flag -> hyphen + uot + zero
	printf("[%d]\n", printf("%-.07p", 1346));
	printf("[%d]\n", ft_printf("%.0-7p", 1347)); // flag -> dot + zero + hyphen {fuck}
	printf("[%d]\n", printf("%.0-7p", 1347));
	printf("[%d]\n", ft_printf("%.-08p", 2222)); // flag -> dot + hyphen + zero {fuck}
	printf("[%d]\n", printf("%.-08p", 2222));
*/

	return (1);
}