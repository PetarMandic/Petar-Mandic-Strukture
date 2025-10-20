#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Person{
    char Name[50];
    char Surname[50];
    int Year;
    struct Person* next;
}Person;

Person* addElementOnBeginning(Person* head, const char* Name, const char* Surname, int Year){
    Person* new = (Person*)malloc(sizeof(Person));
    strcpy(new ->Name, Name);
    strcpy(new ->Surname, Surname);
    new -> Year = Year;
    new -> next = head;
    return new;

}

void printList(Person* head){
    Person* temp = head;
    while(temp != NULL){
        printf("%s %s %d\n", temp->Name, temp->Surname, temp->Year);
        temp = temp->next;
    }
}

Person* addElementOnEnd(Person* head, const char* Name, const char* Surname, int Year) {
    Person* new = (Person*)malloc(sizeof(Person));
    strcpy(new->Name, Name);
    strcpy(new->Surname, Surname);
    new->Year = Year;
    new->next = NULL;

    if(head == NULL) return new;  

    Person* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = new;
    return head;
}

Person* findBySurname(Person* head, const char* Surname) {
    Person* temp = head;
    while(temp != NULL) {
        if(strcmp(temp->Surname, Surname) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL; 
}

Person* deleteElementBySurname(Person* head, const char* Surname) {
    Person* temp = head;
    Person* prev = NULL;

    while(temp != NULL) {
        if(strcmp(temp->Surname, Surname) == 0) {
            if(prev == NULL) {
                Person* newHead = temp->next;
                free(temp);
                return newHead;
            } else {
                prev->next = temp->next;
                free(temp);
                return head;
            }
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Osoba s prezimenom %s nije pronađena.\n", Surname);
    return head;
}


int main() {
    Person* list = NULL;

    list = addElementOnBeginning(list, "Marko", "Markovic", 1990);
    list = addElementOnBeginning(list, "Ana", "Ilic", 1992);

    list = addElementOnEnd(list, "Ivan", "Horvat", 1985);

    printf("Lista nakon dodavanja:\n");
    printList(list);

    Person* wanted = findBySurname(list, "Ilic");
    if(wanted != NULL)
        printf("Pronađeno: %s %s %d\n", wanted->Name, wanted->Surname, wanted->Year);

    list = deleteElementBySurname(list, "Markovic");
    printf("Lista nakon brisanja:\n");
    printList(list);

    while(list != NULL) {
        Person* temp = list;
        list = list->next;
        free(temp);
    }

    return 0;
}

