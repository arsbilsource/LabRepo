#include "Translator.h"
#include "../../Utils/TestRunner.h"

using namespace std;


void TestSimple() {
    Translator translator;
    translator.Add(string("okno"), string("window"));
    translator.Add(string("stol"), string("table"));

    ASSERT_EQUAL(translator.TranslateForward("okno"), "window");
    ASSERT_EQUAL(translator.TranslateBackward("table"), "stol");
    ASSERT_EQUAL(translator.TranslateBackward("stol"), "");
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestSimple);

    Translator t;
    t.Add(string("okno"), string("window"));
    t.Add(string("stol"), string("table"));
    t.Add(string("okno"), string("window1"));
    t.Add(string("stol"), string("table1"));
    t.Add(string("okno"), string("window2"));
    t.Add(string("stol"), string("table2"));
    t.Add(string("okno2"), string("window10"));
    t.Add(string("stol2"), string("table10"));


    std::cout << t.TranslateForward("okno") << "\n";
    std::cout << t.TranslateForward("okno2") << "\n";
    std::cout << t.TranslateForward("stol") << "\n";
    std::cout << t.TranslateForward("stol2") << "\n";

    std::cout << t.TranslateForward("window10") << "\n";
    std::cout << t.TranslateForward("window2") << "\n";
    std::cout << t.TranslateForward("table2") << "\n";
    std::cout << t.TranslateForward("table10") << "\n";


    return 0;
}

