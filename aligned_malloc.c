#include <stdio.h>
#include <stdlib.h>
/*
e.g., align to 128 Byte boundry, off=127+8
*/
void *aligned_malloc(size_t size, size_t alignment) {
	void *p, **pp;
	size_t off = alignment-1 + sizeof(void *);		// the offset makes malloc'ed memory across boundry
	if ((p = malloc(size+off)) == NULL)
		return NULL;
	pp = (void **)(((size_t)p+off) & ~(alignment-1));	// add offset, fold back to aligned addr;
	pp[-1] = p;
	printf("alloc p@%p pp[-1]=%p\n", p, pp[-1]);
	return pp;
}
void aligned_free(void *p) {
	void *pp = (void **)p[-1];
	free(pp);
}
int main(){
	void **pp, *p = aligned_malloc(1000, 128);
	pp = (void **)p;
	printf("alloc p@%p pp[-1]=%p\n", p, pp[-1]);
	
}
