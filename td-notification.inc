/*
    td-notification - Version 0.9

    Modes of use:
    MAX_TDN: set how many TextDraw will be shown in TextDraw's Notification
    TDN_POS_X: TextDraw notifications will be at the position set on the X axis
    TDN_POS_Y: TextDraw notifications will be at the position set on the Y axis
    TDN_FONT: TextDraw Notification will have the set font
    TDN_LETTER_SIZE_X: TextDraw notifications will have the set font size on the X axis
    TDN_LETTER_SIZE_Y: TextDraw notifications will have the set font size on the Y axis
    TDN_SIZE: TextDraw notifications will have the set width size
    TDN_COLOR: TextDraw notifications will have the set font color
    TDN_COLOR_BOX: TextDraw notifications will have the set box color
    TDN_PROPORTIONAL: TextDraw notifications will have the set proportional
    TDN_DISTANCE: TextDraw notifications will have the set distance
    MAX_TDN_TEXT: TextDraw notifications will have a maximum the set text
    TDN_MODE_DOWN: TextDraw notifications will scroll down
    TDN_MODE_UP: TextDraw notifications will scroll up
    TDN_TIME: TextDraw notifications will hide at the set time
    
    TDN_MODE_DEFAULT: TextDraw notifications will use the default settings

    Created by ThePez - NaS
*/
 
#if defined include_td_notification
    #endinput
#endif
#define include_td_notification
 
#if !defined TDN_MODE_DEFAULT
    #if !defined MAX_TDN
        #error "MAX_TDN is not defined"
    #endif
 
    #if !defined TDN_POS_X
        #error "TDN_POS_X is not defined"
    #endif
 
    #if !defined TDN_POS_Y
        #error "TDN_POS_Y is not defined"
    #endif
 
    #if !defined TDN_FONT
        #error "TDN_FONT is not defined"
    #endif
 
    #if !defined TDN_LETTER_SIZE_X
        #error "TDN_LETTER_SIZE_X is not defined"
    #endif
 
    #if !defined TDN_LETTER_SIZE_Y
        #error "TDN_LETTER_SIZE_Y is not defined"
    #endif
 
    #if !defined TDN_SIZE
        #error "TDN_SIZE is not defined"
    #endif
 
    #if !defined TDN_COLOR
        #error "TDN_COLOR is not defined"
    #endif
 
    #if !defined TDN_COLOR_BOX
        #error "TDN_COLOR_BOX is not defined"
    #endif
 
    #if !defined TDN_PROPORTIONAL
        #error "TDN_PROPORTIONAL is not defined"
    #endif
 
    #if !defined TDN_DISTANCE
        #error "TDN_DISTANCE is not defined"
    #endif
 
    #if !defined TDN_MODE_DOWN && !defined TDN_MODE_UP
        #error "TDN_MODE is not defined"
    #elseif defined TDN_MODE_DOWN && defined TDN_MODE_UP
        #error "TDN_MODE_DOWN and TDN_MODE_UP is defined"
    #endif
 
    #if !defined TDN_TIME
        #error "TDN_TIME is not defined"
    #endif
 
    #if !defined MAX_TDN_TEXT
        #error "MAX_TDN_TEXT is not defined"
    #endif
#else
    #define MAX_TDN 1
    #define TDN_POS_X 497.000000
    #define TDN_POS_Y 130.000000
    #define TDN_FONT 3
    #define TDN_LETTER_SIZE_X 0.250000
    #define TDN_LETTER_SIZE_Y 1.000000
    #define TDN_SIZE 112.000000
    #define TDN_COLOR 0xFFFFFFFF
    #define TDN_COLOR_BOX 0x000000FF
    #define TDN_PROPORTIONAL 1
    #define TDN_DISTANCE 5
    #define TDN_MODE_DOWN
    #define TDN_TIME 20000
    #define MAX_TDN_TEXT 800
#endif
 
#define YSI_NO_HEAP_MALLOC
 
#include <YSI_Coding\y_hooks>
#include <YSI_Coding\y_timers>
#include <td-string-width>
 
enum InformationTDN
{
    Use,
    Line,
    Text[MAX_TDN_TEXT],
    Text:TextDraw,
    Float:MinPosY,
    Float:MaxPosY
}
new TextDrawsNotification[MAX_PLAYERS][MAX_TDN][InformationTDN],
    counter = 0;
 
hook OnGameModeInit()
{
    for(new playerid = 0; playerid < MAX_PLAYERS; playerid++)
    {
        for(new TDN = 0; TDN < MAX_TDN; TDN++)
        {
            TextDrawsNotification[playerid][TDN][TextDraw] = Text:-1;
        }
    }
    return 1;
}
 
