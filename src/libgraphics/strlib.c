/*
 * File: strlib.c
 * Version: 1.0
 * Last modified on Fri Jul 15 14:10:41 1994 by eroberts
 * -----------------------------------------------------
 * This file implements the strlib.h interface.
 */

/*
 * General implementation notes:
 * -----------------------------
 * This module implements the strlib library by mapping all
 * functions into the appropriate calls to the ANSI <string.h>
 * interface.  The implementations of the individual functions
 * are all quite simple and do not require individual comments.
 * For descriptions of the behavior of each function, see the
 * interface.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "genlib.h"
#include "strlib.h"

/*
 * Constant: MaxDigits
 * -------------------
 * This constant must be larger than the maximum
 * number of digits that can appear in a number.
 */

#define MaxDigits 30

/* Private function prototypes */

static string CreateString(int len);

/* Section 1 -- Basic string operations */

string Concat(string s1, string s2)
{
    string s;
    int len1, len2;

    if (s1 == NULL || s2 == NULL) {
        Error("NULL string passed to Concat");
    }
    len1 = strlen(s1);
    len2 = strlen(s2);
    s = CreateString(len1 + len2);
    strcpy(s, s1);
    strcpy(s + len1, s2);
    return (s);
}

char IthChar(string s, int i)
{
    int len;

    if (s == NULL) Error("NULL string passed to IthChar");
    len = strlen(s);
    if (i < 0 || i > len) {
        Error("Index outside of string range in IthChar");
    }
    return (s[i]);
}

string SubString(string s, int p1, int p2)
{
    int len;
    string g_result;

    if (s == NULL) Error("NULL string passed to SubString");
    len = strlen(s);
    if (p1 < 0) p1 = 0;
    if (p2 >= len) p2 = len - 1;
    len = p2 - p1 + 1;
    if (len < 0) len = 0;
    g_result = CreateString(len);
    strncpy(g_result, s + p1, len);
    g_result[len] = '\0';
    return (g_result);
}

string CharToString(char ch)
{
    string g_result;

    g_result = CreateString(1);
    g_result[0] = ch;
    g_result[1] = '\0';
    return (g_result);
}

int StringLength(string s)
{
    if (s == NULL) Error("NULL string passed to StringLength");
    return (strlen(s));
}

string CopyString(string s)
{
    string newstr;

    if (s == NULL) Error("NULL string passed to CopyString");
    newstr = CreateString(strlen(s));
    strcpy(newstr, s);
    return (newstr);
}

/* Section 2 -- String comparison functions */

bool StringEqual(string s1, string s2)
{
    if (s1 == NULL || s2 == NULL) {
        Error("NULL string passed to StringEqual");
    }
    return (strcmp(s1, s2) == 0);
}

int StringCompare(string s1, string s2)
{
    if (s1 == NULL || s2 == NULL) {
        Error("NULL string passed to StringCompare");
    }
    return (strcmp(s1, s2));
}

/* Section 3 -- Search functions */

int FindChar(char ch, string text, int start)
{
    char *cptr;

    if (text == NULL) Error("NULL string passed to FindChar");
    if (start < 0) start = 0;
    if (start > strlen(text)) return (-1);
    cptr = strchr(text + start, ch);
    if (cptr == NULL) return (-1);
    return ((int) (cptr - text));
}

int FindString(string str, string text, int start)
{
    char *cptr;

    if (str == NULL) Error("NULL pattern string in FindString");
    if (text == NULL) Error("NULL text string in FindString");
    if (start < 0) start = 0;
    if (start > strlen(text)) return (-1);
    cptr = strstr(text + start, str);
    if (cptr == NULL) return (-1);
    return ((int) (cptr - text));
}

/* Section 4 -- Case-conversion functions */

string ConvertToLowerCase(string s)
{
    string g_result;
    int i;

    if (s == NULL) {
        Error("NULL string passed to ConvertToLowerCase");
    }
    g_result = CreateString(strlen(s));
    for (i = 0; s[i] != '\0'; i++) g_result[i] = tolower(s[i]);
    g_result[i] = '\0';
    return (g_result);
}

string ConvertToUpperCase(string s)
{
    string g_result;
    int i;

    if (s == NULL) {
        Error("NULL string passed to ConvertToUpperCase");
    }
    g_result = CreateString(strlen(s));
    for (i = 0; s[i] != '\0'; i++) g_result[i] = toupper(s[i]);
    g_result[i] = '\0';
    return (g_result);
}

/* Section 5 -- Functions for converting numbers to strings */

string IntegerToString(int n)
{
    char buffer[MaxDigits];

    sprintf(buffer, "%d", n);
    return (CopyString(buffer));
}

int StringToInteger(string s)
{
    int g_result;
    char dummy;

    if (s == NULL) {
        Error("NULL string passed to StringToInteger");
    }
    if (sscanf(s, " %d %c", &g_result, &dummy) != 1) {
        Error("StringToInteger called on illegal number %s", s);
    }
    return (g_result);
}

string RealToString(double d)
{
    char buffer[MaxDigits];

    sprintf(buffer, "%G", d);
    return (CopyString(buffer));
}

double StringToReal(string s)
{
    double g_result;
    char dummy;

    if (s == NULL) Error("NULL string passed to StringToReal");
    if (sscanf(s, " %lg %c", &g_result, &dummy) != 1) {
        Error("StringToReal called on illegal number %s", s);
    }
    return (g_result);
}

/* Private functions */

/*
 * Function: CreateString
 * Usage: s = CreateString(len);
 * -----------------------------
 * This function dynamically allocates space for a string of
 * len characters, leaving room for the null character at the
 * end.
 */

static string CreateString(int len)
{
    return ((string) GetBlock(len + 1));
}
