#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QPen>
#include <cmath>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);

    // 배경색을 flatdark로 설정
    scene->setBackgroundBrush(QColor("#2b2b2b")); // flatdark 색상
    ui->view->setScene(scene);

    // 전체 배경색을 flatdark 색상(#2b2b2b)으로 설정
    this->setStyleSheet("background-color: #2b2b2b;");

    // Joint Angle Label 배경색을 회색으로 설정
    ui->label1->setStyleSheet("background-color: #a0a0a0; color: gray;"); // 회색
    ui->label2->setStyleSheet("background-color: #a0a0a0; color: gray;"); // 회색
    ui->label3->setStyleSheet("background-color: #a0a0a0; color: gray;"); // 회색

    // Link SpinBox 배경색을 flatdark로 설정
    ui->link1_spinbox->setStyleSheet("background-color: #2b2b2b; color: white;"); // flatdark
    ui->link2_spinbox->setStyleSheet("background-color: #2b2b2b; color: white;"); // flatdark
    ui->link3_spinbox->setStyleSheet("background-color: #2b2b2b; color: white;"); // flatdark

    // Joint Slider 배경색을 flatdark 색상으로 설정
    ui->joint1_slider->setStyleSheet("background-color: #2b2b2b; color: white;");
    ui->joint2_slider->setStyleSheet("background-color: #2b2b2b; color: white;");
    ui->joint3_slider->setStyleSheet("background-color: #2b2b2b; color: white;");

    // 버튼과 레이블의 글씨 색을 회색으로 설정
    ui->draw_btn->setStyleSheet("color: gray;");
    ui->reset_btn->setStyleSheet("color: gray;");
    ui->label1->setStyleSheet("color: gray;");
    ui->label2->setStyleSheet("color: gray;");
    ui->label3->setStyleSheet("color: gray;");
    ui->link1_spinbox->setStyleSheet("color: gray;");
    ui->link2_spinbox->setStyleSheet("color: gray;");
    ui->link3_spinbox->setStyleSheet("color: gray;");

    // SpinBox 범위 설정
    ui->link1_spinbox->setRange(1, 100);
    ui->link2_spinbox->setRange(1, 100);
    ui->link3_spinbox->setRange(1, 100);

    // Slider 범위 설정
    ui->joint1_slider->setRange(0, 360);
    ui->joint2_slider->setRange(0, 360);
    ui->joint3_slider->setRange(0, 360);

    // 초기 QLabel 값 설정
    ui->label1->setText(QString::number(ui->joint1_slider->value()));
    ui->label2->setText(QString::number(ui->joint2_slider->value()));
    ui->label3->setText(QString::number(ui->joint3_slider->value()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::checkCollision(double x1, double y1, double x2, double y2, double x3, double y3) {
    // 두 선분 (x1, y1) <-> (x2, y2)와 (x2, y2) <-> (x3, y3) 가 교차하는지 확인하는 함수
    double denominator = (y3 - y2) * (x1 - x2) - (x2 - x1) * (y1 - y2);
    if (denominator == 0) {
        return false; // 평행
    }

    double ua = ((x3 - x2) * (y1 - y2) - (y3 - y2) * (x1 - x2)) / denominator;
    double ub = ((x1 - x2) * (y1 - y2) - (y3 - y2) * (x1 - x2)) / denominator;

    return (ua >= 0 && ua <= 1 && ub >= 0 && ub <= 1);
}

void MainWindow::draw_arm()
{
    scene->clear();

    int l1 = ui->link1_spinbox->value();
    int l2 = ui->link2_spinbox->value();
    int l3 = ui->link3_spinbox->value();

    QPen pen(Qt::white); // 로봇 팔을 흰색으로 그리기
    pen.setWidth(3);

    static int base_x = 100;
    static int base_y = ui->view->height() / 2;

    double a1 = static_cast<double>(ui->joint1_slider->value()) * M_PI / 180.0;
    double a2 = static_cast<double>(ui->joint2_slider->value()) * M_PI / 180.0;
    double a3 = static_cast<double>(ui->joint3_slider->value()) * M_PI / 180.0;

    double x1 = base_x + l1 * cos(a1);
    double y1 = base_y - l1 * sin(a1);
    QGraphicsLineItem *line1 = new QGraphicsLineItem(base_x, base_y, x1, y1);
    line1->setPen(pen);
    scene->addItem(line1);

    QGraphicsEllipseItem *point1 = new QGraphicsEllipseItem(x1 - 3, y1 - 3, 6, 6);
    point1->setBrush(Qt::blue);
    point1->setZValue(1);
    scene->addItem(point1);

    double x2 = x1 + l2 * cos(a1 + a2);
    double y2 = y1 - l2 * sin(a1 + a2);
    QGraphicsLineItem *line2 = new QGraphicsLineItem(x1, y1, x2, y2);
    line2->setPen(pen);
    scene->addItem(line2);

    QGraphicsEllipseItem *point2 = new QGraphicsEllipseItem(x2 - 3, y2 - 3, 6, 6);
    point2->setBrush(Qt::blue);
    point2->setZValue(1);
    scene->addItem(point2);

    double x3 = x2 + l3 * cos(a1 + a2 + a3);
    double y3 = y2 - l3 * sin(a1 + a2 + a3);
    QGraphicsLineItem *line3 = new QGraphicsLineItem(x2, y2, x3, y3);
    line3->setPen(pen);
    scene->addItem(line3);

    QGraphicsEllipseItem *point3 = new QGraphicsEllipseItem(x3 - 3, y3 - 3, 6, 6);
    point3->setBrush(Qt::red);
    point3->setZValue(1);
    scene->addItem(point3);

    // 충돌 감지
    if (checkCollision(base_x, base_y, x1, y1, x2, y2)) {
        QMessageBox::warning(this, "Collision Detected", "Link 1 and Link 2 are colliding!");
    }
    if (checkCollision(x1, y1, x2, y2, x3, y3)) {
        QMessageBox::warning(this, "Collision Detected", "Link 2 and Link 3 are colliding!");
    }
}

void MainWindow::on_draw_btn_clicked()
{
    draw_arm();
}

void MainWindow::on_reset_btn_clicked()
{
    ui->joint1_slider->setValue(0);
    ui->joint2_slider->setValue(0);
    ui->joint3_slider->setValue(0);
    ui->label1->setText("0");
    ui->label2->setText("0");
    ui->label3->setText("0");
    ui->link1_spinbox->setValue(1);
    ui->link2_spinbox->setValue(1);
    ui->link3_spinbox->setValue(1);
    scene->clear();
}

void MainWindow::on_joint1_slider_valueChanged(int value)
{
    ui->label1->setText(QString::number(value));
    draw_arm();
}

void MainWindow::on_joint2_slider_valueChanged(int value)
{
    ui->label2->setText(QString::number(value));
    draw_arm();
}

void MainWindow::on_joint3_slider_valueChanged(int value)
{
    ui->label3->setText(QString::number(value));
    draw_arm();
}

void MainWindow::on_link1_spinbox_valueChanged(int)
{
    draw_arm(); // Arm을 다시 그리기
}

void MainWindow::on_link2_spinbox_valueChanged(int)
{
    draw_arm(); // Arm을 다시 그리기
}

void MainWindow::on_link3_spinbox_valueChanged(int)
{
    draw_arm(); // Arm을 다시 그리기
}
