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
#include <QComboBox>
#include <QLabel>
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
    QButtonGroup *bgT1Radio;
    QPushButton *pbT1Exe;

    QComboBox *cbT2Hash, *cbT2Padding;

    void execTrans();
    void bgT1Exchange(int id);

    void showPubkey(RSA *r);
    void showPrikey(RSA *r);

};

#endif // DIALOG_H
