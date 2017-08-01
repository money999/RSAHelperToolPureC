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
#include <QLineEdit>
#include <QCryptographicHash>
#include "helper.h"
#include "algdialog.h"

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    MyDialog(QWidget *parent = 0);
    ~MyDialog();

private:
    QTabWidget *twDisplay;

    QTextEdit *teT1Input, *teT1Show, *teT2InputMsg, *teT2InputKey, *teT2Show, *teT3InputSign, *teT3InputMsg, *teT3InputKey, *teT3Show;
    QTextEdit *teT4Input, *teT4Show, *teT4InputPass ,*teT5ShowPri, *teT5ShowPub, *teT5InputPass;
    QButtonGroup *bgT1Radio, *bgT2Radio, *bgT3Radio, *bgT4Radio;
    QPushButton *pbT1Exe, *pbT2Exe, *pbT3Exe, *pbT4Exe, *pbT4ChooseAlg, *pbT5Exe, *pbT5ChooseAlg;
    QLineEdit *leT5Modulus;

    QCheckBox *cbT3Msg;
    QComboBox *cbT2Hash, *cbT5Modulus, *cbT5Exponent;
    QLabel *lbT4Alg, *lbT5Alg;
    QGroupBox *gbT3Hash, *gbT4Alg, *gbT4InputPass;

    AlgDialog *dlSetAlg;

    int nidCipher;

protected:

    void execTrans();
    void execSign();
    void execVerify();
    void execDeOrEncode();
    void execGenerateRSA();
    void bgT1Exchange(int id);
    void cbT3MsgExchange(int id);
    void bgT4Exchange(int id);
    void leT5Edited(QString text);

    void chooseCryptoAlg();
    void setAlg(int nid);
    void tabChanged(int index);


    QString showPubkey(RSA *r);
    QString showPrikey(RSA *r);
    QString showCryptoPrikey(RSA *r, QString pass);

};

#endif // DIALOG_H
