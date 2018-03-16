#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QPushButton>
#include<QCheckBox>
#include<QLabel>
#include<QLineEdit>
#include<QGridLayout>
#include<QHBoxLayout>
#include<QVBoxLayout>
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);

    ~Widget();
signals:
    void  findNext(const QString &str , Qt::CaseSensitivity cs);
    void  findPrevious(const QString &str,Qt::CaseSensitivity cs);

 private slots:
    void findClicked();
    void enabledFindButton(const QString &text);



 private:
    QLabel *tipLabel;
    QLineEdit * keywordLineEdit;
    QCheckBox  * matchCheckBox;
    QCheckBox  * backCheckBox;
    QPushButton * findButton;
    QPushButton * closeButton;
};

#endif // WIDGET_H
