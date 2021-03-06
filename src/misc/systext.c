/*
** $Id: systext.c 8013 2007-10-30 05:11:41Z xwyan $
**
** systext.c: GetSysText function.
**
** Copyright (C) 2003 ~ 2007 Feynman Software.
** Copyright (C) 1999 ~ 2002 Wei Yongming.
**
** All rights reserved by Feynman Software.
** 
**
** Current maintainer: Wei Yongming.
**
** Create date: 2000/12/31
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "minigui.h"
#include "gdi.h"
#include "window.h"

/*
 * This function translates system strings.
 * You can use gettext to return the text.
 *
 * System text as follows:
 *
 const char* SysText [] =
 {
    "Windows",                  // 0
    "Start",                    // 1
    "Refresh Background",       // 2
    "Close All Windows",        // 3
    "End Session",              // 4
    "Operations",               // 5
    "Minimize",                 // 6
    "Maximize",                 // 7
    "Restore",                  // 8
    "Close",                    // 9
    "OK",                       // 10
    "Next",                     // 11
    "Cancel",                   // 12
    "Previous",                 // 13
    "Yes",                      // 14
    "No",                       // 15
    "Abort",                    // 16
    "Retry",                    // 17
    "Ignore",                   // 18
    "About MiniGUI...",         // 19
    "Open File",                // 20
    "Save File",                // 21
    "Color Selection",          // 22
    "Switch Layer",             // 23
    "Delete Layer",             // 24
    "Error",                     // 25
    "LOGO",                      // 26 
    "Current Path",              // 27 
    "File",                      // 28 
#if (!defined (__NOUNIX__) || defined (WIN32)) && defined (_EXT_CTRL_LISTVIEW)
    "Location",                 //0 + 29
    "Up",                       //1 + 29
    "Name",                     //2 + 29
    "Size",                     //3 + 29
    "Access Mode",              //4 + 29
    "Last Modify Time",         //5 + 29
    "Open",                     //6 + 29
    "File Name",                //7 + 29
    "File Type",                //8 + 29
    "Show Hide File",           //9 + 29
    "Sorry! not find %s ", //10 + 29
    "Can't Read %s !",        //11 + 29
    "Can't Write  %s !",      //12 + 29
    "Information",              //13 + 29
    "R",                        //14 + 29
    "W",                        //15 + 29
    "WR",                       //16 + 29
    "Save",                     //17 + 29
    "File %s exists, Replace or not?", //18 + 29
#endif
    NULL
};
*/

const char** local_SysText;

const char* SysText [] =
{
    "Windows",                  // 0
    "Start",                    // 1
    "Refresh Background",       // 2
    "Close All Windows",        // 3
    "End Session",              // 4
    "Operations",               // 5
    "Minimize",                 // 6
    "Maximize",                 // 7
    "Restore",                  // 8
    "Close",                    // 9
    "OK",                       // 10
    "Next",                     // 11
    "Cancel",                   // 12
    "Previous",                 // 13
    "Yes",                      // 14
    "No",                       // 15
    "Abort",                    // 16
    "Retry",                    // 17
    "Ignore",                   // 18
    "About MiniGUI...",         // 19
    "Open File",                // 20
    "Save File",                // 21
    "Color Selection",          // 22
    "Switch Layer",             // 23
    "Delete Layer",             // 24
    "Error",                     // 25
    "LOGO",                      // 26 
    "Current Path",              // 27 
    "File",                      // 28 
#if (!defined (__NOUNIX__) || defined (WIN32)) && defined (_EXT_CTRL_LISTVIEW)
    "Location",                 //0 + 29
    "Up",                       //1 + 29
    "Name",                     //2 + 29
    "Size",                     //3 + 29
    "Access Mode",              //4 + 29
    "Last Modify Time",         //5 + 29
    "Open",                     //6 + 29
    "File Name",                //7 + 29
    "File Type",                //8 + 29
    "Show Hide File",           //9 + 29
    "Sorry! not find %s ", //10 + 29
    "Can't Read %s !",        //11 + 29
    "Can't Write  %s !",      //12 + 29
    "Information",              //13 + 29
    "R",                        //14 + 29
    "W",                        //15 + 29
    "WR",                       //16 + 29
    "Save",                     //17 + 29
    "File %s exists, Replace or not?", //18 + 29
#endif
    NULL
};

