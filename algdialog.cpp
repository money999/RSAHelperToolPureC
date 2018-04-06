#include "algdialog.h"

AlgDialog::AlgDialog(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout *mainVL = new QVBoxLayout(this);
    hint = new QLabel();
    glAlg = new QGridLayout();
    pbSure = new QPushButton();
    pbCancel = new QPushButton();
    bgRadio = new QButtonGroup();
    hintOldAlg = new QLabel();


    hint->setText(tr("chooseCryptoAlgorithm"));
    pbSure->setText(tr("sure"));
    pbCancel->setText(tr("cancel"));
    hintOldAlg->setText(tr("oldAlg"));

    char *algList[] = {"AES-128-CBC", "AES-128-ECB", "AES-128-CFB", "AES-128-OFB","AES-192-CBC", "AES-192-ECB", "AES-192-CFB", "AES-192-OFB","AES-256-CBC", "AES-256-ECB", "AES-256-CFB", "AES-256-OFB","DES-CBC", "DES-ECB", "DES-CFB", "DES-OFB","DES-EDE-CBC", "DES-EDE", "DES-EDE-OFB", "DES-EDE-CFB","DES-EDE3-CBC", "DES-EDE3", "DES-EDE3-OFB", "DES-EDE3-CFB","DESX-CBC","RC4","RC4-40","IDEA-CBC", "IDEA-ECB", "IDEA-CFB", "IDEA-OFB","RC2-CBC", "RC2-ECB", "RC2-CFB", "RC2-OFB","RC2-40-CBC", "RC2-64-CBC","BF-CBC", "BF-ECB", "BF-CFB", "BF-OFB","CAST5-CBC", "CAST5-ECB", "CAST5-CFB", "CAST5-OFB","AES-128-OCB", "AES-192-OCB", "AES-256-OCB","id-aes128-GCM", "id-aes192-GCM", "id-aes256-GCM","id-aes128-CCM", "id-aes192-CCM", "id-aes256-CCM","ChaCha20","ChaCha20-Poly1305","RC5-32-12-16-CBC", "RC5-32-12-16-ECB", "RC5-32-12-16-CFB", "RC5-32-12-16-OFB"};
    int algGrid[] = {12,12,1,2,4,6,4,4,9,2};
    int i,j,k;
    k=0;
    QRadioButton *tmpRB;
    for(i=0;i<10;i++){
        for(j=0;j<algGrid[i];j++){
            tmpRB = new QRadioButton(QString(algList[k]));
            if(k==0){tmpRB->setChecked(true);}
            bgRadio->addButton(tmpRB, k);
            glAlg->addWidget(tmpRB, j, i);
            k++;
        }
    }

    QHBoxLayout *tmpHL;

    mainVL->addWidget(hint);
    mainVL->addLayout(glAlg);
    mainVL->addWidget(hintOldAlg);
    tmpHL = new QHBoxLayout;
    tmpHL->addWidget(pbSure);
    tmpHL->addWidget(pbCancel);
    mainVL->addLayout(tmpHL);


    connect(pbSure, &QPushButton::clicked, this, &AlgDialog::execSure);
    connect(pbCancel, &QPushButton::clicked, this, &AlgDialog::execCancel);
}

AlgDialog::~AlgDialog()
{

}

void AlgDialog::execSure()
{
    QAbstractButton *checkedButton = bgRadio->checkedButton();
    QByteArray tmpba = checkedButton->text().toLatin1();
    char *key = tmpba.data();
    const EVP_CIPHER *tmpCipher = EVP_get_cipherbyname(key);
    int nid = EVP_CIPHER_nid(tmpCipher);

    emit sendAlg(nid);

    this->close();
}

void AlgDialog::execCancel()
{
    this->close();
}
