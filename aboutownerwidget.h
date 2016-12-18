#ifndef ABOUTOWNERWIDGET_H
#define ABOUTOWNERWIDGET_H
#include<QFrame>
#include<QtWidgets>
#include<QObject>
QT_BEGIN_NAMESPACE
class QPushButton;
QT_END_NAMESPACE
class AboutOwnerWidget:public QFrame
{
    Q_OBJECT
public:
    AboutOwnerWidget(QWidget*parent=0);
private:
    QTableView *aboutOwnersTable;
    QPushButton *aboutOwnersButton;
private slots:
    void aboutOwners();
};

#endif // ABOUTOWNERWIDGET_H
