#include "widget.h"
#include<QVBoxLayout>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout * mainlayout = new QHBoxLayout;
     spinBox = new QSpinBox;
     slider  = new QSlider(Qt::Horizontal);
     spinBox->setRange(0,100);
     slider->setRange(0,100);
     mainlayout->addWidget(spinBox);
     mainlayout->addWidget(slider);

    connect(spinBox,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
    connect(slider,SIGNAL(valueChanged(int)),spinBox,SLOT(setValue(int)));
     spinBox->setValue(50);
     setLayout(mainlayout);

     setWindowTitle(tr("Please do Test"));
}

Widget::~Widget()
{

}
