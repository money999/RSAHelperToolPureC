#ifndef ALGDIALOG_H
#define ALGDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

class AlgDialog : public QDialog
{
    Q_OBJECT

public:
    AlgDialog(QWidget *parent = 0);
    ~AlgDialog();

private:
    QLabel *hint;
    QGridLayout *glAlg;
    QPushButton *pbSure, *pbCancel;
};

#endif // ALGDIALOG_H
