/*
** $Id: medit_impl.h 7338 2007-08-16 03:46:09Z xgwang $
**
** medit.h: the head file of Multi-Line Edit control.
**
** Copyright (C) 2003 ~ 2007 Feynman Software.
** Copyright (C) 1999, 2000 Chen Lei
** Copyright (C) 1999 ~ 2002 Wei Yongming.
**
** Create date: 1999/8/26
*/

#ifndef GUI_MEDIT_IMPL_H_
#define GUI_MEDIT_IMPL_H_

#ifdef  __cplusplus
extern  "C" {
#endif

#define WIDTH_MEDIT_BORDER       2
#define MARGIN_MEDIT_LEFT        1
#define MARGIN_MEDIT_TOP         1
#define MARGIN_MEDIT_RIGHT       2
#define MARGIN_MEDIT_BOTTOM      1

#define LEN_MLEDIT_BUFFER       256
#define LEN_MLEDIT_UNDOBUFFER   1024
#define MAX_IMPOSSIBLE          10000

#define EST_FOCUSED     0x00000001L
#define EST_MODIFY      0x00000002L
#define EST_READONLY    0x00000004L
#define EST_REPLACE     0x00000008L

#define MEDIT_OP_NONE    0x00
#define MEDIT_OP_DELETE  0x01
#define MEDIT_OP_INSERT  0x02
#define MEDIT_OP_REPLACE 0x03

#define MAX_WRAP_NUM    100
        
typedef struct tagLINEDATA
{
    int     lineNO;                       // 行号
    int     dataEnd; 
    struct  tagLINEDATA *previous;        // 前一行
    struct  tagLINEDATA *next;            // 后一行 
    char    buffer[LEN_MLEDIT_BUFFER+1];
    int     nwrapline;                    // wrap line support, wrap line number in current line
    int     wrapStartPos[MAX_WRAP_NUM];   // starting address of each wrap line in current line
}LINEDATA;

typedef    LINEDATA*     PLINEDATA;

typedef struct tagMLEDITDATA
{
    DWORD   status;         // status of box
    int     editLine;       // current eidt line
    int     dispPos;        // 开始显示的位置
    int     StartlineDisp;  // start line displayed
    int     EndlineDisp;    // end line displayed
    int     linesDisp;      // 需要显示的行数
    int     lines;          // 总的行数`
    int     MaxlinesDisp;   // 最大显示的行数.
                            
#if 0
    int     selStartPos;    // selection start position
    int     selStartLine;   // selection start line
    int     selEndPos;      // selection end position
    int     selEndLine;     // selection end line
#endif
    
    int     passwdChar;     // password character
    
    int     leftMargin;     // left margin
    int     topMargin;      // top margin
    int     rightMargin;    // right margin
    int     bottomMargin;   // bottom margin
    
    int     lineHeight;     // height of line.
    
    int     totalLimit;     // total text Len hard limit
    int     curtotalLen;    // current total text len
    int     lineLimit;      // len limit per line

    PLINEDATA   head;       // buffer
    PLINEDATA   tail;       // 可能不需要
                        // added by leon for charset support
    int     fit_chars;      // number of valid units to display
    int*    pos_chars;      // postion of each valid unit in buffer
    int*    dx_chars;       // display postion of each valid unit
    SIZE    sz;             // display rect size
    int     veditPos;       // editPos position of valid unit in both arrays
    int     vdispPos;       // dispPos position of valid unit in both arrays
    int     realeditLine;   // the 'real' line number that the cursor should be on if visible
    int     realdispPos;    // the 'real' valid unit edit position that the cursor should be on if visible
    int     realStartLine;  // the 'real' valid start line number
    int     realEndLine;    // the 'real' valid end line number
    int     diff;           // 0: no difference; 1: difference
    int     bSCROLL;        // 0: not scroll; 1: scroll
                            // add end 
    int     wraplines;      // total wrapline number
    
#if 0
    int     lastOp;         // last operation
    int     lastPos;        // last operation position
    int     lastLine;       // last operation line
    int     affectedLen;    // affected len of last operation
    int     undoBufferLen;  // undo buffer len
    char    undoBuffer [LEN_MLEDIT_UNDOBUFFER];
                            // Undo buffer;
    PLOGFONT logfont;
#endif
}MLEDITDATA;
typedef MLEDITDATA* PMLEDITDATA;

BOOL RegisterMLEditControl (void);
void MLEditControlCleanup (void);

#ifdef __cplusplus
}
#endif

#endif /* GUI_MEDIT_IMPL_H_ */

