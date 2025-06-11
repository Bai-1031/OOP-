#include "scene.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <sstream> 

Scene::Scene(const string& i, const string& c, const vector<Choice>& ch)
    : id(i), content(c), choices(ch) {
}

void Scene::display() const {

    stringstream ss(content);
    string line;

    while (getline(ss, line, '\n')) {
        for (char c : line) {
            cout << c << flush;
            this_thread::sleep_for(chrono::milliseconds(20)); // 打字機效果
        }
        cin.ignore();
    }

    cout << "\n";

    for (int i = 0; i < choices.size(); ++i) {
        choices[i].display(i);
    }
}


void Scene::setId(string i) {
    id = i;
}
string Scene::getId() {
    return id;
}
void Scene::setContent(string c) {
    content = c;
}
string Scene::getContent() {
    return content;
}
const vector<Choice>& Scene::getChoices() const {
    return choices;
}
