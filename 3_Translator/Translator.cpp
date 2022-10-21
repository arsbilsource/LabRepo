#include "Translator.h"

    void Add(string_view source, string_view target){
        forward.emplace(std::make_pair(source, target));
        auto it = forward.find(std::string(source));
        auto it2 = backward.find(target);
        if(it2 != backward.end()) {
            backward.erase(it2);
        }
        backward.emplace(it->second, it->first);
    }

    string_view TranslateForward(string_view source) const{
        auto it = forward.find(std::string(source));
        if(it != forward.end()){
            return it->second;
        } else return "";
    }

    string_view TranslateBackward(string_view target) const{
        auto it = backward.find(target);
        if(it != backward.end()){
            return it->second;
        } else return "";
    }