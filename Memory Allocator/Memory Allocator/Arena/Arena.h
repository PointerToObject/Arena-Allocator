#pragma once
#include "../Includes.h"


typedef struct Arena
{
	unsigned char* arena;
	size_t len;
	size_t pointer;
} Arena;


void arena_init(Arena* a, void* buf, size_t size);
void* arena_alloc(Arena* a, size_t size);
void arena_reset(Arena* a);

