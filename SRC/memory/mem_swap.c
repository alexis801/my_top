/*
** EPITECH PROJECT, 2025
** mem_swap
** File description:
** mem_swap
*/

#include "my.h"

static void print_swap(float total, float free, float available)
{
    printw("MiB Swap:   %.1f total,   ", total);
    printw("%.1f free,      %.1f used.  ", free, total - free);
    printw("%.1f avail Mem", available);
}

static void swap_calcul(FILE* meminfo)
{
    char file[500];
    int recup = 0;
    float total;
    float free;
    float available;

    while (fscanf(meminfo, "%s %d", file, &recup)) {
        if (strcmp(file, "MemAvailable:") == 0)
            available = recup / 1024.0;
        if (strcmp(file, "SwapTotal:") == 0)
            total = recup / 1024.0;
        if (strcmp(file, "SwapFree:") == 0) {
            free = recup / 1024.0;
            break;
        }
    }
    print_swap(total, free, available);
}

int mem_swap_file(void)
{
    FILE* meminfo;

    meminfo = fopen("/proc/meminfo", "r");
    swap_calcul(meminfo);
    fclose(meminfo);
    return 0;
}
