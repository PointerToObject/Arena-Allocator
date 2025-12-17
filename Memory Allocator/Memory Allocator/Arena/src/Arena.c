#include "../Arena.h"


void arena_init(Arena* a, void* buf, size_t size)
{
	a->arena = (unsigned char*)buf;
	a->len = size;
	a->pointer = 0;
}

void* arena_alloc(Arena* a, size_t size)
{
	if (a->pointer + size > a->len)
	{
		printf("[ARENA ERROR]Out of memory!\n");
		return NULL;
	}

	void* ptr = &a->arena[a->pointer];

	a->pointer += size;

	return ptr;
}

void arena_reset(Arena* a)
{
	a->pointer = 0;
}