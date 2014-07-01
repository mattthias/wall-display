#ifndef WALLDISPLAYSETTINGS_H
#define WALLDISPLAYSETTINGS_H

#include <QDialog>

namespace Ui {
class WallDisplaySettings;
}

class WallDisplaySettings : public QDialog
{
    Q_OBJECT

public:
    explicit WallDisplaySettings(QWidget *parent = 0);
    ~WallDisplaySettings();

private:
    Ui::WallDisplaySettings *ui;
};

#endif // WALLDISPLAYSETTINGS_H
