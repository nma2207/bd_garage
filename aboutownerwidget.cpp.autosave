#include"aboutownerwidget.h"
#include<QtSql>
AboutOwnerWidget::AboutOwnerWidget(QWidget *parent/*=0*/):
    QFrame(parent)
{
    aboutOwnersTable=new QTableView;
    aboutOwnersTable->setMinimumSize(1400,600);
    aboutOwnersButton=new QPushButton("Показать \n клиентов",this);
    connect(aboutOwnersButton,SIGNAL(clicked()),this, SLOT(aboutOwners()));
    QGridLayout*layout=new QGridLayout;
    layout->addWidget(aboutOwnersTable,0,0);
    layout->addWidget(aboutOwnersButton,0,1);
    setBackgroundRole(QPalette::Window);
    setLayout(layout);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
}
void AboutOwnerWidget::aboutOwners(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("garage.sqlite");
    if (!db.open()){
        qDebug()<<db.lastError();
        return;
    }else{
        QSqlTableModel *model=new QSqlTableModel (0,db);
        model->setTable("Clients");
        model->select();
        aboutOwnersTable->setModel(model);
        aboutOwnersTable->show();
    }
    db.removeDatabase(db.databaseName());
}
