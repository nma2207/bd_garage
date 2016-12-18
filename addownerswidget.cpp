#include"addownerswidget.h"
#include<QtWidgets>
AddOwnerWidget::AddOwnerWidget(QWidget* parent/*=0*/):
    QFrame(parent)
{
    nameLabel=new QLabel("Имя",this);
    telNumLabel=new QLabel("Телефон",this);
    adressLabel=new QLabel("Адрес",this);
    drLicNumLabel=new QLabel("Номер ВУ",this);
    QGridLayout * layout=new QGridLayout;
    layout->addWidget(nameLabel,0,0);
    layout->addWidget(telNumLabel,0,1);
    layout->addWidget(adressLabel,0,2);
    layout->addWidget(drLicNumLabel,0,3);
//    nameLabel->show();
//    telNumLabel->show();
//    drLicNumLabel->show();
//    adressLabel->show();
    nameLine=new QLineEdit(this);
    telNumLine=new QLineEdit(this);
    adressLine=new QLineEdit(this);
    drLicNumLine=new QLineEdit(this);
    layout->addWidget(nameLine,1,0);
    layout->addWidget(telNumLine,1,1);
    layout->addWidget(adressLine,1,2);
    layout->addWidget(drLicNumLine,1,3);
//    nameLine->show();
//    telNumLin->show();
//    adressLabel->show();
//    drLicNumLine->show();
    addButton=new QPushButton("Добавить запись \n в базу данных",this);
    layout->addWidget(addButton,2,3);
    setLayout(layout);
    connect(addButton,SIGNAL(clicked()),this,SLOT(addToDataBase()));
    //setStyleSheet("border-style: outset; border-width: 2px;border-color: black;");
    //setStyleSheet("border: 2px");
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);

}
AddOwnerWidget::~AddOwnerWidget()
{
    //base.close();
}

void AddOwnerWidget::addToDataBase()
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
        my_query.prepare("INSERT INTO clients"
                         "(name,tel_number,adress,dr_lic_num)"
                         "VALUES(:name, :tel_number,:adress, :dr_lic_num);");
        my_query.bindValue(":name",nameLine->text());
        my_query.bindValue(":tel_number",telNumLine->text());
        my_query.bindValue(":adress", adressLine->text());
        my_query.bindValue(":dr_lic_num", drLicNumLine->text());
        bool b=my_query.exec();
        if(!b)
            qDebug()<<my_query.lastError();
    }
    dbase.removeDatabase(dbase.databaseName());
}
