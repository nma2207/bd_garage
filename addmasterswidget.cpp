#include"addmasterswidget.h"
#include<QtWidgets>
#include<QtSql>
AddMastersWidget::AddMastersWidget(QWidget *parent):
    QFrame(parent)
{
    nameLabel=new QLabel("Имя",this);
    categoryLabel=new QLabel("Разряд",this);
    telNumLabel=new QLabel("Номер телефона",this);
    certificateLabel=new QLabel("Номер удостоверения",this);
    specialityLabel=new QLabel("Специальность",this);
    nameLine=new QLineEdit(this);
    categoryLine=new QLineEdit(this);
    telNumLine=new QLineEdit(this);
    certificateLine=new QLineEdit(this);
    specialityLine=new QLineEdit(this);
    addButton=new QPushButton("Добавить механика \n в базу данных",this);
    connect(addButton,SIGNAL(clicked()),this,SLOT(addToDB()));
    QGridLayout*layout=new QGridLayout;
    layout->addWidget(nameLabel,0,0);
    layout->addWidget(categoryLabel,0,1);
    layout->addWidget(certificateLabel,0,2);
    layout->addWidget(specialityLabel,0,3);
    layout->addWidget(telNumLabel,0,4);
    layout->addWidget(nameLine,1,0);
    layout->addWidget(categoryLine,1,1);
    layout->addWidget(certificateLine,1,2);
    layout->addWidget(specialityLine,1,3);
    layout->addWidget(telNumLine,1,4);
    layout->addWidget(addButton,2,4);
    setLayout(layout);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
}
void AddMastersWidget::addToDB()
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
        my_query.prepare("INSERT INTO Masters"
                         "(name,category,tel_num,certificate, speciality)"
                         "VALUES(:name,:category,:tel_num,:certificate,:speciality);");
        my_query.bindValue(":name",nameLine->text());
        my_query.bindValue(":category",categoryLine->text());
        my_query.bindValue(":tel_num", telNumLine->text());
        my_query.bindValue(":certificate", certificateLine->text());
        my_query.bindValue(":speciality",specialityLine->text());
        //qDebug()<<my_query.lastQuery();
        bool b=my_query.exec();
        if(!b)
            qDebug()<<my_query.lastError();
    }
    dbase.removeDatabase(dbase.databaseName());


}
