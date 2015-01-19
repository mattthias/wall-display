#ifndef WALLDISPLAYSETTINGS_H
#define WALLDISPLAYSETTINGS_H

#include <QDialog>
#include <QMessageBox>
#include <QSettings>
#include <QInputDialog>
#include <QDebug>

namespace Ui {
class WallDisplaySettings;
}

class WallDisplaySettings : public QDialog
{
    Q_OBJECT

public:
    explicit WallDisplaySettings(QSettings *settings, QWidget *parent = 0);
    ~WallDisplaySettings();

private slots:
    void on_addUrl_clicked();
    void on_removeUrl_clicked();

    void on_buttonBox_accepted();

private:
    Ui::WallDisplaySettings *ui;
    QSettings *settings_;

};

#endif // WALLDISPLAYSETTINGS_H
