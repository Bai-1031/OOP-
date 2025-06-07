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
    cout << "╔════════════════════════════════════════════════════╗\n";
    cout << "║                  \033[36m 機密邀請函 \033[0m                      ║\n";
    cout << "║                                                    ║\n";
    cout << "║  親愛的 M.：                                       ║\n";
    cout << "║                                                    ║\n";
    cout << "║  你的狀況已持續穩定，藥物反應良好。                ║\n";
    cout << "║  雖然記憶仍斷斷續續，但這並非你的問題。            ║\n";
    cout << "║                                                    ║\n";
    cout << "║  有些事，我們不便透過正式管道說明。                ║\n";
    cout << "║  你是否從未質疑——那場意外，究竟是怎麼發生的？    ║\n";
    cout << "║                                                    ║\n";
    cout << "║  今晚，午夜十二點，舊實驗棟 B 區。                 ║\n";
    cout << "║  若你真渴望真相，請獨自前來。                      ║\n";
    cout << "║                                                    ║\n";
    cout << "║  \033[33m我們將揭開你遺忘的一切。\033[0m                          ║\n";
    cout << "║                                                    ║\n";
    cout << "║  \033[31m期待你的答覆。\033[0m                                    ║\n";
    cout << "╚════════════════════════════════════════════════════╝\n";
   
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
    cout << endl;

    cout << "現在時刻 晚間11:50" << endl<<endl;
    vector<string> ooo = {
        "\033[33m真高興你還是選擇過來了 \033[0m \n",
        "\033[31m本以為你在過來之前就死了... 想不到活到了現在\033[0m",
        "他看你臉色不太對勁，連忙轉移話題",
        "\033[33m就當是開個小玩笑 \033[0m ",
        "\033[33m請千萬別放在心上 \033[0m ",
        "你看著眼前輕浮的男人",
        "除了你與他，沒有其他人尾隨",
        "男人像前走了幾步，緩緩拉開實驗室厚重的鐵門",
        "你依然死死盯著他，但他似乎並不在意",
        "好像早就知道會發生甚麼",
        "\033[33m你應該也很清楚你來這裡的目的，我就不多廢話了\033[0m",
        "\033[33m提醒你一句\033[0m",
        "\033[31m接下來不論看到甚麼\033[0m",
        "\033[33m都不要試圖相信，也不要試圖回想\033[0m",
        "\033[33m不然......\033[0m",
        "\033[31m你很有可能離不開這裡\033[0m",
        "\033[33m還有，你的每一個選擇，都會攸關到你的未來\033[0m",
        "\033[31m我想，第一個選擇很快就會出現了。\033[0m",
        "突然，四周閃現一道藍光，男人輕笑一聲",
        "\033[36m---------------------\033[0m",
        "\033[36m--------------------------\033[0m",
        "\033[36m-----------------------\033[0m",
        "\033[33m這麼快就開始了嗎......果然還是一如往常的心急\033[0m",
        "\033[31m祝好運\033[0m",
        "接著，你的眼前閃現第一個問題字樣，男人的聲音也漸漸隱沒",
    };

    typeWriterParagraph(ooo, 30, 1000);

    cout << endl << endl;


    unordered_map<string, Scene> scenes;
    string playerName, item;
    int fearScore = 0;
    string choose; 


    while (true) {
        cout << "是否要自行選擇進入的劇場，還是交給命運安排？(yes 自己選擇/no 轉交命運)：";
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

        vector<string> aa = {
        "\033[33m顯然你已經做出選擇 \033[0m ",
        "\033[33m既然選擇交給我們處理 \033[0m ",
        "四周充斥著各種金屬儀器得雜音 \033[0m ",
        "\033[33m在這裡，我有幾個問題想問你 \033[0m ",
        "\033[31m 也順便讓我好好了解你 \033[0m \n",
        "\033[33m期待你的表現 \033[0m ",
        };
        typeWriterParagraph(aa, 30, 1000);
        cout << endl;


        cin.ignore();
        cout << "請輸入你的名字：";
        getline(cin, playerName);

        vector<string> introText = {
        "\033[33m還真是個沒有美感的名字\033[0m\n",
        "你頓時分辨不出傳出聲音的方向",
        "肚中的一團火油然而生",
        "\033[33我們接著下一題，一共有七題，接下來請好好回答\033[0m\n",
        "你不耐煩的踱著腳",
        "\033[91總不會是詢問一些奇怪的特殊癖好吧......\033[0m\n",
        };

        cout << "\n\n";
        typeWriterParagraph(introText, 30, 1000);  // 打字速度 50ms，句與句間隔 1 秒

        cout << endl;
        cout << "\n 問題 1：你更害怕哪種『無能為力』？\n"
            "(1. 在深夜中呼救卻沒人聽見\n"
            " 2. 親眼看到危險卻不能動彈\n"
            " 3. 知道真相卻無法說服任何人)：";
        int q1 = getChoice(1, 3);
        fearScore += q1; // 1->1, 2->2, 3->3（可對應孤立感/真相焦慮）

        cout << endl;
        cout << "\n 問題 2：當你『迷路』時，你的第一反應？\n"
            "(1. 找人幫忙\n"
            " 2. 原地等待\n"
            " 3. 硬著頭皮亂走一通)：";
        int q2 = getChoice(1, 3);
        fearScore += (4 - q2); // 主動者分數低，怕者高

        cout << endl;
        cout << "\n 問題 3：你最不想被誰背叛？\n"
            "(1. 家人\n"
            " 2. 摯友\n"
            " 3. 自己)：";
        int q3 = getChoice(1, 3);
        fearScore += q3; // 3(自我)最高，心理壓力大

        cout << endl;
        cout << "\n 問題 4：夜裡夢到陌生人在對你低語，你會怎麼做？\n"
            "(1. 回答他\n"
            " 2. 假裝聽不到\n"
            " 3. 嘗試掙脫夢境)：";
        int q4 = getChoice(1, 3);
        fearScore += (q4 == 2 ? 3 : q4); // 2為逃避反應，加高分

        cout << endl;
        cout << "\n 問題 5：你無法忍受哪種感覺？\n"
            "(1. 被注視\n"
            " 2. 被遺忘\n"
            " 3. 被控制)：";
        int q5 = getChoice(1, 3);
        fearScore += q5; // 3被控制最高

        cout << endl;
        cout << "\n 問題 6：如果現實突然扭曲，你最可能相信的說法是？\n"
            "(1. 自己瘋了\n"
            " 2. 這是個夢\n"
            " 3. 有東西正在操縱這一切)：";
        int q6 = getChoice(1, 3);
        fearScore += (4 - q6); // 越相信外力操控，fear 越低

        cout << endl;
        cout << "\n 問題 7：如果你能選一樣護身物，你會選？\n"
            "(1. 老舊的護身符\n"
            " 2. 一本沒有字的書\n"
            " 3. 一面永遠照不出影子的鏡子)：";
        int itemChoice = getChoice(1, 3);
        if (itemChoice == 1) {
            item = "amulet";
            fearScore += 1;
        }
        else if (itemChoice == 2) {
            item = "blank_book";
            fearScore += 2;
        }
        else {
            item = "mirror";
            fearScore += 3;
        }




        if (fearScore <= 10)
            scenes = createScenes();
        else if (fearScore <= 13)
            scenes = createHauntedForestScenes();
        else if (fearScore <= 16)
            scenes = createOrphanageScenes();
        else if (fearScore <= 18)
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
