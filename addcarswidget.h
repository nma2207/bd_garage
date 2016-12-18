#ifndef ADDCARSWIDGET_H
#define ADDCARSWIDGET_H
#include<QFrame>
QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QLineEdit;
QT_END_NAMESPACE

class AddCarsWidget:public QFrame
{
    Q_OBJECT
public:
    AddCarsWidget(QWidget*parent=0);
private:
    QLabel *vinLabel;
    QLabel *modelLabel;
    QLabel *kLabel;
    QLabel *countryLabel;
    QLabel *idOwnerLabel;
    QLineEdit *vinLine;
    QLineEdit *modelLine;
    QLineEdit *kLine;
    QLineEdit *countryLine;
    QLineEdit *idOwnerLine;
    QPushButton* addButton;
private slots:
    void addToDB();
};

#endif // ADDCARSWIDGET_H
