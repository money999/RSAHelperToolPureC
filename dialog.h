#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTabWidget>
#include <QTabBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QButtonGroup>
#include <QRadioButton>
#include <QByteArray>
#include <QLatin1String>
#include "helper.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    QTabWidget *twDisplay;
    QTextEdit *teT1Input, *teT1Show;
    QGroupBox *gbT1Input;
    QButtonGroup *bgT1Radio;
    QRadioButton *rbT1Pub, *rbT1Pri, *rbT1Xml;
    QPushButton * pbT1Exe;

    void execTrans();
    QString showPubkey();
    QString showPrikey();

};

#endif // DIALOG_H
