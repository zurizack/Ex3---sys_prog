#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "txtfind.h"

int getParagraph(char *buf)
{
    int trueSize = 0;
    char *tmp = malloc(1);
    scanf("%c", tmp);
    free(tmp);

    while (fgets((buf + trueSize), sizeof((buf + trueSize)), stdin))
    {
        if (trueSize >= MAX_LINES * LINE || *(buf + trueSize) == EOF || !strcmp((buf + trueSize), "\n"))
            break;
        trueSize = strlen(buf);
    }
    if (isspace(*(buf + trueSize - 1)))
        *(buf + trueSize - 1) = '\0';
    else
        *(buf + trueSize) = '\0';
    return trueSize;
}

int getWord(char *line, char *buf)
{
    int i = 0;
    while (*(line + i) && !isspace(*(line + i)))
    {
        *(buf + i) = (char)*(line + i);
        i++;
    }
    *(buf + i) = '\0';
    return strlen(buf);
}

int getLine(char *paragraph, char *buf)
{
    int i = 0;
    while (*(paragraph + i) && (char)*(paragraph + i) != '\n')
    {
        *(buf + i) = (char)*(paragraph + i);
        i++;
    }
    *(buf + i) = '\0';
    return strlen(buf);
}

int word_match(char *string, char *to_match)
{
    int match = 0;
    int i = 0, str_len = strlen(string), match_len = strlen(to_match);

    if (abs(str_len - match_len) > MAX_ERROR)
        return 0;
    while (*(string + i))
    {
        if ((char)*(to_match + match) == (char)*(string + i))
        {
            match++; 
        }
        i++;
    }
    return match >= match_len;
}

void search(char *s, char *q)
{

    int current_pos = 0, query_len = strlen(q), string_len = strlen(s) - query_len;
    char *word_buf = malloc(WORD);
    int skip = 0, match;
    while (current_pos <= string_len)
    {
        word_buf = (char *)realloc(word_buf, WORD);
        skip = 0;
        while (isspace(*(s + skip + current_pos))) 
            skip++;
        current_pos += skip;
        current_pos += getWord((s + current_pos), word_buf);
        match = word_match(word_buf, q);
        if (match)
            printf("%s\n", word_buf);
    }
    free(word_buf);
}

void searchLines(char *string, char *q)
{

    int current_pos = 0, query_len = strlen(q), string_len = strlen(string) - query_len;
    char *line_buf = malloc(WORD);
    int skip = 0;
    char *match;
    while (current_pos <= string_len)
    {
        line_buf = (char *)realloc(line_buf, LINE);
        skip = 0;
        while (isspace(*(string + skip + current_pos)))
            skip++;
        current_pos += skip;
        current_pos += getLine((string + current_pos), line_buf);
        match = strstr(line_buf, q);
        if (match != NULL)
            printf("%s\n", line_buf);
    }
    free(line_buf);
}

int getOperands(char *cmd, char *query)
{
    int trueSize = 0, queryLen;
    char *buf = malloc(LINE);
    while (fgets((buf + trueSize), sizeof((buf + trueSize)), stdin))
    {
        if (trueSize >= LINE || *(buf + trueSize) == EOF || (char)*(buf + trueSize) != '\n')
            break;
        trueSize = strlen(buf);
    }
    queryLen = getWord(buf, query) + 1; /* query length + whitespace */
    getWord(buf + queryLen, cmd);
    return trueSize;
}

int main()
{
    char *cmd = (char *)malloc(1), *query = (char *)malloc(WORD);
    char *buf = (char *)malloc(MAX_LINES * LINE);
    getOperands(cmd, query);
    getParagraph(buf);

    if (!strcmp(cmd, OPTION_A))
        searchLines(buf, query);
    else if (!strcmp(cmd, OPTION_B))
        search(buf, query);

    free(cmd);
    free(query);
    free(buf);

    return 0;
}
