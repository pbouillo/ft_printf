#include <stdio.h>
#include "libftprintf.h"
 #include <limits.h>

int	main(void)
{
	char *testpointer = NULL;
	char *emptystring = "";
	char	test[] = "is that a test string?";
	int int1 = 0;
	int int2 = 0;
	int int3 = INT_MAX;
	int int4 = INT_MIN;
	printf("****************************\n");
	printf("****************************\n");
	printf("=========FIRST TESTS========\n");
	printf("****************************\n");
	printf("****************************\n");

	int ml = ft_printf("Testtesttes! %%%%%%%%%%%%%%%% %% %d %d %s %%%%%%%% Wow that's a nice test! %% %% %% test mich %u %i %p %x %s %d %p %p \n", int1, int2, "TEST ME", int3, int4, testpointer, int4, NULL, 4, NULL, NULL);
	int pl = printf("Testtesttes! %%%%%%%%%%%%%%%% %% %d %d %s %%%%%%%% Wow that's a nice test! %% %% %% test mich %u %i %p %x %s %d %p %p \n", int1, int2, "TEST ME", int3, int4, testpointer, int4, NULL, 4, NULL, NULL);
	
	printf("****************************\n");
	printf("my__PRINTFLENGTH: %d\n", ml);
	printf("____PRINTFLENGTH: %d\n", pl);
	printf("ml\n");
	
	printf("****************************\n");
	int ml2 = ft_printf("A %% AAA %d\n", 0);
	int pl2 = printf("A %% AAA %d\n", 0);
	printf("my__PRINTFLENGTH: %d\n", ml2);
	printf("____PRINTFLENGTH: %d\n", pl2);
	printf("ml2\n");
	
	printf("****************************\n");
	int ml3 = ft_printf("");
	int pl3 = printf("");
	printf("my__PRINTFLENGTH: %d\n", ml3);
	printf("____PRINTFLENGTH: %d\n", pl3);
	printf("ml3\n");
	
	printf("****************************\n");
	int ml4 = ft_printf("aa\n");
	int pl4 = printf("aa\n");
	printf("my__PRINTFLENGTH: %d\n", ml4);
	printf("____PRINTFLENGTH: %d\n", pl4);
	printf("ml4\n");
	
	printf("****************************\n");
	int ml5 = ft_printf("%%\n");
	int pl5 = printf("%%\n");
	printf("my__PRINTFLENGTH: %d\n", ml5);
	printf("____PRINTFLENGTH: %d\n", pl5);
	printf("ml5\n");
	
	printf("****************************\n");
	int s1 = ft_printf("%% %s %% %p %% %x %% %X\n", test, test, test, test);
	int s2 = printf("%% %s %% %p %% %x %% %X\n", test, test, test, test);
	printf("my__PRINTFLENGTH: %d\n", s1);
	printf("____PRINTFLENGTH: %d\n", s2);
	printf("s1\n");

	printf("****************************\n");
	int x1 = ft_printf("%%%% %x %X %x %X\n", 123123, 123123, test, test);
	int x2 = printf("%%%% %x %X %x %X\n", 123123, 123123, test, test);
	printf("my__PRINTFLENGTH: %d\n", x1);
	printf("____PRINTFLENGTH: %d\n", x2);
	printf("x1\n");

	printf("****************************\n");
	int ml6 = ft_printf("%% A %% A %% \n");
	int pl6 = printf("%% A %% A %% \n");
	printf("my__PRINTFLENGTH: %d\n", ml6);
	printf("____PRINTFLENGTH: %d\n", pl6);
	printf("ml6\n");

	printf("****************************\n");
	int ml7 = ft_printf("!!%d %%\n", -2147483647);
	int pl7 = printf("!!%d %%\n", -2147483647);
	printf("my__PRINTFLENGTH: %d\n", ml7);
	printf("____PRINTFLENGTH: %d\n", pl7);
	printf("ml7\n");

	printf("****************************\n");
	int ml8 = ft_printf("!!%d %% %s \n", -123123, emptystring);
	int pl8 = printf("!!%d %% %s \n", -123123, emptystring);
	printf("my__PRINTFLENGTH: %d\n", ml8);
	printf("____PRINTFLENGTH: %d\n", pl8);
	printf("ml8\n");

	printf("****************************\n");
	int ml9 = ft_printf("!!%d %% %s %u %p \n", -123123, emptystring, (unsigned int) 4294967295, emptystring);
	int pl9 = printf("!!%d %% %s %u %p \n", -123123, emptystring, (unsigned int) 4294967295, emptystring);
	printf("my__PRINTFLENGTH: %d\n", ml9);
	printf("____PRINTFLENGTH: %d\n", pl9);
	printf("ml9\n");

	printf("****************************\n");
	
	system("leaks a.out");
	return 0;
}