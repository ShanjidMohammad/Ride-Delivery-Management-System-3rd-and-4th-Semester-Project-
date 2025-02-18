#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlError>
#include<QSqlQueryModel>
#include <QStringList>
#include <QRegularExpression>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QDebug>
#include <QPropertyAnimation>
#include <QObject>
#include <QSequentialAnimationGroup>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,graph()
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    //connect(ui->Log_in_btn, &QPushButton::clicked, this, &MainWindow::on_Log_in_btn_clicked);


    //database;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("E:/project/Eazy.db");

    db.open();
    qDebug()<<db. isOpen();
    if (db.open()) {
        qDebug() << "Database opened successfully.";
    } else {
        //qDebug() << "Failed to open the database:" << db.lastError().text();
    }
    graph.addNode("A");
    graph.addNode("B");
    graph.addNode("C");
    graph.addNode("D");
    graph.addNode("E");
    graph.addNode("F");
    graph.addNode("G");
    graph.addNode("H");
    graph.addNode("I");


    b1 = nullptr;
    b2 = nullptr;
    b3 = nullptr;
    b4 = nullptr;
    b5 = nullptr;
    b6 = nullptr;
    b7 = nullptr;
    b8 = nullptr;
    b9 = nullptr;

   // connect(ui->find_btn, &QPushButton::clicked, this, &MainWindow::on_find_btn_clicked);

    // Connect the start button clicked signal to the slot
    connect(ui->find_btn, &QPushButton::clicked, this, &MainWindow::on_find_btn_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_getstartbtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Home_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_sign_up_btn_clicked()
{
    sign_name=ui->sign_name_input->text();
    sign_contact=ui->sign_contact_input->text();
    sign_email=ui->sign_email_input->text();
    sign_password=ui->sign_password_input->text();
    //
    QString comboBox_select = ui->select_member_comboBox->currentText();
        //qDebug() << comboBox_select;
    if(comboBox_select=="USER"){


        //if the email is available or not;
        QSqlQuery checkQuery;
        checkQuery.exec("SELECT * FROM Sign_info WHERE email='"+sign_email+"'");
        {
            if (checkQuery.next()) {
                QMessageBox::warning(this, "Sign Up", "This  email already exists.");
                ui->sign_name_input->clear();
                ui->sign_contact_input->clear();
                ui->sign_password_input->clear();
                ui->sign_email_input->clear();
                return;
            }
        }
        if (sign_name.isEmpty() || sign_email.isEmpty() || sign_password.isEmpty()) {
            QMessageBox::warning(this, "Login", "Name, Email and password cannot be empty");
        }
        else
        {



        QSqlQuery q2;
        q2.exec("INSERT INTO Sign_info (name,contact,email,password) VALUES('"+sign_name+"','"+sign_contact+"','"+ sign_email+"','"+sign_password+"') ");
        QMessageBox::information(this, "Sign Up","Sign Up Successfully");
        ui->sign_name_input->clear();
        ui->sign_contact_input->clear();
        ui->sign_password_input->clear();
        ui->sign_email_input->clear();
        //ui->stackedWidget->setCurrentIndex(1);
        }
    }
    else if(comboBox_select=="RIDER")
    {

        //if the email is available or not;
        QSqlQuery checkQuery;
        checkQuery.exec("SELECT * FROM Sign_ride_info WHERE email='"+sign_email+"'");
        {
            if (checkQuery.next()) {
                QMessageBox::warning(this, "Sign Up", "This  email already exists.");
                ui->sign_name_input->clear();
                ui->sign_contact_input->clear();
                ui->sign_password_input->clear();
                ui->sign_email_input->clear();
                return;
            }
        }
        if (sign_name.isEmpty() || sign_email.isEmpty() || sign_password.isEmpty()) {
            QMessageBox::warning(this, "Login", "Name, Email and password cannot be empty");
        }

        else
        {


        QSqlQuery q2;
        q2.exec("INSERT INTO Sign_ride_info (name,contact,email,password) VALUES('"+sign_name+"','"+sign_contact+"','"+ sign_email+"','"+sign_password+"') ");
        QMessageBox::information(this, "Sign Up","Sign Up Successfully");
        ui->sign_name_input->clear();
        ui->sign_contact_input->clear();
        ui->sign_password_input->clear();
        ui->sign_email_input->clear();
        //ui->stackedWidget->setCurrentIndex(1);
        }
    }


}





void MainWindow::on_sign_in_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}





