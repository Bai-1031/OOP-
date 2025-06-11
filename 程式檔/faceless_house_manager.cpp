// faceless_house_manager.cpp
#include "faceless_house_manager.h"

#define RED "\033[31m"
#define RESET "\033[0m"

std::unordered_map<std::string, Scene> createFacelessHouseScenes() {
    std::unordered_map<std::string, Scene> scenes;

    scenes["0"] = Scene("0",
        "你在黑暗中醒來，眼前是一面鏡子，映出一張" + std::string(RED) + "沒有五官的臉" + RESET + "。\n"
        "你的手指觸碰到光滑冰冷的皮膚，卻沒有鼻子、眼睛或嘴巴。",
        {
            Choice("摸摸自己的臉", "", "1"),
            Choice("大聲喊叫求救", RED "鏡中的你張嘴，卻沒有聲音。" RESET, "2")
        });

    scenes["1"] = Scene("1",
        "鏡中臉慢慢變形，像是在模仿你的表情，卻又令人毛骨悚然。\n"
        "你感覺背後有東西正注視著你。",
        {
            Choice("轉身查看", "", "3"),
            Choice("不敢回頭，繼續盯著鏡子", RED "鏡子突然碎裂，映出無數張血臉。" RESET, "4")
        });

    scenes["2"] = Scene("2",
        RED "四周迴盪著你的無聲尖叫，卻沒有人回應。" RESET "\n"
        "你覺得心跳越來越快，視線開始模糊。",
        {
            Choice("試圖冷靜下來", "", "1"),
            Choice("狂奔離開房間", "", "5")
        });

    scenes["3"] = Scene("3",
        RED "你看到一個無臉的身影慢慢從陰影中走出，模仿你的動作。" RESET "\n"
        "它的皮膚像是用縫線縫合，充滿腐爛的氣味。",
        {
            Choice("與它對話", "", "6"),
            Choice("逃跑", "", "5")
        });

    scenes["4"] = Scene("4",
        "碎鏡中映出你自己，卻是一張用縫線拼湊的" + std::string(RED) + "血臉皮" + RESET + "，眼中滿是空洞。",
        {
            Choice("試圖用手撕下鏡片", "", "7"),
            Choice("跪下哭泣", "", "8")
        });

    scenes["5"] = Scene("5",
        "你跑進另一個房間，裡面擺滿鏡子和縫合針具，牆上掛滿了臉皮。\n"
        RED "每張臉都在蠢蠢欲動，似乎在觀察你。" RESET,
        {
            Choice("戴上一張臉皮", "", "9"),
            Choice("焚燒臉皮", "", "10")
        });

    scenes["6"] = Scene("6",
        RED "無臉人用低沉的聲音說：你不是你了，我才是真正的你。\"\n"
        "你感覺自己逐漸失去記憶與自我。",
        {
            Choice("抵抗並逃走", "", "5"),
            Choice("接受它", "", "11")
        });

    scenes["7"] = Scene("7",
        RED "你用力撕碎鏡片，血液從鏡中飛濺而出，濺在你的手上冰冷刺痛。" RESET,
        {
            Choice("繼續撕碎鏡子", "", "12"),
            Choice("停下來", "", "8")
        });

    scenes["8"] = Scene("8",
        "你跪地哭泣，淚水卻化成血滴落在地板上。\n"
        RED "你感覺有雙無形的手在撕扯你的靈魂。" RESET,
        {}
    );

    scenes["9"] = Scene("9",
        "你戴上臉皮，鏡子裡映出的是另一張臉，不是你的。\n"
        RED "你聽見自己笑聲變得扭曲不堪。" RESET,
        {
            Choice("繼續戴著", "", "13"),
            Choice("想要摘下", "", "14")
        });

    scenes["10"] = Scene("10",
        "你用火焚燒臉皮，濃煙充滿整個房間。\n"
        RED "那些臉皮開始哀號，像有靈魂被折磨般痛苦。" RESET,
        {
            Choice("逃出房間", "", "5"),
            Choice("繼續焚燒", "", "15")
        });

    scenes["11"] = Scene("11",
        RED "你接受無臉人的取代，忘記了自己是誰。\n"
        "成為無臉之家其中一張臉皮。" RESET,
        {}
    );

    scenes["12"] = Scene("12",
        RED "鏡子碎片刺入你的手掌，你感覺一陣劇痛與暈眩。" RESET,
        {
            Choice("忍住痛繼續撕", "", "8"),
            Choice("放棄，倒地昏迷", "", "")
        });

    scenes["13"] = Scene("13",
        "你在鏡中看到不斷變形的自己，感覺逐漸融入另一個存在。",
        {
            Choice("放棄抵抗", "", "11"),
            Choice("試圖脫下臉皮", "", "14")
        });

    scenes["14"] = Scene("14",
        "你掙扎著摘下面具，卻發現自己的臉皮像膠水般黏住。\n"
        RED "無數細小縫線扎入你的皮膚，血流不止。" RESET,
        {}
    );

    scenes["15"] = Scene("15",
        RED "火焰吞噬臉皮，連帶吞噬你的心智。\n"
        "你感覺靈魂正在燃燒，無法自拔。" RESET,
        {}
    );

    return scenes;
}
