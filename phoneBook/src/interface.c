#include "interface.h"
#include "phonebook.h"

void printAll(phonebook *phonebook) {
    user **iUser = phonebook->users;

    printf("\n#id\tName\tPhone\n\n");
    for (size_t i = 0; i < phonebook->numbUsers; i++)
        printf("#%zd\t%s\t%s\n", iUser[i]->id, iUser[i]->name, iUser[i]->phone);
}

void printRemoveError() {
    printf("Error! Func remove_by_id crash.\n");
}