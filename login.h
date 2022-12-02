#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QFile>
#include "qdom.h"
#include "storage.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_SignIn_clicked();

private:
    Ui::Login *ui;
    Storage *sto;
    QDomDocument QDom;
};
#endif // LOGIN_H
