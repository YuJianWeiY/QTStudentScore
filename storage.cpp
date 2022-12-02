#include "storage.h"
#include "ui_storage.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

Storage::Storage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Storage)
{
    ui->setupUi(this);
    CreateDataBase();
    CreateDataSheet();
    ShowDataSheet();
}

Storage::~Storage()
{
    delete ui;
}

void Storage::CreateDataBase()
{
    QSqlDatabase QSQL = QSqlDatabase::addDatabase("QSQLITE");
    QSQL.setDatabaseName("SQL.db");
    if(QSQL.open())
    {
        QMessageBox::information(this,"注意","数据库打开成功",QMessageBox::Ok);
    }
    else
    {
        QMessageBox::warning(0, QObject::tr("注意"), "数据库打开失败");
        return;
    }
}

void Storage::CreateDataSheet()
{
    QSqlQuery show;
    QString student = QString("CREATE TABLE SQL (""学号 INT PRIMARY KEY,""姓名 TEXT,""语文 INT,""数学 INT,""英语 INT)");
    if(show.exec(student))
    {
        QMessageBox::information(this,"注意","数据表创建成功",QMessageBox::Ok);
    }
    else
    {
        QMessageBox::information(this,"注意","数据表已创建",QMessageBox::Ok);
    }
}

void Storage::on_Add_clicked()
{
        QSqlQuery show;
        int StudentNumber = ui->StudentNumberEdit->text().toInt();
        QString Name = ui->NameEdit->text();
        int ChineseScore = ui->ChineseEdit->text().toInt();
        int MathScore = ui->MathEdit->text().toInt();
        int EnglishScore = ui->EnglishEdit->text().toInt();
        QString student = QString("INSERT INTO SQL ""VALUES(%1,'%2',%3,%4,%5)").arg(StudentNumber).arg(Name).arg(ChineseScore).arg(MathScore).arg(EnglishScore);
        if(show.exec(student))
        {
            QMessageBox::information(this,"注意","学生成绩添加成功",QMessageBox::Ok);
            ShowDataSheet();
        }
        else
        {
            QMessageBox::warning(0, QObject::tr("注意"), "该学生已存在");
        }
}

void Storage::on_Delete_clicked()
{
        QSqlQuery show;
        int StudentNumber = ui->StudentNumberEdit->text().toInt();
        QString student = QString("DELETE FROM SQL WHERE 学号 = %1").arg(StudentNumber);
        if(QMessageBox::question(this,"DELETE","是否删除？",QMessageBox::Yes|QMessageBox::No) == QMessageBox::No)
        {
            return;
        }
        if(show.exec(student))
        {
            QMessageBox::information(this,"注意","删除成功",QMessageBox::Ok);
            ShowDataSheet();
        }
        else
        {
           QMessageBox::warning(0, QObject::tr("注意"), "删除失败");
        }
}

void Storage::on_Modify_clicked()
{
        QSqlQuery show;
        int StudentNumber = ui->StudentNumberEdit->text().toInt();
        int ChineseScore = ui->ChineseEdit->text().toInt();
        int MathScore = ui->MathEdit->text().toInt();
        int EnglishScore = ui->EnglishEdit->text().toInt();
        QString student = QString("UPDATE SQL SET  语文 = %1 , 数学 = %2 , 英语 = %3 ""WHERE 学号 = %4").arg(ChineseScore).arg(MathScore).arg(EnglishScore).arg(StudentNumber);
        if(show.exec(student))
        {
            QMessageBox::information(this,"注意","修改成功",QMessageBox::Ok);
            ShowDataSheet();
        }
        else
        {
            QMessageBox::warning(0, QObject::tr("注意"), "修改失败");
        }
}

void Storage::ShowDataSheet()
{
    QString student = QString("SELECT * FROM SQL");
    QModel.setQuery(student);
    ui->StudentScoreList->setModel(&QModel);
}
