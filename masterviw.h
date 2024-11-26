#ifndef MASTERVIW_H
#define MASTERVIW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MasterViw; }
QT_END_NAMESPACE

class MasterViw : public QWidget
{
    Q_OBJECT

public:
    MasterViw(QWidget *parent = nullptr);
    ~MasterViw();

private:
    Ui::MasterViw *ui;
};
#endif // MASTERVIW_H