void MainWindow::on_Log_in_btn_clicked()
{
    login_username = ui->email_input->text();
    login_password = ui->password_input->text();

    if (login_username.isEmpty() || login_password.isEmpty()) {
        QMessageBox::warning(this, "Login", "Email and password cannot be empty");
        return; // Exit the method if the inputs are empty
    }

    QString comboBox_select1 = ui->select_member_comboBox_2->currentText();
    qDebug() << comboBox_select1;

    if(comboBox_select1 == "USER"){
        QSqlQuery query1;
        query1.prepare("SELECT * FROM Sign_info WHERE email = :email AND password = :password");
        query1.bindValue(":email", login_username);
        query1.bindValue(":password", login_password);

        if(!query1.exec()){
            qDebug() << "Query execution error: " << query1.lastError().text();
            QMessageBox::warning(this, "Database Error", "Failed to execute the query.");
            return;
        }

        if(query1.next()){
            QMessageBox::information(this, "Log In", "Successfully Logged In");
            ui->stackedWidget->setCurrentIndex(12);

            //show owner profile....
            ui->acc_name_label->setText(query1.value(0).toString());
            ui->acc_email_label->setText(query1.value(2).toString());
            ui->acc_contact_label->setText(query1.value(1).toString());

        } else {
            QMessageBox::warning(this, "Login failed", "Wrong User & Password!!");
        }
    }
    //
    else if(comboBox_select1 == "ADMIN"){
        //login_username = ui->customer_email_input->text();
        //login_password = ui->customer_password_input->text();
        // qDebug() << login_username;

        //matching owner login and password;
        QSqlQuery query12;
        query12.exec("SELECT * FROM admin WHERE email = '"+login_username+"' AND password = '"+login_password+"'");

        if(query12.next()){
            //if match then go to owner profile page.
            ui->stackedWidget->setCurrentIndex(6);

            //show owner profile....
            //ui->customer_name->setText(query12.value(0).toString());
            // ui->display_email_show->setText(query.value(1).toString());
            //ui->display_contact_show->setText(query.value(3).toString());
        }
        else{
            //else show e wrong message.
            QMessageBox::warning(this,"Login failed","Wrong User & Password!!");
        }

        //for clear display data .....
        //ui->customer_email_input->clear();
       // ui->customer_password_input->clear();
    }

    //
    else if(comboBox_select1 == "RIDER"){
        QSqlQuery query1;
        query1.prepare("SELECT * FROM Sign_ride_info WHERE email = :email AND password = :password");
        query1.bindValue(":email", login_username);
        query1.bindValue(":password", login_password);

        if(!query1.exec()){
            qDebug() << "Query execution error: " << query1.lastError().text();
            QMessageBox::warning(this, "Database Error", "Failed to execute the query.");
            return;
        }

        if(query1.next()){
            QMessageBox::information(this, "Log In", "Successfully Logged In");
            ui->stackedWidget->setCurrentIndex(7);

            ui->rider_name_label->setText(query1.value(0).toString());
            ui->rider_email_label->setText(query1.value(2).toString());
            ui->rider_contact_label->setText(query1.value(1).toString());

        } else {
            QMessageBox::warning(this, "Login failed", "Wrong User & Password!!");
        }
    }

    ui->email_input->clear();
    ui->password_input->clear();
}


