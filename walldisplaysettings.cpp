#include "walldisplaysettings.h"
#include "ui_walldisplaysettings.h"

WallDisplaySettings::WallDisplaySettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WallDisplaySettings)
{
    ui->setupUi(this);

    QSettings settings;
    QList<QString> urls;
    int changeUrlInterval;

    /* read urls and cycle interval from the settings file */
    urls = settings.value("wall-display/urls","http://endocode.com").toStringList();
    changeUrlInterval = settings.value("wall-display/interval", 10).toInt();

    QListWidget *listWidget = ui->listWidget;
    QSpinBox *spinBox = ui->spinBox;

    for(int i = 0; i < urls.length(); ++i) {
        new QListWidgetItem(urls.at(i), listWidget);
    }
    spinBox->setValue(changeUrlInterval);
}

WallDisplaySettings::~WallDisplaySettings()
{
    delete ui;
}

void WallDisplaySettings::on_addUrl_clicked()
{
    bool ok;
    QListWidget *listWidget = ui->listWidget;
    /*Get new URL from input dialog*/
    QString newUrl = QInputDialog::getText(this, "Add new URL", "URL:", QLineEdit::Normal, "", &ok);

    // TODO: validate URL
    if(ok && !newUrl.isEmpty()) {
        new QListWidgetItem(newUrl, listWidget);
    }
}

void WallDisplaySettings::on_removeUrl_clicked()
{
    delete ui->listWidget->currentItem();
}

void WallDisplaySettings::on_buttonBox_accepted()
{
    QSettings settings;
    QListWidget *listWidget = ui->listWidget;
    QSpinBox *spinBox = ui->spinBox;
    QStringList urls;

    for(int i = 0; i < listWidget->count(); ++i) {
        urls << listWidget->item(i)->text();
    }
    settings.setValue("wall-display/urls", urls);
    settings.setValue("wall-display/interval", spinBox->value());

}
