#include "choice.h"
#include <iostream>

Choice::Choice(const string& t, const string& h, const string& n)
    : text(t), hint(h), nextSceneId(n) {
}

void Choice::setText(string t) {
    text = t;
}
string Choice::getText() const{
    return text;
}
void Choice::setHint(string h) {
    hint = h;
}
string Choice::getHint()const {
    return hint;
}
void Choice::setNextSceneId(string n) {
    nextSceneId = n;
}
string Choice::getNextSceneId()const {
    return nextSceneId;
}

void Choice::display(int index) const {
    cout << index + 1 << ". " << text << endl;
}
