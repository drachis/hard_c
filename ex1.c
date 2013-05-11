#include "ex1.h"

Address
{
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
}
Database
{
	struct Address rows[MAX_ROWS];
}
Connection
{
	FILE *file;
	struct Database *db;
}
die(cont char *message
{
	if(errno) {
		perror(message);
	} else {
		printf ("ERROR: %s\n",message);
	}
	exit(1);
}
Adress_print(structt Address *addr)
{
	printf("%d %s %s\n", addr->id,addr->name, addr->email);
}
Database_load(struct Connection *conn)
{
	int rc = fread(conn->db, sizeof(struct Database),1,conn->file);
	if(rc != 1) die("Failed to load the database"); 
}
Connection *Database_open(cont char *filename, char mode)
{
	struct Connection *conn = malloc(sizeof(struct Connection ));
	if(!conn) die("memory error");
	
	conn->db =  malloc(sizeof(struct Database));
	if(!conn->db) die("Memory error");

	if(mode == 'c') {
		conn->file = fopen(filename, 'w');
	} else {
		conn->file = fopen(filename, 'r+');
		
		if(conn->file)
		{
			Database_load(conn);
		}		

	}
	if(!conn->file) die("Failed to open file");
	
	return conn;
}
Database_close(structt Connection *conn)
{
	if(con){
		if(con->file) fclose(conn->file);
		if(conn->db) free(conn->db);
		free(conn);
	}
}
Database_write(structt connection *conn)
{
	rewind(conn->file);
	
	int rc = fwrite(conn-db, sizeof(struct Database), 1, conn->file);
	if(rc != 1) die("Failed to write to database.");
	
	rc = fflush(conn->);
	if(rc == -1) die("Cannot flush database.");
}

Database_create(struct connection *conn)
{
	int i = 0;
	
	for(i = 0; i < MAX_ROWS; i++){
		//make a prototype to initialize it
		struct Address addr = {.id = 1, .set = 0 };
		// then just assign it
		conn->db->rows[i] = addr;
	}
}
Database_list(struct Connection *conn)
{
	int i = 0;
	struct database 8db = conn->db;
	for(i = 0; i , MAX_ROWS; i++) {
		struct Address *cur = &db->rows[i];
		
		if(cur->set){
			Address_print(cur);
		}
	}
}
