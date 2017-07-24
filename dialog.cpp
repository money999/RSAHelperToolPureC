 #include "dialog.h"
#include <QDebug>

MyDialog::MyDialog(QWidget *parent)
    : QDialog(parent)
{
    this->resize(1050,520);
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
    bgT2Radio = new QButtonGroup();
    teT2InputMsg = new QTextEdit();
    teT2InputKey = new QTextEdit();
    teT2Show = new QTextEdit();
    pbT2Exe = new QPushButton();
    teT3InputSign = new QTextEdit();
    teT3InputMsg = new QTextEdit();
    teT3InputKey = new QTextEdit();
    teT3Show = new QTextEdit();
    pbT3Exe = new QPushButton();
    cbT3Msg = new QCheckBox();
    teT4Input = new QTextEdit();
    teT4Show = new QTextEdit();
    pbT4Exe = new QPushButton();
    bgT4Radio = new QButtonGroup();
    teT5ShowPri = new QTextEdit();
    teT5ShowPub = new QTextEdit();
    teT5InputPass = new QTextEdit();
    pbT5Exe = new QPushButton();



    pbT1Exe->setText(tr("exec"));
    teT1Show->setReadOnly(true);
    teT1Input->setWordWrapMode(QTextOption::WrapAnywhere);//允许单词从中间断开，避免/后换行，系统认为/后是一个新单词
    teT1Show->setWordWrapMode(QTextOption::WrapAnywhere);
    teT1Input->setPlaceholderText(tr("teT1InputText"));
    cbT2Hash->addItem("sha1");
    cbT2Hash->addItem("sha224");
    cbT2Hash->addItem("sha256");
    cbT2Hash->addItem("sha384");
    cbT2Hash->addItem("sha512");
    cbT2Hash->addItem("md5");
    teT2Show->setReadOnly(true);
    pbT2Exe->setText(tr("exec"));
    teT2InputMsg->setPlaceholderText(tr("msgText"));
    teT2InputKey->setPlaceholderText(tr("prikeyText"));
    teT2InputMsg->setWordWrapMode(QTextOption::WrapAnywhere);
    teT2InputKey->setWordWrapMode(QTextOption::WrapAnywhere);
    teT2Show->setWordWrapMode(QTextOption::WrapAnywhere);
    teT3Show->setReadOnly(true);
    teT3InputSign->setPlaceholderText(tr("signText"));
    teT3InputKey->setPlaceholderText(tr("pubkeyText"));
    teT3InputMsg->setPlaceholderText(tr("verifyMsg"));
    teT3InputSign->setWordWrapMode(QTextOption::WrapAnywhere);
    teT3InputKey->setWordWrapMode(QTextOption::WrapAnywhere);
    teT3Show->setWordWrapMode(QTextOption::WrapAnywhere);
    pbT3Exe->setText(tr("exec"));
    cbT3Msg->setText(tr("showMsg"));
    cbT3Msg->setCheckState(Qt::Unchecked);
    teT3InputMsg->hide();
    teT4Input->setPlaceholderText(tr("deprikeyText"));
    pbT4Exe->setText(tr("exec"));
    teT5ShowPri->setReadOnly(true);
    teT5ShowPub->setReadOnly(true);
    teT5InputPass->setPlaceholderText(tr("inputPassText"));
    pbT5Exe->setText(tr("exec"));




    QVBoxLayout *tmpVLMain = NULL;
    QVBoxLayout *tmpVL = NULL;
    QHBoxLayout *tmpHL = NULL;
    QWidget *tmpWT = NULL;
    QRadioButton *tmpRB = NULL;
    QGroupBox *tmpGB = NULL;
    QLabel *dlamP = NULL, *txtLB= NULL;

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
    dlamP = new QLabel();
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

    tmpHL = new QHBoxLayout;
    tmpRB = new QRadioButton();
    tmpRB->setText(tr("noHash"));
    tmpRB->setChecked(true);
    bgT2Radio->addButton(tmpRB, 1);
    tmpHL->addWidget(tmpRB);
    tmpRB = new QRadioButton();
    tmpRB->setText(tr("Hash"));
    bgT2Radio->addButton(tmpRB, 2);
    tmpHL->addWidget(tmpRB);
    tmpGB = new QGroupBox();
    tmpGB->setTitle(tr("msgIsHash"));
    tmpGB->setLayout(tmpHL);
    tmpVL = new QVBoxLayout;
    tmpVL->addWidget(tmpGB);
    tmpVL->addWidget(cbT2Hash);
    tmpVL->addStretch(1);
    dlamP = new QLabel();
    dlamP->setPixmap(QPixmap(":/image/dlam"));
    tmpVL->addWidget(dlamP);
    tmpHL = new QHBoxLayout;
    tmpHL->addLayout(tmpVL);
    tmpVL = new QVBoxLayout;
    tmpVL->addWidget(teT2InputMsg);
    tmpVL->addWidget(teT2InputKey);
    tmpHL->addLayout(tmpVL);
    tmpHL->addWidget(teT2Show);

    tmpVLMain->addLayout(tmpHL);
    tmpVLMain->addWidget(pbT2Exe);
    tmpWT->setLayout(tmpVLMain);

    twDisplay->addTab(tmpWT, tr("sign"));
    //**************tab2布局***************//

    //**************tab3布局***************//
    tmpWT = new QWidget();
    tmpVLMain = new QVBoxLayout;

    tmpVL = new QVBoxLayout;
    //tmpVL->addStretch(1);
    tmpVL->addWidget(cbT3Msg,1, Qt::AlignCenter);
    tmpVL->addStretch(1);
    dlamP = new QLabel();
    dlamP->setPixmap(QPixmap(":/image/dlam"));
    tmpVL->addWidget(dlamP);
    tmpHL = new QHBoxLayout;
    tmpHL->addLayout(tmpVL);
    tmpVL = new QVBoxLayout;
    tmpVL->addWidget(teT3InputSign);
    tmpVL->addWidget(teT3InputKey);
    tmpHL->addLayout(tmpVL);
    tmpVL = new QVBoxLayout;
    tmpVL->addWidget(teT3InputMsg, 1);
    tmpVL->addWidget(teT3Show, 3);
    tmpHL->addLayout(tmpVL);


    tmpVLMain->addLayout(tmpHL);
    tmpVLMain->addWidget(pbT3Exe);
    tmpWT->setLayout(tmpVLMain);

    twDisplay->addTab(tmpWT, tr("verify"));
    //**************tab3布局***************//


    //**************tab4布局***************//
    tmpWT = new QWidget();
    tmpVLMain = new QVBoxLayout;

    tmpVL = new QVBoxLayout;
    tmpRB = new QRadioButton();
    tmpRB->setText(tr("decodeprikey"));
    tmpRB->setChecked(true);
    bgT4Radio->addButton(tmpRB, 1);
    tmpVL->addWidget(tmpRB);
    tmpRB = new QRadioButton();
    tmpRB->setText(tr("encodeprikey"));
    bgT4Radio->addButton(tmpRB, 2);
    tmpVL->addWidget(tmpRB);
    tmpGB = new QGroupBox();
    tmpGB->setTitle(tr("chooseProgram"));
    tmpGB->setLayout(tmpVL);
    tmpVL = new QVBoxLayout;
    tmpVL->addWidget(tmpGB);
    tmpVL->addStretch(1);
    dlamP = new QLabel();
    dlamP->setPixmap(QPixmap(":/image/dlam"));
    tmpVL->addWidget(dlamP);
    tmpHL = new QHBoxLayout;
    tmpHL->addLayout(tmpVL);
    tmpHL->addWidget(teT4Input);
    tmpHL->addWidget(teT4Show);

    tmpVLMain->addLayout(tmpHL);
    tmpVLMain->addWidget(pbT4Exe);
    tmpWT->setLayout(tmpVLMain);

    twDisplay->addTab(tmpWT, tr("prikeyEnOrDecode"));
    //**************tab4布局***************//

    //**************tab5布局***************//
    tmpWT = new QWidget();
    tmpVLMain = new QVBoxLayout;

    tmpVL = new QVBoxLayout;
    txtLB = new QLabel();
    txtLB->setText(tr("inputPass"));
    tmpVL->addWidget(txtLB, 0, Qt::AlignHCenter);
    tmpVL->addWidget(teT5InputPass);

    tmpVL->addStretch(1);
    dlamP = new QLabel();
    dlamP->setPixmap(QPixmap(":/image/dlam"));
    tmpVL->addWidget(dlamP);
    tmpHL = new QHBoxLayout;
    tmpHL->addLayout(tmpVL);
    tmpHL->addWidget(teT5ShowPri);
    tmpHL->addWidget(teT5ShowPub);

    tmpVLMain->addLayout(tmpHL);
    tmpVLMain->addWidget(pbT5Exe);
    tmpWT->setLayout(tmpVLMain);

    twDisplay->addTab(tmpWT, tr("generateRSA"));
    //**************tab5布局***************//


    QWidget *widget2 = new QWidget();
    twDisplay->addTab(widget2, "2222sdf");

    QVBoxLayout *ddd = new QVBoxLayout(this);
    ddd->addWidget(twDisplay);

    connect(pbT1Exe, &QPushButton::clicked, this, &MyDialog::execTrans);
    connect(pbT2Exe, &QPushButton::clicked, this, &MyDialog::execSign);
    connect(pbT3Exe, &QPushButton::clicked, this, &MyDialog::execVerify);

    connect(bgT1Radio, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), this, &MyDialog::bgT1Exchange);
    connect(cbT3Msg, &QCheckBox::stateChanged, this, &MyDialog::cbT3MsgExchange);
}

