// orphanage_manager.cpp
#include "orphanage_manager.h"
#include "choice.h"

std::unordered_map<std::string, Scene> createOrphanageScenes() {
    std::unordered_map<std::string, Scene> scenes;

    scenes["0"] = Scene("0",
        "\n你站在破敗孤兒院的門前，門微開，夜風吹動銹鐵聲尖銳刺耳。\n"
        "天色已晚，手機沒訊號，身後的道路早已消失無蹤。\n"
        "你彷彿被什麼牽引，走了進去。",
        {
            Choice("走進孤兒院", "", "1"),
            Choice("轉身逃離", "", "BAD_END")
        });

    scenes["1"] = Scene("1",
        "孤兒院內一片死寂，牆上照片模糊退色。\n"
        "突然一張照片上的孩子眼睛動了一下。\n"
        "你聽到耳語聲：「……你來了……」",
        {
            Choice("查看照片", "", "2"),
            Choice("無視繼續走", "", "3")
        });

    scenes["2"] = Scene("2",
        "照片裡的孩子嘴角露出詭異笑容，一行血字浮現在牆上：\n"
        "\033[31m『我們一直在等你。』\033[0m",
        {
            Choice("逃跑", "", "BAD_END"),
            Choice("繼續深入", "", "4")
        });

    scenes["3"] = Scene("3",
        "走廊盡頭傳來音樂聲，是古老音樂盒的旋律。\n"
        "門後傳來哭聲——像是小孩，也像是你自己的聲音。",
        {
            Choice("打開門", "", "5"),
            Choice("轉身離開", "", "BAD_END")
        });

    scenes["4"] = Scene("4",
        "你踏入藏書室，書本翻飛，空氣中寫著：\n"
        "\033[31m『你不能忘記你曾是誰。』\033[0m\n"
        "你看見一張舊檔案：\n姓名：你\n狀態：第十三位實驗體。",
        {
            Choice("接受記憶", "", "6"),
            Choice("撕碎檔案", "", "7")
        });

    scenes["5"] = Scene("5",
        "房內是一群小孩的身影圍繞一個人偶，齊聲說：\n"
        "\033[31m『和我們一起永遠玩下去吧！』\033[0m",
        {
            Choice("點頭答應", "", "BAD_END"),
            Choice("大喊逃離", "", "6")
        });

    // 新增場景開始
    scenes["6"] = Scene("6",
        "你的記憶片段開始湧現，看到自己曾在這裡被囚禁。\n"
        "你必須選擇下一步：\n",
        {
            Choice("尋找出口", "", "8"),
            Choice("找其他孩子", "", "9")
        });

    scenes["7"] = Scene("7",
        "你撕碎檔案，牆上文字開始變得扭曲，聲音越來越大。\n"
        "你感到頭痛欲裂，無法控制自己。",
        {
            Choice("掙扎清醒", "", "6"),
            Choice("放棄抵抗", "", "BAD_END")
        });

    scenes["8"] = Scene("8",
        "你發現一扇隱藏的地下室門，通向未知的黑暗。\n"
        "是否要進入？",
        {
            Choice("進入地下室", "", "SECRET_END"),
            Choice("繼續尋找主出口", "", "TRUE_END")
        });

    scenes["9"] = Scene("9",
        "你找到幾個孩子，他們眼神空洞，但似乎在等待救援。\n"
        "你能帶他們一起逃離嗎？",
        {
            Choice("帶他們逃出", "", "GOOD_END"),
            Choice("獨自逃離", "", "TRUE_END")
        });

    scenes["TRUE_END"] = Scene("TRUE_END",
        "你成功逃出孤兒院，清晨的陽光照耀著你疲憊的臉龐。\n"
        "你帶著破碎的記憶重新開始"
        "\n但心中的疑問卻漸漸佔滿全身。",
        {});

    scenes["GOOD_END"] = Scene("GOOD_END",
        "你帶著其他孩子一同逃出孤兒院，大家重獲自由。\n"
        "孤兒院的陰影雖然未完全散去"
        "\n但當陽光灑落的那一刻"
        "\n你們相信，終將到達希望的未來。",
        {});

    scenes["SECRET_END"] = Scene("SECRET_END",
        "你進入地下室，發現一個秘密實驗室"
        "\n裡面有更多的實驗檔案與錄影。\n"
        "真相令人震驚，你決定揭露這個黑暗秘密，對抗幕後黑手。",
        {});

    scenes["BAD_END"] = Scene("BAD_END",
        "你感到一股冰冷包圍全身。\n"
        "最後你也成了孤兒院照片裡的一員。\n"
        "\033[31m你，再也無法離開。\033[0m",
        {});

    return scenes;
}
