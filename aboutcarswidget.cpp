#include"aboutcarswidget.h"
#include<QtSql>
AboutCarsWidget::AboutCarsWidget(QWidget *parent/*=0*/):
    QFrame(parent)
{
    aboutCarsTable=new QTableView;
    aboutCarsTable->setMinimumSize(1400,600);
    aboutCarsButton=new QPushButton("Показать \n машины",this);
    connect(aboutCarsButton,SIGNAL(clicked()),this, SLOT(aboutCars()));
    QGridLayout*layout=new QGridLayout;
    layout->addWidget(aboutCarsTable,0,0);
    layout->addWidget(aboutCarsButton,0,1);

    setBackgroundRole(QPalette::Window);

    setLayout(layout);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
}
void AboutCarsWidget::aboutCars()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("garage.sqlite");
    if (!db.open()){
        qDebug()<<db.lastError();
        return;
    }
    else
    {
        QSqlQuery query("SELECT cars.id, cars.VIN, cars.model, cars.k, cars.country, Clients.name "
                        "FROM cars INNER JOIN Clients "
                        "ON cars.id_owner=Clients.idClients;");
        bool b=query.exec();
        if(!b)
        {
            qDebug()<<query.lastError();
            return;
        }else{
           QSqlQueryModel *model=new QSqlQueryModel;
            model->setQuery(query);
            aboutCarsTable->setModel(model);
        }
    }
    db.removeDatabase(db.databaseName());
}
