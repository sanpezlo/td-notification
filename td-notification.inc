/*
    td-notification - Version 0.9

    Modes of use:

    MAX_TDN: set how many TextDraw will be shown in TextDraw's Notification

    TDN_POS_X: TextDraw's notifications will be at the position set on the X axis
    TDN_POS_Y: TextDraw's notifications will be at the position set on the Y axis
    TDN_FONT: TextDraw's Notification will have the set font
    TDN_LETTER_SIZE_X: TextDraw's notifications will have the set font size on the X axis
    TDN_LETTER_SIZE_Y: TextDraw's notifications will have the set font size on the Y axis
    TDN_SIZE: TextDraw's notifications will have the set width size
    TDN_COLOR: TextDraw's notifications will have the set font color
    TDN_COLOR_BOX: TextDraw's notifications will have the set box color
    TDN_PROPORTIONAL: TextDraw's notifications will have the set proportional
    TDN_DISTANCE: TextDraw's notifications will have the set distance

    TDN_MODE_DOWN: TextDraw's notifications will scroll down
    TDN_MODE_UP: TextDraw's notifications will scroll up
    
    TDN_TIME: TextDraw's notifications will hide at the set time

    TDN_MODE_DEFAULT: TextDraw's notifications will use the default settings

	Created by ThePez
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
#else
    #define MAX_TDN 4
    #define TDN_POS_X 497.000000
    #define TDN_POS_Y 130.000000
    #define TDN_FONT 1
    #define TDN_LETTER_SIZE_X 0.250000
    #define TDN_LETTER_SIZE_Y 1.000000
    #define TDN_SIZE 112.000000
    #define TDN_COLOR 0xFFFFFFFF
    #define TDN_COLOR_BOX 0x000000FF
    #define TDN_PROPORTIONAL 1
    #define TDN_DISTANCE 5
    #define TDN_MODE_DOWN
    #define TDN_TIME 30000
#endif

#define YSI_NO_HEAP_MALLOC

#include <YSI_Coding\y_hooks>
#include <YSI_Coding\y_timers>
#include <td-streamer>
#include <td-string-width>

enum InformationTDN
{
    Use,
    Line,
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
            TextDrawsNotification[playerid][TDN][TextDraw] = TextDrawCreate(TDN_POS_X, TDN_POS_Y, "TDNotifications");
            TextDrawFont(TextDrawsNotification[playerid][TDN][TextDraw], 1);
            TextDrawLetterSize(TextDrawsNotification[playerid][TDN][TextDraw], TDN_LETTER_SIZE_X, TDN_LETTER_SIZE_Y);
            TextDrawTextSize(TextDrawsNotification[playerid][TDN][TextDraw], floatadd(TDN_POS_X, TDN_SIZE), 1.000000);
            TextDrawSetOutline(TextDrawsNotification[playerid][TDN][TextDraw], 1);
            TextDrawSetShadow(TextDrawsNotification[playerid][TDN][TextDraw], 0);
            TextDrawAlignment(TextDrawsNotification[playerid][TDN][TextDraw], 1);
            TextDrawColor(TextDrawsNotification[playerid][TDN][TextDraw], TDN_COLOR);
            TextDrawBackgroundColor(TextDrawsNotification[playerid][TDN][TextDraw], TDN_COLOR_BOX);
            TextDrawBoxColor(TextDrawsNotification[playerid][TDN][TextDraw], TDN_COLOR_BOX);
            TextDrawUseBox(TextDrawsNotification[playerid][TDN][TextDraw], 1);
            TextDrawSetProportional(TextDrawsNotification[playerid][TDN][TextDraw], 1);
            TextDrawSetSelectable(TextDrawsNotification[playerid][TDN][TextDraw], 0);
        }
    }
    return 1;
}

timer TimerHideTDNotification[TDN_TIME](playerid, TDN)
{
    TextDrawsNotification[playerid][TDN][Use] = 0;
    TextDrawHideForPlayer(playerid, TextDrawsNotification[playerid][TDN][TextDraw]);
    UpdateTDNotifications(playerid, TDN);
    return 1;
}

forward ShowTDNotification(playerid, const reason[]);
public ShowTDNotification(playerid, const reason[])
{
    new TDN = counter;
    for(new cycle; cycle < floatsub(MAX_TDN, 1); cycle++)
    {
        if(!TextDrawsNotification[playerid][TDN][Use])
        {
            TextDrawsNotification[playerid][TDN][Line] = LinesTDNotification(reason);
            TextDrawSetString(TextDrawsNotification[playerid][TDN][TextDraw], reason);
            TextDrawsNotification[playerid][TDN][Use] = 1;
            MinPosYTDNotification(playerid, TDN);
            TDNotificationMaxPosY(playerid, TDN);
            TextDrawSetPos(TextDrawsNotification[playerid][TDN][TextDraw], TDN_POS_X, TextDrawsNotification[playerid][TDN][MinPosY]);
            TextDrawShowForPlayer(playerid, TextDrawsNotification[playerid][TDN][TextDraw]);
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

stock UpdateTDNotifications(playerid, TDN)
{
    new after = counter,
        before;
    if(TDN == MAX_TDN - 1)
    {
        counter = 0;
    }
    else
    {
        counter = TDN + 1;
    }
    for(new cycle; cycle < MAX_TDN - 1; cycle++)
    {
        if(TextDrawsNotification[playerid][TDN][Use])
        {
            if(cycle == 0)
            {
                TextDrawsNotification[playerid][TDN][Line] = 0;
                TextDrawsNotification[playerid][TDN][MinPosY] = 0;
                TextDrawsNotification[playerid][TDN][MaxPosY] = 0;
                TextDrawsNotification[playerid][after][MinPosY] = TextDrawsNotification[playerid][TDN][MinPosY];
                TDNotificationMaxPosY(playerid, after);
                TextDrawSetPos(TextDrawsNotification[playerid][after][TextDraw], TDN_POS_X, TextDrawsNotification[playerid][after][MinPosY]);
            }
            else
            {
                TextDrawsNotification[playerid][after][MinPosY] = TDN_DISTANCE + TextDrawsNotification[playerid][before][MaxPosY];
                TDNotificationMaxPosY(playerid, after);
                TextDrawSetPos(TextDrawsNotification[playerid][after][TextDraw], TDN_POS_X, TextDrawsNotification[playerid][after][MinPosY]);
            }
            before = after;
        }
        if(after == MAX_TDN - 1)
        {
            after = 0;
        }
        else
        {
            after++;
        }
    }
    return 1;
}

stock LinesTDNotification(const reason[])
{
    new line = 1, before, sub, size;
    for(new character = 0; character < strlen(reason); character++)
    {
        size += TDN_LETTER_SIZE_X * GetTextDrawCharacterWidth(character, TDN_FONT, TDN_PROPORTIONAL);
        if(size - sub > floatsub(TDN_SIZE, 1))
        {
            sub = before * (line + 1);
            line++;
        } 
        before = size;
    }
    return line;
}

stock MinPosYTDNotification(playerid, TDN)
{
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
}

stock TDNotificationMaxPosY(playerid, TDN)
{
    new Float:up = (TDN_LETTER_SIZE_Y * 2) + 2;
    new Float:letter = (TDN_LETTER_SIZE_Y * 6) * TextDrawsNotification[playerid][TDN][Line];
    new Float:middle = (TextDrawsNotification[playerid][TDN][Line] - 1) * ((TDN_LETTER_SIZE_Y * 2) + 2 + TDN_LETTER_SIZE_Y + 2);
    new Float:down = TDN_LETTER_SIZE_Y + 2;
    TextDrawsNotification[playerid][TDN][MaxPosY] = up + letter + middle + down;
    return 1;
}