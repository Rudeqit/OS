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

    for (size_t i = 0; i < phonebook->numbUsers;  i++)
        free(iUser[i]);

    free(phonebook->users);
    free(phonebook);
}

user* search_by_id(phonebook* phonebook, size_t id) {
    user **iUser = phonebook->users;

    for (size_t i = 0; i < phonebook->numbUsers; i++) {
        if (iUser[i]->id == id) {
            return iUser[i]; 
        }
    }

    return NULL;
}

user* search_by_name(phonebook* phonebook, char* name) {
    user **iUser = phonebook->users;

    for (size_t i = 0; i < phonebook->numbUsers; i++) {
        if (!strcmp(iUser[i]->name, name)) {
            return iUser[i]; 
        }
    }

    return NULL;
}

user* search_by_phone(phonebook* phonebook, char* phone) {
    user **iUser = phonebook->users;

    for (size_t i = 0; i < phonebook->numbUsers; i++) {
        if (!strcmp(iUser[i]->phone, phone)) {
            return iUser[i]; 
        }
    }

    return NULL;
}


int remove_user_by_id(phonebook* phonebook, size_t id) {
    user** iUser = phonebook->users;

    size_t i;

    for (i = 0; i < phonebook->numbUsers; i++) {
        if (iUser[i]->id == id) {
            break;
        } else if (i == (phonebook->numbUsers - 1)) {
            return 0;
        }
    }

    user** newUsers = malloc(sizeof(user*) * (phonebook->size - 1));

    if (NULL == newUsers) {
        return 0;
    }

    int ij = 0;

    for (size_t j = 0; j < phonebook->numbUsers; j++) {
        if (j == i) {
            ij = 1;
            continue;
        } else if (ij) {
            newUsers[j - 1] = iUser[j];
        } else {
            newUsers[j] = iUser[j];
        }
    }

    --phonebook->size;
    --phonebook->numbUsers;
    free(iUser[i]);
    free(phonebook->users);
    phonebook->users = newUsers;

    return 1;
}

/*
struct update_user() {

}
*/