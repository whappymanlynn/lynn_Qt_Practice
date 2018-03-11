#ifndef WIDGET_H
#define WIDGET_H


/*
 * author: lynn
 * data : 2018/3/10
 * descript: 使用QBoxGroup ,以及QGridLayout 和QVBoxLayout 和QHBoxLayout等布局
 */
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QString>
class Widget : public QWidget
{
 Q_OBJECT
 //设置标签数量
 enum{
     Label_Count =3
 };
 //设置标签名字
 const QString labelname[Label_Count] = {"top",
                                         "mid",
                                         "bottom"};
 const QString buttonName[Label_Count]={"left",
                                        "Center",
                                        "right"};
public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QLabel * label[Label_Count];
    QLineEdit * lineEidt[Label_Count];
    QPushButton * buttongroup[Label_Count];
    QGroupBox * groupbox;
    QGroupBox * HortiButtonBox;

private:
    void CreateGroupBox();
    void CreateHortiGroupBox();

};

#endif // WIDGET_H
