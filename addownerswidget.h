#ifndef OWNERSWIDGET_H
#define OWNERSWIDGET_H
#include<QFrame>
#include<QtSql>
QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QLineEdit;
QT_END_NAMESPACE

class AddOwnerWidget:public QFrame
{
    Q_OBJECT
public:
   AddOwnerWidget(QWidget *parent=0);
   ~AddOwnerWidget();
private:
    QLabel* nameLabel;
    QLabel* telNumLabel;
    QLabel* adressLabel;
    QLabel* drLicNumLabel;
    QLineEdit* nameLine;
    QLineEdit *telNumLine;
    QLineEdit*adressLine;
    QLineEdit *drLicNumLine;
    QPushButton *addButton;

public slots:
    void addToDataBase();
};

#endif // OWNERSWIDGET_H
