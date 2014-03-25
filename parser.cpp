#include "parser.h"
#include <string>
// constructor
Parser::Parser(std::string s, std::string m)
{
    str = s;
    match = m;
    last_position = 0;
    end_of_parsing = false;
}
bool Parser::endOfParsing(void){
    return end_of_parsing;
}
std::string Parser::next(){
    std::string part = "";
    if(last_position == str.length()){
        end_of_parsing = true;
    }
    else{
        bool eqi = false,end_of_word = false;
        for(unsigned int i = last_position;i < str.length();i++, eqi = false){
            for(unsigned int j = 0;j < match.length();j++){
                if(str[i] == match[j]){
                    eqi = true;
                    if(!end_of_word)
                        end_of_word = true;
                }
                if(j == (match.length()-1) && !eqi && end_of_word){
                    break;
                }
            }
            if(end_of_word && !eqi){
                break;
            }
            if(!end_of_word)
                part += str[i];
            last_position = i;
        }
        last_position++;
    }
    return part;
}
// added one chat to match string
void Parser::update_match(char c){
    last_position = 0;
    end_of_parsing = false;
    match += c;
}
// clean match string
void Parser::delete_match(){
    last_position = 0;
    end_of_parsing = false;
    match = "";
}
