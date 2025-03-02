/*
** EPITECH PROJECT, 2024
** mem
** File description:
** mem
*/

#include "my.h"

static mem_info_t mem(FILE* meminfo, mem_info_t mem_stock)
{
    char test[200];
    int recup = 0;

    while (fscanf(meminfo, "%s %d", test, &recup)) {
        if (strcmp(test, "MemTotal:") == 0)
            mem_stock.total = recup / 1024.0;
        if (strcmp(test, "MemAvailable:") == 0)
            mem_stock.available = recup / 1024.0;
        if (strcmp(test, "MemFree:") == 0)
            mem_stock.free = recup / 1024.0;
        if (strcmp(test, "Buffers:") == 0)
            mem_stock.buffers = recup / 1024.0;
        if (strcmp(test, "Cached:") == 0)
            mem_stock.cached = recup / 1024.0;
        if (strcmp(test, "SReclaimable:") == 0) {
            mem_stock.SReclaimable = recup / 1024.0;
            break;
        }
    }
    return mem_stock;
}

static void print_mem(mem_info_t mem_stock, float mem_used, float buff_cache)
{
    printw("\nMiB Mem :  %.1f total,   ", mem_stock.total);
    printw("%.1f free,   ", mem_stock.free);
    printw("%.1f used,   ", mem_used);
    printw("%.1f buff/cache", buff_cache);
}

static void calculator(mem_info_t mem_stock)
{
    float mem_used = mem_stock.total - mem_stock.available;
    float buff_cache;

    buff_cache = mem_stock.buffers + mem_stock.cached + mem_stock.SReclaimable;
    print_mem(mem_stock, mem_used, buff_cache);
}

int mem_file(void)
{
    FILE* meminfo;
    mem_info_t mem_stock;

    meminfo = fopen("/proc/meminfo", "r");
    mem_stock = mem(meminfo, mem_stock);
    calculator(mem_stock);
    fclose(meminfo);
    return 0;
}
