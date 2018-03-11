#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    CreateGroupBox();
    CreateHortiGroupBox();
    QVBoxLayout * mainlayout  =new QVBoxLayout;
    mainlayout->addWidget(groupbox);
    mainlayout->addWidget(HortiButtonBox);
    setLayout(mainlayout);
}

Widget::~Widget()
{

}
void Widget::CreateGroupBox()
{
    groupbox = new QGroupBox;
    QGridLayout * layout = new QGridLayout;

    for(int i =0 ; i < Label_Count; ++i)
    {
        label[i] = new QLabel(labelname[i]);
        layout->addWidget(label[i],i,0);
        lineEidt[i] = new QLineEdit;
        layout->addWidget(lineEidt[i],i,1);
        label[i]->setBuddy(lineEidt[i]);
    }
    groupbox->setLayout(layout);
    groupbox->setTitle(tr("GridLayout"));
}

void Widget::CreateHortiGroupBox()
{
    HortiButtonBox = new QGroupBox;
    QHBoxLayout * layout = new QHBoxLayout;
    for(int i = 0 ; i < Label_Count; ++i)
    {
       buttongroup[i]= new QPushButton(buttonName[i]);
       layout->addWidget(buttongroup[i]);
    }
    HortiButtonBox->setLayout(layout);
    HortiButtonBox->setTitle(tr("Horizontal layout"));
}
