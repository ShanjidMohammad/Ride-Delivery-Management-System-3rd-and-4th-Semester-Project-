#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDebug>
#include<QMessageBox>
#include<QSqlDatabase>
#include<QSqlQuery>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QRect>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QTimer>
#include "graph.h"
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
    void on_getstartbtn_clicked();

    void on_Home_btn_clicked();

    void on_sign_up_btn_clicked();



    void on_sign_in_btn_clicked();



    void on_Log_in_btn_clicked();

    void on_ride_btn_clicked();

    void on_find_btn_clicked();

    void on_Save_btn_clicked();

    void on_account_btn_clicked();

    void on_delivery_btn_clicked();

    void on_confirm_btn_clicked();

    void on_history_btn_clicked();

    void on_cus_his_btn_clicked();

    void on_ride_request_btn_clicked();

    void on_delivery_req_btn_clicked();

    void on_load_btn_clicked();

    void on_load_btn_2_clicked();

    void on_ride_confirm_btn_clicked();

    void on_Home_btn_2_clicked();

    void on_Home_btn_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_find_btn_2_clicked();

    void on_pushButton_8_clicked();

    void on_Home_btn_4_clicked();

    void on_roadanimation_clicked();

    void on_Home_btn_5_clicked();

    void on_pushButton_10_clicked();

    void on_delivery_confirm_req_btn_clicked();

    void on_rider_acc_btn_clicked();

    void on_rider_his_load_btn_clicked();

    void on_rider_his_btn_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_Home_btn_6_clicked();

    void on_Home_btn_7_clicked();

    void on_Home_btn_8_clicked();

    void on_ride_btn_2_clicked();

    void on_delivery_btn_2_clicked();

    void on_account_btn_2_clicked();

    void on_history_btn_2_clicked();

    void on_Home_btn_9_clicked();

    void on_Home_btn_10_clicked();

    void on_Home_btn_11_clicked();

    void on_Home_btn_12_clicked();

    void on_Home_btn_13_clicked();

private:
    Ui::MainWindow *ui;
    QString sign_name,sign_contact,sign_email,sign_password;
    QString login_username,login_password;
    QString comboBox_select;
    QSqlDatabase db;
    Graph graph;
    QString edge_f, edge_t, edge_d;
    int Flag = 0;

    QString A1, B1, C1;
    QPropertyAnimation *rd;
    QPropertyAnimation *b1, *b2, *b3, *b4, *b5, *b6, *b7, *b8, *b9;

    QLabel Linelabel;

    void clearAnimations();
    void setupAnimations(const std::vector<std::string>& path);
    void all_vertex_connected_line();
    QLabel* lineLabel = nullptr;


};
#endif // MAINWINDOW_H