void MainWindow::all_vertex_connected_line()
{
    QLabel *lineLabel = new QLabel(ui->centralwidget);
    lineLabel->setAttribute(Qt::WA_TransparentForMouseEvents); // Allow mouse events to pass through
    lineLabel->setGeometry(ui->centralwidget->rect());

    // Create a new QPixmap for drawing the lines
    QPixmap pixmap(lineLabel->size());
    pixmap.fill(Qt::transparent);

    // Prepare QPainter for drawing lines
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen(Qt::yellow, 5); // Yellow line for all edges
    painter.setPen(pen);

    // Load edges from the database and draw them with distances
    QSqlQuery query("SELECT edge_f, edge_t, edge_d FROM user");
    while (query.next()) {
        QString edge_f = query.value(0).toString();
        QString edge_t = query.value(1).toString();
        int distance = query.value(2).toInt(); // Distance from the database

        QPoint fromPoint, toPoint;

        QRect rectA = ui->a->geometry();
        QRect rectB = ui->b->geometry();
        QRect rectC = ui->c->geometry();
        QRect rectD = ui->d->geometry();
        QRect rectE = ui->e->geometry();
        QRect rectF = ui->f->geometry();
        QRect rectG = ui->g->geometry();
        QRect rectH = ui->h->geometry();
        QRect rectI = ui->i->geometry();

        // Determine the from and to points based on vertex labels
        if (edge_f == "A") fromPoint = rectA.center();
        else if (edge_f == "B") fromPoint = rectB.center();
        else if (edge_f == "C") fromPoint = rectC.center();
        else if (edge_f == "D") fromPoint = rectD.center();
        else if (edge_f == "E") fromPoint = rectE.center();
        else if (edge_f == "F") fromPoint = rectF.center();
        else if (edge_f == "G") fromPoint = rectG.center();
        else if (edge_f == "H") fromPoint = rectH.center();
        else if (edge_f == "I") fromPoint = rectI.center();

        if (edge_t == "A") toPoint = rectA.center();
        else if (edge_t == "B") toPoint = rectB.center();
        else if (edge_t == "C") toPoint = rectC.center();
        else if (edge_t == "D") toPoint = rectD.center();
        else if (edge_t == "E") toPoint = rectE.center();
        else if (edge_t == "F") toPoint = rectF.center();
        else if (edge_t == "G") toPoint = rectG.center();
        else if (edge_t == "H") toPoint = rectH.center();
        else if (edge_t == "I") toPoint = rectI.center();

        // Draw the line between the two points
        painter.drawLine(fromPoint, toPoint);

        // Calculate the midpoint for placing the distance label
        QPoint midPoint = (fromPoint + toPoint) / 2;

        // Create a label for the distance and set its properties
        QLabel *distanceLabel = new QLabel(ui->centralwidget);
        distanceLabel->setText(QString::number(distance) + " KM");
        distanceLabel->setStyleSheet("color: red; background-color: white; border: 1px solid black;");
        distanceLabel->move(midPoint);
        distanceLabel->adjustSize();
        distanceLabel->setAttribute(Qt::WA_TransparentForMouseEvents); // Allow mouse events to pass through
        distanceLabel->show();
    }

    painter.end();
    lineLabel->setPixmap(pixmap);
    lineLabel->show();

    // Create a QTimer to hide and delete the label and distance labels after a set time
    QTimer::singleShot(10000, [lineLabel]() {
        lineLabel->hide();
        lineLabel->deleteLater();
    });

    // Additional cleanup for distance labels
    QTimer::singleShot(10000, [this]() {
        QList<QLabel *> labels = ui->centralwidget->findChildren<QLabel *>();
        for (QLabel *label : labels) {
            if (label->styleSheet().contains("color: red;")) {
                label->hide();
                label->deleteLater();
            }
        }
    });

}


void MainWindow::on_ride_btn_clicked()
{
    Flag=0;
    ui->stackedWidget->setCurrentIndex(2);
    all_vertex_connected_line();

}


void MainWindow::on_find_btn_clicked()
{


    QString from = ui->lineEdit_from->text();
    QString to = ui->lineEdit_to->text();

    if (from.isEmpty() || to.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setStyleSheet("QLabel{ color: white; }"
                             "QMessageBox{ background-color: black; }");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Please enter both 'from' and 'to' places.");
        msgBox.exec();
        return;
    }

    // Clear previous graph edges
    graph.clearEdges();

    // Load edges from database
    QSqlQuery query("SELECT edge_f, edge_t, edge_d FROM user");
    while (query.next()) {
        QString edge_f = query.value(0).toString();
        QString edge_t = query.value(1).toString();
        int edge_d = query.value(2).toInt();
        graph.addEdge(edge_f.toStdString(), edge_t.toStdString(), edge_d);
    }

    std::string fromPlace = from.toStdString();
    std::string toPlace = to.toStdString();

    std::vector<std::string> path;
    int totalDistance = graph.shortestPath(fromPlace, toPlace, path);

    if (totalDistance == -1 || path.empty()) {
        QMessageBox msgBox;
        msgBox.setStyleSheet("QLabel{ color: white; }"
                             "QMessageBox{ background-color: black; }");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("No path found from '" + from + "' to '" + to + "'.");
        msgBox.exec();

        // Clear the labels if no path is found
        ui->label_path->clear();
        ui->label_distance->clear();
        ui->label_cost->clear();
        ui->label_discount->clear();
        ui->label_offer_price->clear();

        // Clear animations if no path found
        clearAnimations();

    } else {
        ui->stackedWidget->setCurrentIndex(3);
        QString pathString;
        for (const auto& place : path) {
            pathString += QString::fromStdString(place) + " ";
        }

        ui->label_path->setText(" '" + from + "' to '" + to + "' is: " + pathString);
        ui->label_distance->setText("Total distance: " + QString::number(totalDistance) + " KM");

        // Calculate cost, discount, and offer price
        double cost = totalDistance * 30.0; // Assuming cost is equal to distance
        double discount = cost * 0.5;
        double offerPrice = cost - discount;

        ui->label_cost->setText("Cost: " + QString::number(cost) + " TK");
        ui->label_discount->setText("Discount: " + QString::number(discount) + " TK");
        ui->label_offer_price->setText("Offer price: " + QString::number(offerPrice) + " TK");

        // Clear animations before setting up new ones
        clearAnimations();

        // Set up new animations
        setupAnimations(path);
    }


}

