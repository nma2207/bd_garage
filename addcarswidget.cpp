#include"addcarswidget.h"
#include<QtWidgets>
#include<QtSql>
AddCarsWidget::AddCarsWidget(QWidget *parent):
    QFrame(parent)
{
    vinLabel=new QLabel("VIN",this);
    modelLabel=new QLabel("Модель",this);
    kLabel=new QLabel("коэффициент",this);
    countryLabel=new QLabel("Страну",this);
    idOwnerLabel=new QLabel("id хозяина",this);
    vinLine=new QLineEdit(this);
    modelLine=new QLineEdit(this);
    kLine=new QLineEdit(this);
    countryLine=new QLineEdit(this);
    idOwnerLine=new QLineEdit(this);
    addButton=new QPushButton("Добавить запись \n в базу данных",this);
    connect(addButton,SIGNAL(clicked()),this,SLOT(addToDB()));
    QGridLayout*layout=new QGridLayout;
    layout->addWidget(vinLabel,0,0);
    layout->addWidget(modelLabel,0,1);
    layout->addWidget(kLabel,0,2);
    layout->addWidget(countryLabel,0,3);
    layout->addWidget(idOwnerLabel,0,4);
    layout->addWidget(vinLine,1,0);
    layout->addWidget(modelLine,1,1);
    layout->addWidget(kLine,1,2);
    layout->addWidget(countryLine,1,3);
    layout->addWidget(idOwnerLine,1,4);
    layout->addWidget(addButton,2,4);
    setLayout(layout);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
}
void AddCarsWidget::addToDB()
{
    QSqlDatabase dbase=QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("garage.sqlite");
    if(!dbase.open())
    {
        qDebug()<<"you have problem,men";
        return;
    }
    else
    {
        QSqlQuery my_query;
        my_query.prepare("INSERT INTO cars"
                         "(VIN,model,k,country, id_owner)"
                         "VALUES(:VIN,:model,:k,:country, :id_owner);");
        my_query.bindValue(":VIN",vinLine->text());
        my_query.bindValue(":model",modelLine->text());
        my_query.bindValue(":k", kLine->text());
        my_query.bindValue(":country", countryLine->text());
        my_query.bindValue(":id_owner",idOwnerLine->text());
        bool b=my_query.exec();
        if(!b)
            qDebug()<<my_query.lastError();
    }
    dbase.removeDatabase(dbase.databaseName());
}
