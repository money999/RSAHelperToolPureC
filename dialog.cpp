#include "dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    this->resize(1000,520);
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    flags |=Qt::WindowMaximizeButtonHint;
    setWindowFlags(flags);

    twDisplay = new QTabWidget();
    teT1Input = new QTextEdit();
    teT1Show = new QTextEdit();
    bgT1Radio = new QButtonGroup();
    pbT1Exe = new QPushButton();
    cbT2Hash = new QComboBox();
    cbT2Padding = new QComboBox();


    pbT1Exe->setText(tr("exec"));
    teT1Show->setReadOnly(true);
    teT1Input->setWordWrapMode(QTextOption::WrapAnywhere);//允许单词从中间断开，避免/后换行，系统认为/后是一个新单词
    teT1Show->setWordWrapMode(QTextOption::WrapAnywhere);
    teT1Input->setPlaceholderText(tr("teT1InputText"));
    cbT2Hash->addItem(tr("sha1"));
    cbT2Hash->addItem(tr("sha224"));
    cbT2Hash->addItem(tr("sha256"));
    cbT2Hash->addItem(tr("sha384"));
    cbT2Hash->addItem(tr("sha512"));
    cbT2Hash->addItem(tr("md5"));



    QVBoxLayout *tmpVLMain = NULL;
    QVBoxLayout *tmpVL = NULL;
    QHBoxLayout *tmpHL = NULL;
    QWidget *tmpWT = NULL;
    QRadioButton *tmpRB = NULL;
    QGroupBox *tmpGB = NULL;

    //**************tab1布局***************//
    tmpWT = new QWidget();
    tmpVLMain = new QVBoxLayout;

    tmpVL = new QVBoxLayout;
    tmpRB = new QRadioButton();
    tmpRB->setText(tr("privateKey"));
    tmpRB->setChecked(true);
    bgT1Radio->addButton(tmpRB, 1);
    tmpVL->addWidget(tmpRB);
    tmpRB = new QRadioButton();
    tmpRB->setText(tr("publicKey"));
    bgT1Radio->addButton(tmpRB, 2);
    tmpVL->addWidget(tmpRB);
    tmpRB = new QRadioButton();
    tmpRB->setText(tr("xmlFromat"));
    bgT1Radio->addButton(tmpRB, 3);
    tmpVL->addWidget(tmpRB);

    tmpGB = new QGroupBox();
    tmpGB->setTitle(tr("chooseInputType"));
    tmpGB->setLayout(tmpVL);

    tmpVL = new QVBoxLayout;
    tmpVL->addWidget(tmpGB);
    tmpVL->addStretch(1);//加弹簧
    QLabel *dlamP = new QLabel();
    dlamP->setPixmap(QPixmap(":/image/dlam"));
    tmpVL->addWidget(dlamP);

    tmpHL = new QHBoxLayout;
    //tmpHL->setMargin(5);
    //tmpHL->setSpacing(10);
    tmpHL->addLayout(tmpVL);
    tmpHL->addWidget(teT1Input);
    tmpHL->addWidget(teT1Show);

    tmpVLMain->addLayout(tmpHL);
    tmpVLMain->addWidget(pbT1Exe);
    tmpWT->setLayout(tmpVLMain);

    twDisplay->addTab(tmpWT, tr("transFormat"));
    //**************tab1布局***************//

    //**************tab2布局***************//
    tmpWT = new QWidget();
    tmpVLMain = new QVBoxLayout;


    //**************tab2布局***************//


    QWidget *widget2 = new QWidget();
    twDisplay->addTab(widget2, "2222sdf");

    QVBoxLayout *ddd = new QVBoxLayout(this);
    ddd->addWidget(twDisplay);

    connect(pbT1Exe, &QPushButton::clicked, this, &Dialog::execTrans);

    connect(bgT1Radio, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), this, &Dialog::bgT1Exchange);
}

Dialog::~Dialog()
{

}

void Dialog::execTrans()
{
    QByteArray tmpba = teT1Input->toPlainText().toLatin1();
    char *key = tmpba.data();
    RSA *r = NULL;
    if(bgT1Radio->checkedId() == 1){
        if(!prikeyToRSA(key, &r)){
            teT1Show->setPlainText(tr("priKeyInputErr"));
            return ;
        }
        showPrikey(r);
    }else if(bgT1Radio->checkedId() == 2){
        int err = pubkeyToRSA(key, &r);
        if(0 == err){
            if(!pubPKCS1keyToRSA(key, &r)){
                teT1Show->setPlainText(tr("pubKeyInputErr"));
                return ;
            }
        }
        showPubkey(r);
    }else{
        int flag = xmlkeyToRSA(key, &r);
        if(flag == 2){
            showPubkey(r);
        }else if(flag == 1){
            showPrikey(r);
        }else{
            teT1Show->setPlainText(tr("xmlKeyInputErr"));
            return ;
        }
    }
    if(r!=NULL){RSA_free(r);r=NULL;}
}

void Dialog::bgT1Exchange(int id)
{
        teT1Input->clear();
        teT1Show->clear();
}

void Dialog::showPubkey(RSA *r)
{
    char res[2000];
    QString show = "";
    RSAGetPub(r, res);
    show += QString(QLatin1Literal(res));
    show += "\n\n";

    RSAGetPubPKCS1(r, res);
    show += QString(QLatin1Literal(res));
    show += "\n\n";

    RSAGetPubXml(r, res);
    show += QString(QLatin1Literal(res));
    teT1Show->setPlainText(show);
}

void Dialog::showPrikey(RSA *r)
{

    char res[2000];
    QString show = "";
    RSAGetPKCS1(r, res);
    show += QString(QLatin1Literal(res));
    show += "\n\n";

    RSAGetPKCS8(r, res);
    show += QString(QLatin1Literal(res));
    show += "\n\n";

    RSAGetPriXml(r, res);
    show += QString(QLatin1Literal(res));
    show += "\n\n";

    RSAGetPub(r, res);
    show += QString(QLatin1Literal(res));
    show += "\n\n";

    RSAGetPubPKCS1(r, res);
    show += QString(QLatin1Literal(res));
    show += "\n\n";

    RSAGetPubXml(r, res);
    show += QString(QLatin1Literal(res));
    teT1Show->setPlainText(show);
}
