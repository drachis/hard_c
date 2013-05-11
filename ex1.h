#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DAT 512
#define MAX_ROWS 100

struct Address {
  int id;
  int set;
  char name[MAX_DATA];
  char email[MAX_DATA];
}
