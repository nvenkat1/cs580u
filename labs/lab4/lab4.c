#include "tournament.h"
#include<stdio.h>
#include<stdlib.h>

int main(){

#if PART_A1
	Team * team1 = initTeam("India");

#if DEBUG_A1
	int i = 0;
	printf("In Main : Team Name = %s\n",(*team1).teamName);
        for(i = 0; i< 10; i++){
                printf("Offensive: %d\t", team1->players[i].offensive);
                printf("Defensive: %d\n", team1->players[i].defensive);
        }
#endif

	Team *league[8];
	char teamName1 = "Team";
	for(i=0; i<8 ; i++){
		league[i] = initTeam("Team");
	}

#endif


return 0;
}
