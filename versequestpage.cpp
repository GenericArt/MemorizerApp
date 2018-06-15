#include "versequestpage.h"
#include "ui_versequestpage.h"

#include <fstream>
#include <QDebug>
#include <iostream>
#include <memory>

#include <experimental/filesystem>
#include <string>
#include <limits>
#include <unistd.h>

#include <nlohmann/json.hpp>
using json = nlohmann::json;



versequestpage::versequestpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::versequestpage)
{
    ui->setupUi(this);

    std::ifstream ifile("data/verseQuestQuestions.json");
    if (ifile.is_open())
    {
        qDebug() << "File is open";
        json verseData = json::parse(ifile);
        std::string word = verseData["verseDict"]["verse1"]["verseType"];
        QString convWord = QString::fromUtf8(word.c_str());

//        ui->buttonGroup_top->buttons()
        ui->pushButton_1->setText(convWord);

//        for (json::iterator it = verseData.begin(); it != verseData.end(); ++it) {
//          std::cout << it.key() << " : " << it.value() << "\n";
//        }



    }else
    {
        qDebug() << "File is NOT open";
    }


}

versequestpage::~versequestpage()
{
    delete ui;
}

void versequestpage::on_btn_skip_released()
{

    qDebug() << get_current_dir_name();

}

void versequestpage::on_btn_check_released()
{
    // firstAnswer needs check, will crash if nothing selected
    QString firstAnswer = ui->buttonGroup_top->checkedButton()->text();
    qDebug() << firstAnswer;
}

