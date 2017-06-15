#include "dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
   this->resize(1000,520);

   twDisplay = new QTabWidget();
   teT1Input = new QTextEdit();
   teT1Show = new QTextEdit();
   bgT1Radio = new QButtonGroup();
   rbT1Pri = new QRadioButton();
   rbT1Pub = new QRadioButton();
   rbT1Xml = new QRadioButton();
   gbT1Input = new QGroupBox();
   pbT1Exe = new QPushButton();

   rbT1Pri->setText("私钥");
   rbT1Pub->setText("公钥");
   rbT1Xml->setText("xml格式");
   gbT1Input->setTitle("选择输入类型");
   pbT1Exe->setText("执行");
   rbT1Pri->setChecked(true);
   teT1Show->setReadOnly(true);
   bgT1Radio->addButton(rbT1Pri, 1);
   bgT1Radio->addButton(rbT1Pub, 2);
   bgT1Radio->addButton(rbT1Xml, 3);


   QVBoxLayout *tmpVLMain;
   QVBoxLayout *tmpVL;
   QHBoxLayout *tmpHL;
   QWidget *tmpWT;

   //**************tab1布局***************//
   tmpWT = new QWidget();
   tmpVLMain = new QVBoxLayout;

   tmpVL = new QVBoxLayout;
   tmpVL->addWidget(rbT1Pri);
   tmpVL->addWidget(rbT1Pub);
   tmpVL->addWidget(rbT1Xml);
   gbT1Input->setLayout(tmpVL);

   tmpVL = new QVBoxLayout;
   tmpVL->addStretch(1);//加弹簧
   tmpVL->addWidget(gbT1Input);
   tmpVL->addStretch(1);//加弹簧,加两个保居中

   tmpHL = new QHBoxLayout;
   //tmpHL->setMargin(5);
   //tmpHL->setSpacing(10);
   tmpHL->addLayout(tmpVL);
   tmpHL->addWidget(teT1Input);
   tmpHL->addWidget(teT1Show);

   tmpVLMain->addLayout(tmpHL);
   tmpVLMain->addWidget(pbT1Exe);
   tmpWT->setLayout(tmpVLMain);

   twDisplay->addTab(tmpWT, "格式转换");
   //**************tab1布局***************//


    QWidget *widget2 = new QWidget();
    twDisplay->addTab(widget2, "2222sdf");

    QVBoxLayout *ddd = new QVBoxLayout(this);
    ddd->addWidget(twDisplay);

    connect(pbT1Exe, &QPushButton::clicked, this, &Dialog::execTrans);
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
        prikeyToRSA(key, &r);
        showPrikey(r);
    }else if(bgT1Radio->checkedId() == 2){
        pubkeyToRSA(key, &r);
        showPubkey(r);
    }else{
        int flag = xmlkeyToRSA(key, &r);
        qDebug()<<flag;
        if(flag == 2){
            showPubkey(r);
        }else{
            showPrikey(r);
        }
    }
    if(r!=NULL){RSA_free(r);r=NULL;}
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
    teT1Show->setText(show);
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
    teT1Show->setText(show);
}
