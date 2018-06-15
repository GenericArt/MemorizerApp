#ifndef VERSEQUESTPAGE_H
#define VERSEQUESTPAGE_H

#include <QWidget>
//#include <vector>

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
    void next_question();

    std::vector<std::string> shuffle_the_list(std::vector<std::string> theList);


};

#endif // VERSEQUESTPAGE_H
