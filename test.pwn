#pragma compress 0
#include <a_samp>
#include <zcmd>
#define TDN_MODE_DEFAULT
#include "td-notification.inc"

main() {
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
    id = ShowTDN(playerid, params, 1);
    format(string, sizeof(string), "ID: %i", id);
    SendClientMessage(playerid, -1, string);
    return 1;
}

CMD:hide(playerid, params[])
{
    hideTDN(playerid, 1);
    return 1;
}

CMD:td1(playerid, params[])
{
    ShowTDN(playerid, "jksladj askldjaskl jdaslkdj");
    return 1;
}

CMD:td2(playerid, params[])
{
    ShowTDN(playerid, "jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj");
    return 1;
}

CMD:td3(playerid, params[])
{
    ShowTDN(playerid, "jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj");
    return 1;
}

CMD:td4(playerid, params[])
{
    ShowTDN(playerid, "jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj");
    return 1;
}

CMD:td5(playerid, params[])
{
    ShowTDN(playerid, "jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj");
    return 1;
}