#include <iostream>
#include "Table.h" 

int main() {
    try {
        Table tab(6);
        tab.PutPair(271236, "Bevz Markiyan");
        tab.PutPair(272127, "Mekheda Ksenia");
        tab.PutPair(276544, "Prozay Ivan");
        tab.PutPair(274345, "Shulhak Danylo");
        tab.PutPair(276564, "Mraka Olga");
        tab.PutPair(274346, "Proz Mykhailo-Ihor");
        tab.PutPair(276543, "Kovalchuk Julia");
        tab.PutPair(271422, "Lopatinskiy Oleksa");
        tab.PrintTable();
        std::cout << "Who you want to terminate? \n";
        int delete_choice;
        std::cin >> delete_choice;
        try {
            tab.PrintPair(delete_choice, tab.GetValue(delete_choice));
            tab.EraseByKey(delete_choice);
            tab.PrintTable();
        }
        catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    
        Table tab(0);
        try {
            tab.EraseByKey(121);
        }
        catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

    return 0;
}