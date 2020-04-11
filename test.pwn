#pragma compress 0
#include <a_samp>
#include <zcmd>
#define YSI_NO_HEAP_MALLOC
#define TDN_MODE_DEFAULT
#include "td-notification.inc"

main() {
}

public OnPlayerDisconnect(playerid, reason)
{
    return 1;
}

CMD:spawn(playerid, params[])
{
    SetSpawnInfo(playerid, 0, 46, 1484.1082, -1668.4976, 14.9159, 0, 0,0,0,0,0,0);
    SpawnPlayer(playerid);
    return 1;
}

CMD:td(playerid, params[])
{
    new string[6],
    id;
    id = ShowTDN_Manual(playerid, params);
    format(string, sizeof(string), "ID: %i", id);
    SendClientMessage(playerid, -1, string);
    return 1;
}

CMD:hide0(playerid, params[])
{
    hideTDN(playerid, 0);
    return 1;
}

CMD:hide1(playerid, params[])
{
    hideTDN(playerid, 1);
    return 1;
}

CMD:hide2(playerid, params[])
{
    hideTDN(playerid, 2);
    return 1;
}

CMD:hide3(playerid, params[])
{
    hideTDN(playerid, 3);
    return 1;
}

CMD:hide4(playerid, params[])
{
    hideTDN(playerid, 4);
    return 1;
}

CMD:td1(playerid, params[])
{
    ShowTDN(playerid, "jksladj askldjaskl jdaslk 1");
    return 1;
}

CMD:td2(playerid, params[])
{
    ShowTDN(playerid, "jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslk 2");
    return 1;
}

CMD:td3(playerid, params[])
{
    ShowTDN(playerid, "jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslk 3");
    return 1;
}

CMD:td4(playerid, params[])
{
    ShowTDN(playerid, "jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslk 4");
    return 1;
}

CMD:td5(playerid, params[])
{
    ShowTDN(playerid, "jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj jksladj askldjaskl jdasl 5");
    return 1;
}