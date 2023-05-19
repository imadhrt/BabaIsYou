#ifndef CHOOSELEVEL_H
#define CHOOSELEVEL_H

#include <QWidget>

namespace Ui {
class ChooseLevel;
}

class ChooseLevel : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseLevel(QWidget *parent = nullptr);
    ~ChooseLevel();

private slots :
    void addRadioButtons();
    void exitClicked();
    void continueClicked();

private:
    Ui::ChooseLevel *ui;
    QString level;
    std::vector<std::string> listLevel;
    std::vector<std::string> listLevelSaved;
};




#endif // CHOOSELEVEL_H
