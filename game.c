#include "timer.h"
#include "gpio.h"
#include "gpio_extra.h"
#include "mango.h"
#include "uart.h"
#include "printf.h"
#include "hc_sr04.h"
#include "gl.h"
#include "animate.h"
#include "utils.h"
#include "game.h"
#include "keyboard.h"
#include "malloc.h"
#include "strings.h"
#define MAX_PLAYER_NAME_LENGTH 10

char ** start_game() {
    char *player1 = malloc(MAX_PLAYER_NAME_LENGTH * sizeof(char));
    char *player2 = malloc(MAX_PLAYER_NAME_LENGTH * sizeof(char));
    char **players = malloc(2 * sizeof(char *));
    int x = 260;
    int y = 292;
    gl_draw_string(50, 292, "First Player: ", GL_AMBER);
    gl_swap_buffer();
    gl_draw_string(50, 292, "First Player: ", GL_AMBER);
    int count = 0;
    while (1){
        char ch = keyboard_read_next();
        player1[count] = ch;
        count++;
        if (ch == '\n') {
            break;
        }
        gl_draw_char(x, y, ch, GL_AMBER);
        gl_swap_buffer();
        gl_draw_char(x, y, ch, GL_AMBER);
        x += gl_get_char_width();
    }
    player1[count] = '\0';
    count = 0;
    gl_clear(gl_color(0, 0, 0));
    gl_swap_buffer();
    gl_clear(gl_color(0, 0, 0));
    x = 260;
    y = 292;
    gl_draw_string(50, 292, "Second Player: ", GL_AMBER);
    gl_swap_buffer();
    gl_draw_string(50, 292, "Second Player: ", GL_AMBER);
    while (1) {
        char ch = keyboard_read_next();
        player2[count] = ch;
        count++;
        if (ch == '\n') {
            break;
        }
        gl_draw_char(x, y, ch, GL_AMBER);
        gl_swap_buffer();
        gl_draw_char(x, y, ch, GL_AMBER);
        x += gl_get_char_width();
    }
    player2[count] = '\0';
    players[0] = player1;
    players[1] = player2;
    return players;
}

void draw_rect_with_score(int x, int y, int num) {
    char ch = num + '0';
    gl_draw_rect(x, y, 24, 26, GL_WHITE);
    gl_draw_char(x + 5, y + 5, ch, GL_AMBER);
}

void display_turn(int count, const char * name1, const char* name2) {
    clear(0, 0, 800, 80);
    char buf1 [30];
    char buf2 [30];
    memcpy(buf1, name1, strlen(name1));
    memcpy(buf2, name2, strlen(name2));
    strlcat(buf1, "'s Turn", 1024);
    strlcat(buf2, "'s Turn", 1024);
    if (count % 2 == 0) {
        gl_draw_string(0, 5, buf1, GL_AMBER);
    } else {
        gl_draw_string(0, 5, buf2, GL_AMBER);
    }
}

// void display_scoreboard(int * scores, int round) {

// }