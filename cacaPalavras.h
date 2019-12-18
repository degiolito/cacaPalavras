#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>
#include <windows.h>
#define stringMax 46
#define true 1
#define false 0

typedef int bool;

typedef struct{
char letra;
int achou;
} elemento;

typedef struct{
 int n_col;
 int n_lin;
 int n_pal;
 elemento **data;
} matriz;

typedef matriz* pontMatriz;

enum DOS_COLORS {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
    LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
    LIGHT_RED, LIGHT_MAGENTA, YELLOW, RESET };
