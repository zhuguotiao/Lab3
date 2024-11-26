#include "welcomeview.h"
#include "ui_welcomeview.h"
#include "QDebug";

WelcomeView::WelcomeView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomeView)
{
    qDebug()<<"创建欢迎界面";
    ui->setupUi(this);
}

WelcomeView::~WelcomeView()
{
    qDebug() << "删除欢迎界面";
    delete ui;
}




void WelcomeView::on_btDepartment_clicked()
{
    emit goDepartmentView();
}


void WelcomeView::on_btDoctor_clicked()
{
    emit goDoctorView();
}


void WelcomeView::on_btPatient_clicked()
{
    emit goPatientView();
}

