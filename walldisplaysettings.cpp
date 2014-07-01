#include "walldisplaysettings.h"
#include "ui_walldisplaysettings.h"

WallDisplaySettings::WallDisplaySettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WallDisplaySettings)
{
    ui->setupUi(this);
}

WallDisplaySettings::~WallDisplaySettings()
{
    delete ui;
}
