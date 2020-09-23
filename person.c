#include<stdlib.h>

#include "person.h"

Person* createPerson(int src, int dest){
  Person* p = (Person*)malloc(sizeof(Person));
  p->dest = dest;
  p->src = src;
  return p;
}

PersonList* insert(Person *p, PersonList *list){
  PersonList *Liste = (PersonList*)malloc(sizeof(PersonList));
  Liste->next = list;
  Liste->person = p;
  return Liste;
}
