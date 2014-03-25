#ifndef PARSER_H
#define PARSER_H
#include <string>

class Parser
{
private:
    std::string str;
    std::string match;
    bool isUpdated;
    unsigned int last_position;
    bool end_of_parsing;
public:
    Parser(std::string s, std::string m="");
    void update_match(char c);
    void delete_match(void);
    bool endOfParsing();
    std::string next(void);
};
#endif // PARSER_H
