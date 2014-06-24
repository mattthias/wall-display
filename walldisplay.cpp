#include "walldisplay.h"
#include "ui_walldisplay.h"

QList<QString> urls;
int changeUrlInterval;

WallDisplay::WallDisplay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WallDisplay)
{
    ui->setupUi(this);

    QSettings settings;
    urls = settings.value("wall-display/urls","http://endocode.com").toStringList();
    changeUrlInterval = settings.value("wall-display/interval", 10000 ).toInt();

    ui->webView->setUrl(QUrl(urls[0]));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(changeUrl()));
    timer->start(changeUrlInterval);
}

WallDisplay::~WallDisplay()
{
    delete ui;
}

void WallDisplay::changeUrl() {
    if ( urls.length() > 1) {
        QString url = urls.takeFirst();
        urls.append(url);
        ui->webView->setUrl(QUrl(urls[0]));
    }
}
