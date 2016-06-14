#include "tournament.h"
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdio.h>

Team* initTeam(char * name){
	Team * team  = (Team *) malloc(sizeof(Team));

#if DEBUG_A1
	printf("\tIn InitTeam: Team Name= %s\n",name);
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
	printf("\t----<%s vs %s>----\n", (*A).teamName, (*B).teamName);
	int score = 0, scoreA = 0, scoreB = 0, i = 0, matchTied = 0;
	srand (time(NULL));

	//for 10 rounds
	for( i = 0; i < 10; i++){
		//get positive value. 1:Defensive Team 2:Offensive Team
		score =  abs( calTotalDefenseOffence(B,2) - calTotalDefenseOffence(A,1)); //TotalOffence - TotalDefense
		score =  rand() %  50 + 1; //generating random number 0 to 49, adding 1 shifts, 1 to 50

#if DEBUG_A2
		//printf("Random Number for game: %d ",randomNumber);
		printf("Game: RandNum= %d ",rand() % 50 +1);
#endif
		if(score > 40 ){
			//Offensive Team B Won (2nd Team)
			scoreB++;
#if DEBUG_A2
	printf("\tAt the end of %dth round\n",i);
	printf("\tOffensive Team %s won this round, \tWith Score=%d\n", (*B).teamName, score);
#endif
		}else{//Defensive Team A won
			scoreA++;
#if DEBUG_A2
	printf("\tAt the end of %dth round\n",i);
	printf("\tDefensive Team %s won this round, \tWith Score=%d\n", (*A).teamName, score);
#endif
		}//end else

	}//end for

	if(scoreB > scoreA){
		printf("\tOffensive %s Won!!\nWith Total score of: %d\n", (*B).teamName, scoreB);
		return B;
	}else if(scoreA > scoreB){
		printf("\tDefensive %s Won!!\nWith Total score of: %d\n", (*A).teamName, scoreA);
		return A;
	}else{
		printf("\tMatch was Tied\n");
		matchTied =1;
	}

	if(matchTied){
		printf("\tPenalty Shoot out!!\n");
		if( (rand()%2 +1)%2 == 0){
			printf("\tOffensive %s Scored!\n, Hence Winner!\n", (*B).teamName);
			printf("\tWith Final Score = %d\n", scoreB + 1);
			return B;
		}else{
			printf("\tDefensive %s Scored!\n, Hence Winner!\n", (*A).teamName);
                        printf("\tWith Final Score = %d\n", scoreA + 1);
			return A;
		}
	}



}

int calTotalDefenseOffence(Team* team, int rank){
#if DEBUG_A2
		printf("\tIn CalOfenseDefense- number of players = %d\n", sizeof((*team).players)/sizeof(Player));
#endif
	int totalScore = 0, i = 0;
	if(rank == 1){//Defensive team
		for( i = 0; i< sizeof((*team).players)/sizeof(Player); i++)
			totalScore += (*team).players[i].defensive;
	}else if( rank == 2){//Offensive team
		for( i = 0; i< sizeof((*team).players)/sizeof(Player); i++)
			totalScore += (*team).players[i].offensive;
	}
#if DEBUG_A2
	printf("\tTotal Score %d\n", totalScore);
#endif
	return totalScore;
}
