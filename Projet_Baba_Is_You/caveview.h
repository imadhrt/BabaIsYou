#ifndef CAVEVIEW_H
#define CAVEVIEW_H

#include "headerFile/model/babaisyou.h"
#include "qgridlayout.h"
#include <QWidget>

namespace Ui {
class CaveView;
}

class CaveView : public QWidget
{
    Q_OBJECT

public:
    explicit CaveView(int levelNumber, QWidget *parent = nullptr);
    ~CaveView();

private:
    Ui::CaveView *ui;
    BabaIsYou babaIsYou;
    int levelNumber;
    QGridLayout *gridLayout;
};

#endif // CAVEVIEW_H
