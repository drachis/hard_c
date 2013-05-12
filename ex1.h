#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address;
struct Database;
struct Connection;

void die(
	const char *message
	);
void Adress_print(
	struct Address *addr
	);
void Database_load(
	struct Connection *conn
	);
struct Connection *Database_open(
	const char *filename,
	char mode
	);
void Database_close(
	struct Connection *conn
	);
void Database_write(
	struct Connection *conn
	);
void Database_create(
	struct Connection *conn
	);
void Database_set(
	struct Connection *conn
	,int id,const char *name
	,const char *email
	);
void Database_get(
	struct Connection *conn
	,int id
	);
void Database_delete(
	struct Connection *conn
	,int id
	);
void Database_list(
	struct Connection *conn
	);
