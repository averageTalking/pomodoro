#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void write_config(char *arg);

int parseTime(int h, int m, int s);
void print_progress(int current, int total);
void timer(int h, int m, int s);
void start_session(char *arg);

void show_history();
void delete(char *arg);

int main(int argc, char *argv[]);




#endif
