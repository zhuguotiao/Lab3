#ifndef PATIENTVIEW_H
#define PATIENTVIEW_H

#include <QWidget>
#include <QDataWidgetMapper>

namespace Ui {
class PatientView;
}

class PatientView : public QWidget
{
    Q_OBJECT

public:
    explicit PatientView(QWidget *parent = nullptr);
    ~PatientView();

private slots:
    void on_btAdd_clicked();

signals:
    void goPatientEditView();

private:
    Ui::PatientView *ui;

    QDataWidgetMapper *dataMapper;
};

#endif // PATIENTVIEW_H
