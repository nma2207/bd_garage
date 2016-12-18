#include"addjournalwidget.h"
#include<QtWidgets>
#include<QtSql>

AddJournalWidget::AddJournalWidget(QWidget *parent):
    QFrame(parent)
{
    startDateLabel=new QLabel("Дата начала работ");
    endDateLabel=new QLabel("Фактическая дата\nокончания работ");
    planDateLabel=new QLabel("Планируемая дата\nокончания работ");
    carsIdLabel=new QLabel("id машины");
    servicesIdLabel=new QLabel("id работы");
    idMasterLabel=new QLabel("id механика");

    startDateLine=new QLineEdit;
    endDateLine=new QLineEdit;
    planDateLine=new QLineEdit;
    carsIdLine=new QLineEdit;
    servicesIdLine=new QLineEdit;
    idMasterLine=new QLineEdit;
    addButton=new QPushButton("Добавить запись в журнал");
    connect(addButton,SIGNAL(clicked()),this,SLOT(addToDB()));
    QGridLayout*layout=new QGridLayout;
    layout->addWidget(startDateLabel,0,0);
    layout->addWidget(endDateLabel,0,1);
    layout->addWidget(planDateLabel,0,2);
    layout->addWidget(carsIdLabel,0,3);
    layout->addWidget(servicesIdLabel,0,4);
    layout->addWidget(idMasterLabel,0,5);
    layout->addWidget(startDateLine,1,0);
    layout->addWidget(endDateLine,1,1);
    layout->addWidget(planDateLine,1,2);
    layout->addWidget(carsIdLine,1,3);
    layout->addWidget(servicesIdLine,1,4);
    layout->addWidget(idMasterLine,1,5);
    layout->addWidget(addButton,2,5);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
    setLayout(layout);
}
void AddJournalWidget::addToDB()
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
        my_query.prepare("INSERT INTO journal"
                         "(start_date, end_data,plan_data, cars_id, services_id, id_master)"
                         "VALUES(:start_date, :end_data, :plan_data, :cars_id, :services_id, :id_master);");
        my_query.bindValue(":start_date",startDateLine->text());
        my_query.bindValue(":end_data",endDateLine->text());
        my_query.bindValue(":plan_data", planDateLine->text());
        my_query.bindValue(":cars_id", carsIdLine->text());
        my_query.bindValue(":services_id",servicesIdLine->text());
        my_query.bindValue(":id_master",idMasterLine->text());
        bool b=my_query.exec();
        if(!b)
            qDebug()<<my_query.lastError();
    }
    dbase.removeDatabase(dbase.databaseName());

}
