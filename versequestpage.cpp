#include "versequestpage.h"
#include "ui_versequestpage.h"

#include "mainwindow.h"
#include <QDebug>



versequestpage::versequestpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::versequestpage)
{
    ui->setupUi(this);



}

versequestpage::~versequestpage()
{
    delete ui;
}

void versequestpage::on_btn_skip_released()
{

}

void versequestpage::on_btn_check_released()
{
    // firstAnswer needs check, will crash if nothing selected
    QString firstAnswer = ui->buttonGroup_top->checkedButton()->text();
    qDebug() << firstAnswer;
}

//void versequestpage::on_btn_quit_released()
//{

//}
