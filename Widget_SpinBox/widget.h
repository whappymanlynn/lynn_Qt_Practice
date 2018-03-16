#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QSpinBox>
#include<QSlider>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QSpinBox * spinBox;
    QSlider * slider;
};

#endif // WIDGET_H
