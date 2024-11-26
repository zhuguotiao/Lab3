#include "idatabase.h"


void IDatabase::initDatabase()
{
    //加载数据库驱动
    database=QSqlDatabase::addDatabase("QSQLITE");
    QString aFile="‪../../../../../../Lab4a.db";
    database.setDatabaseName(aFile);

    if(!database.open()){
        qDebug()<<"failed to open database";
     }else{
        qDebug()<<"open database successfully";
    }

    // 验证数据库是否正确
            // QSqlQuery query(database);
            // if (query.exec("SELECT name FROM sqlite_master WHERE type='table'")) {
            //     while (query.next()) {
            //         qDebug() << "Found table:" << query.value(0).toString();
            //     }
            // } else {
            //     qDebug() << "Failed to execute query:" << query.lastError().text();
            // }


}

IDatabase::IDatabase(QObject *parent)
    : QObject{parent}
{
    initDatabase();
}
