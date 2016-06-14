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

Team * game(Team * A, Team * B){
	int score = 0, scoreA = 0, scoreB = 0, i = 0;
	//for 10 rounds
	for( i = 0; i < 10; i++){
		score = calTotalDefenseOffence(A,1) + calTotalDefenseOffence(B,2);
	}

}

int calTotalDefenseOffence(Team* team, int rank){
#if DEBUG_A1
		printf("In CalOFF_DEF number of players = %d\n", sizeof((*team).players)/sizeof(Player));
#endif
	int totalScore = 0, i = 0;
	if(rank == 1){//Defensive team
		for( i = 0; i< sizeof((*team).players)/sizeof(Player); i++)
			totalScore += (*team).players[i].defensive;
	}else if( rank == 2){//Offensive team
		for( i = 0; i< sizeof((*team).players)/sizeof(Player); i++)
			totalScore += (*team).players[i].offensive;
	}
#if DEBUG_A1
	printf("Total Score %d\n", totalScore);
#endif
	return totalScore;
}
