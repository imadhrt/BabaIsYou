#include "chooselevel.h"
#include "ui_chooselevel.h"
#include "caveview.h"
#include <QMessageBox>
#include <QRadioButton>

ChooseLevel::ChooseLevel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChooseLevel),
    listLevel(listLvl()),
    listLevelSaved(listLvlSaved())
{
    ui->setupUi(this);

    connect(ui->continueButton, &QPushButton::clicked, this, &ChooseLevel::continueClicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &ChooseLevel::exitClicked);
    addRadioButtons();
}

ChooseLevel::~ChooseLevel()
{
    delete ui;
}

void ChooseLevel::addRadioButtons()
{
    for (int i = 0; i < listLevel.size(); ++i) {
        QRadioButton *radioButton = new QRadioButton(QString::fromStdString(listLevel.at(i)), this);

        QFont font("Arial", 10);
        radioButton->setFont(font);
        ui->verticalLayout->addWidget(radioButton);

    }

    for (int i = 0; i < listLevelSaved.size(); ++i) {
        QRadioButton *radioButtonSaved = new QRadioButton(QString::fromStdString(listLevelSaved.at(i)), this);

        QFont font("Arial", 10);
        radioButtonSaved->setFont(font);
        ui->verticalLayout_2->addWidget(radioButtonSaved);

    }
}

void ChooseLevel::continueClicked()
{
    QList<QRadioButton*> allRadios = findChildren<QRadioButton*>();


    bool radioChecked = false;
    bool isSavedLevel = false;

    for (QRadioButton *radio : allRadios) {
        if (radio->isChecked()) {
            radioChecked = true;
            level = radio->text();

            if (std::find(listLevel.begin(), listLevel.end(), level.toStdString()) != listLevel.end()) {
                isSavedLevel = false;
            } else if (std::find(listLevelSaved.begin(), listLevelSaved.end(), level.toStdString()) != listLevelSaved.end()) {
                isSavedLevel = true;
            }

            break;
        }
    }

    if (!radioChecked) {
        QMessageBox::critical(this, tr("Erreur"), tr("Aucun niveau n'est sélectionnée !"));
    }else{
        std::string lvl = level.toStdString();
        size_t startIndex = lvl.find_first_of("0123456789");
        size_t endIndex = lvl.find_last_of("0123456789");

        // Extraire la sous-chaîne contenant uniquement le nombre
        std::string numberStr = lvl.substr(startIndex, endIndex - startIndex + 1);

        int intLevel = std::stoi(numberStr);
        std::cout << numberStr << std::endl;
        close();


        LevelLoader levelLoader(intLevel, isSavedLevel);
        Board board(levelLoader);
        BabaIsYou babaIsYou(&board);

        CaveView *g = new CaveView(intLevel,babaIsYou);
        g->show();
    }

}


void ChooseLevel::exitClicked(){
    QApplication::quit();
}
