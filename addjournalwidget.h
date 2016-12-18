#ifndef ADDJOURNALWIDGET_H
#define ADDJOURNALWIDGET_H
#include<QFrame>
QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QLineEdit;
QT_END_NAMESPACE

class AddJournalWidget:public QFrame
{
    Q_OBJECT
public:
    AddJournalWidget(QWidget*parent=0);
    QLabel *startDateLabel;
    QLabel *endDateLabel;
    QLabel *planDateLabel;
    QLabel *carsIdLabel;
    QLabel *servicesIdLabel;
    QLabel *idMasterLabel;
    QLineEdit *startDateLine;
    QLineEdit *endDateLine;
    QLineEdit *planDateLine;
    QLineEdit *carsIdLine;
    QLineEdit *servicesIdLine;
    QLineEdit *idMasterLine;
    QPushButton* addButton;
private slots:
    void addToDB();
};

#endif // ADDJOURNALWIDGET_H
