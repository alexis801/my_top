/*
** EPITECH PROJECT, 2024
** tasks
** File description:
** tasks
*/

#include "my.h"

static status_t status_counter(char *buffer, int i, status_t tasks)
{
    switch (buffer[i]) {
    case 'R':
        tasks.R_count += 1;
        break;
    case 'Z':
        tasks.Z_count += 1;
        break;
    case 'T':
        tasks.T_count += 1;
        break;
    default:
        tasks.S_count += 1;
    }
    return tasks;
}

static status_t status_search(struct dirent *entry, status_t tasks)
{
    char buffer[100];
    char file_path[100];
    FILE* status_file;
    int i;

    strcpy(file_path, "/proc/");
    strcat(file_path, entry->d_name);
    strcat(file_path, "/status");
    status_file = fopen(file_path, "r");
    fread(buffer, sizeof(char), 100, status_file);
    for (i = 0; buffer[i] != '\0'; i++) {
        if (isupper(buffer[i]) && buffer[i + 1] == ' ') {
            tasks = status_counter(buffer, i, tasks);
            break;
        }
    }
    fclose(status_file);
    return tasks;
}

static status_t init_tasks(status_t tasks)
{
    tasks.R_count = 0;
    tasks.S_count = 0;
    tasks.T_count = 0;
    tasks.Z_count = 0;
    return tasks;
}

int task(void)
{
    struct dirent *entry;
    DIR *dir = opendir("/proc");
    int counter = 0;
    status_t tasks;

    tasks = init_tasks(tasks);
    if (dir == NULL)
        return 84;
    for (entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
        if (isdigit(entry->d_name[0])) {
            counter++;
            tasks = status_search(entry, tasks);
        }
    }
    printw("Tasks: %d total,   ", counter);
    printw("%i running, %i sleeping,   ", tasks.R_count, tasks.S_count);
    printw("%i stopped,   %i zombie", tasks.T_count, tasks.Z_count);
    closedir(dir);
    return 0;
}
