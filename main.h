#ifndef main_h
#define main_h

/* c libaries */
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include <stddef.h>
extern char **environ;


/* functions */
void _print(const char *str);
char *_strdup(const char *str);
char *_strcpy(char *destin, const char *source);
void trim_buffer(char *buffer);
int main(int argc, char *argv[], char *env[]);
size_t _strlen(const char *str);
void child(int argc, char *argv[], char *buf,
		char **ave, char *only, int *status);
int _strcmp(const char *string1, const char *string2);
void tok_buf(char *buf, char *args[], const char *del,
		char *str, char *env[]);
char *full_path(char *env[], char cmd[]);
void myprintf(const char *format, ...);
void tostring(int num);
char *path_check(char path[]);
void _env(void);
void _envNon(int *no_exc);
void non_interactive(int argc, char *argv[],
		char *env[], int *pipe);
char *take_only_cmd(char **buffer, int *no_exc,
		int argc, char *argv[], int *n_err);
void ls_check(char *ave[], char *buf, char *only);
void change_dir(char *buffer, char *cmd, int argc, char *argv[], int *n_err);
void comments(char **buf, int *no_exc);
void tok(char **buf, const char **del, char **token,
		char **str, char *args[]);
void handle_input_command(char **buffer, size_t *n_buffer,
		int *no_exc, char **only_command, int status,
		int argc, char *argv[], int *n_err);
void handle_sigint(int sig_num);
char *name_prg(int argc, char *argv[]);
void shell_exit(int status);

#endif
