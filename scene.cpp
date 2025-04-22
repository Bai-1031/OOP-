#include "scene.h"
#include <iostream>
#include <thread>
#include <chrono>

Scene::Scene(const string& i, const string& c, const vector<Choice>& ch)
    : id(i), content(c), choices(ch) {}

void Scene::display() const {
    // 逐字輸出場景內容，有點像打字效果
    for (char c : content) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(30));  // 等 30 毫秒
    }
    cout << "\n\n"; // 加兩行空白做美觀分隔

    // 顯示所有選項
    for (int i = 0; i < choices.size(); ++i) {
        choices[i].display(i);
    }
}

