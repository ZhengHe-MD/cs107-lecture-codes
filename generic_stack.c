#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "generic_stack.h"

#define kInitialAllocationSize 4
// The implementation chooses to allocate space for 4 client 
// elements. The 4 is arbitrary, but it should probably be 
// small, since a good number of applications never deal with 
// stacks that are all that deep. If during the course of a 
// program the stack saturates allocated memory, the implementation
// can just reallocate the storage using a (popular) doubling strategy.

void StackNew(stack *s, int elemSize) {
  // The constructor requires that the client element 
  // size be identified up front. Since it doesn’t 
  // (and will never) know the true data type, it needs 
  // the size so it at least knows how many bytes to 
  // replicate behind the scenes with every call to StackPush.
  assert(elemSize > 0);
  s->elemSize = elemSize;
  s->loglength = 0;
  s->alloclength = kInitialAllocationSize;
  s->elems = malloc(kInitialAllocationSize * elemSize);
  assert(s->elems != NULL);
}

void StackDispose(stack *s) {
  // The destructor simply needs to dispose of any resources
  // that'll otherwise be orphaned. The client has no clue that
  // one single block of dynamically allocated memory is being
  // used to house all of the elements, so the implementation
  // needs to properly free that memory, else it'll be orphaned
  // and unavailable for the lifetime of the application.
  free(s->elems);
  // Note that we don’t call free(s). StackNew doesn’t allocate 
  // space for the stack struct—the client does! The stack 
  // destructor should only clean up its own mess, not someone
  // else’s.
}

bool StackEmpty(stack *s) {
  return s->loglength == 0;
}

static void StackGrow(stack *s) {
  s->alloclength *= 2;
  s->elems = realloc(s->elems, s->alloclength * s->elemSize);
}

void StackPush(stack *s, void *elemAddr) {
  if (s->loglength == s->alloclength) {
    StackGrow(s);
  }
  // replicate the byte pattern addressed by elemAddr, placing
  // it at the manually computed address with raw storage.
  // Note that the copy is a shallow copy. If the s->elemSize bytes
  // copied in are pointers to dynamically allocated memory,
  // then ownership of that memory is transferred from the client
  // to the implementation.
  void *destAddr = (char *) s->elems + s->loglength * s->elemSize;
  memcpy(destAddr, elemAddr, s->elemSize);
  s->loglength++;
}

void StackPop(stack *s, void *elemAddr) {
  // decision: don't seperate the responsibilities of allocating and freeing space
  // into two different functions.
  const void *sourceAddr;

  assert(!StackEmpty(s));
  s->loglength--;
  sourceAddr = (char *) s->elems + s->loglength * s->elemSize;
  memcpy(elemAddr, sourceAddr, s->elemSize);
}