#ifndef TASK_3_TRANSLATOR_H
#define TASK_3_TRANSLATOR_H

#include <string>
#include <vector>
#include <map>


using namespace std;

class Translator {
public:

    Translator() = default;

    void Add(string_view source, string_view target);
    string_view TranslateForward(string_view source) const;
    string_view TranslateBackward(string_view target) const;


private:
    std::map<std::string, std::string> forward;
    std::map<std::string_view , std::string_view> backward;
};


#endif //TASK_3_TRANSLATOR_H
