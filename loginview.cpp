#include "loginview.h"
#include "ui_loginview.h"
#include "QDebug"

LoginView::LoginView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginView)
{
    ui->setupUi(this);
}

LoginView::~LoginView()
{
    delete ui;
}

void LoginView::on_btSignIn_clicked()
{
    emit loginSuccess();
    qDebug()<<"发送信号成功";
}

