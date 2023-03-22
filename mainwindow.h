#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMessageBox"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    double point_Xb (int Xa,int angl,int d);
    ~MainWindow();

private slots:

    void on_pushButton_answer_clicked();

    void on_pushButton_changeTask_clicked();

    void on_pushButton_changeTask_back_clicked();


    void on_lineEdit_angl_textChanged(const QString &arg1);



    void on_lineEdit_Xa_textChanged(const QString &arg1);

    void on_lineEdit_Ya_textChanged(const QString &arg1);

    void on_lineEdit_d_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_lineEdit_Xa_reverse_textChanged(const QString &arg1);

    void on_lineEdit_Ya_reverse_textChanged(const QString &arg1);

    void on_lineEdit_Xb_reverse_textChanged(const QString &arg1);

    void on_lineEdit_Yb_reverse_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
