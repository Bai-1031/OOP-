#include <iostream>
#include <string>
#include <unordered_map>
#include <limits>
#include "scene_manager.h"
#include "orphanage_manager.h"
#include "haunted_forest_manager.h"
#include "train_realm_manager.h"
#include "faceless_house_manager.h"  // ·s¼W²Ä¤­¼@¥»

using namespace std;

void displayIntro(int choice) {
    cout << "ùÝùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùß\n";
    cout << "ùø           ¢w Åå®ª¤å¦r«_ÀI ¢w           ùø\n";

    if (choice == 1) {
        cout << "ùø          ¡m¯d°|¯f©Ð¡G¹êÅç½g¡n        ùø\n";
        cout << "ùàùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùâ\n";
        cout << "ùø §A¦b¤@¶¡­¯¥Í¯f©Ð¿ô¨Ó¡A°O¾Ð¥þ¥¢¡K¡K   ùø\n";
        cout << "ùø ªÅ®ð¤¤Äjº©µÛ®ø¬r¤ô¨ý»P¤£¦w®ð®§¡C     ùø\n";
        cout << "ùø ¨C¤@­Ó¿ï¾Ü³£±N¤Þ»â¤£¦Pµ²§½¡C         ùø\n";
        cout << "ùø §A¡A¬O§_¤w·Ç³Æ¦n­±¹ï¯u¬Û¡H           ùø\n";
    }
    else if (choice == 2) {
        cout << "ùø         ¡m¶A©G©t¨à°|¡G®ø¥¢½g¡n       ùø\n";
        cout << "ùàùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùâ\n";
        cout << "ùø ¤@«Ê¯«¯µ«H¥ó¡A±a§A½ñ¤J³Q¿ò§Ñªº©t¨à°| ùø\n";
        cout << "ùø »G¦´Àð­±¶¡¡A¼çÂÃµÛµLÁnªº­úª_¡K¡K     ùø\n";
        cout << "ùø ¯u¬Û¡A±N¦b°O¾Ð»P¤ÛÄ±¤¤¯B²{¡C         ùø\n";
    }
    else if (choice == 3) {
        cout << "ùø           ¡m¸Þ´ËªL¡G°gÃú½g¡n         ùø\n";
        cout << "ùàùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùâ\n";
        cout << "ùø ¿@ÃúÅ¢¸nªº´ËªL¡A°g¥¢¨ä¤¤ªº®£©Æ¬G¨Æ¡C ùø\n";
        cout << "ùø ¶Ç»¡²`³BÁôÂÃµÛ³Q¿ò§Ñªº¯µ±K»P¦MÀI¡C   ùø\n";
    }
    else if (choice == 4) {
        cout << "ùø           ¡m¹q¨®²§¬É¡G°g³~½g¡n       ùø\n";
        cout << "ùàùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùâ\n";
        cout << "ùø ²`©]¹q¨®¡AªÅµL¤@¤H¡A¿O¥ú©¿©ú©¿·t¡C   ùø\n";
        cout << "ùø ¤@½ëµL²×ÂIªº¦C¨®¡A±a§A«e©¹¥¼ª¾²§¬É¡C ùø\n";
    }
    else if (choice == 5) {
        cout << "ùø        ¡mµLÁy¤H¤§«Î¡G¾µ¹Ú½g¡n        ùø\n";
        cout << "ùàùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùâ\n";
        cout << "ùø §A³Q§x¦b¤@©ÒµLÁy¤Hªº©t¨à°|äú¤ß¥B®£©Æ ùø\n";
        cout << "ùø ³o¸Ì¨S¦³°kÂ÷ªº¸ô¡A¥u¦³­±¹ï»P±Y¼ì¡K¡K ùø\n";
        cout << "ùø §Aªº²z´¼±N³Q¼¹µõ¦¨¸H¤ù¡C             ùø\n";
    }

    cout << "ùãùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùå\n";
}

int main() {
    cout << "ùÝùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùß\n";
    cout << "ùø           ¢w Åå®ª¤å¦r«_ÀI ¢w           ùø\n";
    cout << "ùø             ¹CÀ¸¼@¥»¿ï¾Ü             ùø\n";
    cout << "ùàùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùâ\n";
    cout << "ùø 1. ¡m¯d°|¯f©Ð¡G¹êÅç½g¡n              ùø\n";
    cout << "ùø 2. ¡m¶A©G©t¨à°|¡G®ø¥¢½g¡n            ùø\n";
    cout << "ùø 3. ¡m¸Þ´ËªL¡G°gÃú½g¡n                ùø\n";
    cout << "ùø 4. ¡m¹q¨®²§¬É¡G°g³~½g¡n              ùø\n";
    cout << "ùø 5. ¡mµLÁy¤H¤§«Î¡G¾µ¹Ú½g¡n            ùø\n";
    cout << "ùãùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùå\n";

    int storyChoice = 0;
    while (true) {
        cout << "½Ð¿ï¾Ü·QÅéÅçªº¼@¥»¡]¿é¤J 1¡ã5¡^¡G";
        cin >> storyChoice;
        if (storyChoice >= 1 && storyChoice <= 5) break;
        cout << "½Ð¿é¤J¦³®Ä¿ï¶µ¡]1¡ã5¡^¡C\n";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    displayIntro(storyChoice);
    cout << "\n½Ð«ö¤U Enter Áä¶}©l¹CÀ¸...";
    cin.get();

    unordered_map<string, Scene> scenes;
    string currentSceneId = "0";

    if (storyChoice == 1) scenes = createScenes();
    else if (storyChoice == 2) scenes = createOrphanageScenes();
    else if (storyChoice == 3) scenes = createHauntedForestScenes();
    else if (storyChoice == 4) scenes = createTrainRealmScenes();
    else if (storyChoice == 5) scenes = createFacelessHouseScenes(); // ·s¼W²Ä¤­¼@¥»³õ´º¨ç¦¡

    while (!currentSceneId.empty()) {
        const Scene& scene = scenes[currentSceneId];
        scene.display();

        if (scene.getChoices().empty()) {
            cout << "\n¬G¨Æµ²§ô¡C\n";
            break;
        }

        int choiceIndex = -1;
        while (true) {
            cout << "\n½Ð¿é¤J¿ï¶µ½s¸¹¡]1-" << scene.getChoices().size() << "¡^¡G";
            cin >> choiceIndex;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "½Ð¿é¤J¼Æ¦r¡C\n";
            }
            else if (choiceIndex < 1 || choiceIndex >(int)scene.getChoices().size()) {
                cout << "µL®Äªº¿ï¶µ¡A½Ð­«·s¿ï¾Ü¡C\n";
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
