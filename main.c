/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "my.h"

int header(void)
{
    my_get_time();
    printw("\n");
    task();
    printw("\n");
    mem_file();
    printw("\n");
    mem_swap_file();
    return 0;
}

void wait(int count, int last)
{
    if (count != last) {
        move(0, 0);
        refresh();
        last = count;
    }
    if (count >= 3)
        timeout(3000);
}

int my_top(char quit, int count, int last)
{
    while (1) {
        quit = getch();
        if (quit == 'q' || quit == 'Q')
            break;
        header();
        count++;
        wait(count, last);
    }
    return 0;
}

int main(void)
{
    char quit = '\0';
    int count = 0;
    int last = -1;

    initscr();
    timeout(0);
    noecho();
    cbreak();
    if (my_top(quit, count, last) == 84)
        return 84;
    endwin();
    return 0;
}