void MainWindow::clearAnimations()
{
    if (b1) delete b1;
    if (b2) delete b2;
    if (b3) delete b3;
    if (b4) delete b4;
    if (b5) delete b5;
    if (b6) delete b6;
    if (b7) delete b7;
    if (b8) delete b8;
    if (b9) delete b9;
}


void MainWindow::setupAnimations(const std::vector<std::string>& path)
{

    if (lineLabel) {
        lineLabel->hide();
        lineLabel->deleteLater();
        lineLabel = nullptr; // Reset pointer to nullptr after deletion
    }

    QRect rectA = ui->a->geometry();
    QRect rectB = ui->b->geometry();
    QRect rectC = ui->c->geometry();
    QRect rectD = ui->d->geometry();
    QRect rectE = ui->e->geometry();
    QRect rectF = ui->f->geometry();
    QRect rectG = ui->g->geometry();
    QRect rectH = ui->h->geometry();
    QRect rectI = ui->i->geometry();

    // Create a new QPixmap for drawing the line
    QPixmap pixmap(ui->centralwidget->size());
    pixmap.fill(Qt::transparent);

    // Draw the line
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen(Qt::blue, 5);
    painter.setPen(pen);

    // Draw the shortest path line
    if (path.size() >= 2) {
        for (size_t i = 0; i < path.size() - 1; ++i) {
            std::string fromPlace = path[i];
            std::string toPlace = path[i + 1];

            QPoint fromPoint, toPoint;

            if (fromPlace == "A") fromPoint = rectA.center();
            else if (fromPlace == "B") fromPoint = rectB.center();
            else if (fromPlace == "C") fromPoint = rectC.center();
            else if (fromPlace == "D") fromPoint = rectD.center();
            else if (fromPlace == "E") fromPoint = rectE.center();
            else if (fromPlace == "F") fromPoint = rectF.center();
            else if (fromPlace == "G") fromPoint = rectG.center();
            else if (fromPlace == "H") fromPoint = rectH.center();
            else if (fromPlace == "I") fromPoint = rectI.center();

            if (toPlace == "A") toPoint = rectA.center();
            else if (toPlace == "B") toPoint = rectB.center();
            else if (toPlace == "C") toPoint = rectC.center();
            else if (toPlace == "D") toPoint = rectD.center();
            else if (toPlace == "E") toPoint = rectE.center();
            else if (toPlace == "F") toPoint = rectF.center();
            else if (toPlace == "G") toPoint = rectG.center();
            else if (toPlace == "H") toPoint = rectH.center();
            else if (toPlace == "I") toPoint = rectI.center();

            painter.drawLine(fromPoint, toPoint);
        }
    }

    painter.end();

    // Create a new QLabel to display the line
    lineLabel = new QLabel(ui->centralwidget);
    lineLabel->setPixmap(pixmap);
    lineLabel->setAttribute(Qt::WA_TransparentForMouseEvents); // Allow mouse events to pass through
    lineLabel->show();

    qDebug() << "Setting up animations with path:" << QString::fromStdString(path[0]);

    if (path.size() >= 2) {
        QSequentialAnimationGroup *animationGroup = new QSequentialAnimationGroup(this);

        for (size_t i = 0; i < path.size() - 1; ++i) {
            std::string fromPlace = path[i];
            std::string toPlace = path[i + 1];

            QRect startRect, endRect;

            if (fromPlace == "A") startRect = rectA;
            else if (fromPlace == "B") startRect = rectB;
            else if (fromPlace == "C") startRect = rectC;
            else if (fromPlace == "D") startRect = rectD;
            else if (fromPlace == "E") startRect = rectE;
            else if (fromPlace == "F") startRect = rectF;
            else if (fromPlace == "G") startRect = rectG;
            else if (fromPlace == "H") startRect = rectH;
            else if (fromPlace == "I") startRect = rectI;

            if (toPlace == "A") endRect = rectA;
            else if (toPlace == "B") endRect = rectB;
            else if (toPlace == "C") endRect = rectC;
            else if (toPlace == "D") endRect = rectD;
            else if (toPlace == "E") endRect = rectE;
            else if (toPlace == "F") endRect = rectF;
            else if (toPlace == "G") endRect = rectG;
            else if (toPlace == "H") endRect = rectH;
            else if (toPlace == "I") endRect = rectI;

            QPropertyAnimation* anim = new QPropertyAnimation(ui->roadanimation, "geometry");
            anim->setDuration(3000); // Adjust duration if needed
            anim->setStartValue(startRect);
            anim->setEndValue(endRect);

            // Add animation to the animation group
            animationGroup->addAnimation(anim);
        }

        // Start the animation
        animationGroup->start();
        qDebug() << "Animation started.";

        // Set up a QTimer to hide the line and navigate after 8 seconds
        QTimer::singleShot(8000, this, [=]() {
            qDebug() << "Hiding the line and navigating to another page...";
            if (lineLabel) {
                lineLabel->hide();
                lineLabel->deleteLater();
                lineLabel = nullptr; // Reset pointer to nullptr after deletion
            }
            // ui->stackedWidget->setCurrentIndex(0);  // Uncomment and replace with the correct index
        });
    }


    /*if (lineLabel) {
        lineLabel->hide();
        lineLabel->deleteLater();
        lineLabel = nullptr; // Reset pointer to nullptr after deletion
    }

    QRect rectA = ui->a->geometry();
    QRect rectB = ui->b->geometry();
    QRect rectC = ui->c->geometry();
    QRect rectD = ui->d->geometry();
    QRect rectE = ui->e->geometry();
    QRect rectF = ui->f->geometry();
    QRect rectG = ui->g->geometry();
    QRect rectH = ui->h->geometry();
    QRect rectI = ui->i->geometry();

    // Create a new QPixmap for drawing the line
    QPixmap pixmap(ui->centralwidget->size());
    pixmap.fill(Qt::transparent);

    // Draw the line
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen(Qt::blue, 5);
    painter.setPen(pen);

    // Draw the shortest path line
    if (path.size() >= 2) {
        for (size_t i = 0; i < path.size() - 1; ++i) {
            std::string fromPlace = path[i];
            std::string toPlace = path[i + 1];

            QPoint fromPoint, toPoint;

            if (fromPlace == "A") fromPoint = rectA.center();
            else if (fromPlace == "B") fromPoint = rectB.center();
            else if (fromPlace == "C") fromPoint = rectC.center();
            else if (fromPlace == "D") fromPoint = rectD.center();
            else if (fromPlace == "E") fromPoint = rectE.center();
            else if (fromPlace == "F") fromPoint = rectF.center();
            else if (fromPlace == "G") fromPoint = rectG.center();
            else if (fromPlace == "H") fromPoint = rectH.center();
            else if (fromPlace == "I") fromPoint = rectI.center();

            if (toPlace == "A") toPoint = rectA.center();
            else if (toPlace == "B") toPoint = rectB.center();
            else if (toPlace == "C") toPoint = rectC.center();
            else if (toPlace == "D") toPoint = rectD.center();
            else if (toPlace == "E") toPoint = rectE.center();
            else if (toPlace == "F") toPoint = rectF.center();
            else if (toPlace == "G") toPoint = rectG.center();
            else if (toPlace == "H") toPoint = rectH.center();
            else if (toPlace == "I") toPoint = rectI.center();

            painter.drawLine(fromPoint, toPoint);
        }
    }

    painter.end();

    // Create a new QLabel to display the line
    lineLabel = new QLabel(ui->centralwidget);
    lineLabel->setPixmap(pixmap);
    lineLabel->show();

    qDebug() << "Setting up animations with path:" << QString::fromStdString(path[0]);

    if (path.size() >= 2) {
        QSequentialAnimationGroup *animationGroup = new QSequentialAnimationGroup(this);

        for (size_t i = 0; i < path.size() - 1; ++i) {
            std::string fromPlace = path[i];
            std::string toPlace = path[i + 1];

            QRect startRect, endRect;

            if (fromPlace == "A") startRect = rectA;
            else if (fromPlace == "B") startRect = rectB;
            else if (fromPlace == "C") startRect = rectC;
            else if (fromPlace == "D") startRect = rectD;
            else if (fromPlace == "E") startRect = rectE;
            else if (fromPlace == "F") startRect = rectF;
            else if (fromPlace == "G") startRect = rectG;
            else if (fromPlace == "H") startRect = rectH;
            else if (fromPlace == "I") startRect = rectI;

            if (toPlace == "A") endRect = rectA;
            else if (toPlace == "B") endRect = rectB;
            else if (toPlace == "C") endRect = rectC;
            else if (toPlace == "D") endRect = rectD;
            else if (toPlace == "E") endRect = rectE;
            else if (toPlace == "F") endRect = rectF;
            else if (toPlace == "G") endRect = rectG;
            else if (toPlace == "H") endRect = rectH;
            else if (toPlace == "I") endRect = rectI;

            QPropertyAnimation* anim = new QPropertyAnimation(ui->roadanimation, "geometry");
            anim->setDuration(3000); // Extend duration to 10 seconds
            anim->setStartValue(startRect);
            anim->setEndValue(endRect);

            // Add animation to the animation group
            animationGroup->addAnimation(anim);
        }

        // Start the animation
        animationGroup->start();
        qDebug() << "Animation started.";

        // Set up a QTimer to hide the line and navigate after 10 seconds
        QTimer::singleShot(8000, this, [=]() {
            qDebug() << "Hiding the line and navigating to another page...";
            if (lineLabel) {
                lineLabel->hide();
                lineLabel->deleteLater();
                lineLabel = nullptr; // Reset pointer to nullptr after deletion
            }
            //ui->stackedWidget->setCurrentIndex(0);  // Replace 0 with the index of your target page
        });
    }*/


}
//Admin road add
void MainWindow::on_Save_btn_clicked()
{
    QString edge_f = ui->lineEdit_edge_from->text();
    QString edge_t = ui->lineEdit_edge_to->text();
    QString edge_d = ui->lineEdit_edge_distance->text();

    if (edge_f.isEmpty() || edge_t.isEmpty() || edge_d.isEmpty()) {
        QMessageBox msgBox;
        msgBox.setStyleSheet("QLabel{ color: white; }"
                             "QMessageBox{ background-color: black; }");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Please fill all fields: from, to, and distance.");
        msgBox.exec();
        return;
    }

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM user WHERE edge_f = :edge_f AND edge_t = :edge_t");
    checkQuery.bindValue(":edge_f", edge_f);
    checkQuery.bindValue(":edge_t", edge_t);

    if (!checkQuery.exec()) {
        QMessageBox msgBox;
        msgBox.setStyleSheet("QLabel{ color: white; }"
                             "QMessageBox{ background-color: black; }");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Error checking road existence: " + checkQuery.lastError().text());
        msgBox.exec();
        return;
    }

    checkQuery.next();
    if (checkQuery.value(0).toInt() > 0) {
        QMessageBox msgBox;
        msgBox.setStyleSheet("QLabel{ color: white; }"
                             "QMessageBox{ background-color: black; }");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Road already exists.");
        msgBox.exec();
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO user (edge_f, edge_t, edge_d) VALUES (:edge_f, :edge_t, :edge_d)");
    query.bindValue(":edge_f", edge_f);
    query.bindValue(":edge_t", edge_t);
    query.bindValue(":edge_d", edge_d.toInt());

    if (!query.exec()) {
        QMessageBox msgBox;
        msgBox.setStyleSheet("QLabel{ color: white; }"
                             "QMessageBox{ background-color: black; }");
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("Error adding road: " + query.lastError().text());
        msgBox.exec();
    } else {
        QMessageBox msgBox;
        msgBox.setStyleSheet("QLabel{ color: white; }"
                             "QMessageBox{ background-color: black; }");
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setText("Road added successfully.");
        msgBox.exec();

        ui->lineEdit_edge_from->clear();
        ui->lineEdit_edge_to->clear();
        ui->lineEdit_edge_distance->clear();

        // Add edge to the graph
        graph.addEdge(edge_f.toStdString(), edge_t.toStdString(), edge_d.toInt());
    }
}


void MainWindow::on_account_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_delivery_btn_clicked()
{
    Flag=1;
    ui->stackedWidget->setCurrentIndex(2);
    all_vertex_connected_line();
}


void MainWindow::on_confirm_btn_clicked()
{
    QString path = ui->label_path->text();
    QString distance = ui->label_distance->text();
    QString offerPrice = ui->label_offer_price->text();
    QString confirm = "Pending";
    QString email=ui->acc_email_label->text();
    QString contact=ui->acc_contact_label->text();

    QSqlQuery query;
    QSqlQuery query8;

    if (Flag == 0)
    {
        // Prepare and bind the first query for customer_history table
        query.prepare("INSERT INTO customer_history (path, distance, offer_price,email,contact) "
                      "VALUES (:path, :distance, :offerPrice, :email, :contact)");
        query.bindValue(":path", path);
        query.bindValue(":distance", distance);
        query.bindValue(":offerPrice", offerPrice);
        query.bindValue(":email", email);
        query.bindValue(":contact", contact);

        // Execute the first query and check for errors
        if (!query.exec()) {
            qDebug() << "Error executing query:" << query.lastError().text();
            QMessageBox::critical(this, "Database Error", "Failed to insert data into customer_history table.");
            return;
        }

        // Prepare and execute the second query for ride_request_info table
        query8.prepare("INSERT INTO ride_request_info (path, distance, offer_price, confirm,email,contact) "
                       "VALUES (:path, :distance, :offerPrice, :confirm, :email, :contact)");
        query8.bindValue(":path", path);
        query8.bindValue(":distance", distance);
        query8.bindValue(":offerPrice", offerPrice);
        query8.bindValue(":confirm", confirm);
        query8.bindValue(":email", email);
        query8.bindValue(":contact", contact);

        // Execute the second query and check for errors
        if (!query8.exec()) {
            qDebug() << "Error executing query8:" << query8.lastError().text();
            QMessageBox::critical(this, "Database Error", "Failed to insert data into ride_request_info table.");
            return;
        }
    }
    else
    {
        // Prepare and bind the first query for customer_delivery table
        query.prepare("INSERT INTO customer_delivery (path, distance, offer_price,email,contact) "
                      "VALUES (:path, :distance, :offerPrice, :email, :contact)");
        query.bindValue(":path", path);
        query.bindValue(":distance", distance);
        query.bindValue(":offerPrice", offerPrice);
        query.bindValue(":email", email);
        query.bindValue(":contact", contact);

        // Execute the first query and check for errors
        if (!query.exec()) {
            qDebug() << "Error executing query:" << query.lastError().text();
            QMessageBox::critical(this, "Database Error", "Failed to insert data into customer_delivery table.");
            return;
        }

        // Prepare and execute the second query for delivery_request_info table
        query8.prepare("INSERT INTO delivery_request_info (path, distance, offer_price, confirm,email,contact) "
                       "VALUES (:path, :distance, :offerPrice, :confirm, :email, :contact)");
        query8.bindValue(":path", path);
        query8.bindValue(":distance", distance);
        query8.bindValue(":offerPrice", offerPrice);
        query8.bindValue(":confirm", confirm);
        query8.bindValue(":email", email);
        query8.bindValue(":contact", contact);
        // Execute the second query and check for errors
        if (!query8.exec()) {
            qDebug() << "Error executing query8:" << query8.lastError().text();
            QMessageBox::critical(this, "Database Error", "Failed to insert data into delivery_request_info table.");
            return;
        }
    }

    // If everything is successful, show success message
    QMessageBox::information(this, "Success", "Data inserted into tables successfully.");
}




void MainWindow::on_history_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);


}


