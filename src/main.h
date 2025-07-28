#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void write_config_cmd(char *arg);
void start_cmd(char *arg);
void history_cmd();
void delete_cmd(char *arg);
void help_cmd();
void version_cmd();
int main(int argc, char *argv[]);




#endif
