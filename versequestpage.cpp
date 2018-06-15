#include "versequestpage.h"
#include "ui_versequestpage.h"

#include <fstream>
#include <QDebug>
#include <iostream>
#include <memory>
#include <random>
#include <algorithm>
#include <iterator>

#include <experimental/filesystem>
#include <string>
#include <limits>
#include <unistd.h>

#include <nlohmann/json.hpp>
using json = nlohmann::json;
json verseData;


versequestpage::versequestpage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::versequestpage)
{
    ui->setupUi(this);

    std::ifstream ifile("data/verseQuestQuestions.json");
    if (ifile.is_open())
    {
        qDebug() << "File is open";
        verseData = json::parse(ifile);
        std::string word = verseData["verseDict"]["verse1"]["verseType"];

        QString convWord = QString::fromUtf8(word.c_str());
        ui->pushButton_1->setText(convWord);

        versequestpage::next_question();

    }else
    {
        qDebug() << "File is NOT open";
    }


//    QList<QButtonGroup*> buttonGroups({ ui->buttonGroup_top, ui->buttonGroup_middle, ui->buttonGroup_bottom});





}

void versequestpage::next_question()
{
    std::map<std::string, std::string> verse1 = verseData["verseDict"]["verse1"];

    // Need to cause seed to change
    auto decoyWords1 = verseData["decoyWords1"][std::rand() % verseData["decoyWords1"].size()];
    std::vector<std::string> decoyWords2 = verseData["decoyWords2"][std::rand() % verseData["decoyWords1"].size()];
    std::vector<std::string> decoyWords3 = verseData["decoyWords3"][std::rand() % verseData["decoyWords1"].size()];

    std::string answer1 = verse1["answer1"];
    std::string answer2 = verse1["answer2"];
    std::string answer3 = verse1["answer3"];

    decoyWords1.push_back(answer1);
    decoyWords2.push_back(answer2);
    decoyWords3.push_back(answer3);

    decoyWords1 = versequestpage::shuffle_the_list(decoyWords1);

    ui->label_vqHead->setText(QString::fromUtf8(verse1["verseID"].c_str()));
    ui->textEdit_vqQuestion->setText(QString::fromUtf8(verse1["verseQuest"].c_str()));
    int btnNum = 0;
    for ( int i = 0; i < ui->buttonGroup_top->buttons().size(); i++)
    {
//        printf("%s - %s - %s", decoyWords2[0].c_str(), decoyWords2[1].c_str(), decoyWords2[2].c_str());
//        QString::fromUtf8(decoyWords2[i].c_str())

        // Problem with getting single button out..
//        QList<QAbstractButton*> buttonss = ui->buttonGroup_top->buttons();
//        QButtonGroup * topGroup = ui->buttonGroup_top;
//        auto button = topGroup->button(1);
//        button->setText("foo");
    }
    btnNum = 0;
    foreach(QAbstractButton *button, ui->buttonGroup_middle->buttons())
    {
        button->setText(QString::fromUtf8(decoyWords2[btnNum].c_str()));
        btnNum += 1;
    }
    btnNum = 0;
    foreach(QAbstractButton *button, ui->buttonGroup_bottom->buttons())
    {
        button->setText(QString::fromUtf8(decoyWords3[btnNum].c_str()));
        btnNum += 1;
    }
}

std::vector<std::string> versequestpage::shuffle_the_list(std::vector<std::string> theList)
{


    return theList;
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

