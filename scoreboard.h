#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "game.h"


struct Player{
    char * name;
    // int score[5];
    int total_score;
    int round;
    int last_round_pin;
};


// /*
// * Create the empty scoreboard, and create all the sengemntation.
// */
// void scoreboard_init();


// // Update the scoreboard with the player's score
// void scoreboard_update(Player *player);


// // Calculate the score of the player in that particular round
// int calculate_round_score(Player *player);



// Draw the scoreboard
void draw_scoreboard_boilerplate(void);






#endif