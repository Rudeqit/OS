#include "interface.h"
#include "phonebook.h"

int main(int argc, char** argv) {
    phonebook *phonebook = create_phonebook();

    add_user(phonebook, 1, "Pupa", "+ 7 913");
    add_user(phonebook, 2, "Lupa", "8 913");
    add_user(phonebook, 3, "Sanya", "666");
    add_user(phonebook, 4, "Zjmih", "777");

    printAll(phonebook);

    if (!(remove_user_by_id(phonebook, 1)))
        printRemoveError();

    printAll(phonebook);

    delete_phonebook(phonebook);

    return 0;
}