#include "train_realm_manager.h"
#include "choice.h"

#define RED "\033[31m"
#define RESET "\033[0m"

std::unordered_map<std::string, Scene> createTrainRealmScenes() {
    std::unordered_map<std::string, Scene> scenes;

    scenes["0"] = Scene("0",
        "你登上一班奇怪的末班電車，車廂裡空無一人，燈光忽明忽暗。\n"
        RED "車門關上後，列車開始無目的地行駛……" RESET,
        {
            Choice("觀察車廂內的廣告", "", "1"),
            Choice("按緊急鈴", "", "2")
        });

    scenes["1"] = Scene("1",
        "廣告紙條上寫著：『下車即是死亡』。\n"
        RED "你突然聽到耳邊傳來細語聲……" RESET,
        {
            Choice("大聲喊叫", "", "BAD_END"),
            Choice("裝作沒聽見", "", "3")
        });

    scenes["2"] = Scene("2",
        RED "緊急鈴毫無反應，反而觸發警報聲，車內燈瞬間熄滅。\n"
        "黑暗中，你感覺有人在你身後呼氣。" RESET,
        {
            Choice("轉頭查看", "", "4"),
            Choice("閉眼假裝睡著", "", "BAD_END")
        });

    scenes["3"] = Scene("3",
        "你靜靜坐著，耳語聲漸漸遠去，車窗外竟是一片墓地景象。\n"
        RED "列車正穿過不存在的空間……" RESET,
        {
            Choice("嘗試開門", "", "5"),
            Choice("繼續等待", "", "6")
        });

    scenes["4"] = Scene("4",
        RED "你看到一個穿著制服但沒有臉的車掌站在你後面。\n"
        "他遞給你一張車票，上頭寫著『單程』。" RESET,
        {
            Choice("接過車票", "", "7"),
            Choice("拒絕並逃跑", "", "BAD_END")
        });

    scenes["5"] = Scene("5",
        RED "門竟然打開了，但外面是空無一物的虛空……\n"
        "一股強風吹向你。" RESET,
        {
            Choice("跳下列車", "", "SECRET_END"),
            Choice("關門回座", "", "6")
        });

    scenes["6"] = Scene("6",
        "列車停下來，一道紅色隧道出現在眼前。\n"
        RED "你感覺一股無形的力量在拉扯你。" RESET,
        {
            Choice("進入隧道", "", "TRUE_END"),
            Choice("留在原地", "", "BAD_END")
        });

    scenes["7"] = Scene("7",
        "你手中車票燃燒起來，列車瞬間閃回現實。\n"
        RED "你醒來，卻發現自己的手機上寫著『歡迎回來』。" RESET,
        {
            Choice("查看手機內容", "", "GOOD_END"),
            Choice("拔掉電池", "", "BAD_END")
        });
    // scene["8"] - 鏡子車窗
    scenes["8"] = Scene("8",
        "你注意到車窗變成了鏡子，\n"
        RED "裡頭的你正在對你微笑……但你根本沒在笑。" RESET,
        {
            Choice("敲碎車窗", "", "9"),
            Choice("無視鏡子", "", "10")
        });

    // scene["9"] - 血手窗內
    scenes["9"] = Scene("9",
        RED "玻璃碎裂，一隻血手從窗內抓住你！\n"
        "你被拖入鏡面世界。" RESET,
        {
            Choice("掙脫逃出", "", "BAD_END"),
            Choice("接受命運", "", "SECRET_END")
        });

    // scene["10"] - 假車掌登場
    scenes["10"] = Scene("10",
        "列車門打開，一位" RED "看起來一模一樣的你" RESET "穿著車掌制服走進來。",
        {
            Choice("詢問他是誰", "", "11"),
            Choice("躲起來", "", "12")
        });

    // scene["11"] - 回答
    scenes["11"] = Scene("11",
        RED "『我是你逃避的樣子。』\n"
        "他靠近你，你的影子開始扭曲。" RESET,
        {
            Choice("逃跑", "", "13"),
            Choice("伸手觸碰他", "", "HIDDEN_END")
        });

    // scene["12"] - 躲藏
    scenes["12"] = Scene("12",
        "你藏進座位底下，感受到車廂變冷，車窗外出現一連串" RED "自己被囚禁的畫面。" RESET,
        {
            Choice("爬出來面對", "", "11"),
            Choice("繼續躲著", "", "BAD_END")
        });

    // scene["13"] - 站台儀式
    scenes["13"] = Scene("13",
        "列車停在一個詭異站台，地上刻著一圈紅色符文。\n"
        RED "你聽見廣播：『只有接受過審判的人才能返回。』" RESET,
        {
            Choice("踏入符文", "", "14"),
            Choice("選擇留在列車", "", "BAD_END")
        });

    // scene["14"] - 多重現實
    scenes["14"] = Scene("14",
        "你眼前出現三個自己，每個人都說他才是真的你。",
        {
            Choice("相信第一個", "", "TRUE_END"),
            Choice("相信第二個", "", "GOOD_END"),
            Choice("誰都不相信", "", "SECRET_END")
        });

    // scene["HIDDEN_END"]
    scenes["HIDDEN_END"] = Scene("HIDDEN_END",
        RED "你碰觸那位假車掌，身體迅速扭曲成與他一樣的樣子……\n"
        "你成為下一位等待旅人的影子。" RESET,
        {});


    // 結局
    scenes["TRUE_END"] = Scene("TRUE_END",
        "你走出紅色隧道，發現自己回到白天的城市街道。\n"
        "但內心的陰影仍揮之不去。",
        {});

    scenes["GOOD_END"] = Scene("GOOD_END",
        "你發現手機上的訊息正是你失蹤好友傳來的警告，\n"
        "你逃過一劫，也揭開了這趟電車的詭異真相。",
        {});

    scenes["SECRET_END"] = Scene("SECRET_END",
        RED "你落入虛空，卻被不明力量托住。\n"
        "你來到一個無人站台，新的世界正等著你探索。" RESET,
        {});

    scenes["BAD_END"] = Scene("BAD_END",
        RED "你成了電車的一部分，無法再離開，靈魂將永遠遊蕩於此。" RESET,
        {});

    return scenes;
}
