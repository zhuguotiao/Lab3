#include "patientview.h"
#include "ui_patientview.h"
#include "idatabase.h"

PatientView::PatientView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientView)
{
    ui->setupUi(this);

    //一些个性化的设置，对表格的
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);

    IDatabase &iDatabase=IDatabase::getInstance();
    if(iDatabase.initPatientModel()){
        ui->tableView->setModel(iDatabase.patientTabModel);
        ui->tableView->setSelectionModel(iDatabase.thePatientSelection);
    }

}

PatientView::~PatientView()
{
    delete ui;
}

void PatientView::on_btAdd_clicked()
{
    emit goPatientEditView();
}

