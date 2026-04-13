/**
 * Print addresses of:
• global variable
• static variable
• stack variable
Goal
Observe .data, .bss, stack layout.

 */

#include <stdio.h>
#include <stdlib.h>
// data segment initialized
int global_data = 100;
static int static_data = 200;

//.bss segment not initialized
int global_bss;
static int static_bss;

void check_memory() {
    // Stack: Local variables
    int stack_var = 500;
    
    // Heap: Dynamically allocated memory
    int *heap_var = malloc(sizeof(int));

    printf("--- Memory Segment Addresses ---\n");
    printf(".data (Global Initialized): %p\n", (void*)&global_data);
    printf(".data (Static Initialized): %p\n", (void*)&static_data);
    printf(".bss  (Global Uninitialized):%p\n", (void*)&global_bss);
    printf(".bss  (Static Uninitialized):%p\n", (void*)&static_bss);
    printf("Heap  (Dynamic Allocation):  %p\n", (void*)heap_var);
    printf("Stack (Local Variable):      %p\n", (void*)&stack_var);

    free(heap_var);
}

int main() {
    check_memory();
    return 0;
}
