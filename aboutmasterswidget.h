#ifndef ABOUTMASTERSWIDGET_H
#define ABOUTMASTERSWIDGET_H
#include<QFrame>
#include<QtWidgets>
#include<QObject>
QT_BEGIN_NAMESPACE
class QPushButton;
QT_END_NAMESPACE
class AboutMastersWidget:public QFrame
{
    Q_OBJECT
public:
    AboutMastersWidget(QWidget*parent=0);
private:
    QTableView *aboutMastersTable;
    QPushButton *aboutMastersButton;
    QPushButton *inComeEachMasterButton;
private slots:
    void aboutMasters();
    void inComeEachMaster();
};
#endif // ABOUTMASTERSWIDGET_H
