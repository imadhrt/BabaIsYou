/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *exitButton;
    QPushButton *continueButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(555, 569);
        label = new QLabel(Form);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 30, 231, 71));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(true);
        label->setFont(font);
        scrollArea = new QScrollArea(Form);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(100, 100, 311, 371));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 309, 369));
        scrollAreaWidgetContents->setCursor(QCursor(Qt::CrossCursor));
        verticalLayoutWidget = new QWidget(scrollAreaWidgetContents);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 10, 251, 331));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);
        horizontalLayoutWidget = new QWidget(Form);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(59, 480, 441, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        exitButton = new QPushButton(horizontalLayoutWidget);
        exitButton->setObjectName("exitButton");

        horizontalLayout->addWidget(exitButton);

        continueButton = new QPushButton(horizontalLayoutWidget);
        continueButton->setObjectName("continueButton");
        QFont font1;
        font1.setUnderline(false);
        continueButton->setFont(font1);
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("accessories-calculator")));
        continueButton->setIcon(icon);
        continueButton->setAutoDefault(false);
        continueButton->setFlat(false);

        horizontalLayout->addWidget(continueButton);


        retranslateUi(Form);

        continueButton->setDefault(true);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form", "choisis ton level !! ", nullptr));
        exitButton->setText(QCoreApplication::translate("Form", "Exit", nullptr));
        continueButton->setText(QCoreApplication::translate("Form", "Continue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
