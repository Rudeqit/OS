#include "interface.h"
#include "phonebook.h"

int main(int argc, char** argv) {
    #if 1
    phonebook *phonebook = create_phonebook();
    char input[3];

    #if 1
    add_user(phonebook, 1, to_dynamic_str("Pupa"), to_dynamic_str("+ 7 913"));
    add_user(phonebook, 2, to_dynamic_str("Lupa"), to_dynamic_str("8 913"));
    
    #endif

    while (1) {
        printMenu();
    
        fgets(input, 3, stdin);

        switch (*input) {
            case '1': // Add
                if (AddMenu(phonebook))
                    printAddError();
                break;
            case '2': // Remove
                if (remove_user_by_id_menu(phonebook))
                    printRemoveError();
                break;
            case '3': // Update
                if (updateMenu(phonebook))
                    printUpdateError();
                break;
            case '4': // Search
                if (searchMenu(phonebook))
                    printSearchError();
                break;
            case '5': // Print
                printAll(phonebook);
                break;                
            case '0':
                delete_phonebook(phonebook);
                return 0;
            default:
                printInputError();
                break;
        }
        
    }
    #endif
    
    /**
     * For test.
     */
    #if 0
    phonebook *phonebook = create_phonebook();

    add_user(phonebook, 1, to_dynamic_str("Pupa"), to_dynamic_str("+ 7 913"));
    add_user(phonebook, 2, to_dynamic_str("Lupa"), to_dynamic_str("8 913"));
    add_user(phonebook, 3, to_dynamic_str("Zjmih"), to_dynamic_str("666"));

    printAll(phonebook);

    if (update_user_by_id(phonebook, 1, to_dynamic_str("NewPupa"), to_dynamic_str("-787")))
        printSearchError();

    printAll(phonebook);

    #if 0

    if (AddMenu(phonebook))
        printAddError();

    printAll(phonebook);

    #endif

    if (remove_user_by_id(phonebook, 1))
        printRemoveError();

    printAll(phonebook);

    delete_phonebook(phonebook);
    #endif

    return 0;

}