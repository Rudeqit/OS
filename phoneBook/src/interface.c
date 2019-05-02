#include "interface.h"
#include "phonebook.h"

void printAll(phonebook *phonebook) {
    user **iUser = phonebook->users;

    printf("#id\tName\tPhone\n\n");
    for (size_t i = 0; i != phonebook->numbUsers; i++)
        printf("#%d\t%s\t%s\n", iUser[i]->id, iUser[i]->name, iUser[i]->phone);
}