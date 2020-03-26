#include <a_samp>
#include <zcmd>
#define TDN_MODE_DEFAULT
#include "td-notification.inc"

main() {
	
}

CMD:spawn(playerid, params[]) {
    SetSpawnInfo(playerid, 0, 46, 1484.1082, -1668.4976, 14.9159, 0, 0,0,0,0,0,0);
    SpawnPlayer(playerid);
    ShowTDNotification(playerid, "jksladj askldjaskl jdaslkdj alskdjaslkjdaslkdj djaks dlasjdaklsjdklas dsakdjaskjd sakldjaslkd");
    return 1;
}
