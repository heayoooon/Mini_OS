/* ************************************************************************** */
/*                                                                            */
/*                                  bases.c                                   */
/*                                                                            */
/*                       By: 최정흠 <andyc707@dgu.ac.kr>                      */
/*                                                                            */
/*                        Created: 2024/05/12 14:40:02                        */
/*                                                                            */
/* ************************************************************************** */

#include "bases.h"
#include "commands.h"

int find_cmd(int size, char **cmd) {

    int is_user_exit;

    is_user_exit = 0;
    printf("size : %d\n", size);
    if (strcmp(cmd[0], LS_CMD) == 0) {
        printf("ls input\n");
    } else if (strcmp(cmd[0], CD_CMD) == 0) {
        printf("cd input\n");
    } else if (strcmp(cmd[0], MKDIR_CMD) == 0) {
        mkdir_(size, cmd);
    } else if (strcmp(cmd[0], CAT_CMD) == 0) {
        printf("cat input\n");
    } else if (strcmp(cmd[0], CHMOD_CMD) == 0) {
        printf("chmod input\n");
    } else if (strcmp(cmd[0], GREP_CMD) == 0) {
        printf("grep input\n");
    } else if (strcmp(cmd[0], CP_CMD) == 0) {
        printf("cp input\n");
    } else if (strcmp(cmd[0], TOUCH_CMD) == 0) {
        printf("touch input\n");
    } else if (strcmp(cmd[0], EXIT_CMD) == 0) {
        is_user_exit = 1;
    } else
        printf("bash: command not found: %s\n", cmd[0]);

    return (is_user_exit);
}

int parsing_cmd(char *target, char **ret) {

    int   cnt;
    char  *token;
    char  *temp;

    cnt = 0;
    temp = target;
    while ((token = strtok_r(temp, " \n", &temp))) {
        if (cnt >= PARSED_MAX)
            break;
        ret[cnt] = token;
        cnt++;
    }
    
    return (cnt);
}

void make_lower_case_word(char *target) {

    while (*target) {
        *target = tolower((unsigned char) *target);
        target++;
    }

    return ;
}

void init_1_dim_char(char *target, int size) {

    for (int i = 0; i < size; i++)
        *(target + i) = 0;

    return ;
}

void init_2_dim_char(char **target, int size) {

    for (int i = 0; i < size; i++)
        *(target + i) = 0;

    return ;
}

void clear_buffer(void) {

    while (getchar() != '\n');

    return ;
}