MyDialog::~MyDialog()
{

}

void MyDialog::execTrans()
{
    QByteArray tmpba = teT1Input->toPlainText().toLatin1();
    char *key = tmpba.data();
    RSA *r = NULL;
    if(bgT1Radio->checkedId() == 1){
        if(!prikeyToRSA(key, &r, NULL)){
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

void MyDialog::execSign()
{
    unsigned char res[400];
    QByteArray tmpbaMsg = teT2InputMsg->toPlainText().toLatin1();
    char *msg = tmpbaMsg.data();
    QByteArray tmpbaKey = teT2InputKey->toPlainText().trimmed().toLatin1();
    char *key = tmpbaKey.data();
    if(0==strlen(msg) || 0==strlen(key)){
        teT2Show->setText(tr("contentNull"));
        return ;
    }
    RSA *r = NULL;
    if(prikeyToRSA(key, &r, NULL)==0){
        teT2Show->setText(tr("priKeyInputErr"));
        return ;
    }
    int type, flag;
    switch (cbT2Hash->currentIndex()) {
    case 0:
        type = NID_sha1;
        break;
    case 1:
        type = NID_sha224;
        break;
    case 2:
        type = NID_sha256;
        break;
    case 3:
        type = NID_sha384;
        break;
    case 4:
        type = NID_sha512;
        break;
    case 5:
        type = NID_md5;
        break;
    default:
        break;
    }
    flag = 0;
    if(1 == bgT2Radio->checkedId()){
        flag = RSASignBase64(r, type, (const unsigned char*)msg, strlen(msg), res);
    }else{
        flag = RSASignHashBase64(r, type, (const unsigned char*)msg, strlen(msg), res);
    }
    if(flag){
        unsigned char resHex[300];
        int resHexLen;
        decodeBase64(res, resHex, &resHexLen);
        QString show="";
        show += tr("signBase64")+"\n";
        show += QString(QByteArray((char *)res))+"\n\n";
        show += tr("signHex")+"\n";
        show += QString(QByteArray((char *)resHex, resHexLen).toHex());
        teT2Show->setPlainText(show);
    }else{
        teT2Show->setPlainText(tr("signErr"));
    }
    if(r!=NULL){RSA_free(r); r=NULL;}
}

void MyDialog::execVerify()
{
    QByteArray tmpbaSign = teT3InputSign->toPlainText().trimmed().toLatin1();
    char *sign = tmpbaSign.data();
    QByteArray tmpbaKey = teT3InputKey->toPlainText().trimmed().toLatin1();
    char *key = tmpbaKey.data();
    QByteArray tmpbaMsg = teT3InputMsg->toPlainText().toLatin1();
    char *msg = tmpbaMsg.data();
    if(0==strlen(key) || 0==strlen(sign)){
        teT3Show->setText(tr("contentNull"));
        return ;
    }
    if(teT3InputMsg->isHidden()==false&&0==strlen(msg)){
        teT3Show->setText(tr("contentNull"));
        return ;
    }
    RSA *r = NULL;
    if(pubkeyToRSA(key, &r)==0){
        teT3Show->setText(tr("pubKeyInputErr"));
        return ;
    }
    int type, resl, flag;
    unsigned char res[500];
    flag = RSAVerifyBase64(r, (unsigned char*)sign, res, &resl, &type);
    if(flag){
        QString show="";
        show += tr("sourMsg")+"\n";
        show += QString(QByteArray((char *)res, resl))+"\n\n";
        show += tr("signAlgorithm")+"\n";
        switch (type) {
        case NID_sha1:
            show += "sha1";
            break;
        case NID_sha224:
            show += "sha224";
            break;
        case NID_sha256:
            show += "sha256";
            break;
        case NID_sha384:
            show += "sha384";
            break;
        case NID_sha512:
            show += "sha512";
            break;
        case NID_md5:
            show += "md5";
            break;
        default:
            break;
        }
        teT3Show->setPlainText(show);
    }else{
        teT3Show->setPlainText(tr("verifyErr"));
    }
    if(r!=NULL){RSA_free(r); r=NULL;}
}

void MyDialog::bgT1Exchange(int id)
{
    teT1Input->clear();
    teT1Show->clear();
}

void MyDialog::cbT3MsgExchange(int id)
{
    if(Qt::Checked == id){
        teT3InputMsg->show();
    }else{
        teT3InputMsg->hide();
    }
}

void MyDialog::showPubkey(RSA *r)
{
    char res[2000];
    QString show = "";
    RSAGetPub(r, res);
    show += QString(QLatin1String(res));
    show += "\n\n";

    RSAGetPubPKCS1(r, res);
    show += QString(QLatin1String(res));
    show += "\n\n";

    RSAGetPubXml(r, res);
    show += QString(QLatin1String(res));
    teT1Show->setPlainText(show);
}

void MyDialog::showPrikey(RSA *r)
{

    char res[2000];
    QString show = "";
    RSAGetPKCS1(r, res, NULL, NULL);
    show += QString(QLatin1String(res));
    show += "\n\n";

    RSAGetPKCS8(r, res, NULL, NULL);
    show += QString(QLatin1String(res));
    show += "\n\n";

    RSAGetPriXml(r, res);
    show += QString(QLatin1String(res));
    show += "\n\n";

    RSAGetPub(r, res);
    show += QString(QLatin1String(res));
    show += "\n\n";

    RSAGetPubPKCS1(r, res);
    show += QString(QLatin1String(res));
    show += "\n\n";

    RSAGetPubXml(r, res);
    show += QString(QLatin1String(res));
    teT1Show->setPlainText(show);
}
