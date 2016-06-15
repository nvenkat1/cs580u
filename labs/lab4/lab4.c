#include "tournament.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
	//char teamName1[] = "Team";
	//char *teamName2 = generateTeamName("India",5);
	char * teams[8] = {"Team1","Team2","Team3","Team4","Team5","Team6","Team7","Team8"};
	for(i=0; i<8 ; i++){
		//league[i] = initTeam(generateTeamName("Team",i+1));
		league[i] = initTeam(teams[i]);
	}

#if DEBUG_A1
	for(i = 0 ; i<8 ; i++){
		printf("Team%d = %s\n", i+1, (*(*(league + i))).teamName);
	}
#endif

#endif 	//Part A ends!

#if PART_B
	//Part B + Part C
	Team * champion = tournament(league);
	printf("\tCongratualation!!,\n\tChampion for this year are team of,%s\n",(*champion).teamName);

#endif	//Part B ends here!

	team1 = deleteTeam(team1);
	team1 = NULL;

	deleteLeague(league);


return 0;
}

/*
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
*/
