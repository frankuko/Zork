#include <stdio.h>
#include <Entity.h>

int main()
{
	printf("\nHello World\n\n");
	printf("\nWelcome to ZORK\n");

	getchar();

	Entity *c = new Entity("a", "b", NULL);
	
	getchar();

}