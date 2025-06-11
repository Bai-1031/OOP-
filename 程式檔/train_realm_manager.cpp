#include "train_realm_manager.h"
#include "choice.h"

#define RED "\033[31m"
#define RESET "\033[0m"

std::unordered_map<std::string, Scene> createTrainRealmScenes() {
    std::unordered_map<std::string, Scene> scenes;

    scenes["0"] = Scene("0",
        "午夜，你踏上了最後一班列車。\n"
        "車廂內充斥著一股腐朽的金屬味，燈光不斷閃爍。\n"
        RED "廣播聲響起：『終點站——不存在。』" RESET,
        {
            Choice("觀察四周乘客", "", "1"),
            Choice("查看手機時間", "", "2")
        });

    scenes["1"] = Scene("1",
        "座位上坐滿了人影，但他們全都低著頭，一動不動。\n"
        RED "你注意到他們的衣服全是黑白反轉，彷彿照片底片。" RESET,
        {
            Choice("靠近其中一人", "", "3"),
            Choice("轉身離開", "", "4")
        });

    scenes["2"] = Scene("2",
        "你的手機時間停在了 00:00。\n"
        RED "螢幕閃爍顯示『你已被登記。』" RESET,
        {
            Choice("關機重啟", "", "5"),
            Choice("丟掉手機", "", "BAD_END")
        });

    scenes["3"] = Scene("3",
        RED "你靠近一位乘客，發現他根本沒有臉——\n"
        "取而代之的是你自己的照片，嘴角微微上揚。" RESET,
        {
            Choice("撕掉那張臉", "", "6"),
            Choice("逃到下一節車廂", "", "4")
        });

    scenes["4"] = Scene("4",
        "你進入下一節車廂，裡面空無一人。\n"
        RED "只有一扇鏡面窗戶，上頭寫著『別回頭看』。" RESET,
        {
            Choice("照鏡子", "", "7"),
            Choice("遮住鏡子走過去", "", "8")
        });

    scenes["5"] = Scene("5",
        "手機重新開機後，跳出一條語音訊息。\n"
        RED "『逃不掉的，不是這班車，而是你自己。』" RESET,
        {
            Choice("播放訊息", "", "9"),
            Choice("拔電池", "", "BAD_END")
        });

    scenes["6"] = Scene("6",
        "你一撕掉那張臉，乘客瞬間睜眼，滿眼血紅。\n"
        RED "『你奪走了我，那你就得還。』" RESET,
        {
            Choice("還給他", "", "BAD_END"),
            Choice("跑入駕駛室", "", "10")
        });

    scenes["7"] = Scene("7",
        RED "鏡中你微笑地舉起一把刀，而你手中空無一物。\n"
        "下一秒，鏡像伸出手穿過玻璃。" RESET,
        {
            Choice("握住他的手", "", "HIDDEN_END"),
            Choice("猛然砸碎鏡子", "", "11")
        });

    scenes["8"] = Scene("8",
        "你遮住鏡子匆匆通過，背後傳來玻璃碎裂聲。\n"
        RED "你知道，有東西逃了出來。" RESET,
        {
            Choice("無視繼續前進", "", "10"),
            Choice("回頭查看", "", "BAD_END")
        });

    scenes["9"] = Scene("9",
        "訊息內容開始變調，成為一段陌生的哭聲。\n"
        RED "你認出那是你小時候的聲音，在呼喚『放我出去』。" RESET,
        {
            Choice("覆誦語音內容", "", "12"),
            Choice("刪除語音", "", "BAD_END")
        });

    scenes["10"] = Scene("10",
        "你來到駕駛室，但那裡沒有司機，只有一張椅子，正對著你。\n"
        RED "儀表板寫著：『選擇你要去的“真相”。』" RESET,
        {
            Choice("選擇『回家』", "", "13"),
            Choice("選擇『遺忘』", "", "14")
        });

    scenes["11"] = Scene("11",
        RED "鏡子碎裂後你昏了過去。\n"
        "醒來時你發現自己穿著制服，坐在駕駛席……" RESET,
        {
            Choice("啟動列車", "", "HIDDEN_END"),
            Choice("下車逃離", "", "SECRET_END")
        });

    scenes["12"] = Scene("12",
        "你邊覆誦語音，邊流下眼淚，感覺記憶被抽離。\n"
        RED "這時，列車停下，一道亮光刺眼。" RESET,
        {
            Choice("踏出車門", "", "GOOD_END"),
            Choice("坐回原位", "", "BAD_END")
        });

    scenes["13"] = Scene("13",
        "你選擇了『回家』，列車開始倒退行駛，車窗外一幕幕熟悉景象倒流。\n"
        RED "你看到的最後一幕，是自己倒在車站月台。" RESET,
        {
            Choice("接受這一切", "", "TRUE_END"),
            Choice("拒絕這個結局", "", "SECRET_END")
        });

    scenes["14"] = Scene("14",
        "你選擇了『遺忘』，腦中浮現各種被你拋下的人事物。\n"
        RED "車廂內乘客一一站起，朝你鞠躬……然後消失。" RESET,
        {
            Choice("留在車上", "", "HIDDEN_END"),
            Choice("走向黑暗終點", "", "BAD_END")
        });

    // 結局
    scenes["TRUE_END"] = Scene("TRUE_END",
        "你醒來時，躺在醫院病床上。\n"
        "醫生說你曾遭遇事故，但你知道——那不是夢。",
        {});

    scenes["GOOD_END"] = Scene("GOOD_END",
        "你逃離電車，在空無一人的城市中醒來。\n"
        "手機螢幕寫著：『第二班列車將於明日啟程。』",
        {});

    scenes["SECRET_END"] = Scene("SECRET_END",
        RED "你跳出列車，落在一個無名站台。\n"
        "車門在你背後關上，一張無臉的你站在車內對你揮手。" RESET,
        {});

    scenes["HIDDEN_END"] = Scene("HIDDEN_END",
        RED "你成為了電車的車掌，身穿制服，靜待下一位迷路之人……" RESET,
        {});

    scenes["BAD_END"] = Scene("BAD_END",
        RED "你陷入無限的回圈，列車不斷重啟，你永遠無法下車。" RESET,
        {});
    return scenes;

}
