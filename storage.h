#ifndef STORAGE_H
#define STORAGE_H

#include <QWidget>
#include <QSqlQueryModel>

namespace Ui {
class Storage;
}

class Storage : public QWidget
{
    Q_OBJECT

public:
    explicit Storage(QWidget *parent = nullptr);
    ~Storage();

private:
    Ui::Storage *ui;
    QSqlQueryModel QModel;

private:
    void CreateDataBase();
    void CreateDataSheet();
    void ShowDataSheet();

private slots:
    void on_Add_clicked();
    void on_Delete_clicked();
    void on_Modify_clicked();
};

#endif // STORAGE_H
