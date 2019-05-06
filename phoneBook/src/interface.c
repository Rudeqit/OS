#include "interface.h"
#include "phonebook.h"

void printAll(phonebook *phonebook) {
    user **iUser = phonebook->users;

    printf("\n#id\tName\tPhone\n\n");
    for (size_t i = 0; i < phonebook->numbUsers; i++)
        printf("#%zd\t%s\t%s\n", iUser[i]->id, iUser[i]->name, iUser[i]->phone);
}

void printUser(user* user) {
    printf("\n#id\tName\tPhone\n");
    printf("#%zd\t%s\t%s\n", user->id, user->name, user->phone);
}

void printRemoveError() {
    printf("\nError! Func remove_by_id crashed.\n");
}

void printSearchError() {
    printf("\nError! User not found.\n");
}

void printInputError() {
    printf("\nInvalid option! Try again.\n");
}

void printAddError() {
    printf("\nError! Func add_user crashed.\n");
}

void printUpdateError() {
    printf("\nError! Func update_user_by_id crashed.\n");
}

void printStart() {
    printf("Welcome to the phonebook application!\n"
        "For first let's create phonebook\n\n"
        "What will we use?\n"
        "\t1. Exist phonebook\n"
        "\t2. New phonebook\n\n"
        "Your choice?: ");
}

void printMenu() {
    printf(
        "\nSelect what you want to do with phonebook:\n\n"
        "\t1. Add user\n"
        "\t2. Delete user\n"
        "\t3. Update user\n"
        "\t4. Search user\n"
        "\t5. Print phonebook\n"
        "\t0. Exit\n\n"
        "Your choice?: ");
}

int AddMenu (phonebook* phonebook) {
    size_t id;
    char* name;
    char* phone;
    char* temp;

    printf("\nType user id: ");
    if (NULL == (temp = get_str()))
        return 1;
    id = atoi(temp);
    free(temp);
    if (0 == id)
        return -1;

    printf("Type user name: ");
    if (NULL == (name = get_str()))
        return 1;

    printf("Type user phone: ");
    if (NULL == (phone = get_str()))
        return 1;

    if (add_user(phonebook, id, name, phone))
        return 1;

    return 0;
}

int AddMenu_(phonebook* phonebook) {
    size_t id;
    char* name;
    char* phone;

    printf("\nType user id: ");
    scanf("%zd", &id);        

    printf("Type user name: ");
    if (NULL == (name = get_str_()))
        return 1;

    printf("Type user phone: ");
    if (NULL == (phone = get_str_()))
        return 1;

    if (add_user(phonebook, id, name, phone))
        return 1;

    return 0;
}

int remove_user_by_id_menu(phonebook* phonebok) {
    size_t id;

    printf("Type id user (type 0 for return): ");
    scanf("%zd", &id);

    if (id == 0)
        return 0;

    if (remove_user_by_id(phonebok, id))
        return 1;

    return 0;
}

int updateMenu(phonebook* phonebook) {
    size_t id;
    char* name;
    char* phone;

    printf("Type id user (type 0 for return): ");
    scanf("%zd", &id);

    if (id == 0)
        return 0;

    printf("Type new user name: ");
    if (NULL == (name = get_str_()))
        return 1;

    printf("Type new user phone: ");
    if (NULL == (phone = get_str_()))
        return 1;    

    if (update_user_by_id(phonebook, id, name, phone))
        return 1;

    return 0;
}

int searchMenu(phonebook* phonebook) {
    size_t id;
    char* name;
    char* phone;
    user* user;
    int input;

    printf("\n\t1. Search by id\n"
           "\t2. Search by name\n"
           "\t3. Search by phone\n"
           "\t0. Return\n"
           "\nYour choise: ");

    scanf("%d", &input);

    switch (input) {
        case 1:
            printf("Type id user: ");
            scanf("%zd", &id);

            user = search_by_id(phonebook, id);
            if (NULL == user)
                return 1;

            printUser(user);
            break;
        case 2:
            printf("Type user name: ");
            if (NULL == (name = get_str_()))
                return 1;

            user = search_by_name(phonebook, name);
            if (NULL == user)
                return 1;

            printUser(user);
            break;
        case 3:
            printf("Type user phone: ");
            if (NULL == (phone = get_str_()))
                return 1;

            user = search_by_phone(phonebook, phone);
            if (NULL == user)
                return 1;

            printUser(user);
            break;
        case 0:
            return 0;
    }

    return 0;
}