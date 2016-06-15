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
	int score = 0, scoreA = 0, scoreB = 0, i = 0, matchTied = 0, isHandicap = 0;
		srand (time(NULL));

	//for 10 rounds
	for( i = 0; i < 10; i++){
		//get positive value. 1:Defensive Team 2:Offensive Team
		score =  abs( calTotalDefenseOffence(B,2) - calTotalDefenseOffence(A,1)); //TotalOffence - TotalDefense
#if DEBUG_A2
	printf("\tOffensive - Defensive = %d\n", score);
#endif
		int randForScore = rand() % 50 + 1;
		score = score + randForScore;
		//score =  rand() %  50 + 1; //generating random number 0 to 49, adding 1 shifts, 1 to 50
#if DEBUG_A2
	printf("\tRandom Number : %d + Score = %d\n", randForScore, score);
#endif

		if(score > 40 ){
			//Offensive Team B Won (2nd Team)
			scoreB++;
#if DEBUG_A2
	printf("\tAt the end of %dth round\n",i+1);
	printf("\tOffensive Team %s won this round, \tWith Score=%d > 40 \n\n", (*B).teamName, score);
#endif
		}else{//Defensive Team A won
			scoreA++;
#if DEBUG_A2
	printf("\tAt the end of %dth round\n",i+1);
	printf("\tDefensive Team %s won this round, \tWith Score=%d > 40\n\n", (*A).teamName, score);
#endif
		}//end else

	}//end for

//#if DEBUG_A2
	printf("\t###After 10 Rounds,\n\tOffensive %s A has scored = %d\n\tDefensive %s has scored = %d\n", (*B).teamName, scoreB, (*A).teamName, scoreA);
//#endif

	if(scoreB > scoreA){
		printf("\tOffensive %s Won!!\n\tWith Total score of: %d\n", (*B).teamName, scoreB);
		srand (time(NULL));
		int randHandi = (rand()%10 + 1);
#if DEBUG_A2
		printf("randHandi= %d\n", randHandi);
#endif
		if(randHandi > 5){
			isHandicap = 1;
			printf("\t Due to Handicap Law, other team has been offered 3 extra points\n!");
			scoreA += 3;
			Team * winningTeam = checkUpdatedScore(A, B, scoreB, scoreA, matchTied);
			printf("\t After upadated scores, Winning Team is, %s\n\n", (*winningTeam).teamName);
			return winningTeam;
		}
		return B;
	}else if(scoreA > scoreB){
		printf("\tDefensive %s Won!!\n\tWith Total score of: %d\n\n", (*A).teamName, scoreA);
		srand (time(NULL));
                int randHandi = (rand()% 10 + 1);
#if DEBUG_A2
                printf("randHandi= %d\n", randHandi);
#endif
                if(randHandi <5){
                        isHandicap = 1;
                        printf("\t Due to Handicap Law, other team has been offered 3 extra points\n!");
                        scoreB += 3;
                        Team * winningTeam = checkUpdatedScore(A, B, scoreB, scoreA, matchTied);
                        printf("\t After upadated scores, Winning Team is, %s\n\n", (*winningTeam).teamName);
                        return winningTeam;
                }
		return A;
	}else{
		printf("\tMatch was Tied\n");
		matchTied =1;
	}

	if(matchTied){
		printf("\tPenalty Shoot out!!\n");
		if( (rand()%2 +1)%2 == 0){
			printf("\tOffensive %s Scored!\n, Hence Winner!\n", (*B).teamName);
			printf("\tWith Final Score = %d\n\n", scoreB + 1);
			return B;
		}else{
			printf("\tDefensive %s Scored!\n, Hence Winner!\n", (*A).teamName);
                        printf("\tWith Final Score = %d\n\n", scoreA + 1);
			return A;
		}
	}




}

int calTotalDefenseOffence(Team* team, int rank){
#if DEBUG_A2
		//printf("\tIn CalOfenseDefense- number of players = %d\n", sizeof((*team).players)/sizeof(Player));
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
	if(rank == 1)
		printf("\tTotal Offensive Score %d\n", totalScore);
	else if(rank == 2)
		printf("\tTotal Defensive Score %d\n", totalScore);

#endif
	return totalScore;
}

Team* tournament(Team * league[]){
	int i = 0;
	Team * champion,* winner1_2, *winner3_4, *winner5_6, *winner7_8, *winner12_34, *winner56_78;

	for( i = 0; i < 3 ; i++){
		if(i==0){
			printf("\tRound1:\n");
			winner1_2 = game(league[i], league[i+1]);
			winner3_4 = game(league[i+2], league[i+3]);
			winner5_6 = game(league[i+4], league[i+5]);
			winner7_8 = game(league[i+6], league[i+7]);
			printf("\tWinners of First round are:\n\t%s\t%s\t%s\t%s\n\n",(*winner1_2).teamName,(*winner3_4).teamName,(*winner5_6).teamName,(*winner7_8).teamName);
		}else if(i==1){
			printf("\tRound2:\n");
			winner12_34 = game(winner1_2, winner3_4);
			winner56_78 = game(winner5_6, winner7_8);
			printf("\tWinners of Second round are:\n\t%s\t%s\n\n",(*winner12_34).teamName,(*winner56_78).teamName);
		}else if(i==2){
			printf("\tFinal Match:\n");
			champion = game(winner12_34, winner56_78);
		}
	//printf("\tCongratualation,\n\tChampion for this year are team of,%s\n",(*champion).teamName); 

	}

	return champion;
}

Team * checkUpdatedScore(Team * A, Team * B, int scoreB,  int scoreA,  int matchTied){
	if(scoreB > scoreA){
        	printf("\tOffensive %s Won!!\n\tWith Total score of: %d\n\n", (*B).teamName, scoreB);
		return B;
        }else if (scoreA > scoreB){
        	printf("\tDefensive %s Won!!\n\tWith Total score of: %d\n\n", (*A).teamName, scoreA);
                return A;
        }else{
                printf("\tMatch was Tied\n");
                matchTied =1;
        }
	if(matchTied){
        	printf("\tPenalty Shoot out!!\n");
                if( (rand()%2 +1)%2 == 0){
                	printf("\tOffensive %s Scored!\n, Hence Winner!\n", (*B).teamName);
                        printf("\tWith Final Score = %d\n\n", scoreB + 1);
                        return B;
	        }else{
			printf("\tDefensive %s Scored!\n, Hence Winner!\n", (*A).teamName);
			printf("\tWith Final Score = %d\n\n", scoreA + 1);
			return A;
		}
       }
}

void * deleteTeam(Team *A){
	free((*A).teamName);
	free(A);
	return NULL;
}

void * deleteLeague(Team **league){
	int i = 0;
	for(i = 0; i< 8; i++){
		free( (*(*(league + i))).teamName);
		free( (*leauge + i));
	}
	free(league);
	return NULL;
}
