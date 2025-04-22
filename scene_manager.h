// scene_manager.cpp
#include "scene.h"
#include "choice.h"
#include <unordered_map>
using namespace std;

unordered_map<string, Scene> createScenes() {
    unordered_map<string, Scene> scenes;

    scenes["0"] = Scene("0", {
        "你在一間陌生病房醒來。"
        "\n四周寂靜無聲，只有心跳聲在耳邊回響。",
    }, {
        Choice("打開門", "", "1"),
        Choice("查看抽屜", "", "2")
    });

    scenes["1"] = Scene("1", {
        "你走進昏暗的走廊，牆上的燈忽明忽暗。"
    }, {
        Choice("往聲音方向走", "", "3"),
        Choice("打開牆邊門", "", "4")
    });

    scenes["2"] = Scene("2", {
        "你打開抽屜，發現一本日記。"
        "\n上面寫著：你是病人？"
    }, {
        Choice("閱讀全部日記", "", "5"),
        Choice("丟掉它", "", "6")
    });

    scenes["3"] = Scene("3", {
        "聲音來自一名女護士的低語：「留下來⋯。」"
    }, {
        Choice("逃跑", "", "7"),
        Choice("跟她走", "", "A") // 結局A：死亡
    });

    scenes["4"] = Scene("4", {
        "你打開牆邊的門，房間裡有一具屍體。"
    }, {
        Choice("查看屍體", "", "8"),
        Choice("立刻離開", "", "7")
    });

    scenes["5"] = Scene("5", {
        "你閱讀日記，發現自己曾自願參與某項實驗。"
    }, {
        Choice("找出真相", "", "9"),
        Choice("離開這裡", "", "B") // 結局B：逃脫
    });

    scenes["6"] = Scene("6", {
        "你開始頭痛，記憶錯亂。"
    }, {
        Choice("自殘讓自己清醒", "", "C"), // 結局C：瘋狂
        Choice("服用藥丸", "", "9")
    });

    scenes["7"] = Scene("7", {
        "你拼命逃跑，來到地下室。"
    }, {
        Choice("開電閘", "", "B"), // 結局B：逃脫
        Choice("繼續逃跑", "", "A") // 結局A：死亡
    });

    scenes["8"] = Scene("8", {
        "你靠近屍體，發現他握有一把鑰匙。"
    }, {
        Choice("拿走鑰匙", "", "9"),
        Choice("放下鑰匙", "", "7")
    });

    scenes["9"] = Scene("9", {
        "你終於找到控制室。眼前有兩個按鈕。"
    }, {
        Choice("終止實驗", "", "D"), // 結局D：拯救所有人
        Choice("啟動更深實驗", "", "E") // 結局E：世界崩壞
    });

    scenes["A"] = Scene("A", {"你選擇相信護士，但這是一個陷阱。你死了。"}, {});
    scenes["B"] = Scene("B", {"你成功逃脫了這場惡夢，陽光灑在你臉上。"}, {});
    scenes["C"] = Scene("C", {"你再也分不清現實與幻想，最後瘋狂地笑著倒下。"}, {});
    scenes["D"] = Scene("D", {"你終止了實驗，病人們一個個甦醒。你拯救了所有人。"}, {});
    scenes["E"] = Scene("E", {"你啟動了實驗，現實崩壞，萬物歸零。"}, {});

    return scenes;
}
