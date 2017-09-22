#include <stdio.h>

int main()
{
	int i = 1;
	char *cptr = (char *)&i;

	//printf("%d\n", *cptr);

	if (*cptr)
	{
		printf("Little Endian\n");
	}
	else
	{
		printf("Big Endian\n");
	}

	return 0;
}
