#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

#define CONFIG_FILE "config.txt"
#define HISTORY_FILE "history.txt"



/**********************************************************************************
 * write_config - Write configuration command
 * @param time_str: Argument for session duration configuration in hh:mm:ss format
 **********************************************************************************/
void write_config(char *time_str) {
    int h, m, s;
    FILE *file;

    if (strlen(time_str) != 8 || time_str[2] != ':' || time_str[5] != ':' ||
        !(isdigit(time_str[0]) && isdigit(time_str[1]) &&
          isdigit(time_str[3]) && isdigit(time_str[4]) &&
          isdigit(time_str[6]) && isdigit(time_str[7]))) {
        printf("Invalid time format. Use hh:mm:ss\n");
        return;
    }

    if (sscanf(time_str, "%2d:%2d:%2d", &h, &m, &s) == 3) {
        if (m >= 60 || s >= 60) {
            printf("Invalid times. Minutes and seconds are not allowed to be over 60\n");
            return;
        }
        file = fopen(CONFIG_FILE, "w");
        if (!file) {
            perror("Could not open config file");
            return;
        }
        fprintf(file, "%s\n", time_str);
        fclose(file);
        printf("Configuration %s saved to %s\n", time_str, CONFIG_FILE);
    } else {
        printf("Invalid time format. Use hh:mm:ss\n");
    }
}



int formatTime(int h, int m, int s) {
    int total = h * 3600 + m * 60 + s;
    return total;
}



/**********************************************************************************
 * start_session - Start a new session
 * @param arg: Argument for session duration in hh:mm:ss format
 **********************************************************************************/
void start_session(char *arg) {
    if (arg) {
        int h, m, s;
        if (sscanf(arg, "%2d:%2d:%2d", &h, &m, &s) == 3 &&
            h >= 0 && m >= 0 && m < 60 && s >= 0 && s < 60) {
            printf("Starting session with duration: %02d:%02d:%02d\n", h, m, s);
        } else {
            printf("Invalid duration format. Use hh:mm:ss\n");
            return;
        }
    }
    printf("Session started with config.\n");
}


/**********************************************************************************
 * show_history - Show session history
 **********************************************************************************/
void show_history() {
    printf("Showing history...\n");
}



/**********************************************************************************
 * delete - Delete a session or all history
 * @param arg: Argument for deletion, can be "all" or a session number
 **********************************************************************************/
void delete(char *arg) {
    if (!arg) {
        printf("Invalid delete command.\n");
        return;
    }

    if (strcmp(arg, "all") == 0) {
        printf("Deleting all history...\n");
    } else if (strspn(arg, "0123456789") == strlen(arg)) {
        int session = atoi(arg);
        printf("Deleting session %d...\n", session);
    }
}



typedef struct {
    const char *cmd;
    void (*func)(char *arg);
    int needs_arg;
} Command;



int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command> [argument]\n", argv[0]);
        return 1;
    }

    Command commands[] = {
        {"config", write_config, 1},
        {"start", start_session, 0},
        {"history", (void (*)(char*)) show_history, 0},
        {"delete", delete, 1}
    };

    const int num_cmds = sizeof(commands) / sizeof(commands[0]);
    const char *input = argv[1];
    char *arg = argc > 2 ? argv[2] : NULL;

    for (int i = 0; i < num_cmds; i++) {
        if (strcmp(input, commands[i].cmd) == 0) {
            if (commands[i].needs_arg && !arg) {
                printf("Command '%s' requires an argument.\n", input);
                return 1;
            }
            commands[i].func(arg);
            return 0;
        }
    }

    printf("Unknown command: %s\n", input);
    return 1;
}
