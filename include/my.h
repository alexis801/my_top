/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** my.h
*/

#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/param.h>
#ifndef MY_H
    #define MY_H

typedef struct satus_s {
    int S_count;
    int R_count;
    int Z_count;
    int T_count;
} status_t;

typedef struct mem_info_s {
    float total;
    float free;
    float buffers;
    float cached;
    float available;
    float SReclaimable;
} mem_info_t;

int main(void);
int my_get_time(void);
int task(void);
int mem_file(void);
int mem_swap_file(void);
#endif /* MY_H */
