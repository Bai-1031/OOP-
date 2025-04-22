#include <iostream>
#include "scene_manager.h"

int main() {
    auto scenes = createScenes();   // 初始化劇情資料
    string currentSceneId = "0";    // 遊戲從場景 0 開始

    while (!currentSceneId.empty()) {  // 只要還有場景，就繼續遊戲
        const Scene& scene = scenes[currentSceneId];  // 找到當前場景
        scene.display();   // 顯示場景內容與選項

        if (scene.choices.empty()) {
                    cout << "\n 故事結束。\n";
                    break;
                }

        
        int choiceIndex = 0;
        cout << "\n請輸入選項編號（1-" << scene.choices.size() << "）：";
        cin >> choiceIndex;   // 讀取使用者輸入

        if (cin.fail()) {   // 如果輸入錯誤（非數字）
            cin.clear();    // 清除錯誤旗標
            cin.ignore(10000, '\n');  // 忽略剩餘輸入直到換行
            cout << "請輸入數字。\n\n";
            continue;
        }

        // 若輸入編號超出範圍
        if (choiceIndex < 1 || choiceIndex > scene.choices.size()) {
            cout << "無效的選項，請重新選擇。\n\n";
            continue;
        }

        const Choice& choice = scene.choices[choiceIndex - 1];  // 取得對應選項（陣列從 0 開始）

        if (!choice.hint.empty()) {
            cout << "\n" << choice.hint << "\n";   // 顯示提示文字
        }

        currentSceneId = choice.nextSceneId;  // 跳轉到下一個場景 ID
        cout << "\n---\n\n";  // 美觀分隔
        
    }
    return 0;
}