void MainWindow::on_cus_his_btn_clicked()
{
    QString email = ui->acc_email_label->text();
    QString comboBox_select = ui->comboBox_for_cus_history->currentText();

    if(comboBox_select == "Ride"){
        QSqlQuery query;
        query.prepare("SELECT path, distance, offer_price, confirm FROM ride_request_info WHERE email = :email");
        query.bindValue(":email", email);
        query.exec();



        QSqlQueryModel *modal = new QSqlQueryModel(ui->tableView_for_cus_history);
        modal->setQuery(query);
        modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Path"));
        modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Distance"));
        modal->setHeaderData(2, Qt::Horizontal, QObject::tr("Price"));
        modal->setHeaderData(3, Qt::Horizontal, QObject::tr("Status"));

        ui->tableView_for_cus_history->setModel(modal);


    }


    if(comboBox_select == "Delivery"){
        QSqlQuery query;
        query.prepare("SELECT path, distance, offer_price, confirm FROM delivery_request_info WHERE email = :email");
        query.bindValue(":email", email);
        query.exec();



        QSqlQueryModel *modal = new QSqlQueryModel(ui->tableView_for_cus_history);
        modal->setQuery(query);
        modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Path"));
        modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Distance"));
        modal->setHeaderData(2, Qt::Horizontal, QObject::tr("Price"));
        modal->setHeaderData(3, Qt::Horizontal, QObject::tr("Status"));

        ui->tableView_for_cus_history->setModel(modal);


    }


}