#if defined(_GB_SUPPORT) | defined (_GBK_SUPPORT) | defined (_GB18030_SUPPORT)
static const char* SysText_GB [] =
{
    "窗口",              // 0
    "开始",              // 1
    "刷新背景",             // 2
    "关闭所有窗口",         // 3
    "结束会话",             // 4
    "窗口操作",             // 5
    "最小化",               // 6
    "最大化",               // 7
    "恢复",                 // 8
    "关闭",                 // 9
    "确定",                 // 10
    "下一步",               // 11
    "取消",                 // 12
    "上一步",               // 13
    "是(Y)",                // 14
    "否(N)",                // 15
    "终止(A)",              // 16
    "重试(R)",              // 17
    "忽略(I)",              // 18
    "关于 MiniGUI...",      // 19
    "打开文件",             // 20
    "保存文件",             // 21
    "颜色选择",             // 22
    "切换层",               // 23
    "删除层",               // 24
    "错误",                 // 25
    "图标",                 // 26
    "当前路径",             // 27
    "文件",                 // 28
#if (!defined (__NOUNIX__) || defined (WIN32)) && defined (_EXT_CTRL_LISTVIEW)
    "查找位于",                                 //0 + 29
    "上一级",                                   //1 + 29
    "名称",                                     //2 + 29
    "大小",                                     //3 + 29
    "访问权限",                                 //4 + 29
    "上次修改时间",                             //5 + 29
    "打开",                                     //6 + 29
    "文 件 名",                                 //7 + 29
    "文件类型",                                 //8 + 29
    "显示隐藏文件",                             //9 + 29
    "对不起，未找到指定的目录： %s ",     //10 + 29
    "不能读取 %s !",                          //11 + 29
    "对 %s 没有写权限!",                      //12 + 29
    "提示信息",                                 //13 + 29
    "读",                                       //14 + 29
    "写",                                       //15 + 29
    "读写",                                     //16 + 29
    "保存",                                     //17 + 29
    "文件 %s 存在，是否替换?"                   //18 + 29
#endif
};
#endif

#ifdef _BIG5_SUPPORT
static const char* SysText_BIG5 [] =
{
    "怠",
    "邵﹍",
    "穝璉春",
    "闽超┮Τ怠",
    "挡穦杠",
    "怠巨",
    "程て",
    "程て",
    "蝋",
    "闽超",
    "谔﹚",
    "˙",
    "",
    "˙",
    "琌(Y)",
    "(N)",
    "沧ゎ(A)",
    "刚(R)",
    "┛菠(I)",
    "闽 MiniGUI...",
    "ゴ秨ゅン",
    "玂ゅン",
	"肅︹匡拒",
    "ち传糷",
    "埃糷",
    "岿粇",                                 // 25
    "瓜夹",                                 // 26 
    "讽玡隔畖",                             // 27 
    "ゅン",                                 // 28 
#if (!defined (__NOUNIX__) || defined (WIN32)) && defined (_EXT_CTRL_LISTVIEW)
    "琩т",                             //0 + 29
    "",                               //1 + 29
    "嘿",                                 //2 + 29
    "",                                 //3 + 29
    "砐拜舦",                             //4 + 29
    "Ωэ丁",                         //5 + 29
    "ゴ秨",                                 //6 + 29
    "ゅ ン ",                             //7 + 29
    "ゅン摸",                             //8 + 29
    "陪ボ留旅ゅン",                         //9 + 29
    "癸ぃ癬ゼт﹚ヘ魁 %s ", //10 + 29
    "ぃ弄 %s !",                      //11 + 29
    "癸 %s ⊿Τ糶舦",                   //23 + 29
    "矗ボ獺",                             //13 + 29
    "弄",                                   //14 + 29
    "糶",                                   //15 + 29
    "弄糶",                                 //16 + 29
    "玂",                                 //17 + 29
    "ゅン %s 琌蠢传?",              //18 + 29
#endif
    NULL
};
#endif

void __mg_init_local_sys_text (void)
{
    const char* charset = GetSysCharset (TRUE);

    local_SysText = SysText;

    if (charset == NULL)
        charset = GetSysCharset (FALSE);

#ifdef _GB_SUPPORT
    if (strcmp (charset, FONT_CHARSET_GB2312_0) == 0) {
        local_SysText = SysText_GB;
	}
#endif

#ifdef _GBK_SUPPORT
    if (strcmp (charset, FONT_CHARSET_GBK) == 0) {
        local_SysText = SysText_GB;
	}
#endif

#ifdef _GB18030_SUPPORT
    if (strcmp (charset, FONT_CHARSET_GB18030_0) == 0) {
        local_SysText = SysText_GB;
	}
#endif

#ifdef _BIG5_SUPPORT
    if (strcmp (charset, FONT_CHARSET_BIG5) == 0) {
        local_SysText = SysText_BIG5;
	}
#endif

}

const char* GUIAPI GetSysText (unsigned int id)
{
    if (id > IDS_MGST_MAXNUM)
        return NULL;
        
    return local_SysText [id];
}

