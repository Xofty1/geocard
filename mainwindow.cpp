#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_answer_clicked() // решение прямой задачи
{
    bool flag;

    double Xa = ui-> lineEdit_Xa -> text().toDouble(&flag);

    if (!flag)
    {
        QMessageBox::information(this, "Ошибка", "Исправьте координаты Xa");
        return;
    }
    double Ya = ui-> lineEdit_Ya -> text().toDouble(&flag);
    if (!flag)
    {
        QMessageBox::information(this, "Ошибка", "Исправьте координаты Ya");
        return;
    }
    double angl = ui -> lineEdit_angl -> text().toDouble(&flag);
    if (!flag or angl > 360 or angl < 0)
    {
        QMessageBox::information(this, "Ошибка", "Исправьте угол");
        return;
    }
    double d = ui -> lineEdit_d -> text().toDouble(&flag);
    if (!flag or d < 0)
    {
        QMessageBox::information(this, "Ошибка", "Исправьте горизонтальное проложение");
        return;
    }
    // Рассчет для координаты X
    double delt_x = d * cos (angl * M_PI/180);
    double Xb = Xa + delt_x;
    Xb = round (Xb*100)/100;

    // Рассчет для координаты Y
    double delt_y = d * sin (angl *M_PI/180);
    double Yb = Ya + delt_y;
    Yb = round (Yb*100)/100;


    // Вывод координат
    ui -> label_Xb_2 -> setText(QString::number(Xb));
    ui -> label_Yb_2 -> setText(QString::number(Yb));
}

void MainWindow::on_pushButton_changeTask_clicked() // перейти к обратной задаче
{
    ui-> stackedWidget-> setCurrentIndex(1);
}

void MainWindow::on_pushButton_changeTask_back_clicked() // перейти к прямой задаче
{
    ui-> stackedWidget-> setCurrentIndex(0);
}

void MainWindow::on_lineEdit_angl_textChanged(const QString &arg1)
{
    ui->label_Xb_2->clear();
    ui->label_Yb_2->clear();

    bool flag;
    QPalette pal;

    double str = ui -> lineEdit_angl -> text().toDouble(&flag);
    if (!flag or str>360 or str<0){
        pal.setColor(QPalette::Text,Qt::red);
    }
    else{
        pal.setColor(QPalette::Text,Qt::black);
    }
    ui->lineEdit_angl->setPalette(pal);
}

void MainWindow::on_lineEdit_Xa_textChanged(const QString &arg1)
{
    ui->label_Xb_2->clear();
    ui->label_Yb_2->clear();

    bool flag;
    QPalette pal;

    double str = ui -> lineEdit_Xa -> text().toDouble(&flag);
    if (!flag){
        pal.setColor(QPalette::Text,Qt::red);
    }
    else{
        pal.setColor(QPalette::Text,Qt::black);
    }
    ui->lineEdit_Xa->setPalette(pal);
}

void MainWindow::on_lineEdit_Ya_textChanged(const QString &arg1)
{
    ui->label_Xb_2->clear();
    ui->label_Yb_2->clear();

    bool flag;
    QPalette pal;

    double str = ui -> lineEdit_Ya -> text().toDouble(&flag);
    if (!flag){
        pal.setColor(QPalette::Text,Qt::red);
    }
    else{
        pal.setColor(QPalette::Text,Qt::black);
    }
    ui->lineEdit_Ya->setPalette(pal);
}

void MainWindow::on_lineEdit_d_textChanged(const QString &arg1)
{
    ui->label_Xb_2->clear();
    ui->label_Yb_2->clear();

    bool flag;
    QPalette pal;

    double str = ui -> lineEdit_d -> text().toDouble(&flag);
    if (!flag or str<0){
        pal.setColor(QPalette::Text,Qt::red);
    }
    else{
        pal.setColor(QPalette::Text,Qt::black);
    }
    ui->lineEdit_d->setPalette(pal);

}

