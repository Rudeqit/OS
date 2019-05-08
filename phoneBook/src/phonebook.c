#include "phonebook.h"

phonebook* create_phonebook() {
    phonebook *phonebook = malloc(sizeof(*phonebook));

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

int add_user(phonebook* phonebook, size_t id, char* name, char* phone) {
    if (NULL == phonebook)
        return -1;

    size_t numbUsers = phonebook->numbUsers;

    if (numbUsers >= phonebook->size) {
        size_t newSize = phonebook->size + phonebook->block_size;
        void **newUsers = realloc(phonebook->users, sizeof(user*) * newSize);
        if (NULL == newUsers) {
            return 1;
        } else {
            phonebook->size = newSize;
            phonebook->users = (user**)newUsers;
            phonebook->users[numbUsers] = malloc(sizeof(user));
        }
    }

    if (NULL == phonebook->users[numbUsers]) {
        return 1;
    } else {
        phonebook->users[numbUsers]->id = id;
        phonebook->users[numbUsers]->name = name;
        phonebook->users[numbUsers]->phone = phone;
        ++phonebook->numbUsers;
    }

    return 0; 
}

void delete_phonebook(phonebook* phonebook) {
    user** iUser = phonebook->users;

    for (size_t i = 0; i < phonebook->numbUsers;  i++) {
        free(iUser[i]->name);
        free(iUser[i]->phone);
        free(iUser[i]);
    }

    free(phonebook->users);
    free(phonebook);
}

user* search_by_id(phonebook* phonebook, size_t id) {
    if (NULL == phonebook)
        return NULL;

    user** iUser = phonebook->users;

    for (size_t i = 0; i < phonebook->numbUsers; i++) {
        if (iUser[i]->id == id) {
            return iUser[i]; 
        }
    }

    return NULL;
}

user* search_by_name(phonebook* phonebook, char* name) {
    if (NULL == phonebook)
        return NULL;
        
    user** iUser = phonebook->users;

    for (size_t i = 0; i < phonebook->numbUsers; i++) {
        if (!strcmp(iUser[i]->name, name)) {
            return iUser[i]; 
        }
    }

    return NULL;
}

user* search_by_phone(phonebook* phonebook, char* phone) {
    if (NULL == phonebook)
        return NULL;

    user** iUser = phonebook->users;

    for (size_t i = 0; i < phonebook->numbUsers; i++) {
        if (!strcmp(iUser[i]->phone, phone)) {
            return iUser[i]; 
        }
    }

    return NULL;
}


int remove_user_by_id(phonebook* phonebook, size_t id) {
    if (NULL == phonebook)
        return -1;

    user** iUser = phonebook->users;

    size_t i;

    for (i = 0; i < phonebook->numbUsers; i++) {
        if (iUser[i]->id == id) {
            break;
        } else if (i == (phonebook->numbUsers - 1)) {
            return 1;
        }
    }

    user** newUsers = malloc(sizeof(user*) * (phonebook->size - 1));

    if (NULL == newUsers)
        return 1;

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
    free(iUser[i]->name);
    free(iUser[i]->phone);
    free(iUser[i]);
    free(phonebook->users);
    phonebook->users = newUsers;

    return 0;
}


int update_user_by_id(phonebook* phonebook, size_t id, char* NewName, char* NewPhone) {
    if (update_name_user_by_id(phonebook, id, NewName))
        return -1;

    if (update_phone_user_by_id(phonebook, id, NewPhone))
        return 1;

    return 0;
}

int update_name_user_by_id(phonebook* phonebook, size_t id, char* NewName) {
    if (NULL == phonebook)
        return -1;

    user* User = search_by_id(phonebook, id);

    if (NULL == User)
        return 1;

    free(User->name);
    User->name = NewName;

    return 0;
}

int update_phone_user_by_id(phonebook* phonebook, size_t id, char* NewPhone) {
    if (NULL == phonebook)
        return -1;

    user* User = search_by_id(phonebook, id);

    if (NULL == User)
        return 1;

    free(User->phone);
    User->phone = NewPhone;

    return 0;    
}

char* get_str() {
    char *line = malloc(100), *linep = line;
    size_t lenmax = 100, len = lenmax;
    int c;

    if(line == NULL)
        return NULL;

    for(;;) {
        c = fgetc(stdin);
        
        if(c == EOF)
            break;

        if(--len == 0) {
            len = lenmax;
            char * linen = realloc(linep, lenmax *= 2);

            if(linen == NULL) {
                free(linep);
                return NULL;
            }
            line = linen + (line - linep);
            linep = linen;
        }

        if(c == '\n')
            break;

        *line++ = c;
    }
    *line = '\0';
    return linep;
}

#if 0
char* get_str_() {
    char *line = malloc(100);

    if (line == NULL)
        return NULL;

    // scanf("%100s", line);
    fgets(line, 100, stdin);

    return line;
}
#endif

char* to_dynamic_str(char* str) {
    size_t len = (size_t)strlen(str);

    char* dStr = malloc(sizeof(char) * (len + 1));
    if (NULL == dStr)
        return NULL;

    for (size_t i = 0; i < len; i++)
        dStr[i] = str[i];

    dStr[len] = '\0';

    return dStr;
}
