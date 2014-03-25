#include "menu.h"
#include "parser.h"
#include <string>
#include <iostream>
Menu::Menu()
{
}
void Menu::show()
{
    std::string str;
    char c;
    std::cout << "Welcome! This is your first login, please, input your string:" << std::endl;
    std::cin >> str;
    Parser p(str);
    while(c != 'q'){
        std::cout << "Please, input one symbol:"<< std::endl
                << "a) Added a some delimiter symbol" << std::endl
                << "r) Remove all delimiters" << std::endl
                << "o) Output substrings" << std::endl
                << "q) Quit" << std::endl;
        std::cin >> c;
        switch (c) {
        case 'a':
            std::cout << "Input a symbol:" << std::endl;
            std::cin >> c;
            p.update_match(c);
            c = ' ';
            break;
        case 'r':
            std::cout << "Done!" << std::endl;
            p.delete_match();
            break;
        case 'o':
            while(!p.endOfParsing()){
                std::cout << p.next() << std::endl;
            }
            break;
        }
    }
}
