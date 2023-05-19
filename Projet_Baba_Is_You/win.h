#ifndef WIN_H
#define WIN_H

#include <QWidget>

namespace Ui {
class Win;
}

class Win : public QWidget
{
    Q_OBJECT

public:
    explicit Win(QWidget *parent = nullptr);
    ~Win();


private slots:
    void exitClicked();

    void chooseClicked();
private:
    Ui::Win *ui;
    void resizeEvent(QResizeEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override ;
    void setBackground(const QString& imagePath);
};

#endif // WIN_H
