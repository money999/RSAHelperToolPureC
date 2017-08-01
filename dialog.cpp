 #include "dialog.h"
#include <QDebug>

MyDialog::MyDialog(QWidget *parent)
    : QDialog(parent)
{
    this->resize(1060,520);
    this->setMinimumSize(1060, 520);
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowMinimizeButtonHint;
    flags |=Qt::WindowCloseButtonHint;
    flags |=Qt::WindowMaximizeButtonHint;
    setWindowFlags(flags);

    setWindowTitle(tr("RSATool by fzj v0.9.0 beta"));
    setWindowIcon(QIcon(":/image/lyd"));

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
    bgT3Radio = new QButtonGroup();
    gbT3Hash = new QGroupBox();
    teT4Input = new QTextEdit();
    teT4Show = new QTextEdit();
    lbT4Alg = new QLabel();
    pbT4Exe = new QPushButton();
    pbT4ChooseAlg = new QPushButton();
    teT4InputPass = new QTextEdit();
    bgT4Radio = new QButtonGroup();
    gbT4Alg = new QGroupBox();
    gbT4InputPass = new QGroupBox();
    cbT5Modulus = new QComboBox();
    cbT5Exponent = new QComboBox();
    teT5ShowPri = new QTextEdit();
    teT5ShowPub = new QTextEdit();
    teT5InputPass = new QTextEdit();
    leT5Modulus = new QLineEdit();
    pbT5Exe = new QPushButton();
    pbT5ChooseAlg = new QPushButton();
    lbT5Alg = new QLabel();

    dlSetAlg = new AlgDialog(this);



    pbT1Exe->setText(tr("exec"));
    pbT1Exe->setMinimumHeight(30);
    teT1Show->setReadOnly(true);
    teT1Input->setWordWrapMode(QTextOption::WrapAnywhere);//允许单词从中间断开，避免/后换行，系统认为/后是一个新单词
    teT1Show->setWordWrapMode(QTextOption::WrapAnywhere);
    teT1Input->setPlaceholderText(tr("teT1InputText") +"\n\n"+ tr("acceptPrikeyFormat"));
    cbT2Hash->addItem("sha1");
    cbT2Hash->addItem("sha224");
    cbT2Hash->addItem("sha256");
    cbT2Hash->addItem("sha384");
    cbT2Hash->addItem("sha512");
    cbT2Hash->addItem("md5");
    teT2Show->setReadOnly(true);
    pbT2Exe->setText(tr("exec"));
    pbT2Exe->setMinimumHeight(30);
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
    pbT3Exe->setMinimumHeight(30);
    cbT3Msg->setText(tr("showMsg"));
    cbT3Msg->setCheckState(Qt::Unchecked);
    teT3InputMsg->hide();
    gbT3Hash->setTitle(tr("msgIsHash"));
    gbT3Hash->hide();
    teT4Input->setPlaceholderText(tr("teT4InputText") + "\n\n"+ tr("encodePrikeyFormat"));
    teT4Input->setWordWrapMode(QTextOption::WrapAnywhere);
    pbT4Exe->setText(tr("exec"));
    pbT4Exe->setMinimumHeight(30);
    lbT4Alg->setText("AES-128-CBC");
    teT4InputPass->setPlaceholderText(tr("inputPassText"));
    teT4InputPass->setMaximumWidth(130);
    //teT4InputPass->setMinimumHeight(10);
    teT4Show->setReadOnly(true);
    teT4Show->setWordWrapMode(QTextOption::WrapAnywhere);
    pbT4ChooseAlg->setText(tr("chooseAlg"));
    gbT4Alg->setTitle(tr("cryptoAlg"));
    cbT5Modulus->addItem(QString("1024"));
    cbT5Modulus->addItem(QString("2048"));
    cbT5Modulus->addItem(QString("3072"));
    cbT5Modulus->addItem(QString("4096"));
    cbT5Modulus->addItem(QString("5120"));
    cbT5Modulus->addItem(QString("6144"));
    cbT5Modulus->setCurrentIndex(1);
    cbT5Exponent->addItem(QString("3"));
    cbT5Exponent->addItem(QString("17"));
    cbT5Exponent->addItem(QString("65537"));
    cbT5Exponent->setCurrentIndex(2);
    teT5ShowPri->setReadOnly(true);
    teT5ShowPub->setReadOnly(true);
    teT5ShowPri->setWordWrapMode(QTextOption::WrapAnywhere);
    teT5ShowPub->setWordWrapMode(QTextOption::WrapAnywhere);
    teT5ShowPri->setPlaceholderText(tr("teT5PriHint"));
    teT5InputPass->setPlaceholderText(tr("inputPassText"));
    teT5InputPass->setMaximumWidth(130);//////////////////////这里斟酌一下，不强制默认很大
    teT5InputPass->setMaximumHeight(1900);
    teT5InputPass->setWordWrapMode(QTextOption::WrapAnywhere);
    leT5Modulus->setPlaceholderText(tr("setBySelf"));
    //leT5Modulus->setMaximumWidth(100);
    leT5Modulus->setValidator(new QIntValidator(0, 6939));
    pbT5Exe->setText(tr("exec"));
    pbT5Exe->setMinimumHeight(30);
    pbT5ChooseAlg->setText(tr("chooseAlg"));
    lbT5Alg->setText("AES-128-CBC");

    dlSetAlg->setModal(true);
    nidCipher = 419;//AES-128-CBC




    QVBoxLayout *tmpVLMain = NULL;
    QVBoxLayout *tmpVL = NULL, *tmpVL2 = NULL;
    QHBoxLayout *tmpHL = NULL;
    QWidget *tmpWT = NULL;
    QRadioButton *tmpRB = NULL;
    QGroupBox *tmpGB = NULL;
    QLabel *dlamP = NULL, *txtLB= NULL, *tmpImage = NULL;
    QGridLayout *tmpGL = NULL;

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
    tmpVL->addWidget(cbT3Msg,1, Qt::AlignCenter);
    tmpHL = new QHBoxLayout;
    tmpRB = new QRadioButton();
    tmpRB->setText(tr("noHash"));
    tmpRB->setChecked(true);
    bgT3Radio->addButton(tmpRB, 1);
    tmpHL->addWidget(tmpRB);
    tmpRB = new QRadioButton();
    tmpRB->setText(tr("Hash"));
    bgT3Radio->addButton(tmpRB, 2);
    tmpHL->addWidget(tmpRB);
    gbT3Hash->setLayout(tmpHL);
    tmpVL->addWidget(gbT3Hash);
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
    tmpVL->addWidget(lbT4Alg, 1, Qt::AlignCenter);
    tmpVL->addWidget(pbT4ChooseAlg);
    gbT4Alg->setLayout(tmpVL);
    gbT4Alg->hide();
    tmpVL = new QVBoxLayout;
    txtLB = new QLabel();
    txtLB->setText(tr("inputPass"));
    tmpVL->addWidget(txtLB);
    tmpVL->addWidget(teT4InputPass);
    gbT4InputPass->setLayout(tmpVL);
    tmpVL = new QVBoxLayout;
    tmpVL->addWidget(tmpGB, 0);
    tmpVL->addWidget(gbT4Alg, 0);
    tmpVL->addWidget(gbT4InputPass, 1);
    //tmpVL->addStretch(1);
    dlamP = new QLabel();
    dlamP->setPixmap(QPixmap(":/image/dlam"));
    tmpVL->addWidget(dlamP, 0, Qt::AlignBottom);

    tmpHL = new QHBoxLayout;
    tmpHL->addLayout(tmpVL, 0);
    tmpHL->addWidget(teT4Input, 1);
    tmpHL->addWidget(teT4Show, 1);

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
    tmpVL->addWidget(txtLB);
    tmpVL->addWidget(teT5InputPass);
    tmpVL->addWidget(lbT5Alg);
    tmpVL->addWidget(pbT5ChooseAlg);
    tmpGB = new QGroupBox();
    tmpGB->setTitle(tr("cryptoOption"));
    tmpGB->setLayout(tmpVL);
    tmpVL = new QVBoxLayout;
    tmpVL->addWidget(tmpGB);

    //tmpVL->addStretch(1);
    dlamP = new QLabel();
    dlamP->setPixmap(QPixmap(":/image/dlam"));
    tmpVL->addWidget(dlamP);

    tmpGL = new QGridLayout;
    txtLB = new QLabel;
    txtLB->setText(tr("modulus bits"));
    //tmpHL->addWidget(txtLB);
    //tmpHL->addWidget(cbT5Modulus);
    //tmpHL->addWidget(leT5Modulus);
    tmpGL->addWidget(txtLB, 0, 0, 1, 1);
    tmpGL->addWidget(cbT5Modulus, 0, 2, 1, 1);
    tmpHL = new QHBoxLayout;
    tmpHL->addWidget(leT5Modulus);
    tmpHL->setContentsMargins(0, 0 ,3, 0);//只是为了让右边界和下面输入框对其
    tmpGL->addLayout(tmpHL, 0 ,3, 1, 1);
    //tmpHL = new QHBoxLayout;
    txtLB = new QLabel;
    txtLB->setText(tr("public exponent"));
    //tmpHL->addWidget(txtLB);
    //tmpHL->addWidget(cbT5Exponent);
    tmpGL->addWidget(txtLB, 0, 4, 1, 1);
    tmpGL->addWidget(cbT5Exponent, 0, 7, 1, 1);
    tmpGL->setColumnStretch(0,1);
    tmpGL->setColumnStretch(1,1);
    tmpGL->setColumnStretch(2,1);
    tmpGL->setColumnStretch(3,1);
    tmpGL->setColumnStretch(4,1);
    tmpGL->setColumnStretch(5,1);
    tmpGL->setColumnStretch(6,1);
    tmpGL->setColumnStretch(7,1);
    //tmpGL->setContentsMargins(0, 0, 5, 0);
    //tmpGL->addLayout(tmpHL, 0, 1, 1 ,1);
    tmpHL = new QHBoxLayout;
    tmpHL->addWidget(teT5ShowPri);
    tmpHL->addWidget(teT5ShowPub);
    tmpVL2 = new QVBoxLayout;
    tmpVL2->addLayout(tmpGL);
    tmpVL2->addLayout(tmpHL);
    tmpHL = new QHBoxLayout;
    tmpHL->addLayout(tmpVL, 0);
    tmpHL->addLayout(tmpVL2, 1);

    tmpVLMain->addLayout(tmpHL);
    tmpVLMain->addWidget(pbT5Exe);
    tmpWT->setLayout(tmpVLMain);

    twDisplay->addTab(tmpWT, tr("generateRSA"));
    //**************tab5布局***************//

    //**************tab6布局***************//
    tmpWT = new QWidget();
    tmpGL = new QGridLayout;
    tmpVL = new QVBoxLayout;
    tmpImage = new QLabel();
    tmpImage->setPixmap(QPixmap(":/image/yxy"));
    txtLB = new QLabel();
    txtLB->setText(tr("copyRight"));
    QFont ft1;
    ft1.setPointSize(20);
    txtLB->setFont(ft1);
    tmpVL->addWidget(tmpImage,0, Qt::AlignHCenter);
    tmpVL->addWidget(txtLB,0, Qt::AlignHCenter);
    tmpGL->addLayout(tmpVL, 0, 0, 1, 1, Qt::AlignVCenter);
    txtLB = new QLabel();
    txtLB->setText("谨献给在兴业数金为期近四个月的实习时光！");
    QFont ft2;
    ft2.setPointSize(20);
    ft2.setFamily("楷体");
    txtLB->setFont(ft2);
    tmpVL = new QVBoxLayout;
    tmpVL->addWidget(txtLB, 0 ,Qt::AlignHCenter);
    QString strHTML = QString("<html> \
                               <head> \
                               <style> \
                               #title{font-size:22px;font-weight:bold;} #desc{font-size:15px}\
                               #descimport{font-size:15px; color:red}\
                               #descCopyright{font-size:20px;font-style:italic;}\
                               </style> \
                               </head> \
                               <body>\
                               <font id=\"title\">%1</font> \
                               <br/> \
                               <font id=\"desc\">%2</font> \
                               <br/> \
                               <font id=\"desc\">%3</font> \
                               <br/> \
                               <font id=\"desc\">%4</font> <font id=\"descimport\">%5</font>\
                               <br/> \
                               <font id=\"desc\">%6</font> \
                               <br/> \
                               <font id=\"desc\">%7</font> \
                               <br/> \
                               <font id=\"desc\">%8</font> \
                               <br/> \
                               <font id=\"title\">%9</font> \
                               <br/> \
                               <font id=\"desc\">%10</font> \
                               <br/> \
                               <font id=\"title\">%11</font> \
                               <br/> \
                               <font id=\"desc\">%12</font> \
                               <br/> \
                               <br/> \
                               <br/> \
                               <font id=\"descCopyright\">%13</font> \
                               </body> \
                               </html>")
                              .arg("说明：")
                              .arg("1、签名和验签中涉及到的公私钥加解密算法所使用的填充方式为：RSA_PKCS1_PADDING。")
                              .arg("2、签名可以直接输入消息值（但一般都是用消息的摘要），实习时有过需要直接签名消息值")
                              .arg("的需求，故添加此功能，").arg("注意消息值的长度要小于密钥长度-11")
                              .arg("3、验签部分可以直接显示签名前的消息（若是消息值请对比ascii值，若为摘要则对比hex值）。")
                              .arg("由于提取了签名前的信息，所以可以选择是否与原消息值进行对比。")
                              .arg("4、对称加密算法列表是直接从Openssl文档中提取的，并不是都可以使用，常用算法均已测试可行。")
                              .arg("Bug：")
                              .arg("1、凡是在输入私钥的地方，若密钥不需要加密格式的请勿输入加密过的密钥，否则会有惊喜。")
                              .arg("Author：")
                              .arg("本人业余程式爱好者，喜在闲时随便写些代码，由于即将正式工作所以本程序先告一段落。")
                              .arg("本软件遵循LGPL协议，但不作为任何商业用途，仅供学习和交流。");

    txtLB = new QLabel();
    txtLB->setText(strHTML);
    tmpVL->addWidget(txtLB);
    tmpGL->addLayout(tmpVL, 0, 1, 1, 1, Qt::AlignCenter);
    tmpGL->setColumnStretch(0,1);
    tmpGL->setColumnStretch(1,3);


    tmpWT->setLayout(tmpGL);
    twDisplay->addTab(tmpWT, tr("about"));
    //**************tab6布局***************//


//    QWidget *widget2 = new QWidget();
//    twDisplay->addTab(widget2, "2222sdf");

    QVBoxLayout *ddd = new QVBoxLayout(this);
    ddd->addWidget(twDisplay);

    connect(pbT1Exe, &QPushButton::clicked, this, &MyDialog::execTrans);
    connect(pbT2Exe, &QPushButton::clicked, this, &MyDialog::execSign);
    connect(pbT3Exe, &QPushButton::clicked, this, &MyDialog::execVerify);
    connect(pbT4Exe, &QPushButton::clicked, this, &MyDialog::execDeOrEncode);
    connect(pbT5Exe, &QPushButton::clicked, this, &MyDialog::execGenerateRSA);


    connect(bgT1Radio, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), this, &MyDialog::bgT1Exchange);
    connect(bgT4Radio, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), this, &MyDialog::bgT4Exchange);
    connect(cbT3Msg, &QCheckBox::stateChanged, this, &MyDialog::cbT3MsgExchange);
    connect(dlSetAlg, &AlgDialog::sendAlg, this, &MyDialog::setAlg);
    connect(pbT4ChooseAlg, &QPushButton::clicked, this, &MyDialog::chooseCryptoAlg);
    connect(pbT5ChooseAlg, &QPushButton::clicked, this, &MyDialog::chooseCryptoAlg);
    connect(twDisplay, &QTabWidget::currentChanged, this, &MyDialog::tabChanged);
    connect(leT5Modulus, &QLineEdit::textEdited, this, &MyDialog::leT5Edited);

    OpenSSL_add_all_algorithms();
    OpenSSL_add_all_ciphers();
    OpenSSL_add_all_digests();
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
        teT1Show->setPlainText(showPrikey(r) + "\n\n\n\n\n" + showPubkey(r));
    }else if(bgT1Radio->checkedId() == 2){
        int err = pubkeyToRSA(key, &r);
        if(0 == err){
            if(!pubPKCS1keyToRSA(key, &r)){
                teT1Show->setPlainText(tr("pubKeyInputErr"));
                return ;
            }
        }
        teT1Show->setPlainText(showPubkey(r));
    }else{
        int flag = xmlkeyToRSA(key, &r);
        if(flag == 2){
            teT1Show->setPlainText(showPubkey(r));
        }else if(flag == 1){
            teT1Show->setPlainText(showPrikey(r) + "\n\n\n\n\n" + showPubkey(r));
        }else{
            teT1Show->setPlainText(tr("xmlKeyInputErr"));
            return ;
        }
    }
    if(r!=NULL){RSA_free(r);r=NULL;}
}

