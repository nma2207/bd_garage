#include"aboutjournalwidget.h"
#include<QtSql>
AboutJournalWidget::AboutJournalWidget(QWidget *parent/*=0*/):
    QFrame(parent)
{
    aboutJournalTable=new QTableView;
    aboutJournalTable->setMinimumSize(1400,600);
    aboutJournalButton=new QPushButton("Показать\nжурнал",this);
    morePriceButton=new QPushButton("Показать работы,\nбольше заданной суммы",this);
    morePriceLine=new QLineEdit("0",this);
    notFreshRemBut=new QPushButton("Показать\nпросроченные заказы");
    connect(morePriceButton,SIGNAL(clicked()),this,SLOT(morePrice()));
    connect(aboutJournalButton,SIGNAL(clicked()),this, SLOT(aboutJournal()));
    connect(notFreshRemBut,SIGNAL(clicked()),this,SLOT(showNotFreshRem()));
    QGridLayout*layout=new QGridLayout;
    layout->addWidget(aboutJournalTable,0,0,5,1);
    layout->addWidget(aboutJournalButton,0,1);
    layout->addWidget(morePriceButton,1,1);
    layout->addWidget(morePriceLine,2,1);
    layout->addWidget(notFreshRemBut,3,1);
    setBackgroundRole(QPalette::Window);
    setLayout(layout);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
}
void AboutJournalWidget::aboutJournal(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("garage.sqlite");
    if (!db.open()){
        qDebug()<<db.lastError();
        return;
    }else{
        QSqlQuery query("SELECT journal.id, cars.model as marka , cars.country country, clients.name as clientName , services.name as remont, masters.name master_name,masters.speciality spec, cars.k*services.price price, start_date, end_data, plan_data "
                        "FROM cars INNER JOIN journal "
                        "ON cars.id=journal.cars_id "
                        "INNER JOIN services "
                        "ON services.id=journal.services_id "
                        "INNER JOIN masters "
                        "ON masters.idMasters=journal.id_master "
                        "INNER JOIN clients "
                        "ON cars.id_owner=clients.idClients "
                        "ORDER by journal.id;");
        bool b=query.exec();
        if(!b){
            qDebug()<<query.lastError();
            return;
        }else{
            QSqlQueryModel *model=new QSqlQueryModel;
            model->setQuery(query);
            aboutJournalTable->setModel(model);
        }
        aboutJournalTable->show();
    }
    db.removeDatabase(db.databaseName());
}
void AboutJournalWidget::morePrice(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("garage.sqlite");
    if (!db.open()){
        qDebug()<<db.lastError();
        return;
    }else{
        QSqlQuery query;
        query.prepare(QString("SELECT cars.model 'Модель', services.name 'Ремонт', cars.k*services.price 'Цена' "
                        "FROM cars INNER JOIN journal "
                        "ON cars.id=journal.cars_id "
                        "INNER JOIN services "
                        "ON services.id=journal.services_id "
                        "WHERE cars.k*services.price >%1;").arg(morePriceLine->text()));
        bool b=query.exec();
        if(!b){
            qDebug()<<query.lastError();
            return;
        }else{
            QSqlQueryModel *model=new QSqlQueryModel;
            model->setQuery(query);
            aboutJournalTable->setModel(model);
        }
        aboutJournalTable->show();
    }
  db.removeDatabase(db.databaseName());
}
void AboutJournalWidget::showNotFreshRem(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("garage.sqlite");
    if (!db.open()){
        qDebug()<<db.lastError();
    }
    QSqlQuery query("SELECT cars.model 'Марка',services.name 'Ремонт',start_date 'начало работы' , end_data 'реальная дата', plan_data 'Плановая дата' "
                    "FROM cars INNER JOIN journal "
                    "ON cars.id=journal.cars_id "
                    "INNER JOIN services "
                    "ON services.id=journal.services_id "
                    "WHERE end_data > plan_data;");
    bool b=query.exec();
    if(!b){
        qDebug()<<query.lastError();
        return;
    }else{
        QSqlQueryModel *model=new QSqlQueryModel;
        model->setQuery(query);
        aboutJournalTable->setModel(model);
        aboutJournalTable->show();
    }
    db.removeDatabase(db.databaseName());
}
