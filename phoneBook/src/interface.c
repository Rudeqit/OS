#include "interface.h"
#include "phonebook.h"

void printAll(user* phonebook) {
    user* i_user;

    printf("#id\tName\tPhone\n\n");
    
    for (i_user = phonebook; NULL != i_user; i_user = i_user -> next)
        printf("#%d\t%s\t%s\n", i_user->id, i_user->name, i_user->phone);
}