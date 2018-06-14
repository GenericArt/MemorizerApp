#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
//#include <versequestpage.h>
#include "versequestpage.h"
versequestpage * page_verseQuest;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    page_verseQuest = new versequestpage;
    ui->stackedWidget->addWidget(page_verseQuest);

    QPushButton *quitButton = page_verseQuest->findChild<QPushButton*>("btn_quit");
    connect(quitButton, SIGNAL(clicked()), this, SLOT(go_home()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_verseQuest_released()
{
//    qDebug() << "Wooo";
    ui->stackedWidget->setCurrentWidget(page_verseQuest);
}

void MainWindow::go_home()
{
//    qDebug() << "Going Home";
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btn_quizQuestions_released()
{
    ui->stackedWidget->setCurrentWidget(ui->page_quizQuestions);
}

void MainWindow::on_btn_moodBooster_released()
{
    ui->stackedWidget->setCurrentWidget(ui->page_moodBooster);
}

