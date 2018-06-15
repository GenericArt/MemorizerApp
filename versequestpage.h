#ifndef VERSEQUESTPAGE_H
#define VERSEQUESTPAGE_H

#include <QWidget>


namespace Ui {
class versequestpage;
}

class versequestpage : public QWidget
{
    Q_OBJECT


public:
    explicit versequestpage(QWidget *parent = 0);
    ~versequestpage();


private slots:
    void on_btn_skip_released();
    void on_btn_check_released();

private:
    Ui::versequestpage *ui;


};

#endif // VERSEQUESTPAGE_H
