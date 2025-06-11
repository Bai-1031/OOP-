#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>
#include "choice.h"
using namespace std;

class Scene {
private:
    string id;
    string content;
    vector<Choice> choices;
public:
    Scene() = default;
    Scene(const string& id, const string& content, const vector<Choice>& choices);

    void setId(string);
    string getId();
    void setContent(string);
    string getContent();

    const vector<Choice>& getChoices() const;

    void display() const;
};

#endif
