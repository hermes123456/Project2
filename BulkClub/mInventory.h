#ifndef MINVENTORY_H
#define MINVENTORY_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>

namespace Ui {
class mInventory;
}

class mInventory : public QWidget
{
    Q_OBJECT

public:
    explicit mInventory(QWidget *parent = nullptr);
    ~mInventory();


private slots:
    void on_InventoryComboBox_currentIndexChanged();
    //!< Displays fields based on selected item name.
    /*!< POSTCONDITONS: Item qty and item total fields are displayed in text edits */

private:
    Ui::mInventory *ui;
    QSqlDatabase myDB; // Database object for database connection
};

#endif // MINVENTORY_H
