#include "tournament.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * generateTeamName(char *teamName, int num){

	char numString[2];
	sprintf(numString, "%d", num);

	char *combinedString = malloc(strlen(teamName)+strlen(numString)+1);
	combinedString[0] = '\0';

	strcat(combinedString,teamName);
	strcat(combinedString,numString);

#if DEBUG_A1
	printf("In generateTeamName : teamName = %s\t %d\n ",teamName, strlen(teamName));
	printf("numString = %s\t length=%d\n", numString , strlen(numString));
	printf("TempString = %s\t length=%d\n", combinedString , strlen(combinedString));
#endif
	return combinedString;
}


int main(){

#if PART_A1
	Team * team1 = initTeam("India");
	int i = 0;

#if DEBUG_A1
	printf("In Main : Team Name = %s\n",(*team1).teamName);
        for(i = 0; i< 10; i++){
                printf("Offensive: %d\t", team1->players[i].offensive);
                printf("Defensive: %d\n", team1->players[i].defensive);
        }
#endif

	Team *league[8];
	char teamName1[] = "Team";
	char *teamName2 = generateTeamName("India",5);
	for(i=0; i<8 ; i++){
		league[i] = initTeam(generateTeamName("Team",i+1));
	}

#if DEBUG_A1
	for(i = 0 ; i<8 ; i++){
		printf("Team%d = %s\n", i+1, (*(*(league + i))).teamName);
	}
#endif
	//Round 1: 1 vs 2 | 3 vs 4 |  5 vs 6 | 7 vs 8
	Team * Winner1_2 = game(league[0], league[1]);
	//Team * Winner3_4 = game(league[2], league[3]);
	//Team * Winner5_6 = game(league[4], league[5]);
	//Team * Winner7_8 = game(league[6], league[7]);

	//Round 2: Winner1_2 vs Winner3_4 | Winner5_6 vs Winner7_8
	//Team * Winner12_34 = game(Winner1_2, Winner3_4);
	//Team * Winner56_78 = game(Winner5_6, Winner7_8);

	//Final: Winner12_34 vs Winner56_78
	//Team * Winner = game(Winner12_34, Winner56_78);
#endif


return 0;
}
