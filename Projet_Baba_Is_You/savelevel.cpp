#include "savelevel.h"
#include "ui_savelevel.h"
#include <QLineEdit>
#include <QMessageBox>
#include <QRegularExpression>
#include <QString>
#include <QRegularExpressionValidator>
#include <QDir>

SaveLevel::SaveLevel(BabaIsYou babaIsYou, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SaveLevel),
    babaIsYou(babaIsYou)
{
    ui->setupUi(this);
}

SaveLevel::~SaveLevel()
{
    delete ui;
}

void SaveLevel::on_saveButton_clicked(){
    QLineEdit *lineEdit = this->findChild<QLineEdit*>("lineEdit");
    QString text;

        text = lineEdit->text().trimmed();

        QRegularExpression regex("\\d+");
        QRegularExpressionValidator validator(regex, lineEdit);

        int pos = 0;
        QValidator::State state = validator.validate(text, pos);

        if (state == QValidator::Acceptable) {
            int number = text.toInt();
            babaIsYou.saveLevel(number);

            QString filePath = "levelSaved/numer.txt"; // Chemin du fichier sauvegardé
            QString message = "Le fichier " + QString::number(number) + ".txt a été sauvegardé dans le répertoire LevelSaved";
            QMessageBox::information(this, "Sauvegarde réussie", message);
            close();
            //afficher les niveaux pour jouer


        } else {
            QMessageBox::warning(this, "Erreur", "Veuillez saisir un nombre valide.");
            lineEdit->clear();
            lineEdit->setFocus();
        }



    //afficher le page avec choisir le niveau
}
