#include"aboutmasterswidget.h"
#include<QtSql>
AboutMastersWidget::AboutMastersWidget(QWidget *parent/*=0*/):
    QFrame(parent)
{
    aboutMastersTable=new QTableView;
    aboutMastersTable->setMinimumSize(1400,600);
    aboutMastersButton=new QPushButton("Показать\nмехаников",this);

    connect(aboutMastersButton,SIGNAL(clicked()),this, SLOT(aboutMasters()));

    inComeEachMasterButton=new QPushButton("Показать\nзаработок каждого",this);
    connect(inComeEachMasterButton,SIGNAL(clicked()),this,SLOT(inComeEachMaster()));
    QGridLayout*layout=new QGridLayout;
    layout->addWidget(aboutMastersTable,0,0,3,1);
    layout->addWidget(aboutMastersButton,0,1);
    layout->addWidget(inComeEachMasterButton,1,1);

    setLayout(layout);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
}
void AboutMastersWidget::aboutMasters()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("garage.sqlite");
    if (!db.open()){
        qDebug()<<db.lastError();
        return;
    }
    else
    {
        QSqlTableModel *model=new QSqlTableModel (0,db);
        model->setTable("Masters");  // Имя таблицы базы данных.
        model->select();
        aboutMastersTable->setModel(model);
        aboutMastersTable->show();
    }
    db.removeDatabase(db.databaseName());

}
void AboutMastersWidget::inComeEachMaster()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("garage.sqlite");
    if (!db.open()){
        qDebug()<<db.lastError();
        return;
    }
    else{
        QSqlTableModel *model=new QSqlTableModel (0,db);
        model->setTable("sum_work");//запрашиваем представление
        model->select();
        aboutMastersTable->setModel(model);
        aboutMastersTable->show();
    }
    db.removeDatabase(db.databaseName());
}