void MainWindow::on_ride_request_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);

}


void MainWindow::on_delivery_req_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);

}


void MainWindow::on_load_btn_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel (ui->tableView_delivery_request);
    modal-> setQuery(QString ("select email,contact,path,distance,offer_price,confirm from delivery_request_info "));
    modal->setHeaderData(2, Qt::Horizontal, QObject::tr("Path"));
    modal->setHeaderData(3, Qt::Horizontal, QObject::tr("Distance"));
    modal->setHeaderData(4, Qt::Horizontal, QObject::tr("Price"));
    modal->setHeaderData(5, Qt::Horizontal, QObject::tr("Confirm"));
    modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Email"));
    modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Contact"));

    ui->tableView_delivery_request-> setModel(modal);
}


void MainWindow::on_load_btn_2_clicked()
{
    QSqlQueryModel * modal = new QSqlQueryModel (ui->tableView_ride_request);
    modal-> setQuery(QString ("select email,contact,path,distance,offer_price,confirm from ride_request_info "));
    modal->setHeaderData(2, Qt::Horizontal, QObject::tr("Path"));
    modal->setHeaderData(3, Qt::Horizontal, QObject::tr("Distance"));
    modal->setHeaderData(4, Qt::Horizontal, QObject::tr("Price"));
    modal->setHeaderData(5, Qt::Horizontal, QObject::tr("Confirm"));
    modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Email"));
    modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Contact"));

    ui->tableView_ride_request-> setModel(modal);
}