void MyDialog::execSign()
{
    unsigned char res[6000];
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
    qDebug()<<"sss";
    if(1 == bgT2Radio->checkedId()){
        flag = RSASignBase64(r, type, (const unsigned char*)msg, strlen(msg), res);
    }else{
        flag = RSASignHashBase64(r, type, (const unsigned char*)msg, strlen(msg), res);
    }
    qDebug()<<"kkk";
    if(flag){
        unsigned char resHex[6000];
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
    unsigned char res[6000];
    flag = RSAVerifyBase64(r, (unsigned char*)sign, res, &resl, &type);
    if(flag){
        QString resAscii = QString(QByteArray((char *)res, resl));
        QString resHex = QString(QByteArray((char *)res, resl).toHex());
        QString show="";
        show += tr("sourMsgAscii")+"\n";
        show += resAscii +"\n\n";
        show += tr("sourMsgHex")+"\n";
        show += resHex+"\n\n";
        show += tr("signAlgorithm")+"\n";
        QCryptographicHash::Algorithm hashAlg;
        switch (type) {
        case NID_sha1:
            show += "sha1";
            hashAlg = QCryptographicHash::Sha1;
            break;
        case NID_sha224:
            show += "sha224";
            hashAlg = QCryptographicHash::Sha224;
            break;
        case NID_sha256:
            show += "sha256";
            hashAlg = QCryptographicHash::Sha256;
            break;
        case NID_sha384:
            show += "sha384";
            hashAlg = QCryptographicHash::Sha384;
            break;
        case NID_sha512:
            show += "sha512";
            hashAlg = QCryptographicHash::Sha512;
            break;
        case NID_md5:
            show += "md5";
            hashAlg = QCryptographicHash::Md5;
            break;
        default:
            break;
        }
        if(cbT3Msg->isChecked()){
            show += "\n\n";
            bool flag = false;
            if(bgT3Radio->checkedId() == 1){
                QByteArray byteArray = QCryptographicHash::hash(teT3InputMsg->toPlainText().toLatin1(), hashAlg);
                show += tr("inputMsgHex")+"\n";
                show += QString(byteArray.toHex()) + "\n\n";
                if(QString(byteArray.toHex()).compare(resHex,Qt::CaseInsensitive) == 0){
                    flag = true;
                }
            }else{
                show += tr("inputMsgAscii")+"\n";
                show += teT3InputMsg->toPlainText() + "\n\n";
                if(resAscii.compare(teT3InputMsg->toPlainText()) == 0){
                    flag = true;
                }
            }
            if(flag){
                show += tr("inputMsgEqualsourMsg");
            }else{
                show += tr("inputMsgUnequalsourMsg");
            }
        }
        teT3Show->setPlainText(show);
    }else{
        teT3Show->setPlainText(tr("verifyErr"));
    }
    if(r!=NULL){RSA_free(r); r=NULL;}
}

void MyDialog::execDeOrEncode()
{
    RSA *r = NULL;
    if(bgT4Radio->checkedId() == 1){
        QByteArray tmpkey = teT4Input->toPlainText().trimmed().toLatin1();
        char *key = tmpkey.data();
        QByteArray tmppass = teT4InputPass->toPlainText().toLatin1();
        char *pass = tmppass.data();
        if(0 == strlen(key) || 0 == strlen(pass)){
            teT4Show->setPlainText(tr("contentNull"));
            return ;
        }

        if(prikeyToRSA(key, &r, pass) == 0){
            teT4Show->setPlainText(tr("passErrOrKeyErr"));
            return ;
        }
        teT4Show->setPlainText(showPrikey(r));
    }else{
        QByteArray tmpbaKey = teT4Input->toPlainText().trimmed().toLatin1();
        char *key = tmpbaKey.data();
        if(prikeyToRSA(key, &r, NULL) == 0){
            teT4Show->setPlainText(tr("priKeyInputErr"));
        }
        if(teT4InputPass->toPlainText().isEmpty()){
            teT4Show->setPlainText(tr("contentNull"));
            return ;
        }
        teT4Show->setPlainText(showCryptoPrikey(r, teT4InputPass->toPlainText()));
    }
    if(r!=NULL){RSA_free(r); r=NULL;}
}

void MyDialog::execGenerateRSA()
{
    RSA *r = NULL;
    BIGNUM *e = NULL;
    e = BN_new();
    r = RSA_new();
    int bits;
    if(cbT5Modulus->isEnabled()){
        bits = cbT5Modulus->currentText().toInt();
    }else{
        bits = leT5Modulus->text().toInt();
        if(bits<16){
            teT5ShowPub->setText(tr("bitsOutLimit"));
            return ;
        }
    }
    QByteArray tmpEx = cbT5Exponent->currentText().toLatin1();
    char *exponent = tmpEx.data();
    BN_dec2bn(&e, exponent);
    RSA_generate_key_ex(r, bits, e, NULL);
    if(teT5InputPass->toPlainText().isEmpty()){
        teT5ShowPri->setPlainText(showPrikey(r));
    }else{
        teT5ShowPri->setPlainText(showCryptoPrikey(r, teT5InputPass->toPlainText()));
    }
    teT5ShowPub->setPlainText(showPubkey(r));

    if(e!=NULL){BN_clear_free(e); e=NULL;}
    if(r!=NULL){RSA_free(r); r=NULL;}
}

void MyDialog::bgT1Exchange(int id)
{
    teT1Input->clear();
    teT1Show->clear();
    switch (id) {
    case 1:
        teT1Input->setPlaceholderText(tr("teT1InputText") +"\n\n"+ tr("acceptPrikeyFormat"));
        break;
    case 2:
        teT1Input->setPlaceholderText(tr("teT1InputText") +"\n\n"+tr("acceptPubkeyFormat"));
        break;
    case 3:
        teT1Input->setPlaceholderText(tr("teT1InputText") +"\n\n"+tr("acceptXmlkeyFormat"));
        break;
    default:
        break;
    }
}

void MyDialog::cbT3MsgExchange(int id)
{
    if(Qt::Checked == id){
        teT3InputMsg->show();
        gbT3Hash->show();
    }else{
        teT3InputMsg->hide();
        gbT3Hash->hide();
    }
}

void MyDialog::bgT4Exchange(int id)
{
    if(1 == id){
        gbT4Alg->hide();
        teT4Input->setPlaceholderText(tr("teT4InputText") + "\n\n"+ tr("encodePrikeyFormat"));
    }else{
        gbT4Alg->show();
        teT4Input->setPlaceholderText(tr("teT4InputText") + "\n\n"+ tr("acceptPrikeyFormat"));
    }
}

void MyDialog::leT5Edited(QString text)
{
    if(text.isEmpty()){
        cbT5Modulus->setEnabled(true);
    }else{
        cbT5Modulus->setEnabled(false);
    }
}

void MyDialog::chooseCryptoAlg()
{
    dlSetAlg->show();
}

void MyDialog::setAlg(int nid)
{
    nidCipher = nid;
    const char *str = OBJ_nid2sn(nid);
    lbT4Alg->setText(QString(QLatin1String(str)));
    lbT5Alg->setText(QString(QLatin1String(str)));
}

void MyDialog::tabChanged(int index)
{
    switch (index) {
    case 0:
        pbT1Exe->setFocus();
        break;
    case 1:
        pbT2Exe->setFocus();
        break;
    case 2:
        pbT3Exe->setFocus();
        break;
    case 3:
        pbT4Exe->setFocus();
        break;
    case 4:
        pbT5Exe->setFocus();
        break;
    default:
        break;
    }
}

QString MyDialog::showPubkey(RSA *r)
{
    char res[6000];
    QString show = "";
    RSAGetPub(r, res);
    show += QString(QLatin1String(res));
    show += "\n\n\n\n\n";

    RSAGetPubPKCS1(r, res);
    show += QString(QLatin1String(res));
    show += "\n\n\n\n\n";

    RSAGetPubXml(r, res);
    show += QString(QLatin1String(res));
    return show;
    //teT1Show->setPlainText(show);
}

QString MyDialog::showPrikey(RSA *r)
{

    char res[6000];
    QString show = "";
    RSAGetPKCS8(r, res, NULL, NULL);
    show += QString(QLatin1String(res));
    show += "\n\n\n\n\n";

    RSAGetPKCS1(r, res, NULL, NULL);
    show += QString(QLatin1String(res));
    show += "\n\n\n\n\n";

    RSAGetPriXml(r, res);
    show += QString(QLatin1String(res));
    show += "\n\n\n\n\n";
    return show;
    //teT1Show->setPlainText(show);
}

QString MyDialog::showCryptoPrikey(RSA *r, QString pass)
{
    qDebug()<<pass;
    char res[6000];
    QByteArray tmpkey = pass.toLatin1();
    char *chpass = tmpkey.data();
    const EVP_CIPHER *cipher = EVP_get_cipherbynid(nidCipher);
    QString show = "";
    if(RSAGetPKCS8(r, res, cipher, chpass) == 1){
        show += QString(QLatin1String(res));
    }else{
        show += tr("showCryPKCS8PemErr");
    }
    show += "\n\n\n\n\n";


    if(RSAGetPKCS1(r, res, cipher, chpass) == 1){
        show += QString(QLatin1String(res));
    }else{
        show += tr("showCryPKCS1PemErr");
    }


    return show;
}
