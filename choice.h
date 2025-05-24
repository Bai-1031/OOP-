#ifndef CHOICE_H
#define CHOICE_H

#include <string>
using namespace std;

class Choice {
private:
    string text;
    string hint;
    string nextSceneId;
public:
    Choice() = default;
    Choice(const string& text, const string& hint, const string& nextSceneId);

    void setText(string);
    string getText()const;
    void setHint(string);
    string getHint()const;
    void setNextSceneId(string);
    string getNextSceneId()const;

    void display(int index) const;
};

#endif
