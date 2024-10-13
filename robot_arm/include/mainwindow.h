#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_draw_btn_clicked();
    void on_reset_btn_clicked();
    void on_joint1_slider_valueChanged(int value);
    void on_joint2_slider_valueChanged(int value);
    void on_joint3_slider_valueChanged(int value);
    void on_link1_spinbox_valueChanged(int);
    void on_link2_spinbox_valueChanged(int);
    void on_link3_spinbox_valueChanged(int);
private:
    void draw_arm();
    bool checkCollision(double x1, double y1, double x2, double y2, double x3, double y3);
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
