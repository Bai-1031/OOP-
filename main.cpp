#include <iostream>
#include <string>
#include <unordered_map>
#include <limits>
#include "scene_manager.h"
#include "orphanage_manager.h"
#include "haunted_forest_manager.h"
#include "train_realm_manager.h"
#include "faceless_house_manager.h" 
#include <vector>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;

void showInvitationLetter() {
    cout << "╔══════════════════════════════════════╗\n";
    cout << "║             \033[36m奇怪的邀請函\033[0m             ║\n";
    cout << "║                                      ║\n";
    cout << "║  尊敬的實驗者：                      ║\n";
    cout << "║  恭喜你被選中，將參與一場未知的實驗。║\n";
    cout << "║  在這裡，你的恐懼將被一一揭露。      ║\n";
    cout << "║                                      ║\n";
    cout << "║  請準備好，再按下 Enter 鍵繼續……   ║\n";
    cout << "╚══════════════════════════════════════╝\n";

    cout << "\n>>> 按下 Enter 鍵繼續...";
    cin.ignore();
}

// 單行打字效果
void typeWriter(const string& text, int delayMs = 30) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(milliseconds(delayMs));
    }
    cout << endl;
}

// 多行打字機，每行打完暫停一會再顯示下一行
void typeWriterParagraph(const vector<string>& lines, int delayMs = 30, int pauseAfterLine = 500) {
    for (const auto& line : lines) {
        typeWriter(line, delayMs);
        this_thread::sleep_for(milliseconds(pauseAfterLine));
    }
}


int getChoice(int minOption, int maxOption) {
    int choice;
    while (true) {
        cin >> choice;

        if (cin.fail() || choice < minOption || choice > maxOption) {
            cin.clear(); // 清除 cin 錯誤狀態
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除緩衝區
            cout << "請輸入有效的選項（" << minOption << " - " << maxOption << "）：";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 清除換行符
            return choice;
        }
    }
}


void displayIntro(int choice) {

    cout << "╔══════════════════════════════════════╗\n";
    cout << "║           ─ 驚悚文字冒險 ─           ║\n";

    if (choice == 1) {
        cout << "║          《留院病房：實驗篇》        ║\n";
        cout << "╠══════════════════════════════════════╣\n";
        cout << "║ 你在一間陌生病房醒來，記憶全失……   ║\n";
        cout << "║ 空氣中瀰漫著消毒水味與不安氣息。     ║\n";
        cout << "║ 每一個選擇都將引領不同結局。         ║\n";
        cout << "║ 你，是否已準備好面對真相？           ║\n";
    }
    else if (choice == 2) {
        cout << "║         《詛咒孤兒院：消失篇》       ║\n";
        cout << "╠══════════════════════════════════════╣\n";
        cout << "║ 一封神秘信件，帶你踏入被遺忘的孤兒院 ║\n";
        cout << "║ 腐朽牆面間，潛藏著無聲的哭泣……     ║\n";
        cout << "║ 真相，將在記憶與幻覺中浮現。         ║\n";
    }
    else if (choice == 3) {
        cout << "║           《詭森林：迷霧篇》         ║\n";
        cout << "╠══════════════════════════════════════╣\n";
        cout << "║ 濃霧籠罩的森林，迷失其中的恐怖故事。 ║\n";
        cout << "║ 傳說深處隱藏著被遺忘的秘密與危險。   ║\n";
    }
    else if (choice == 4) {
        cout << "║           《電車異界：迷途篇》       ║\n";
        cout << "╠══════════════════════════════════════╣\n";
        cout << "║ 深夜電車，空無一人，燈光忽明忽暗。   ║\n";
        cout << "║ 一趟無終點的列車，帶你前往未知異界。 ║\n";
    }
    else if (choice == 5) {
        cout << "║        《無臉人之屋：噩夢篇》        ║\n";
        cout << "╠══════════════════════════════════════╣\n";
        cout << "║ 你被困在一所無臉人的孤兒院噁心且恐怖 ║\n";
        cout << "║ 這裡沒有逃離的路，只有面對與崩潰…… ║\n";
        cout << "║ 你的理智將被撕裂成碎片。             ║\n";
    }

    cout << "╚══════════════════════════════════════╝\n";
}

