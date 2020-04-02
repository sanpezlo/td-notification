#pragma compress 0
#include <a_samp>
#include <zcmd>
#define TDN_MODE_DEFAULT
#include "td-notification.inc"

main() {
}

public OnPlayerConnect(playerid)
{
    SetSpawnInfo(playerid, 0, 46, 1484.1082, -1668.4976, 14.9159, 0, 0,0,0,0,0,0);
    SpawnPlayer(playerid);
    return 1;
}

CMD:td(playerid, params[])
{
    ShowTDNotification(playerid, params);
    return 1;
}

CMD:td1(playerid, params[])
{
    ShowTDNotification(playerid, "jksladj askldjaskl jdaslkdj");
    return 1;
}

CMD:td2(playerid, params[])
{
    ShowTDNotification(playerid, "jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj");
    return 1;
}

CMD:td3(playerid, params[])
{
    ShowTDNotification(playerid, "jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj");
    return 1;
}

CMD:td4(playerid, params[])
{
    ShowTDNotification(playerid, "jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj");
    return 1;
}

CMD:td5(playerid, params[])
{
    ShowTDNotification(playerid, "jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj jksladj askldjaskl jdaslkdj");
    return 1;
}