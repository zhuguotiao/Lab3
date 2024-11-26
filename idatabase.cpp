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

bool IDatabase::initPatientModel()
{
    patientTabModel=new QSqlTableModel(this,database);
    patientTabModel->setTable("patient");
    //设置数据保存方式，按行还是按列
    patientTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //设置排序方式
    patientTabModel->setSort(patientTabModel->fieldIndex("name"),Qt::AscendingOrder);
    if(!(patientTabModel->select()))
        return false;

    thePatientSelection=new QItemSelectionModel(patientTabModel);
    return true;
}

QString IDatabase::userLogin(QString username, QString password)
{
    QSqlQuery query;
    query.prepare("select username,password from user where username= :USER");
    query.bindValue(":USER",username);
    query.exec();
    if(query.first() && query.value("username").isValid()){
        QString passwd=query.value("password").toString();
        if(passwd==password){
            qDebug()<< "loginOK";
            return "loginOK";
        }else{
            qDebug()<< "wrongPassword";
            return "loginFailed";
        }
    }else{
        qDebug()<<"no such user";
        return "loginFailed";
    }

}

IDatabase::IDatabase(QObject *parent)
    : QObject{parent}
{
    initDatabase();
}
