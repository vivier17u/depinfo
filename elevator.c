#include<stdlib.h>

#include <stdio.h>
#include "elevator.h"

Elevator *create_elevator(int capacity, int currentFloor, PersonList
  *persons){
    Elevator *e = (Elevator*)malloc(sizeof(Elevator));
    e->capacity = capacity;
    e->currentFloor = currentFloor;
    e->persons = persons;
    return e;
  }

  Building *create_building(int nbFloor, Elevator *elevator, PersonList
    **waitingLists){
      Building *b = (Building*)malloc(sizeof(Building));
      b->nbFloor = nbFloor;
      b->elevator = elevator;
      b->waitingLists = waitingLists;
      return b;
    }

    PersonList* exitElevator(Elevator *e){
      PersonList *copie = e->persons; 
      PersonList *temp = e->persons;
      PersonList *exit = NULL;
      e->persons = NULL;
      while (temp != NULL){
        if (temp->person->dest != e->targetFloor){
          e->persons = insert(temp->person, e->persons);
        }
        else{
          exit = insert(temp->person, exit);
        }
        temp = temp->next;
      }
      if (exit == NULL){
        e->persons = copie;
      }

      return exit;
    }

    void stepElevator(Building *b){
      int curFloor = b->elevator->currentFloor;
      int tarFloor = b->elevator->targetFloor;
      if (curFloor > tarFloor){
        b->elevator->currentFloor = curFloor-1;
      }
      else if(curFloor < tarFloor){
        b->elevator->currentFloor = curFloor+1;

      }
      else{
        b->waitingLists[b->elevator->targetFloor] = enterElevator(b->elevator, b->waitingLists[b->elevator->targetFloor]);
          PersonList *exit = exitElevator(b->elevator);
        }
      }


    PersonList* enterElevator(Elevator *e, PersonList *list){
      int capacity = e->capacity;
      int nb_occupe = 0;
      int modif = 0;
      PersonList *temp = e->persons;
      PersonList *copie = e->persons;
      e->persons = NULL;
      while (temp != NULL){
        e->persons = insert(temp->person, e->persons);
        temp = temp ->next;
        nb_occupe++;
      }
      modif = nb_occupe;
      while (nb_occupe < capacity && list != NULL){
        e->persons = insert(list->person, e->persons);
        list = list->next;
        nb_occupe ++;
      }

      if (modif == nb_occupe){
        e->persons = copie;
      }
      return list;
    }
