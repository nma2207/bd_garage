#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
QT_BEGIN_NAMESPACE
class QToolBar;
class QAction;
QT_END_NAMESPACE
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString winTitle;
    QToolBar *toolBar;
    QAction *ownerAction;
    QAction *carsAction;
    QAction *mastersAction;
    QAction *journalAction;
    void createActions();
    void createToolBar();
private slots:
    void openOwners();
    void openCars();
    void openMasters();
    void openJournal();
};

#endif // MAINWINDOW_H
