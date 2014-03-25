#include <string>
#include <iostream>
int last_position = 0;
std::string string = "abcdefghijklmonprstuvwxyz";
std::string match = "j";
bool end_of_parsing = false;
std::string next(){
	bool end_of_word = false;
	std::string str = "";
	for(unsigned int i = last_position;i < string.length();i++){
		for(unsigned int j = 0;j < match.length();j++){
			if(string[i] == match[j] && !end_of_word){
				end_of_word = true;
			}
			if(string[i] != match[j] && end_of_word){
				break;break;
			}
		}
		if(!end_of_word)
			str += string[i];
		last_position = i;
	}
	if(last_position == string.length()-1 && end_of_word)
		end_of_parsing = true;
	return str;
}
int main(void){
	while(!end_of_parsing){
		std::cout << next();
	}
	return 0;
}
