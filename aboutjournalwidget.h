#ifndef ABOUTJOURNALWIDGET_H
#define ABOUTJOURNALWIDGET_H
#include<QFrame>
#include<QtWidgets>
#include<QObject>
QT_BEGIN_NAMESPACE
class QPushButton;
class QLineEdit;
QT_END_NAMESPACE
class AboutJournalWidget:public QFrame
{
    Q_OBJECT
public:
    AboutJournalWidget(QWidget*parent=0);
private:
    QTableView *aboutJournalTable;
    QPushButton *aboutJournalButton;
    QPushButton *morePriceButton;
    QLineEdit *morePriceLine;
    QPushButton *notFreshRemBut;

private slots:
    void morePrice();
    void aboutJournal();
    void showNotFreshRem();
};
#endif // ABOUTJOURNALWIDGET_H