void MainWindow::on_ride_confirm_btn_clicked()
{
    QString rider_email = ui->rider_email_label->text();
    QString email = ui->ride_serial_email_label->text();
    QString update_thing = "Accepted";

    QSqlQuery query18;
    query18.prepare("UPDATE ride_request_info SET confirm = :update_thing, rider = :rider_email WHERE email = :email");
    query18.bindValue(":update_thing", update_thing);
    query18.bindValue(":email", email);
    query18.bindValue(":rider_email", rider_email);

    if(query18.exec()){
        QMessageBox::information(this, "Update Info", "Updated Successfully");
    } else {
        QMessageBox::warning(this, "Update Info", "Update Failed: " + query18.lastError().text());
    }
}




void MainWindow::on_Home_btn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_Home_btn_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_pushButton_4_clicked()
{
     ui->stackedWidget->setCurrentIndex(13);
}


void MainWindow::on_find_btn_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QLabel{ color: white; }"
                         "QMessageBox{ background-color: black; }");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setText("Enter Again.");
    msgBox.exec();

    ui->lineEdit_from->clear();
    ui->lineEdit_to->clear();
}


void MainWindow::on_pushButton_8_clicked()
{
     ui->stackedWidget->setCurrentIndex(12);
}


void MainWindow::on_Home_btn_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_roadanimation_clicked()
{

}