int main() {
    
    showInvitationLetter();

    vector<string> ooo = {
        "幹 三小啦。",
    };
    typeWriterParagraph(ooo, 30, 1000);
    cout << endl;

    unordered_map<string, Scene> scenes;
    string playerName, item;
    int fearScore = 0;
    string choose; 


    while (true) {
        cout << "是否要自行選擇劇本？(yes/no)：";
        cin >> choose;

        if (choose == "yes" || choose == "no") break;
        cout << "請輸入正確的選項（yes 或 no）。\n";
    }

    if (choose == "yes") {

        cout << "╔══════════════════════════════════════╗\n";
        cout << "║           ─ 驚悚文字冒險 ─           ║\n";
        cout << "║             遊戲劇本選擇             ║\n";
        cout << "╠══════════════════════════════════════╣\n";
        cout << "║ 1. 《留院病房：實驗篇》              ║\n";
        cout << "║ 2. 《詛咒孤兒院：消失篇》            ║\n";
        cout << "║ 3. 《詭森林：迷霧篇》                ║\n";
        cout << "║ 4. 《電車異界：迷途篇》              ║\n";
        cout << "║ 5. 《無臉人之屋：噩夢篇》            ║\n";
        cout << "╚══════════════════════════════════════╝\n";

        int storyChoice = 0;
        while (true) {
            cout << "請選擇想體驗的劇本（輸入 1～5）：";
            cin >> storyChoice;
            if (storyChoice >= 1 && storyChoice <= 5) break;
            cout << "請輸入有效選項（1～5）。\n";
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        displayIntro(storyChoice);
        cout << "\n請按下 Enter 鍵開始遊戲...";
        cin.get();

        string currentSceneId = "0";

        if (storyChoice == 1) scenes = createScenes();
        else if (storyChoice == 2) scenes = createOrphanageScenes();
        else if (storyChoice == 3) scenes = createHauntedForestScenes();
        else if (storyChoice == 4) scenes = createTrainRealmScenes();
        else if (storyChoice == 5) scenes = createFacelessHouseScenes(); // 新增第五劇本場景函式
    }
    else if (choose == "no") {

        cin.ignore();
        cout << "請輸入你的名字：";
        getline(cin, playerName);

        vector<string> introText = {
        "這個世界不再受你熟悉的邏輯所控制。",
        "當你踏入這扇門，一切都將改變。",
        "請記住，你的每個選擇都會帶來後果。"
        };

        cout << "\n\n";
        typeWriterParagraph(introText, 30, 1000);  // 打字速度 50ms，句與句間隔 1 秒

        cout << endl;
        cout << "\n問題 1：你怕黑的程度？(1 非常怕 / 2 有點怕 / 3 不怕)：";
        int q1 = getChoice(1, 3);
        fearScore += (4 - q1); // 1 -> +3, 2 -> +2, 3 -> +1

        cout << endl;
        cout << "\n問題 2：你對血腥畫面的感受？(1 無法接受 / 2 勉強可以 / 3 完全沒差)：";
        int q2 = getChoice(1, 3);
        fearScore += (4 - q2); // 同上

        cout << endl;
        cout << "\n問題 3：你對孤獨的感覺？(1 非常害怕 / 2 還行 / 3 喜歡一個人)：";
        int q3 = getChoice(1, 3);
        fearScore += (4 - q3);

        cout << endl;
        cout << "\n問題 4：你會帶哪個道具？(1. flashlight / 2. camera / 3. knife)：";
        int itemChoice = getChoice(1, 3);
        if (itemChoice == 1) {
            item = "flashlight";
            fearScore += 3;
        }
        else if (itemChoice == 2) {
            item = "camera";
            fearScore += 2;
        }
        else {
            item = "knife";
            fearScore += 1;
        }


        if (fearScore <= 4)
            scenes = createScenes();
        else if (fearScore <= 6)
            scenes = createHauntedForestScenes();
        else if (fearScore <= 8)
            scenes = createOrphanageScenes();
        else if (fearScore <= 10)
            scenes = createFacelessHouseScenes();
        else
            scenes = createTrainRealmScenes();

        cout << "\n歡迎，實驗者 " << playerName << "，\033[31m準備好了我們就開始。\033[0m\n";
        cout << endl<<"請按下 Enter 鍵開始遊戲..." << endl;
        cin.get();
    }

    string currentSceneId = "0";
    while (!currentSceneId.empty()) {
        const Scene& scene = scenes[currentSceneId];
        scene.display();

        if (scene.getChoices().empty()) {
            cout << "\n故事結束。\n";
            break;
        }

        int choiceIndex = -1;
        while (true) {
            cout << "\n請輸入選項編號（1-" << scene.getChoices().size() << "）：";
            cin >> choiceIndex;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "請輸入數字。\n";
            }
            else if (choiceIndex < 1 || choiceIndex >(int)scene.getChoices().size()) {
                cout << "無效的選項，請重新選擇。\n";
            }
            else {
                break;
            }
        }

        const Choice& choice = scene.getChoices()[choiceIndex - 1];
        if (!choice.getHint().empty()) {
            cout << "\n" << choice.getHint() << "\n";
        }

        currentSceneId = choice.getNextSceneId();
        cout << "\n---\n\n";
    }

    return 0;

}