hook OnFilterScriptInit()
{
    for(new playerid = 0; playerid < MAX_PLAYERS; playerid++)
    {
        for(new TDN = 0; TDN < MAX_TDN; TDN++)
        {
            TextDrawsNotification[playerid][TDN][TextDraw] = Text:-1;
        }
    }
    return 1;
}
 
timer TimerHideTDNotification[TDN_TIME](playerid, TDN)
{
    TextDrawsNotification[playerid][TDN][Use] = 0;
    if(TextDrawsNotification[playerid][TDN][TextDraw] != Text:-1)
    {
        TextDrawDestroy(TextDrawsNotification[playerid][TDN][TextDraw]);
        TextDrawsNotification[playerid][TDN][TextDraw] = Text:-1;
    }
    UpdateTDNotifications(playerid);
    return 1;
}
 
forward ShowTDNotification(playerid, const reason[]);
public ShowTDNotification(playerid, const reason[])
{
    new TDN = counter;
    for(new cycle; cycle < MAX_TDN; cycle++)
    {
        if(!TextDrawsNotification[playerid][TDN][Use])
        {
            TextDrawsNotification[playerid][TDN][Text][0] = EOS;
            strcat(TextDrawsNotification[playerid][TDN][Text], reason, MAX_TDN_TEXT);
 
            TextDrawsNotification[playerid][TDN][Use] = 1;
 
            LinesTDNotification(playerid, TDN);
            #if defined TDN_MODE_DOWN

            MinPosYTDNotification(playerid, TDN);
            MaxPosYTDNotification(playerid, TDN);

            #endif

            #if defined TDN_MODE_UP

            MaxPosYTDNotification(playerid, TDN);
            MinPosYTDNotification(playerid, TDN);
            
            #endif

            TextDrawSetPos(playerid, TDN);

            defer TimerHideTDNotification(playerid, TDN);
            return 1;
        }
        if(TDN == floatsub(MAX_TDN, 1))
        {
            TDN = 0;
        }
        else
        {
            TDN++;
        }
    }
    return 0;
}

stock UpdateTDNotifications(playerid)
{
    new before = -1, Float:y_last;
 
    for(new cycle = 0; cycle < MAX_TDN; cycle ++)
    {
        if(TextDrawsNotification[playerid][cycle][Use])
        {
            if(before == -1)
            {
                #if defined TDN_MODE_DOWN

                TextDrawsNotification[playerid][cycle][MinPosY] = TDN_POS_Y;
                MaxPosYTDNotification(playerid, cycle);
 
                y_last = TextDrawsNotification[playerid][cycle][MaxPosY];
                
                #endif

                #if defined TDN_MODE_UP
                
                TextDrawsNotification[playerid][cycle][MaxPosY] = TDN_POS_Y;
                MinPosYTDNotification(playerid, cycle);
 
                y_last = TextDrawsNotification[playerid][cycle][MinPosY];
                
                #endif
            }
            else
            {
                #if defined TDN_MODE_DOWN

                TextDrawsNotification[playerid][cycle][MinPosY] = y_last + TDN_DISTANCE;
                MaxPosYTDNotification(playerid, cycle);
 
                y_last = TextDrawsNotification[playerid][cycle][MaxPosY];
                
                #endif

                #if defined TDN_MODE_UP
                
                TextDrawsNotification[playerid][cycle][MaxPosY] = y_last - TDN_DISTANCE;
                MinPosYTDNotification(playerid, cycle);
 
                y_last = TextDrawsNotification[playerid][cycle][MinPosY];
                
                #endif
            }
 
            TextDrawSetPos(playerid, cycle);
 
            before = cycle;
        }
    }
 
    return 1;
}

stock MinPosYTDNotification(playerid, TDN)
{
    #if defined TDN_MODE_DOWN

    new before;
    if(TDN == 0)
    {
        before = MAX_TDN - 1;
    }
    else
    {
        before = TDN - 1;
    }
    if(!TextDrawsNotification[playerid][before][Use])
    {
        TextDrawsNotification[playerid][TDN][MinPosY] = TDN_POS_Y;
    }
    else
    {
        TextDrawsNotification[playerid][TDN][MinPosY] = TDN_DISTANCE + TextDrawsNotification[playerid][before][MaxPosY];
    }
    return 1;

    #endif

    #if defined TDN_MODE_UP

    new Float:up = (TDN_LETTER_SIZE_Y * 2) + 2;
    new Float:letter = (TDN_LETTER_SIZE_Y * 5.75) * TextDrawsNotification[playerid][TDN][Line];
    new Float:middle = (TextDrawsNotification[playerid][TDN][Line] - 1) * ((TDN_LETTER_SIZE_Y * 2) + 2 + TDN_LETTER_SIZE_Y - 1);
    new Float:down = TDN_LETTER_SIZE_Y + 3;
    TextDrawsNotification[playerid][TDN][MinPosY] = TextDrawsNotification[playerid][TDN][MaxPosY] - up - letter - middle - down;
    return 1;

    #endif
}

