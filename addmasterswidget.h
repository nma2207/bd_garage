#ifndef ADDMASTERS_H
#define ADDMASTERS_H
#include<QFrame>
QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QLineEdit;
QT_END_NAMESPACE

class AddMastersWidget:public QFrame
{
    Q_OBJECT
public:
    AddMastersWidget(QWidget*parent=0);
private:
    QLabel *nameLabel;
    QLabel *categoryLabel;
    QLabel *telNumLabel;
    QLabel *certificateLabel;
    QLabel *specialityLabel;
    QLineEdit *nameLine;
    QLineEdit *categoryLine;
    QLineEdit *telNumLine;
    QLineEdit *certificateLine;
    QLineEdit *specialityLine;
    QPushButton* addButton;
private slots:
    void addToDB();
};

#endif // ADDMASTERS_H
