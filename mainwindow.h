#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "modellist.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int current_item = 0;
    QString filename;
    ModelList* list;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void saveData();
    void loadData();
    void modelToWidget();

private slots:


    void on_btnAddData_clicked();

    void on_btnSaveData_clicked();

    void on_btnLoadFromFile_clicked();

    void on_listView_clicked(const QModelIndex &index);

    void on_btnApplyChanges_clicked();

    void on_btnGenPass_clicked();

    void on_btnRemoveElem_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
