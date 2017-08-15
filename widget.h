#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    QLineEdit* lineEdit_reg;
    QTextEdit* textEdit_text;
    QTextEdit* textEdit_result;
    QPushButton* button_test;
    QLabel* label_reg;
    QGridLayout* gridLayout;

private slots:
    void slot_regText();
};

#endif // WIDGET_H
