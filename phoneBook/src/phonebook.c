#include "phonebook.h"

phonebook* create_phonebook() {
    phonebook* phonebook = malloc(sizeof(*phonebook));

    if (NULL != phonebook) {
        phonebook->numbUsers = 0;
        phonebook->size = 1;
        phonebook->block_size = 1;
        phonebook->users = malloc(sizeof(user*));
        *phonebook->users = malloc(sizeof(user) * phonebook->block_size);
        if (NULL == phonebook->users) {
            free(phonebook);
            return NULL;
        }
        if(NULL == *phonebook->users) {
            free(phonebook->users);
            free(phonebook);
            return NULL;
        }
    }

    return phonebook;
}

int add_user(phonebook *phonebook, size_t id, char* name, char* phone) {
    size_t numbUsers = phonebook->numbUsers;

    if (numbUsers >= phonebook->size) {
        size_t newSize = phonebook->size + phonebook->block_size;
        void **newUsers = realloc(phonebook->users, sizeof(user*) * newSize);
        if (NULL == newUsers) {
            return 0;
        } else {
            phonebook->size = newSize;
            phonebook->users = (user**)newUsers;
            phonebook->users[numbUsers] = malloc(sizeof(user));
        }
    }

    if (NULL == phonebook->users[numbUsers]) {
        return 0;
    } else {
        phonebook->users[numbUsers]->id = id;
        phonebook->users[numbUsers]->name = name;
        phonebook->users[numbUsers]->phone = phone;
        ++phonebook->numbUsers;
    }

    return 1; 
}

void delete_phonebook(phonebook* phonebook) {
    user **iUser = phonebook->users;

    for (size_t i = 0; i != phonebook->numbUsers;  i++)
        free(iUser[i]);

    free(phonebook->users);
    free(phonebook);
}

/*
struct remove_user() {

}
*/

/*
struct search_by_id() {

}
*/

/*
struct update_user() {

}
*/