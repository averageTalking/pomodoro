#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"



/**********************************************************************************
 * config_session - Write configuration command
 * @param arg: Argument for session duration configuration in hh:mm:ss format
 **********************************************************************************/
void config_session(char *arg) {
    printf("Config: %s\n", arg);
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
    else printf("Starting session with config\n");
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
        {"config", config_session, 1},
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