void MainWindow::on_pushButton_clicked()
{
    bool flag;


    double Xa = ui-> lineEdit_Xa_reverse -> text().toDouble(&flag);

    if (!flag)
    {
        QMessageBox::information(this, "Ошибка", "Исправьте координаты Xa");
        return;
    }

    double Xb = ui-> lineEdit_Xb_reverse -> text().toDouble(&flag);

    if (!flag)
    {
        QMessageBox::information(this, "Ошибка", "Исправьте координаты Xa");
        return;
    }

    double Ya = ui-> lineEdit_Ya_reverse -> text().toDouble(&flag);
    if (!flag)
    {
        QMessageBox::information(this, "Ошибка", "Исправьте координаты Ya");
        return;
    }

    double Yb = ui-> lineEdit_Yb_reverse -> text().toDouble(&flag);
    if (!flag)
    {
        QMessageBox::information(this, "Ошибка", "Исправьте координаты Ya");
        return;
    }

    double delta_x = Xb-Xa;
    double delta_y = Yb-Ya;
    if (delta_x<0){
        delta_x*=-1;
    }
    if (delta_y<0){
        delta_y*=-1;
    }

    // Рассчет угла
    double angle = atan (delta_y/delta_x);
    angle *= 180/M_PI;

    double grad = floor(angle);

    double minute = (angle - grad) * 60;
    double min = floor(minute);

    double secund = (minute - min) * 60;
    secund = round (secund);

    // Рассчет горизонтального проложения
    double s = sqrt(pow(delta_x,2)+ pow(delta_y,2));
    s = round(s*100)/100;

    // Вывод
    ui -> label_dir_angle_ans -> setText(QString::number(grad)+ "°" +QString::number(min) + "'" + QString::number(secund)+ "''");
    ui -> label_d_reverse -> setText(QString::number(s));

}

void MainWindow::on_lineEdit_Xa_reverse_textChanged(const QString &arg1)
{
    ui->label_dir_angle_ans->clear();
    ui->label_d_reverse->clear();

    bool flag;
    QPalette pal;

    double str = ui -> lineEdit_Xa_reverse -> text().toDouble(&flag);
    if (!flag){
        pal.setColor(QPalette::Text,Qt::red);
    }
    else{
        pal.setColor(QPalette::Text,Qt::black);
    }
    ui->lineEdit_Xa_reverse->setPalette(pal);
}

void MainWindow::on_lineEdit_Ya_reverse_textChanged(const QString &arg1)
{
    ui->label_dir_angle_ans->clear();
    ui->label_d_reverse->clear();

    bool flag;
    QPalette pal;

    double str = ui -> lineEdit_Ya_reverse -> text().toDouble(&flag);
    if (!flag){
        pal.setColor(QPalette::Text,Qt::red);
    }
    else{
        pal.setColor(QPalette::Text,Qt::black);
    }
    ui->lineEdit_Ya_reverse->setPalette(pal);
}

void MainWindow::on_lineEdit_Xb_reverse_textChanged(const QString &arg1)
{
    ui->label_dir_angle_ans->clear();
    ui->label_d_reverse->clear();

    bool flag;
    QPalette pal;

    double str = ui -> lineEdit_Xb_reverse -> text().toDouble(&flag);
    if (!flag){
        pal.setColor(QPalette::Text,Qt::red);
    }
    else{
        pal.setColor(QPalette::Text,Qt::black);
    }
    ui->lineEdit_Xb_reverse->setPalette(pal);
}

void MainWindow::on_lineEdit_Yb_reverse_textChanged(const QString &arg1)
{
    ui->label_dir_angle_ans->clear();
    ui->label_d_reverse->clear();

    bool flag;
    QPalette pal;

    double str = ui -> lineEdit_Yb_reverse -> text().toDouble(&flag);
    if (!flag){
        pal.setColor(QPalette::Text,Qt::red);
    }
    else{
        pal.setColor(QPalette::Text,Qt::black);
    }
    ui->lineEdit_Yb_reverse->setPalette(pal);
}
