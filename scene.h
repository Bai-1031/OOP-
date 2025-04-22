#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>
#include "choice.h"

using namespace std;  // 讓我們省去每次都寫 std::

// 場景類別，每個場景有劇情內容與多個選項
class Scene {
public:
    string id;                 // 場景的唯一識別 ID
    string content;           // 場景描述文字（顯示在畫面上）
    vector<Choice> choices;   // 此場景的所有可選項目

    Scene() = default;
    Scene(const string& id, const string& content, const vector<Choice>& choices);

    void display() const;    // 顯示場景內容與所有選項
};

#endif  // SCENE_H

