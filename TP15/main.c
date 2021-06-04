#include "heap.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <readline/readline.h>
#include <readline/history.h>

int verification(Head* head) {
    if(head->size < 2) {
        printf("Error : Less than 2 element entered before.\n");
        return 0;
    }
    return 1;
}
int main(int argc, char* argv[]) {
    char * line;
    Head* head = createHead();
    int exit = 0;
    while((line = readline(">>> "))) {
        add_history(line);
        char* word = strtok(line," ");
        while(word != NULL) {
            if(strcmp("+",word) == 0) {
                if(verification(head)) {
                    int value1 = pop(head);
                    int value2 = pop(head);
                    int result = value1 + value2;
                    push(head, result);
                }
            }
            else if(strcmp("-",word) == 0) {
                if(verification(head)) {
                    int value1 = pop(head);
                    int value2 = pop(head);
                    int result = value1 - value2;
                    push(head, result);
                }
            } 
            else if(strcmp("*",word) == 0) {
                if(verification(head)) {
                    int value1 = pop(head);
                    int value2 = pop(head);
                    int result = value1 * value2;
                    push(head, result);
                }
            }
            else if(strcmp("/",word) == 0) {
                if(verification(head)) {
                    int value1 = pop(head);
                    int value2 = pop(head);
                    if(value2!=0) {
                        int result = value1 / value2;
                        push(head, result);
                    } else {
                        push(head, value2);
                        push(head, value1);
                        printf("You can't divide by 0\n");
                    }
                }
            }
            else if(strcmp("%%",word) == 0) {
                if(verification(head)) {
                    int value1 = pop(head);
                    int value2 = pop(head);
                    int result = value1 % value2;
                    push(head, result);
                }
            }
            else if(strcmp("!",word) == 0) {
                if(head->size < 1) {
                    printf("Error : Less than 1 element entered before.\n");
                } else {
                    int value1 = pop(head);
                    int result=1, i=0;
                    for (i = 1; i <= value1; i++) {
                        result = result * i;
                    }
                    push(head, result);
                }
            }
            else if(strcmp("^",word) == 0) {
                if(verification(head)) {
                    int value1 = pop(head);
                    int value2 = pop(head);
                    int result = pow(value1, value2);
                    push(head, result);
                }
            }
            else if(strcmp("p",word) == 0 || strcmp("print",word) == 0) {
                printHead(head);
            }
            else if(strcmp("c",word) == 0 || strcmp("clear",word) == 0) {
                freeStack(head);
            }
            else if(strcmp("a",word) == 0 || strcmp("all",word) == 0) {
                printWholeStack(head);
            }
            else if(strcmp("r",word) == 0 || strcmp("reverse",word) == 0) {
                reverse(head);
            }
            else if(strcmp("q",word) == 0 || strcmp("quit",word) == 0) {
                exit = 1;
                break;
            } else {
                char* end;
                int value = 0;
            
                value = (int)strtol(word, &end, 10);
                if(word != end) {
                    push(head, value);
                }
                if(*end != '\0') {
                    printf("Those characters are not treated : %s\n", end);
                }
            }
            word = strtok(NULL," ");
        }
        free(line);
        
        if(exit == 1) {
            break;
        }
    }
    clear_history();
    freeStack(head);
    free(head);
    return 0;
}