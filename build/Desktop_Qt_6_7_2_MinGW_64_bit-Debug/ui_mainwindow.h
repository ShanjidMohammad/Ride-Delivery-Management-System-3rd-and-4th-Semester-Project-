/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QPushButton *getstartbtn;
    QWidget *page_2;
    QLabel *label_2;
    QPushButton *sign_in_btn;
    QPushButton *sign_up_btn;
    QLineEdit *sign_email_input;
    QLineEdit *sign_name_input;
    QLineEdit *sign_contact_input;
    QLineEdit *sign_password_input;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QComboBox *select_member_comboBox;
    QWidget *page_5;
    QLabel *label_5;
    QLineEdit *lineEdit_from;
    QLineEdit *lineEdit_to;
    QPushButton *find_btn;
    QWidget *page_6;
    QLabel *label_6;
    QLabel *label_path;
    QLabel *label_distance;
    QLabel *label_cost;
    QLabel *label_discount;
    QLabel *label_offer_price;
    QPushButton *confirm_btn;
    QWidget *page_7;
    QLabel *label_7;
    QTableView *tableView_for_cus_history;
    QComboBox *comboBox_for_cus_history;
    QPushButton *cus_his_btn;
    QWidget *page_8;
    QLabel *label_8;
    QLabel *acc_name_label;
    QLabel *acc_email_label;
    QLabel *acc_contact_label;
    QWidget *page_9;
    QLabel *label_9;
    QLineEdit *lineEdit_edge_from;
    QLineEdit *lineEdit_edge_to;
    QLineEdit *lineEdit_edge_distance;
    QPushButton *Save_btn;
    QWidget *page_10;
    QLabel *label_10;
    QPushButton *ride_request_btn;
    QPushButton *delivery_req_btn;
    QWidget *page_11;
    QLabel *label_11;
    QTableView *tableView_ride_request;
    QPushButton *load_btn_2;
    QPushButton *ride_confirm_btn;
    QLineEdit *ride_serial_label;
    QWidget *page_12;
    QLabel *label_12;
    QTableView *tableView_delivery_request;
    QPushButton *load_btn;
    QWidget *page_4;
    QLabel *label_4;
    QPushButton *Home_btn;
    QPushButton *pushButton_4;
    QPushButton *ride_btn;
    QPushButton *account_btn;
    QPushButton *delivery_btn;
    QPushButton *history_btn;
    QWidget *page_3;
    QLabel *label_3;
    QComboBox *select_member_comboBox_2;
    QLineEdit *email_input;
    QLineEdit *password_input;
    QPushButton *Log_in_btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(321, 661);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 300, 600));
        page = new QWidget();
        page->setObjectName("page");
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 300, 600));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image1/1.png")));
        label->setScaledContents(true);
        getstartbtn = new QPushButton(page);
        getstartbtn->setObjectName("getstartbtn");
        getstartbtn->setGeometry(QRect(90, 510, 121, 31));
        getstartbtn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);\n"
"font-weight:bold;"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_2 = new QLabel(page_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 300, 600));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/image3/3.png")));
        label_2->setScaledContents(true);
        sign_in_btn = new QPushButton(page_2);
        sign_in_btn->setObjectName("sign_in_btn");
        sign_in_btn->setGeometry(QRect(200, 520, 71, 29));
        sign_in_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"font: 9pt \"Segoe UI\";\n"
"font: 6pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"font-weight:bold;"));
        sign_up_btn = new QPushButton(page_2);
        sign_up_btn->setObjectName("sign_up_btn");
        sign_up_btn->setGeometry(QRect(70, 450, 151, 41));
        sign_up_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font-weight:bold;\n"