#ifdef _UNICODE_SUPPORT
static const char* SysText_GB_UTF8 [] =
{
    "绐楀彛",              // 0
    "寮�濮�",              // 1
    "鍒锋柊鑳屾櫙",             // 2
    "鍏抽棴鎵�鏈夌獥鍙�",         // 3
    "缁撴潫浼氳瘽",             // 4
    "绐楀彛鎿嶄綔",             // 5
    "鏈�灏忓寲 ",
    "鏈�澶у寲 ",
    "鎭㈠",                 // 8
    "鍏抽棴",                 // 9
    "纭畾",                 // 10
    "涓嬩竴姝� ", 
    "鍙栨秷",                 // 12
    "涓婁竴姝� ",
    "鏄�(Y)",                // 14
    "鍚�(N)",                // 15
    "缁堟(A)",              // 16
    "閲嶈瘯(R)",              // 17
    "蹇界暐(I)",              // 18
    "鍏充簬 MiniGUI...",      // 19
    "鎵撳紑鏂囦欢",             // 20
    "淇濆瓨鏂囦欢",             // 21
    "棰滆壊閫夋嫨",             // 22
    "鍒囨崲灞� ",
    "鍒犻櫎灞� ",
    "閿欒",                 // 25
    "鍥炬爣",                 // 26
    "褰撳墠璺緞",             // 27
    "鏂囦欢",                 // 28
#if (!defined (__NOUNIX__) || defined (WIN32)) && defined (_EXT_CTRL_LISTVIEW)
    "鏌ユ壘浣嶄簬",                                 //0 + 29
    "涓婁竴绾� ",
    "鍚嶇О",                                     //2 + 29
    "澶у皬",                                     //3 + 29
    "璁块棶鏉冮檺",                                 //4 + 29
    "涓婃淇敼鏃堕棿",                             //5 + 29
    "鎵撳紑",                                     //6 + 29
    "鏂� 浠� 鍚� ",                                 //7 + 29
    "鏂囦欢绫诲瀷",                                 //8 + 29
    "鏄剧ず闅愯棌鏂囦欢",                             //9 + 29
    "瀵逛笉璧凤紝鏈壘鍒版寚瀹氱殑鐩綍锛�  %s ",
    "涓嶈兘璇诲彇 %s !",                          //11 + 29
    "瀵� %s 娌℃湁鍐欐潈闄�!",                      //12 + 29
    "鎻愮ず淇℃伅",                                 //13 + 29
    "璇� ",
    "鍐� ",
    "璇诲啓",                                     //16 + 29
    "淇濆瓨",                                     //17 + 29
    "鏂囦欢 %s 瀛樺湪锛屾槸鍚︽浛鎹�?"                   //18 + 29
#endif
};

static const char* SysText_BIG5_UTF8 [] =
{
	"绐楀彛",              // 0
    "闁嬪",              // 1
    "鍒锋柊鑳屾櫙",             // 2
    "闂滈枆鎵�鏈夌獥鍙�",         // 3
    "绲愭潫鏈冭┍",             // 4
    "绐楀彛鎿嶄綔",             // 5
    "鏈�灏忓寲 ",               // 6
    "鏈�澶у寲 ",               // 7
    "鎭㈠京",                 // 8
    "闂滈枆",                 // 9
    "纰哄畾",                 // 10
    "涓嬩竴姝� ",               // 11
    "鍙栨秷",                 // 12
    "涓婁竴姝� ",               // 13
    "鏄�(Y)",                // 14
    "鍚�(N)",                // 15
    "绲傛(A)",              // 16
    "閲嶈│(R)",              // 17
    "蹇界暐(I)",              // 18
    "闂滀簬 MiniGUI...",      // 19
    "鎵撻枊鏂囦欢",             // 20
    "淇濆瓨鏂囦欢",             // 21
    "椤忚壊閬告搰",             // 22
    "鍒囨彌灞� ",               // 23
    "鍒櫎灞� ",               // 24
    "閷",                 // 25
    "鍦栨",                 // 26
    "鐣跺墠璺緫",             // 27
    "鏂囦欢",                 // 28
#if (!defined (__NOUNIX__) || defined (WIN32)) && defined (_EXT_CTRL_LISTVIEW)
    "鏌ユ壘浣嶄簬",                                 //0 + 29
    "涓婁竴绱� ",                                   //1 + 29
    "鍚嶇ū",                                     //2 + 29
    "澶у皬",                                     //3 + 29
    "瑷晱娆婇檺",                                 //4 + 29
    "涓婃淇敼鏅傞枔",                             //5 + 29
    "鎵撻枊",                                     //6 + 29
    "鏂� 浠� 鍚� ",                                 //7 + 29
    "鏂囦欢椤炲瀷",                                 //8 + 29
    "椤ず闅辫棌鏂囦欢",                             //9 + 29
    "灏嶄笉璧凤紝鏈壘鍒版寚瀹氱殑鐩寗锛�%s ",     //10 + 29
    "涓嶈兘璁�鍙� %s !",                          //11 + 29
    "灏� %s 娌掓湁瀵瑠闄�!",                      //12 + 29
    "鎻愮ず淇℃伅",                                 //13 + 29
    "璁� ",                                       //14 + 29
    "瀵� ",                                       //15 + 29
    "璁�瀵�",                                     //16 + 29
    "淇濆瓨",                                     //17 + 29
    "鏂囦欢 %s 瀛樺湪锛屾槸鍚︽浛鎻�?",                  //18 + 29
#endif
    NULL
};

const char** GUIAPI GetSysTextInUTF8 (const char* language)
{
    if (strncasecmp (language, "zh_CN", 5) == 0) {
        return SysText_GB_UTF8;
	}
    else if (strncasecmp (language, "zh_TW", 5) == 0) {
        return SysText_BIG5_UTF8;
	}

    return SysText;
}
#endif /* _UNICODE_SUPPORT */

