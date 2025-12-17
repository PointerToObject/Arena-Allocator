#include "Main.h"


int main()
{

	arena_init(&arena, &buf, ARENA_SIZE);

	int* alloc = arena_alloc(&arena, sizeof(int) * 4);

	*alloc = 42069;


	printf("allocated pointer at -> %p\n", alloc);

	while (1)
	{
		Sleep(5);
	}

	return 0;
}