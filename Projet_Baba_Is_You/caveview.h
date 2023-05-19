#ifndef CAVEVIEW_H
#define CAVEVIEW_H

#include "headerFile/model/babaisyou.h"
#include "qgridlayout.h"
#include <QWidget>
#include <QString>
namespace Ui {
class CaveView;
}

class CaveView : public QWidget
{
    Q_OBJECT

public:
    explicit CaveView(int levelNumber, BabaIsYou babaIsYou, QWidget *parent = nullptr);
    ~CaveView();
    void initMenu();
    void displayBoard();
    QString toPicsIcon(Icon icon);
    QString toPicsSubject(SubjectEnum subjet);
    QString toPicsOperator(OperatorEnum operatorEnum);
    QString toPicsComplement(ComplementEnum complementEnum);

private:
    Ui::CaveView *ui;
    BabaIsYou babaIsYou;
    int levelNumber;
    QGridLayout *gridLayout;

private slots:
    void saveGame();
    void replay();
    void exit();
    void chooselevel();
    void helpCommand();
    void keyPressEvent(QKeyEvent *event) override;

};



#endif // CAVEVIEW_H
