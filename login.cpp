#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->Password->setFocus();
}

Login::~Login()
{
    delete ui;
}

void Login::on_SignIn_clicked()
{
    this->close();
    QFile UserXml("UserList.xml");
    UserXml.open(QIODevice::ReadOnly);
    QDom.setContent(&UserXml);
    UserXml.close();
    QDomElement QDE = QDom.documentElement();
    if (QDE.hasChildNodes())
    {
        QDomNodeList QNList = QDE.childNodes();
        bool coincode = false;
        for (int i = 0; i < QNList.count(); i++)
        {
            QDomNode Users = QNList.at(i);
            QDomNodeList QDList = Users.childNodes();
            QString QUserName = QDList.at(0).toElement().text();
            QString QPassWord = QDList.at(1).toElement().text();
            if (QUserName == ui->User->text())
            {
                coincode = true;
                if (!(QPassWord == ui->Password->text()))
                {
                    QMessageBox::warning(0, QObject::tr("注意"), "密码错误");
                    ui->Password->clear();
                    ui->Password->setFocus();
                    return;
                }
            }
        }
        if (!coincode)
        {
            QMessageBox::warning(0, QObject::tr("注意"), "用户名错误");
            ui->User->clear();
            ui->Password->clear();
            ui->User->setFocus();
            return;
        }
        sto = new Storage(0);
        sto->setWindowTitle(ui->User->text());
        sto->show();
    }
}

