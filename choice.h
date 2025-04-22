#ifndef CHOICE_H
#define CHOICE_H

#include <string>

using namespace std;  // 讓我們省去每次都寫 std::

// 選項類別，代表玩家在場景中能做的選擇
class Choice {
public:
    string text;           // 顯示給玩家看的選項文字
    string hint;           // 玩家選擇後看到的提示訊息（用來補充劇情）
    string nextSceneId;    // 選擇這個選項後會跳轉的場景 ID

    Choice() = default;
    Choice(const string& text, const string& hint, const string& nextSceneId);

    void display(int index) const; // 顯示這個選項（加上序號）
};

#endif  // CHOICE_H
