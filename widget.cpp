#include "widget.h"
#include <QRegExp>
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    lineEdit_reg = new QLineEdit;
    textEdit_text = new QTextEdit;
    textEdit_result = new QTextEdit;
    button_test = new QPushButton("test");
    label_reg = new QLabel("Reg: ");

    gridLayout = new QGridLayout(this);


    label_reg->setFixedSize(50,30);
    label_reg->setAlignment(Qt::AlignCenter);
    lineEdit_reg->setFixedHeight(30);
    button_test->setFixedSize(100,30);

    gridLayout->setRowStretch(0,1);
    gridLayout->setRowStretch(1,0);
    gridLayout->setRowStretch(2,1);
    gridLayout->setColumnStretch(0,0);
    gridLayout->setColumnStretch(1,1);
    gridLayout->setColumnStretch(2,0);

    gridLayout->addWidget(textEdit_text,0,0,1,3);
    gridLayout->addWidget(label_reg,1,0,1,1);
    gridLayout->addWidget(lineEdit_reg,1,1,1,1);
    gridLayout->addWidget(button_test,1,2,1,1);
    gridLayout->addWidget(textEdit_result,2,0,1,3);


    textEdit_text->setToolTip("Please enter the pattern");

    lineEdit_reg->setToolTip("Please enter the pattern");
    lineEdit_reg->setPlaceholderText("enter the reg");
    textEdit_result->setReadOnly(true);
    this->resize(800,600);
    connect(button_test,SIGNAL(clicked(bool)),this,SLOT(slot_regText()));
}

Widget::~Widget()
{

}

void Widget::slot_regText()
{
    QString str_reg = lineEdit_reg->text();
    if (str_reg.isEmpty())
    {
        QMessageBox::warning(this,"Warning","please enter the pattern of the QRegExp");
        return;
    }
    str_reg.replace("\\\\","\\");

    QRegExp rx(str_reg);
    QString str = textEdit_text->toPlainText();
    if (str.isEmpty())
    {
        QMessageBox::warning(this,"Warning","Please enter the string");
        return;
    }
    QStringList list;
    int pos = 0;

    while ((pos = rx.indexIn(str, pos)) != -1) {
        list << rx.cap(1);
        pos += rx.matchedLength();
    }
    textEdit_result->clear();
    textEdit_result->append("Result:\n");
    for(int i = 0; i < list.size();++i)
    {
        textEdit_result->append(list.at(i));
    }
}
