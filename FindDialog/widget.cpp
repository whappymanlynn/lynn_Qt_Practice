#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *leftlayout = new QVBoxLayout;

    QHBoxLayout * left_top_layout = new QHBoxLayout;
    tipLabel = new QLabel(tr("&Find what:"));
    keywordLineEdit = new QLineEdit;
    tipLabel->setBuddy(keywordLineEdit);

    matchCheckBox =new QCheckBox(tr("&Match case"));
    backCheckBox = new QCheckBox(tr("search backword"));


    left_top_layout->addWidget(tipLabel);
    left_top_layout->addWidget(keywordLineEdit);

    leftlayout->addLayout(left_top_layout);
    leftlayout->addWidget(matchCheckBox);
    leftlayout->addWidget(backCheckBox);


    QVBoxLayout * rightlayout = new QVBoxLayout;


    findButton = new QPushButton(tr("&find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("&Close"));
    rightlayout->addWidget(findButton);
    rightlayout->addWidget(closeButton);
    rightlayout->addStretch();


    QHBoxLayout * mainlayout = new QHBoxLayout;
    mainlayout->addLayout(leftlayout);
    mainlayout->addLayout(rightlayout);
    setLayout(mainlayout);

    setWindowTitle(tr("find file"));
    setFixedHeight(sizeHint().height());
    connect(keywordLineEdit,SIGNAL(textChanged(const QString&)),
            this,SLOT(enabledFindButton(const QString &)));
    connect(findButton,SIGNAL(clicked()),
            this,SLOT(findClicked()));
    connect(closeButton,SIGNAL(clicked()),
            this,SLOT(close()));





}

Widget::~Widget()
{

}
void Widget::findClicked()
{
    QString text = keywordLineEdit->text();
    Qt::CaseSensitivity cs = matchCheckBox->isCheckable()?Qt::CaseSensitive:
                                                           Qt::CaseInsensitive;
    if(backCheckBox->isCheckable()){
        emit findPrevious(text,cs);
    }
    else
    {
        emit findNext(text,cs);
    }

}

void Widget::enabledFindButton(const QString &text)
{
    findButton->setEnabled(!text.isEmpty());
}
