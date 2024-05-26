#include <ugid_functions.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define ME "root"

bool is_belong_to_me(const char *stat_file, char *process_name)
{
    FILE *status_file = fopen(stat_file, "r");
    if (status_file == NULL)
    {
        return false;
    }
    char name_buffer[256] = "";
    fgets(name_buffer, 256, status_file);
    char dummy[256] = "";
    for (int i = 0; i < 7; i++)
    {
        fgets(dummy, 256, status_file);
    }
    char uid_buffer[256] = "";
    fgets(uid_buffer, 256, status_file);
    int uid = 0;
    char *save_ptr = NULL;
    strtok_r(uid_buffer, "\t", &save_ptr); // Uid:
    char *uid_str = strtok_r(NULL, "\t", &save_ptr); // uid 
    if (uid_str == NULL)
    {
        printf("Unable to parse by strtok_r\n");
        fclose(status_file);
        return false;
    }
    uid = strtol(uid_str, NULL, 10);
    fclose(status_file);
    if (uid == userIdFromName(ME))
    {
        strtok_r(name_buffer, "\t", &save_ptr);
        char *name = strtok_r(NULL, "\t", &save_ptr);
        for (int i = 0; i < strlen(name); i++)
        {
            if ((name[i] == '\r') || (name[i] == '\n'))
            {
                name[i] = '\0';
            } 
        }
        strcpy(process_name, name);
        return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *ent;
    struct stat states;;
    printf("user id: %d\n", userIdFromName(ME));
    dir = opendir("/proc");
    char status_name[300] = "";
    while ((ent=readdir(dir)) != NULL)
    {
        stat(ent->d_name, &states);
        if (!strcmp(".", ent->d_name) || !strcmp("..", ent->d_name))
        {
            continue;
        }
        if (strtol(ent->d_name, NULL, 10) != 0)
        {
            snprintf(status_name, 300, "%s/%s/status", "/proc", ent->d_name);
            char process_name[256] = "";
            if(is_belong_to_me(status_name, process_name))
            {
                printf("USER %s: FOUND: %s\n", ME, process_name);
            }
        }
    }
    return 0;
}