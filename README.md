# 🚖 **EAZYTRIP** - Ride & Delivery Management System  

Welcome to **EAZYTRIP**, an advanced **Ride and Delivery Service Management System** built to provide efficient solutions for booking rides, managing deliveries, and optimizing routes. Designed with a user-friendly interface, EAZYTRIP simplifies transport logistics by integrating shortest path algorithms and customizable maps for seamless navigation.  

This project was developed using the **Qt Framework** and **SQLite Database** as part of the **3rd Semester Data Structures Course** at **International Islamic University Chittagong (IIUC)**.  

---

## 👥 **Developed By**
- **Mohammed Hasan** (Team Leader & Lead Developer)  
- **Shanjid Mahammad**  
- **Prasenjit Chowdhury**  

### 🎓 **Institution**  
- **International Islamic University Chittagong (IIUC)**  
- Project for the **Data Structures and Algorithms Course**  

---

## 🌟 **Key Features**
### 🚘 **Ride & Delivery Services**  
- Effortlessly book rides or manage delivery services.  
- Shortest path algorithms ensure efficient routes for all services.  

### 🗺️ **Interactive Map**  
- Customizable map integration to visualize and optimize navigation.  
- Real-time updates on routes and destinations.  

### 🔄 **Dynamic Data Management**  
- Database integration using **SQLite** to securely store ride and delivery details.  
- Fast data retrieval and modification capabilities.  

### 📊 **User-Friendly Interface**  
- Intuitive and simple design for an enhanced user experience.  
- Well-organized navigation and visually appealing components.  

### 🔐 **Security Features**  
- Role-based access for different user categories.  
- Secure data handling for sensitive transport-related operations.  

---

## 🛠️ **Technologies Used**

| Component        | Details                      |  
|-------------------|------------------------------|  
| **Programming**   | C++                          |  
| **Frontend**      | Qt Framework                 |  
| **Database**      | SQLite                       |  
| **Algorithms**    | Shortest Path Algorithms     |  

---

## 🚀 **Installation & Setup Guide**

### 📌 **Prerequisites**  
Make sure the following software is installed on your system:  
#### **1. Qt Framework**  
   - Download: [Qt Official Site](https://www.qt.io/download)  
#### **2. SQLite Database**  
   - Download: [SQLite Official Site](https://www.sqlite.org/download.html)  

---

### 🛠 **Steps to Run the Project**

#### **1. Extract Project Files**  
   - Extract the project archive `EasyTrip_DS_Project.zip`.  

#### **2. Open in Qt Creator**  
   - Locate the `EasyTrip.pro` file in the extracted folder.  
   - Open it using **Qt Creator**.  

#### **3. Configure the Database Path**  
   - Open the `mainwindow.cpp` file.  
   - Locate the database connection code. Update the file path for `Eazy.db` to match the location of your database file.  

   Example:  
   ```cpp
   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName("C:/path-to-your-database/Eazy.db");
   ```  

#### **4. Build the Project**  
   - Use Qt Creator's build tools to compile the project.  

#### **5. Run the Application**  
   - After a successful build, run the application.  

---

## 📋 **Project Features Overview**

### **Modules**
- **Booking Module:** Allows users to book rides and deliveries.  
- **Route Optimization Module:** Uses shortest path algorithms for efficient navigation.  
- **Admin Panel:** Manage all rides, deliveries, and user details.  

### **Pages**
- **Home Page:** A welcoming dashboard summarizing key application features.  
- **Ride Management Page:** Manage ride bookings, including adding and canceling rides.  
- **Delivery Management Page:** Oversee delivery requests, including scheduling and tracking.  
- **Analytics Dashboard:** View performance insights, ride statistics, and route efficiency.  

---

## 🛡️ **Troubleshooting**

| **Issue**                         | **Solution**                                                                 |  
|------------------------------------|-------------------------------------------------------------------------------|  
| Database connection issues         | Ensure `Eazy.db` path is correct in `mainwindow.cpp`.                         |  
| Compilation errors in Qt Creator   | Clean the build and rebuild the project. Ensure Qt and SQLite are properly configured. |  
| Application crashes on startup     | Check all file paths and ensure `Eazy.db` exists in the specified location.   |  

---

## 📈 **Project Highlights**

#### 1. **Efficient Algorithms:**  
   - Advanced data structures and algorithms ensure optimal routing and scheduling.  

#### 2. **Custom Map Integration:**  
   - Provides interactive and customizable map views for improved navigation.  

#### 3. **Scalability:**  
   - The architecture supports future enhancements, including real-time GPS tracking and payment gateway integration.  

#### 4. **Data Security:**  
   - Secure SQLite integration ensures reliable data storage and retrieval.  

---

## 🔍 **Future Enhancements**

- **Real-Time GPS Integration**: Enable live tracking for rides and deliveries.  
- **Payment Gateway**: Add secure online payment options for services.  
- **Push Notifications**: Notify users about bookings, cancellations, and status updates.  
- **Multilingual Support**: Expand the app's usability by supporting multiple languages.  

---

## 📧 **Support**  

For any queries, issues, or feedback, feel free to reach out:  
📩 **Email:** mohammedhasan.contact@gmail.com  

We are excited to share **EAZYTRIP** with you and look forward to hearing your feedback! 😊  

---  

**Enjoy your journey with EAZYTRIP – Making Rides and Deliveries Effortless! 🚖**  
