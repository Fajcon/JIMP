//
// Created by fajcon on 21.03.18.
//


#include <string>
#include <unordered_map>
#include <regex>
#include "SimpleTemplateEngine.h"
namespace nets {
    View::View(std::string text){
        text_ = text;
    }
    View::~View() {
    }
    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {
        int i;
        std::regex pattern(R"(\{\{\w+\}\})");
        std::smatch matches;
        std::string input = text_;

        while (std::regex_search(input, matches, pattern)){
            for (auto word: matches){
                std::string value = word.str().substr(2, word.length()-4);
                auto it = model.find(value);
                if (it != model.end()) {
                    std::string founded_key = it->first; // to jest klucz
                    std::string pattern = "{{"+founded_key+"}}";
                    std::string founded_value = it->second; // to jest wartosc
                    for (int j = 0; j < input.length(); ++j) {
                        if(input[j]=='{' && input[j+1]=='{' && input[j+2] != '{' && input[j+pattern.length()-1] == '}' && input[j+pattern.length()-2] == '}'){
                            i = j;
                            break;
                        }
                    }
                    input = input.replace(i, pattern.length(), founded_value);

                } else {
                    for (int j = 0; j < input.length(); ++j){
                        if(input[j] == '{' && input[j+1] == '{' && input[j+value.length()+2] == '}' && input[j+value.length()+3] == '}'){
                            i = j;
                            break;
                        }
                    }
                    input = input.replace(i, value.length()+4, "");
                }
            }

        }
        return input;
    }
}