""));
        sign_email_input = new QLineEdit(page_2);
        sign_email_input->setObjectName("sign_email_input");
        sign_email_input->setGeometry(QRect(40, 330, 221, 21));
        sign_email_input->setStyleSheet(QString::fromUtf8("border:none;"));
        sign_email_input->setReadOnly(false);
        sign_name_input = new QLineEdit(page_2);
        sign_name_input->setObjectName("sign_name_input");
        sign_name_input->setGeometry(QRect(30, 200, 241, 41));
        sign_name_input->setReadOnly(false);
        sign_contact_input = new QLineEdit(page_2);
        sign_contact_input->setObjectName("sign_contact_input");
        sign_contact_input->setGeometry(QRect(30, 260, 241, 41));
        sign_contact_input->setReadOnly(false);
        sign_password_input = new QLineEdit(page_2);
        sign_password_input->setObjectName("sign_password_input");
        sign_password_input->setGeometry(QRect(30, 380, 241, 41));
        sign_password_input->setReadOnly(false);
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 570, 93, 29));
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(200, 570, 93, 29));
        select_member_comboBox = new QComboBox(page_2);
        select_member_comboBox->addItem(QString());
        select_member_comboBox->addItem(QString());
        select_member_comboBox->setObjectName("select_member_comboBox");
        select_member_comboBox->setGeometry(QRect(30, 140, 241, 41));
        stackedWidget->addWidget(page_2);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        label_5 = new QLabel(page_5);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 0, 300, 600));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/image5/5.png")));
        label_5->setScaledContents(true);
        lineEdit_from = new QLineEdit(page_5);
        lineEdit_from->setObjectName("lineEdit_from");
        lineEdit_from->setGeometry(QRect(60, 390, 113, 26));
        lineEdit_to = new QLineEdit(page_5);
        lineEdit_to->setObjectName("lineEdit_to");
        lineEdit_to->setGeometry(QRect(60, 450, 113, 26));
        find_btn = new QPushButton(page_5);
        find_btn->setObjectName("find_btn");
        find_btn->setGeometry(QRect(70, 520, 93, 29));
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        label_6 = new QLabel(page_6);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 0, 300, 600));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/image6/6.png")));
        label_6->setScaledContents(true);
        label_path = new QLabel(page_6);
        label_path->setObjectName("label_path");
        label_path->setGeometry(QRect(142, 350, 151, 20));
        label_distance = new QLabel(page_6);
        label_distance->setObjectName("label_distance");
        label_distance->setGeometry(QRect(140, 380, 161, 20));
        label_cost = new QLabel(page_6);
        label_cost->setObjectName("label_cost");
        label_cost->setGeometry(QRect(70, 400, 63, 20));
        label_discount = new QLabel(page_6);
        label_discount->setObjectName("label_discount");
        label_discount->setGeometry(QRect(170, 430, 131, 20));
        label_offer_price = new QLabel(page_6);
        label_offer_price->setObjectName("label_offer_price");
        label_offer_price->setGeometry(QRect(120, 450, 181, 20));
        confirm_btn = new QPushButton(page_6);
        confirm_btn->setObjectName("confirm_btn");
        confirm_btn->setGeometry(QRect(100, 520, 93, 29));
        stackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        label_7 = new QLabel(page_7);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 0, 300, 600));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/image7/7.png")));
        label_7->setScaledContents(true);
        tableView_for_cus_history = new QTableView(page_7);
        tableView_for_cus_history->setObjectName("tableView_for_cus_history");
        tableView_for_cus_history->setGeometry(QRect(0, 100, 291, 351));
        comboBox_for_cus_history = new QComboBox(page_7);
        comboBox_for_cus_history->addItem(QString());
        comboBox_for_cus_history->addItem(QString());
        comboBox_for_cus_history->addItem(QString());
        comboBox_for_cus_history->setObjectName("comboBox_for_cus_history");
        comboBox_for_cus_history->setGeometry(QRect(0, 460, 111, 26));
        cus_his_btn = new QPushButton(page_7);
        cus_his_btn->setObjectName("cus_his_btn");
        cus_his_btn->setGeometry(QRect(130, 460, 111, 29));
        stackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        label_8 = new QLabel(page_8);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, 0, 300, 600));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/image8/8.png")));
        label_8->setScaledContents(true);
        acc_name_label = new QLabel(page_8);
        acc_name_label->setObjectName("acc_name_label");
        acc_name_label->setGeometry(QRect(60, 110, 221, 41));
        acc_email_label = new QLabel(page_8);
        acc_email_label->setObjectName("acc_email_label");
        acc_email_label->setGeometry(QRect(60, 180, 221, 31));
        acc_contact_label = new QLabel(page_8);
        acc_contact_label->setObjectName("acc_contact_label");
        acc_contact_label->setGeometry(QRect(60, 260, 231, 31));
        stackedWidget->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName("page_9");
        label_9 = new QLabel(page_9);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(0, 0, 300, 600));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/image9/9.png")));
        label_9->setScaledContents(true);
        lineEdit_edge_from = new QLineEdit(page_9);
        lineEdit_edge_from->setObjectName("lineEdit_edge_from");
        lineEdit_edge_from->setGeometry(QRect(60, 380, 113, 26));
        lineEdit_edge_to = new QLineEdit(page_9);
        lineEdit_edge_to->setObjectName("lineEdit_edge_to");
        lineEdit_edge_to->setGeometry(QRect(60, 430, 113, 26));
        lineEdit_edge_distance = new QLineEdit(page_9);
        lineEdit_edge_distance->setObjectName("lineEdit_edge_distance");
        lineEdit_edge_distance->setGeometry(QRect(60, 490, 113, 26));
        Save_btn = new QPushButton(page_9);
        Save_btn->setObjectName("Save_btn");
        Save_btn->setGeometry(QRect(110, 540, 93, 29));
        stackedWidget->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName("page_10");
        label_10 = new QLabel(page_10);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(0, 0, 300, 600));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/image10/10.png")));
        label_10->setScaledContents(true);
        ride_request_btn = new QPushButton(page_10);
        ride_request_btn->setObjectName("ride_request_btn");
        ride_request_btn->setGeometry(QRect(40, 350, 93, 29));
        delivery_req_btn = new QPushButton(page_10);
        delivery_req_btn->setObjectName("delivery_req_btn");
        delivery_req_btn->setGeometry(QRect(162, 350, 101, 29));
        stackedWidget->addWidget(page_10);
        page_11 = new QWidget();
        page_11->setObjectName("page_11");
        label_11 = new QLabel(page_11);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(0, 0, 300, 600));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/image11/11.png")));
        label_11->setScaledContents(true);
        tableView_ride_request = new QTableView(page_11);
        tableView_ride_request->setObjectName("tableView_ride_request");
        tableView_ride_request->setGeometry(QRect(0, 90, 291, 211));
        load_btn_2 = new QPushButton(page_11);
        load_btn_2->setObjectName("load_btn_2");
        load_btn_2->setGeometry(QRect(10, 330, 93, 29));
        ride_confirm_btn = new QPushButton(page_11);
        ride_confirm_btn->setObjectName("ride_confirm_btn");
        ride_confirm_btn->setGeometry(QRect(100, 510, 93, 29));
        ride_serial_label = new QLineEdit(page_11);
        ride_serial_label->setObjectName("ride_serial_label");
        ride_serial_label->setGeometry(QRect(222, 430, 61, 26));
        stackedWidget->addWidget(page_11);
        page_12 = new QWidget();
        page_12->setObjectName("page_12");
        label_12 = new QLabel(page_12);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(0, 0, 300, 600));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/image12/12.png")));
        label_12->setScaledContents(true);
        tableView_delivery_request = new QTableView(page_12);
        tableView_delivery_request->setObjectName("tableView_delivery_request");
        tableView_delivery_request->setGeometry(QRect(10, 90, 281, 241));
        load_btn = new QPushButton(page_12);
        load_btn->setObjectName("load_btn");
        load_btn->setGeometry(QRect(20, 350, 93, 29));
        stackedWidget->addWidget(page_12);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        label_4 = new QLabel(page_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 0, 300, 600));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/image4/4.png")));
        label_4->setScaledContents(true);
        Home_btn = new QPushButton(page_4);
        Home_btn->setObjectName("Home_btn");
        Home_btn->setGeometry(QRect(110, 590, 93, 16));
        Home_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        pushButton_4 = new QPushButton(page_4);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(33, 575, 16, 16));
        pushButton_4->setStyleSheet(QString::fromUtf8("\n"
"border:none;\n"
"background-color: rgb(255, 255, 255);"));
        ride_btn = new QPushButton(page_4);
        ride_btn->setObjectName("ride_btn");
        ride_btn->setGeometry(QRect(40, 280, 71, 29));
        account_btn = new QPushButton(page_4);
        account_btn->setObjectName("account_btn");
        account_btn->setGeometry(QRect(50, 490, 71, 29));
        delivery_btn = new QPushButton(page_4);
        delivery_btn->setObjectName("delivery_btn");
        delivery_btn->setGeometry(QRect(170, 280, 71, 29));
        history_btn = new QPushButton(page_4);
        history_btn->setObjectName("history_btn");
        history_btn->setGeometry(QRect(170, 490, 93, 29));
        stackedWidget->addWidget(page_4);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        label_3 = new QLabel(page_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 0, 300, 600));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/Image2/2.png")));
        label_3->setScaledContents(true);
        select_member_comboBox_2 = new QComboBox(page_3);
        select_member_comboBox_2->addItem(QString());
        select_member_comboBox_2->addItem(QString());
        select_member_comboBox_2->addItem(QString());
        select_member_comboBox_2->setObjectName("select_member_comboBox_2");
        select_member_comboBox_2->setGeometry(QRect(30, 250, 241, 41));
        email_input = new QLineEdit(page_3);
        email_input->setObjectName("email_input");
        email_input->setGeometry(QRect(30, 310, 241, 41));
        email_input->setReadOnly(false);
        password_input = new QLineEdit(page_3);
        password_input->setObjectName("password_input");
        password_input->setGeometry(QRect(30, 370, 241, 41));
        password_input->setReadOnly(false);
        Log_in_btn = new QPushButton(page_3);
        Log_in_btn->setObjectName("Log_in_btn");
        Log_in_btn->setGeometry(QRect(100, 460, 93, 29));
        stackedWidget->addWidget(page_3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 321, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        getstartbtn->setText(QCoreApplication::translate("MainWindow", "GET STARTED", nullptr));
        label_2->setText(QString());
        sign_in_btn->setText(QCoreApplication::translate("MainWindow", "Sign In", nullptr));
        sign_up_btn->setText(QCoreApplication::translate("MainWindow", "SIGN UP", nullptr));
        sign_email_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email Address", nullptr));
        sign_name_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "Full Name", nullptr));
        sign_contact_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "Phone Number", nullptr));
        sign_password_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        select_member_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "RIDER", nullptr));
        select_member_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "USER", nullptr));

        label_5->setText(QString());
        find_btn->setText(QCoreApplication::translate("MainWindow", "FIND", nullptr));
        label_6->setText(QString());
        label_path->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_distance->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_cost->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_discount->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_offer_price->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        confirm_btn->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        label_7->setText(QString());
        comboBox_for_cus_history->setItemText(0, QCoreApplication::translate("MainWindow", "Choose", nullptr));
        comboBox_for_cus_history->setItemText(1, QCoreApplication::translate("MainWindow", "Ride", nullptr));
        comboBox_for_cus_history->setItemText(2, QCoreApplication::translate("MainWindow", "Delivery", nullptr));

        cus_his_btn->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        label_8->setText(QString());
        acc_name_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        acc_email_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        acc_contact_label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_9->setText(QString());
        Save_btn->setText(QCoreApplication::translate("MainWindow", "ADD ROAD", nullptr));
        label_10->setText(QString());
        ride_request_btn->setText(QCoreApplication::translate("MainWindow", "Ride Request", nullptr));
        delivery_req_btn->setText(QCoreApplication::translate("MainWindow", "Delivery Reaquest", nullptr));
        label_11->setText(QString());
        load_btn_2->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        ride_confirm_btn->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        label_12->setText(QString());
        load_btn->setText(QCoreApplication::translate("MainWindow", "Load", nullptr));
        label_4->setText(QString());
        Home_btn->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        ride_btn->setText(QCoreApplication::translate("MainWindow", "Ride", nullptr));
        account_btn->setText(QCoreApplication::translate("MainWindow", "Account", nullptr));
        delivery_btn->setText(QCoreApplication::translate("MainWindow", "Delivery", nullptr));
        history_btn->setText(QCoreApplication::translate("MainWindow", "History", nullptr));
        label_3->setText(QString());
        select_member_comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "ADMIN", nullptr));
        select_member_comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "RIDER", nullptr));
        select_member_comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "USER", nullptr));

        email_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "Email Address", nullptr));
        password_input->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        Log_in_btn->setText(QCoreApplication::translate("MainWindow", "SIGN In", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
