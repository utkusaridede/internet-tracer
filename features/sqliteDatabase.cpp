#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
	int i;
	for(i=0; i<argc; i++){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

int main(int argc, char **argv){
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc, rc2, rc3;

	if( argc!=2 ){
		fprintf(stderr, "Usage: %s DATABASE SQL-STATEMENT\n", argv[0]);
		return(1);
	}
	rc = sqlite3_open(argv[1], &db);
	if( rc ){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return(1);
	}
	char sql[1000] = "CREATE TABLE TRACER("  \
         "date TIMESTAMP PRIMARY KEY     NOT NULL," \
         "down_speed           INT    NOT NULL," \
         "up_speed            INT     NOT NULL," \
         "transmit        INT    NOT NULL," \
         "recieve         INT    NOT NULL );";
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if( rc!=SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}

	char sql2[1000] = "INSERT INTO TRACER (date, down_speed, up_speed, transmit, recieve) "  \
         "VALUES (CURRENT_TIMESTAMP, '1', '1', '1', '1');";

    rc2 = sqlite3_exec(db, sql2, callback, 0, &zErrMsg);
    if( rc2!=SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}

	char sql3[1000] = "SELECT date FROM TRACER WHERE down_speed = '1'";
	sqlite3_stmt *selectStmt;
	sqlite3_prepare(db, sql3, strlen(sql3)+1, &selectStmt, NULL);
	const unsigned char *text = sqlite3_column_text(selectStmt, 1);
	cout << text << endl;
	printf("%s\n", text);
	//cout << sqlite3_exec(db, sql3, callback, 0, &zErrMsg);

	sqlite3_close(db);
	return 0;
}