#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QStackedLayout>
#include <QDebug>

#include "admin.h"
#include "manager.h"
#include "databasemanger.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

    void connectToDB();
    //!< Creates and opens database connection if not open

private slots:

    void on_loginManagerButton_clicked();
    //!< On valid username/password for manager, open manager window
    /*!< Checks if database is already open */

    void on_loginAdminButton_clicked();
    //!< On valid username/password for admin, open admin window
    /*!< Checks if database is already open */

    void on_exitProgramButton_clicked();
    //!< Closes database and program when exit button is clicked

    void on_usernameLineEdit_textEdited(const QString &arg1);

    void on_passwordLineEdit_textEdited(const QString &arg1);

    void on_usernameLineEdit_textChanged(const QString &arg1);

    void on_passwordLineEdit_textChanged(const QString &arg1);

private:
    Ui::login *ui;
    QString managerPassword;
    QString adminPassword;
    QString adminUsername;
    QString managerUsername;

    manager *managerWindow; // Manager window object
    admin   *adminWindow;   // Admin window object

    databaseManger myDB;    // Database object for database connection
};

#endif // LOGIN_H
