# Arena Allocator

## What It Is

An arena allocator is a memory management strategy where you allocate from a large pre-allocated buffer by moving a pointer forward. Instead of freeing individual allocations, you free everything at once by resetting the pointer.

Think of it like a notepad: you write on it sequentially from top to bottom. When you're done with the page, you throw it away and start fresh on a new page.

## How It Works

```
Step 1: Start with a buffer
[                                    ]
^
offset = 0

Step 2: Someone requests 10 bytes
[XXXXXXXXXX                          ]
          ^
          offset = 10

Step 3: Someone requests 5 bytes
[XXXXXXXXXXYYYYY                     ]
               ^
               offset = 15

Step 4: Reset the arena
[                                    ]
^
offset = 0
```

The allocation is just:
1. Check if there's enough space left
2. Return pointer at current offset
3. Move offset forward by allocation size

Resetting is just:
1. Set offset back to 0

## Why Use It

**Speed**: Allocating is O(1) - just increment a pointer. No searching for free blocks, no complex bookkeeping.

**Simplicity**: The entire allocator is about 20 lines of code.

**No fragmentation**: Memory is allocated sequentially, so there are no gaps.

**Bulk deallocation**: When you're done with a batch of work, reset the whole arena instantly instead of freeing thousands of individual allocations.

## When To Use It

Use arenas when you have groups of allocations with the same lifetime:

- **Game frame data**: Allocate everything needed for one frame, reset at frame end
- **Request handling**: Allocate data for one HTTP request, reset when response is sent
- **Parsing**: Allocate AST nodes while parsing, reset after compilation pass
- **Temporary strings**: Build up strings during processing, reset when done



