#ifndef ALGDIALOG_H
#define ALGDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QRadioButton>
#include <QAbstractButton>
#include <openssl/evp.h>

class AlgDialog : public QDialog
{
    Q_OBJECT

public:
    AlgDialog(QWidget *parent = 0);
    ~AlgDialog();

private:
    QLabel *hint, *hintOldAlg;
    QGridLayout *glAlg;
    QPushButton *pbSure, *pbCancel;
    QButtonGroup *bgRadio;

protected:
    void execSure();
    void execCancel();

signals:
    void sendAlg(int nid);

};

#endif // ALGDIALOG_H
