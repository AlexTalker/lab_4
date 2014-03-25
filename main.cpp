#include <iostream>
#include <string>
#include "parser.h"

using namespace std;

int main(void)
{
    std::string str, match;
    char c;
    cin >> str;
    cin >> match;
    Parser p(str, match);
    cin >> c;
    while(!p.endOfParsing()){
        str = p.next();
        cout << str << endl;
    }
    p.update_match(c);
    while(!p.endOfParsing()){
        str = p.next();
        cout << str;
    }

    return 0;
}

