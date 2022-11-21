#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <nml.h>
#include <halui.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void update();

private slots:
    void on_pushButton_estop_pressed();

    void on_pushButton_load_pressed();

    void on_pushButton_auto_pressed();

    void on_pushButton_mdi_pressed();

    void on_pushButton_manual_pressed();

    void on_pushButton_run_pressed();

    void on_pushButton_pause_pressed();

    void on_pushButton_machine_on_pressed();

    void on_pushButton_teleop_pressed();

    void on_pushButton_coord_pressed();

    void on_pushButton_free_pressed();

    void on_pushButton_home_x_pressed();

    void on_pushButton_home_y_pressed();

    void on_pushButton_home_z_pressed();

    void on_pushButton_resume_pressed();

    void on_pushButton_reverse_pressed();

    void on_pushButton_stop_pressed();

    void on_pushButton_spindle_off_pressed();

    void on_pushButton_spindle_on_cw_pressed();

    void on_pushButton_spindle_on_ccw_pressed();

    void on_pushButton_jog_x_plus_pressed();

    void on_pushButton_jog_x_min_pressed();

    void on_pushButton_jog_x_min_released();

    void on_pushButton_jog_x_plus_released();

    void on_pushButton_jog_y_min_pressed();

    void on_pushButton_jog_y_min_released();

    void on_pushButton_jog_y_plus_pressed();

    void on_pushButton_jog_y_plus_released();

    void on_pushButton_jog_z_min_pressed();

    void on_pushButton_jog_z_min_released();

    void on_pushButton_jog_z_plus_pressed();

    void on_pushButton_jog_z_plus_released();

    void on_horizontalScrollBar_jog_speed_valueChanged(int value);

    void on_pushButton_home_all_pressed();

    void on_pushButton_unhome_all_pressed();

private:
    Ui::MainWindow *ui;
    nml *myNml=new nml();
    halui *myHalui=new halui();
};
#endif
