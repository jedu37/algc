//NMEC: 93250
//NICK: João Eduardo da Silva Figueiredo

// Complete the functions (marked by ...)
// so that it passes all tests in DateTimeTest.

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "PersonSet.h"
#include "Person.h"
#include "Date.h"

// Definition of the structure
struct _PersonSet_ {
  int capacity; // the current capacity of the array
  int size;     // the number of elements currently stored
  Person **array; // points to an array of pointers to persons
};

#define INITIAL_CAPACITY 4
#define new_max(x,y) (((x) >= (y)) ? (x) : (y))
#define new_min(x,y) (((x) <= (y)) ? (x) : (y))
// You may add auxiliary definitions and declarations here, if you need to.


// Create a PersonSet.
PersonSet* PersonSetCreate() {
  // You must allocate space for the struct and for the array.
  // The array should be created with INITIAL_CAPACITY elements.
  // (The array will be reallocated if necessary, when elements are appended.)
  PersonSet* ps = (PersonSet*)malloc(sizeof(*ps));
  if(ps == NULL) {perror("PersonSetCreate"); exit(2);};
  ps->capacity = INITIAL_CAPACITY;
  ps->size = 0;
  ps->array = (Person**)malloc(ps->capacity*sizeof(Person));
  if(ps->array == NULL) {perror("PersonSetCreate"); exit(2);};
  printf("PersonSet Created!\n");
  return ps;
}

// Destroy PersonSet *pps
void PersonSetDestroy(PersonSet **pps) {
  assert(*pps != NULL);
  for(int i = 0; i < (*pps)->size; i++){
    PersonDestroy( (Person**)(*pps)->array[i] );
  }
  free((*pps)->array); // frees the array
  free(*pps);
  *pps = NULL;
  assert(*pps==NULL);
  printf("PersonSet Destroyed!\n");
}

int PersonSetSize(const PersonSet *ps) {
  return ps->size;
}

int PersonSetIsEmpty(const PersonSet *ps) {
  return ps->size == 0;
}

void PersonSetPrint(const PersonSet *ps) {
  printf("{\n");
  for (int i = 0; i < ps->size; i++) {
    Person *p = ps->array[i];
    PersonPrintf(p, ";\n");
  }
  printf("}(size=%d, capacity=%d)\n", ps->size, ps->capacity);
}


// Find index in ps->array of person with given id.
// (INTERNAL function.)
static int search(const PersonSet *ps, int id) {
  for(int i = 0; i < ps->size; i++){
    if(id == ps->array[i]->id){
      printf("Person found.\n");
      return i;};
  }
  printf("Person not found.\n");
  return -1;
}

// Append person *p to *ps, without verifying presence.
// Use only when sure that *p is not contained in *ps!
// (INTERNAL function.)
static void append(PersonSet *ps, Person *p) {
  // MODIFY the function so that if the array is full,
  // use realloc to double the array capacity!
  if(ps->capacity == ps->size){
    printf("Array at capacity!\n");
    ps->capacity = ps->capacity*2;
    ps->array = (Person**)realloc(ps->array,ps->capacity*sizeof(Person));
    printf("Capacity Doubled.\n");
  }
  ps->array[ps->size] = p;
  ps->size++;
}


// Add person *p to *ps.
// Do nothing if *ps already contains a person with the same id.
void PersonSetAdd(PersonSet *ps, Person *p) {
  // You may call the append function here!
  if(search(ps,p->id) ==-1){
    append(ps,p);
    printf("Person added.\n");
  }
  else{printf("Person already exists!\n");}
}

// Pop one person out of *ps.
Person* PersonSetPop(PersonSet *ps) {
  assert(!PersonSetIsEmpty(ps));
  // It is easiest to pop and return the person in the last position!
  Person* p = ps->array[ps->size-1];
  PersonDestroy((Person**) ps->array[ps->size-1]);
  ps->size--;
  printf("Person popped.\n");
  return p;
}

// Remove the person with given id from *ps, and return it.
// If no such person is found, return NULL and leave set untouched.
Person *PersonSetRemove(PersonSet *ps, int id) {
  // You may call search here!
  int i = search(ps,id);
  if(i == -1){
    printf("Person not found.\n");
    return NULL;
  }
  Person* p = ps->array[i];
  PersonDestroy( (Person**) ps->array[i] );
  for(int c = i;c < (ps->size-1); c++){
    ps->array[i] = ps->array[i+1];
  }
  PersonDestroy((Person**) ps->array[ps->size-1]);
  ps->array--;
  printf("Person found and removed.\n");
  return p;
}


// Get the person with given id of *ps.
// return NULL if it is not in the set.
Person *PersonSetGet(const PersonSet *ps, int id) {
  // You may call search here!
  int i = search(ps,id);
  if(i == -1){
    printf("Person not found.\n");
    return NULL;
  }
   Person* p = ps->array[i];
  printf("Person found and returned.\n");
  return p;
}

// Return true (!= 0) if set contains person wiht given id, false otherwise.
int PersonSetContains(const PersonSet *ps, int id) {
  return search(ps, id) >= 0;
}


// Return a NEW PersonSet with the union of *ps1 and *ps2.
// Return NULL if allocation fails.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetUnion(const PersonSet *ps1, const PersonSet *ps2) {
  PersonSet *ps = PersonSetCreate();
  ps->capacity = ps1->capacity+ps2->capacity;
  ps->array = (Person**)malloc(ps->capacity*sizeof(Person));
  if(ps->array == NULL) {perror("PersonSetCreate"); exit(2);};
  for(int i = 0; i < ps1->size; i++){
    PersonSetAdd(ps, ps1->array[i]);
  }
  PersonSetDestroy((PersonSet**)ps1);
  for(int i = 0; i < ps2->size; i++){
    PersonSetAdd(ps, ps2->array[i]);
  }
  PersonSetDestroy((PersonSet**) ps2);
  return ps;
}

// Return a NEW PersonSet with the intersection of *ps1 and *ps2.
// Return NULL if allocation fails.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetIntersection(const PersonSet *ps1, const PersonSet *ps2) {
  PersonSet *ps = PersonSetCreate();
  ps->capacity = new_min(ps1->capacity,ps2->capacity);
  ps->array = (Person**)malloc(ps->capacity*sizeof(Person));
  if(ps->array == NULL) {perror("PersonSetCreate"); exit(2);};
  for(int i = 0; i < ps1->size; i++){
    if(search(ps2,ps1->array[i]->id)!=-1){
      PersonSetAdd(ps, ps1->array[i]);
    }
  }
  PersonSetDestroy((PersonSet**) ps1);
  PersonSetDestroy((PersonSet**) ps2);
  return ps;
}


// Return a NEW PersonSet with the set difference of *ps1 and *ps2.
// Return NULL if allocation fails.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetDifference(const PersonSet *ps1, const PersonSet *ps2) {
  //...
  
}

// Return true iff *ps1 is a subset of *ps2.
int PersonSetIsSubset(const PersonSet *ps1, const PersonSet *ps2) {
  //...
  
}

// Return true if the two sets contain exactly the same elements.
int PersonSetEquals(const PersonSet *ps1, const PersonSet *ps2) {
  // You may call PersonSetIsSubset here!
  //...
  
}


