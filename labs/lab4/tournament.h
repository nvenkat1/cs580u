#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#define PART_A1 1
#define PART_A2 1

#define DEBUG_A1 1
#define DEBUG_A2 1

typedef struct player{
	int offensive;
	int defensive;
}Player;

typedef struct team{
	char *teamName;
	Player players[10];
}Team;

Team* initTeam(char *name);

#endif
