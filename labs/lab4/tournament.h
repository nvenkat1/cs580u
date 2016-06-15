#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#define PART_A1 1
#define PART_A2 1
#define PART_B 1
#define PART_C 1

#define DEBUG_A1 0
#define DEBUG_A2 0
#define DEBUG_B 1
#define DEBUG_C 1

typedef struct player{
	int offensive;
	int defensive;
}Player;

typedef struct team{
	char *teamName;
	Player players[10];
}Team;

Team* initTeam(char *name);
Team* game(Team*, Team*);
int calTotalDefenseOffence(Team *, int);
Team * tournament(Team *league[]);
#endif