stock MaxPosYTDNotification(playerid, TDN)
{
    #if defined TDN_MODE_DOWN

    TextDrawsNotification[playerid][TDN][MaxPosY] = TextDrawsNotification[playerid][TDN][MinPosY] + (TDN_LETTER_SIZE_Y * 2) + 2 + (TDN_LETTER_SIZE_Y * 5.75 * TextDrawsNotification[playerid][TDN][Line]) + ((TextDrawsNotification[playerid][TDN][Line] - 1) * ((TDN_LETTER_SIZE_Y * 2) + 2 + TDN_LETTER_SIZE_Y - 1)) + TDN_LETTER_SIZE_Y + 3;
    return 1;

    #endif

    #if defined TDN_MODE_UP

    new before;
    if(TDN == 0)
    {
        before = MAX_TDN - 1;
    }
    else
    {
        before = TDN - 1;
    }
    if(!TextDrawsNotification[playerid][before][Use])
    {
        TextDrawsNotification[playerid][TDN][MaxPosY] = TDN_POS_Y;
    }
    else
    {
        TextDrawsNotification[playerid][TDN][MaxPosY] = TextDrawsNotification[playerid][before][MinPosY] - TDN_DISTANCE;
    }
    return 1;

    #endif
}

stock LinesTDNotification(playerid, TDN)
{
    new lines = 1, width, lastspace = -1, len = strlen(TextDrawsNotification[playerid][TDN][Text]);
 
    for(new i = 0; i < len; i ++)
    {
        if(TextDrawsNotification[playerid][TDN][Text][i] == ' ') lastspace = i;
 
        width += floatround(TDN_LETTER_SIZE_X * GetTextDrawCharacterWidth(TextDrawsNotification[playerid][TDN][Text][i], TDN_FONT, bool:TDN_PROPORTIONAL), floatround_ceil);
 
        if(width > TDN_SIZE - 1)
        {
            if(lastspace != i && lastspace != -1)
            {
                lines ++;
                i = lastspace;
                lastspace = -1;
                width = 0;
            }
            else
            {
                lines ++;
                lastspace = -1;
                width = 0;
            }
        }
    }
 
    TextDrawsNotification[playerid][TDN][Line] = lines;
 
    return 1;
}

stock TextDrawSetPos(playerid, TDN)
{
    if(TextDrawsNotification[playerid][TDN][TextDraw] != Text:-1)
    {
        TextDrawDestroy(TextDrawsNotification[playerid][TDN][TextDraw]);
    }
   
    TextDrawsNotification[playerid][TDN][TextDraw] = TextDrawCreate(TDN_POS_X, TextDrawsNotification[playerid][TDN][MinPosY], TextDrawsNotification[playerid][TDN][Text]);
    TextDrawFont(TextDrawsNotification[playerid][TDN][TextDraw], TDN_FONT);
    TextDrawLetterSize(TextDrawsNotification[playerid][TDN][TextDraw], TDN_LETTER_SIZE_X, TDN_LETTER_SIZE_Y);
    TextDrawTextSize(TextDrawsNotification[playerid][TDN][TextDraw], floatadd(TDN_POS_X, TDN_SIZE), 1.000000);
    TextDrawSetOutline(TextDrawsNotification[playerid][TDN][TextDraw], 1);
    TextDrawSetShadow(TextDrawsNotification[playerid][TDN][TextDraw], 0);
    TextDrawAlignment(TextDrawsNotification[playerid][TDN][TextDraw], 1);
    TextDrawColor(TextDrawsNotification[playerid][TDN][TextDraw], TDN_COLOR);
    TextDrawBackgroundColor(TextDrawsNotification[playerid][TDN][TextDraw], TDN_COLOR_BOX);
    TextDrawBoxColor(TextDrawsNotification[playerid][TDN][TextDraw], TDN_COLOR_BOX);
    TextDrawUseBox(TextDrawsNotification[playerid][TDN][TextDraw], 1);
    TextDrawSetProportional(TextDrawsNotification[playerid][TDN][TextDraw], TDN_PROPORTIONAL);
    TextDrawSetSelectable(TextDrawsNotification[playerid][TDN][TextDraw], 0);
    TextDrawShowForPlayer(playerid, TextDrawsNotification[playerid][TDN][TextDraw]);
    return 1;
}