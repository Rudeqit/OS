#include "phonebook.h"

user* create_phonebook(unsigned int id, char* name, char* phone) {
    user* phonebook = malloc(sizeof(user));
    
    if (NULL != phonebook) {
        phonebook->id = id;
        phonebook->name = name;
        phonebook->phone = phone;
        phonebook->next = NULL;
    }

    return phonebook;
}

user* add_user(user* phonebook, unsigned int id, char* name, char* phone) {
    user* newPhonebook = create_phonebook(id, name, phone);
    
    if (NULL != newPhonebook) {
        newPhonebook->next = phonebook;
    }
    
    return newPhonebook;
}

/*
struct remove_user() {

}
*/

/*
void delete_phonebook() {

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