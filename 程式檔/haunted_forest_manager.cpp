#include "haunted_forest_manager.h"
#include "choice.h"

#define RED_TEXT(str) "\033[31m" str "\033[0m"  // 紅色文字

std::unordered_map<std::string, Scene> createHauntedForestScenes() {
    std::unordered_map<std::string, Scene> scenes;

    scenes["0"] = Scene("0",
        "你踏入一片陰森的森林，" RED_TEXT("濃霧") "如鬼魂般纏繞，樹影在風中顫抖。\n"
        "耳邊似乎傳來低語聲……\n"
        "傳說中，森林深處藏有" RED_TEXT("失蹤村民的屍體") "。\n"
        "你是否敢深入探查？",
        {
            Choice("往森林深處走去", "", "1"),
            Choice("原路返回", "", "BAD_END")
        });

    scenes["1"] = Scene("1",
        "你發現一棟破舊小屋，" RED_TEXT("窗戶破裂") "，屋內閃過一道人影。\n"
        "一股" RED_TEXT("腐敗與霉味") "撲鼻而來，腳下的枯葉彷彿在低語……\n"
        "你想要……",
        {
            Choice("敲門", "", "2"),
            Choice("偷偷觀察", "", "3")
        });

    scenes["2"] = Scene("2",
        "門緩緩打開，一名" RED_TEXT("眼神空洞的老人") "站在你面前。\n"
        "他聲音低沉地說：『我知道你要找什麼……』\n"
        "他聲稱能帶你離開森林。\n"
        "你相信他嗎？",
        {
            Choice("相信老人", "", "4"),
            Choice("拒絕並離開", "", "5")
        });

    scenes["3"] = Scene("3",
        "你從窗縫窺視，發現牆上掛滿" RED_TEXT("失蹤者的照片") "。\n"
        "忽然，燭火熄滅，空氣瞬間凝結……\n"
        "你感覺" RED_TEXT("身後有東西靠近") "。",
        {
            Choice("轉身面對", "", "6"),
            Choice("逃跑", "", "BAD_END")
        });

    scenes["4"] = Scene("4",
        "老人領你進入森林深處的" RED_TEXT("秘密通道") "。\n"
        "途中樹木扭曲、低語聲不斷，感覺有什麼" RED_TEXT("東西在跟著你") "。\n"
        "你選擇……",
        {
            Choice("繼續前行", "", "7"),
            Choice("中途撤退", "", "5")
        });

    scenes["5"] = Scene("5",
        "你獨自穿越濃霧，視線模糊，方向全失。\n"
        "夜色降臨，" RED_TEXT("恐懼吞噬你的理智") "。\n"
        "你開始懷疑，是否還有人能聽見你的求救……",
        {
            Choice("嘗試找到出路", "", "8"),
            Choice("坐下等待救援", "", "BAD_END")
        });

    scenes["6"] = Scene("6",
        "你轉身，一個" RED_TEXT("無臉黑影") "出現在你眼前，牠眼中閃爍著紅光。\n"
        "牠一步步逼近，你冷汗直流。\n"
        "你能冷靜應對嗎？",
        {
            Choice("用火把嚇走牠", "", "7"),
            Choice("放棄抵抗", "", "BAD_END")
        });

    scenes["7"] = Scene("7",
        "你抵達森林深處，一座" RED_TEXT("詭異祭壇") "出現在眼前，周圍佈滿" RED_TEXT("乾涸的血跡") "。\n"
        "祭壇上擺著" RED_TEXT("村民遺留的物品") "，氣氛凝重。\n"
        "你決定……",
        {
            Choice("拿起物品", "", "GOOD_END"),
            Choice("離開祭壇", "", "TRUE_END")
        });

    scenes["8"] = Scene("8",
        "你在迷霧中找到一條" RED_TEXT("詭異小徑") "，似乎是出口。\n"
        "但腳下突然" RED_TEXT("陷落") "，你即將掉入一個黑暗陷阱……",
        {
            Choice("跳過陷阱", "", "SECRET_END"),
            Choice("小心繞過", "", "BAD_END")
        });

    // 結局
    scenes["TRUE_END"] = Scene("TRUE_END",
        "你選擇理智離開，雖未揭露真相，\n"
        "但你逃出了" RED_TEXT("死亡森林") "，重見天日。\n"
        "有時……" RED_TEXT("活著就是勝利") "。",
        {});

    scenes["GOOD_END"] = Scene("GOOD_END",
        "你拿走村民遺物，一道光從天空灑下，\n"
        "森林中的怨靈逐漸消散。\n"
        "詛咒終於解開，你成為" RED_TEXT("村莊英雄") "。",
        {});

    scenes["SECRET_END"] = Scene("SECRET_END",
        "你觸發陷阱卻誤入一處" RED_TEXT("地下密室") "，裡面藏著\n"
        "村莊歷史最黑暗的秘密。\n"
        "你，或許改變的不只是這座森林……",
        {});

    scenes["BAD_END"] = Scene("BAD_END",
        RED_TEXT("你被迷霧吞噬") "，再也沒有人找到你。\n"
        "你的故事……將成為森林的" RED_TEXT("下一段傳說") "。",
        {});

    return scenes;
}
