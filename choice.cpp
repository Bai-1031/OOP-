#include "choice.h"
#include <iostream>

Choice::Choice(const string& t, const string& h, const string& n)
    : text(t), hint(h), nextSceneId(n) {}

void Choice::display(int index) const {
    cout << index + 1 << ". " << text << endl;
}
