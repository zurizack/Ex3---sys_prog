#ifndef TXFIND
#include <ctype.h>
#define TXTFIND
#define LINE 256
#define MAX_LINES 250
#define OPTION_A "a"
#define OPTION_B "b"
#define WORD 30
#define MAX_ERROR 1
#define END_LINE '\n'
#define IS_END_WORD(A) isspace(A);
/* reads from stdin until a blank line is entered */
int getParagraph(char*buf);
/* reads from stdin until a newline is entered*/
int getLine(char *paragraph, char *buf);
/* reads from stdin until any space is enetered*/
int getWord(char *line, char *buf);
int word_match(char *s, char *q);
/* search all mutations of q inside s*/
void search(char *s, char *q);
/* search all lines in s where q appears */
void searchLines(char *s, char *q);
#endif
