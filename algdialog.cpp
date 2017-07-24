#include "algdialog.h"

AlgDialog::AlgDialog(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout *mainVL = new QVBoxLayout(this);
    hint = new QLabel();
    glAlg = new QGridLayout();
    pbSure = new QPushButton();
    pbCancel = new QPushButton();


    hint->setText(tr("chooseCryptoAlgorithm"));
    pbSure->setText(tr("sure"));
    pbCancel->setText(tr("cancel"));


    QHBoxLayout *tmpHL;

    mainVL->addWidget(hint);
    mainVL->addLayout(glAlg);
    tmpHL = new QHBoxLayout;
    tmpHL->addWidget(pbSure);
    tmpHL->addWidget(pbCancel);
    mainVL->addLayout(tmpHL);
}

AlgDialog::~AlgDialog()
{

}
