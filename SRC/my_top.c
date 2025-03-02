/*
** EPITECH PROJECT, 2024
** my top
** File description:
** my top
*/

#include "my.h"
#include <string.h>

static void minutes(float temp)
{
    while (temp >= 3600)
        temp -= 3600;
    temp /= 60;
    if (temp < 10)
        printw("0");
    printw("%d, ", (int)temp);
}

static int sec_to_days(char *buffer)
{
    int i;
    float temp;

    for (i = 0; buffer[i] != ' '; i++);
    buffer[i] = '\0';
    temp = atof(buffer);
    if (temp >= 86400)
        printw("up %d days, ", (int)temp / 86400);
    while (temp >= 86400)
        temp -= 86400;
    if (temp >= 3600)
        printw("%d:", (int)temp / 3600);
    minutes(temp);
    return 0;
}

static int my_get_uptime(void)
{
    char *buffer = malloc(sizeof(char) * 10);
    FILE* uptime_file = fopen("/proc/uptime", "r");
    int read_return;

    if (!uptime_file)
        return 84;
    read_return = fread(buffer, sizeof(int), 1000, uptime_file);
    if (read_return == 0)
        return 84;
    sec_to_days(buffer);
    free(buffer);
    fclose(uptime_file);
    return 0;
}

static int my_getloadavg(void)
{
    char buffer[100];
    FILE* loadavg_file = fopen("/proc/loadavg", "r");
    int read_return;

    if (!loadavg_file)
        return 84;
    read_return = fread(buffer, sizeof(char), 1000, loadavg_file);
    if (read_return == 0)
        return 84;
    printw(" load average: ");
    for (int i = 0; i < 15; i++) {
        if (i == 4 || i == 9)
            printw(",");
        printw("%c", buffer[i]);
    }
    fclose(loadavg_file);
    return 0;
}

int my_get_time(void)
{
    time_t s = 1;
    struct tm* current_time;

    s = time(NULL);
    current_time = localtime(&s);
    printw("\rtop - %02d:", current_time->tm_hour);
    printw("%02d:%02d ", current_time->tm_min, current_time->tm_sec);
    my_get_uptime();
    printw(" 1 user, ");
    my_getloadavg();
    return 0;
}
