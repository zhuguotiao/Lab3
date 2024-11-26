#include "masterviw.h"
#include "ui_masterviw.h"

MasterViw::MasterViw(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MasterViw)
{
    ui->setupUi(this);
}

MasterViw::~MasterViw()
{
    delete ui;
}

