#ifndef GAME_H
#define GAME_H

struct Player{
    char * name;
    int score[5];
    int round;
};

char ** start_game();

void draw_rect_with_score(int x, int y, int num);

void display_turn(int count, const char * name1, const char* name2);

void display_scoreboard(int * scores, int round);

#endif