#ifndef MASTERVIW_H
#define MASTERVIW_H

#include <QWidget>
#include "loginview.h"
#include "doctorview.h"
#include "patienteditview.h"
#include "patientview.h"
#include "welcomeview.h"
#include "departmentview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MasterViw; }
QT_END_NAMESPACE

class MasterViw : public QWidget
{
    Q_OBJECT

public:
    MasterViw(QWidget *parent = nullptr);
    ~MasterViw();

public:
    void goLoginView();
    void goWelcomeView();
    void goDoctorView();
    void goDepartmentView();
    void goPatientEditView(int rowNo);
    void goPatientView();
    void goPreviousView();

private slots:
    void on_btBack_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_btLogout_clicked();

private:

    void pushWidgetToStackView(QWidget *widget);

    Ui::MasterViw *ui;

    LoginView *loginView;
    DoctorView *doctorView;
    PatientEditView *patientEditView;
    PatientView *patientView;
    WelcomeView *welcomeView;
    DepartmentView *departmentView;
};
#endif // MASTERVIW_H
