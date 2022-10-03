#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(500,500);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Solve_Button_clicked()
{

    //set all QString vars from line inputs
    QString a_text = ui->a_input->text();
    QString b_text = ui->b_input->text();
    QString c1_text = ui->c1_input->text();
    QString c2_text = ui->c2_input->text();

    //set all line inputs to floats
    float a = a_text.toFloat();
    float b = b_text.toFloat();
    float c1 = c1_text.toFloat();
    float c2 = c2_text.toFloat();

    //intermediate calc
    float p = 2*b*c2;
    float q = 2*b*c1;

    //plug in for scaling
    float r = pow(b,2)+pow(c1,2)+pow(c2,2)-pow(a,2);
    float s = r-q;
    float t = 2*p;
    float u = r+q;

    //atan2 calculation
    float theta1 = (2*atan2((-t+sqrt(pow(t,2)-4*s*u)),(2*s)))*(180/3.14159);
    float theta2 = (2*atan2((-t-sqrt(pow(t,2)-4*s*u)),(2*s)))*(180/3.14159);
    float theta3 = atan2((-b*sin(theta1*(3.14159/180))-c2),(-b*cos(theta1*(3.14159/180))-c1))*(180/3.14159);
    float theta4 = atan2((-b*sin(theta2*(3.14159/180))-c2),(-b*cos(theta2*(3.14159/180))-c1))*(180/3.14159);


    //Set outputs for thetas
    QString theta1_output = QString::number(theta1);
    ui->theta1_input->setText(theta1_output);
    QString theta2_output = QString::number(theta2);
    ui->theta2_input->setText(theta2_output);

    QString theta3_output = QString::number(theta3);
    ui->theta3_input->setText(theta3_output);
    QString theta4_output = QString::number(theta4);
    ui->theta4_input->setText(theta4_output);

}

