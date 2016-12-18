#ifndef ABOUTCARS_H
#define ABOUTCARS_H
#include<QFrame>
#include<QtWidgets>
#include<QObject>
QT_BEGIN_NAMESPACE
class QPushButton;
QT_END_NAMESPACE
class AboutCarsWidget:public QFrame
{
    Q_OBJECT
public:
    AboutCarsWidget(QWidget*parent=0);
private:
    QTableView *aboutCarsTable;
    QPushButton *aboutCarsButton;
private slots:
    void aboutCars();
};
#endif // ABOUTCARS_H
