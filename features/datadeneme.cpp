#include <sqlite3.h>
#include <stdio.h>

double* dataCommand(const char* command){
    double* q=new double[4];
    sqlite3 *db;
    sqlite3_stmt *res;
    int rc = sqlite3_open("memory", &db);
    rc = sqlite3_prepare_v2(db,command , -1, &res, 0);
    rc = sqlite3_step(res);

    if (rc == SQLITE_ROW) {
        for(int i=1;i<5;i++)
            q[i-1]= sqlite3_column_double(res, i);
    }

    sqlite3_finalize(res);
    sqlite3_close(db);
    return q;
}


int main(void) {

    char in[1000];
    while(1){
        scanf("%[^\n]%*c",in);
        dataCommand(in);
    }
    return 0;
}