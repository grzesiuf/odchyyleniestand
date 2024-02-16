#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString elementySTR = "";
    QString el;
        float n = elementy.length();
        elementy.append(ui->spinBox->value());
        ui->spinBox->clear();
        for(int i = 0;i<n;i++){
            el = QString::number(elementy[i]);
            elementySTR += el + " ";
        }
        ui->label->setText(elementySTR);
}



void MainWindow::on_pushButton_2_clicked()
{
    float n = elementy.length();
    float srednia;
    QString osrednia;
    double owynik;
    double wynik;
    QString wyniczel;
    for(int i=0;i<n;i++){
        srednia = srednia+elementy[i];
    }
    srednia = srednia / n;
    osrednia = osrednia.setNum(srednia);
    ui->label_4->setText(osrednia);

    for(int j=0;j<n;j++){
        wynik += pow(elementy[j]-srednia,2);
    }
    wynik /=n;

    owynik = sqrt(wynik);
    wyniczel.setNum(owynik);
    QMessageBox msg(this);
    msg.setText(wyniczel);
    msg.setStandardButtons(QMessageBox::Ok);
    msg.setWindowTitle("Odchylenie standardowe");
    msg.exec();
}