void MainWindow::on_Home_btn_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_delivery_confirm_req_btn_clicked()
{
    QString rider_email = ui->rider_email_label->text();
    QString email = ui->delivery_serial_email_line_edit->text();
    QString update_thing = "Accepted";

    QSqlQuery query18;
    query18.prepare("UPDATE delivery_request_info SET confirm = :update_thing, rider = :rider_email WHERE email = :email");
    query18.bindValue(":update_thing", update_thing);
    query18.bindValue(":email", email);
    query18.bindValue(":rider_email", rider_email);

    if(query18.exec()){
        QMessageBox::information(this, "Update Info", "Updated Successfully");
    } else {
        QMessageBox::warning(this, "Update Info", "Update Failed: " + query18.lastError().text());
    }
}


void MainWindow::on_rider_acc_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_rider_his_load_btn_clicked()
{
    QString rider_email = ui->rider_email_label->text();
    QString comboBox_select = ui->comboBox_for_rider_history->currentText();

    if(comboBox_select == "Ride"){
        QSqlQuery query;
        query.prepare("SELECT path, distance, offer_price FROM ride_request_info WHERE rider = :rider_email");
        query.bindValue(":rider_email", rider_email);
        query.exec();



        QSqlQueryModel *modal = new QSqlQueryModel(ui->tableView_for_rider_history);
        modal->setQuery(query);
        modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Path"));
        modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Distance"));
        modal->setHeaderData(2, Qt::Horizontal, QObject::tr("Price"));

        ui->tableView_for_rider_history->setModel(modal);


    }


    if(comboBox_select == "Delivery"){
        QSqlQuery query;
        query.prepare("SELECT path, distance, offer_price FROM delivery_request_info WHERE rider = :rider_email");
        query.bindValue(":rider_email", rider_email);
        query.exec();



        QSqlQueryModel *modal = new QSqlQueryModel(ui->tableView_for_rider_history);
        modal->setQuery(query);
        modal->setHeaderData(0, Qt::Horizontal, QObject::tr("Path"));
        modal->setHeaderData(1, Qt::Horizontal, QObject::tr("Distance"));
        modal->setHeaderData(2, Qt::Horizontal, QObject::tr("Price"));

        ui->tableView_for_rider_history->setModel(modal);



    }
}


void MainWindow::on_rider_his_btn_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}


void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}


void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_18_clicked()
{
     ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_pushButton_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_pushButton_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}


void MainWindow::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}


void MainWindow::on_pushButton_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_pushButton_25_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}


void MainWindow::on_pushButton_26_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}


void MainWindow::on_pushButton_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_27_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}


void MainWindow::on_pushButton_29_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}


void MainWindow::on_pushButton_30_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_pushButton_32_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_31_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_9_clicked()
{

}


void MainWindow::on_Home_btn_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_Home_btn_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_Home_btn_8_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_ride_btn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}


void MainWindow::on_delivery_btn_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(9);
}


void MainWindow::on_account_btn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}


void MainWindow::on_history_btn_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);

}


void MainWindow::on_Home_btn_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_Home_btn_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_Home_btn_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_Home_btn_12_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_Home_btn_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

