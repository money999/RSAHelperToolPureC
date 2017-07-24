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
#include <QCheckBox>
#include "helper.h"

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    MyDialog(QWidget *parent = 0);
    ~MyDialog();

private:
    QTabWidget *twDisplay;

    QTextEdit *teT1Input, *teT1Show, *teT2InputMsg, *teT2InputKey, *teT2Show, *teT3InputSign, *teT3InputMsg, *teT3InputKey, *teT3Show;
    QTextEdit *teT4Input, *teT4Show, *teT5ShowPri, *teT5ShowPub, *teT5InputPass;
    QButtonGroup *bgT1Radio, *bgT2Radio, *bgT4Radio;
    QPushButton *pbT1Exe, *pbT2Exe, *pbT3Exe, *pbT4Exe, *pbT5Exe;

    QCheckBox *cbT3Msg;
    QComboBox *cbT2Hash;

protected:

    void execTrans();
    void execSign();
    void execVerify();
    void bgT1Exchange(int id);
    void cbT3MsgExchange(int id);

    void showPubkey(RSA *r);
    void showPrikey(RSA *r);

};

#endif // DIALOG_H
