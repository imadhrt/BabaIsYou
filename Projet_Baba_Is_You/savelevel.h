#ifndef SAVELEVEL_H
#define SAVELEVEL_H

#include <QWidget>
#include "headerFile/model/babaisyou.h"

namespace Ui {
class SaveLevel;
}

class SaveLevel : public QWidget
{
    Q_OBJECT

public:
    explicit SaveLevel(BabaIsYou babaIsYou, QWidget *parent = nullptr);
    ~SaveLevel();

private:
    Ui::SaveLevel *ui;
    BabaIsYou babaIsYou;

private slots:
    void on_saveButton_clicked();
};

#endif // SAVELEVEL_H
