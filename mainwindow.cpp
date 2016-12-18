#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"aboutownerwidget.h"
#include"addownerswidget.h"
#include"addcarswidget.h"
#include"aboutcarswidget.h"
#include"addmasterswidget.h"
#include"aboutmasterswidget.h"
#include"addjournalwidget.h"
#include"aboutjournalwidget.h"
#include<QtWidgets>
#include<QSplitter>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    winTitle("Гараж")
{
    ui->setupUi(this);
    //QSplitter*splitter=new QSplitter(Qt::Vertical);
    createActions();
    createToolBar();
    openOwners();
    setWindowIcon(QIcon(":/images/garage.jpg"));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::createActions()
{
    ownerAction=new QAction("Посмотреть\nклиентов",this);
    connect(ownerAction,SIGNAL(triggered()),this, SLOT(openOwners()));
    carsAction=new QAction("Посмотреть\nмашины",this);
    connect(carsAction,SIGNAL(triggered()),this,SLOT(openCars()));
    mastersAction=new QAction("Посмотреть\nмехаников",this);
    connect(mastersAction,SIGNAL(triggered()),this,SLOT(openMasters()));
    journalAction=new QAction("Посмотреть\nжурнал",this);
    connect(journalAction,SIGNAL(triggered()),this,SLOT(openJournal()));
}
void MainWindow::createToolBar()
{
    toolBar=new QToolBar("toolBar",this);
    toolBar->addSeparator();
    toolBar->addAction(ownerAction);
    toolBar->addSeparator();
    toolBar->addAction(carsAction);
    toolBar->addSeparator();
    toolBar->addAction(mastersAction);
    toolBar->addSeparator();
    toolBar->addAction(journalAction);
    toolBar->addSeparator();
    addToolBar(Qt::RightToolBarArea,toolBar);
}
void MainWindow::openOwners()
{
    QGridLayout*layout=new QGridLayout;
     QWidget*widget=new QWidget;
     AddOwnerWidget*add=new AddOwnerWidget;
     AboutOwnerWidget*about=new AboutOwnerWidget;
     layout->addWidget(add,0,0);

     layout->setHorizontalSpacing(100);
     layout->addWidget(about,1,0);
     widget->setLayout(layout);
     setCentralWidget(widget);
     setWindowTitle(winTitle+" - Клиенты");
}
void MainWindow::openCars()
{
    QGridLayout*layout=new QGridLayout;
     QWidget*widget=new QWidget;
     AddCarsWidget*add=new AddCarsWidget;
     AboutCarsWidget*about=new AboutCarsWidget;
     layout->addWidget(add,0,0);

     layout->setHorizontalSpacing(100);
     layout->addWidget(about,1,0);
     widget->setLayout(layout);
     setCentralWidget(widget);
     setWindowTitle(winTitle+" - Машины");
}
void MainWindow::openMasters()
{
    QGridLayout*layout=new QGridLayout;
     QWidget*widget=new QWidget;
     AddMastersWidget*add=new AddMastersWidget;
     AboutMastersWidget*about=new AboutMastersWidget;
     layout->addWidget(add,0,0);

     layout->setHorizontalSpacing(100);
     layout->addWidget(about,1,0);
     widget->setLayout(layout);
     setCentralWidget(widget);
     setWindowTitle(winTitle+" - Механики");
}
void MainWindow::openJournal()
{
    QGridLayout*layout=new QGridLayout;
     QWidget*widget=new QWidget;
     AddJournalWidget*add=new AddJournalWidget;
     AboutJournalWidget*about=new AboutJournalWidget;
     layout->addWidget(add,0,0);

     layout->setHorizontalSpacing(100);
     layout->addWidget(about,1,0);
     widget->setLayout(layout);
     setCentralWidget(widget);
     setWindowTitle(winTitle+" - Журнал");
}
