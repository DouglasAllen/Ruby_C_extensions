#include <stdio.h>
main()
{
	int i=5;
	int x;
	x=++i + i++ + ++i + i++;
	printf("%d %d",x,i);
	return 0;
}