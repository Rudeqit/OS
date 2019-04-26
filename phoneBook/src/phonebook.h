#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "user.h"
#include <stdlib.h>

user* create_phonebook(unsigned int id, char* name, char* phone);
user* add_user(user* phonebook, unsigned int id, char* name, char* phone);

#endif