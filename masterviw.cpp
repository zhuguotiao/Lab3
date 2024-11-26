#include "masterviw.h"
#include "ui_masterviw.h"
#include <QDebug>
#include "idatabase.h"

MasterViw::MasterViw(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MasterViw)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);

    //初始化跳转到登录页面
    goLoginView();

    IDatabase::getInstance();

}

MasterViw::~MasterViw()
{
    delete ui;
}

void MasterViw::goLoginView()
{
    qDebug() << "跳转到登录页面";

    loginView=new LoginView(this);
    //把页面加进去
    pushWidgetToStackView(loginView);

    //等待接受登录成功的信号
    //这是新版本的
    connect(loginView, &LoginView::loginSuccess, this, &MasterViw::goWelcomeView);;
}

void MasterViw::goWelcomeView()
{
    qDebug() << "跳转到欢迎页面";

    welcomeView=new WelcomeView(this);
    pushWidgetToStackView(welcomeView);
    connect(welcomeView, &WelcomeView::goDepartmentView, this, &MasterViw::goDepartmentView);;
    connect(welcomeView, &WelcomeView::goDoctorView, this, &MasterViw::goDoctorView);;
    connect(welcomeView, &WelcomeView::goPatientView, this, &MasterViw::goPatientView);;

}

void MasterViw::goDoctorView()
{
    qDebug() << "跳转到医生页面";

    doctorView=new DoctorView(this);
    pushWidgetToStackView(doctorView);
}

void MasterViw::goDepartmentView()
{
    qDebug() << "跳转到部门页面";

    departmentView=new DepartmentView(this);
    pushWidgetToStackView(departmentView);
}

void MasterViw::goPatientEditView()
{
    qDebug() << "跳转到患者编辑页面";

    patientEditView=new PatientEditView(this);
    pushWidgetToStackView(patientEditView);
}

void MasterViw::goPatientView()
{
    qDebug() << "跳转到患者页面";

    patientView=new PatientView(this);
    pushWidgetToStackView(patientView);;
    connect(patientView, &PatientView::goPatientEditView, this, &MasterViw::goPatientEditView);;

}

void MasterViw::goPreviousView()
{
    qDebug() << "跳转到前一个";
    int count=ui->stackedWidget->count();

    if(count>1){
        ui->stackedWidget->setCurrentIndex(count-2);
        ui->labelTitle->setText(ui->stackedWidget->currentWidget()->windowTitle());

        //获取当前的页面如何把他删掉
        QWidget *widget=ui->stackedWidget->widget(count-1);
        ui->stackedWidget->removeWidget(widget);
        delete widget;
    }

}

void MasterViw::pushWidgetToStackView(QWidget *widget)
{
    //把页面加进去
    ui->stackedWidget->addWidget(widget);
    //显示最新的页面
    int count=ui->stackedWidget->count();
    ui->stackedWidget->setCurrentIndex(count-1);
    ui->labelTitle->setText(widget->windowTitle());
}


void MasterViw::on_btBack_clicked()
{
    goPreviousView();
}


void MasterViw::on_stackedWidget_currentChanged(int arg1)
{
    int count=ui->stackedWidget->count();
    if(count>1)
        ui->btBack->setEnabled(true);
    else
        ui->btBack->setEnabled(false);

    QString title=ui->stackedWidget->currentWidget()->windowTitle();

    if(title=="欢迎"){
        ui->btLogout->setEnabled(true);
        ui->btBack->setEnabled(false);
    }else{
        ui->btLogout->setEnabled(false);
    }
}


void MasterViw::on_btLogout_clicked()
{
    goPreviousView();
}

