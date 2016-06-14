#include "tournament.h"
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdio.h>

Team* initTeam(char * name){
	Team * team  = (Team *) malloc(sizeof(Team));

#if DEBUG_A1
	printf("In InitTeam: Team Name= %s\n",name);
#endif
	(*team).teamName =  malloc(strlen(name)+1);
	strcpy((*team).teamName, name);
	srand (time(NULL));
        int i = 0;
        for(i = 0; i < 10; i++){
                team->players[i].offensive =  rand() % 10 + 1; // 1 to 10 rand numbers
                team->players[i].defensive =  rand() % 7 + 1; //1 to 7 random numbers
        }
	return team;
}
