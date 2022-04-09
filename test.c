#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *s=(char *)malloc(sizeof(char) * 100);
	s[1]='\0';
	printf("%s",s);
}

