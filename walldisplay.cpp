#include "walldisplay.h"
#include "ui_walldisplay.h"
#include "walldisplaysettings.h"
#include "ui_walldisplaysettings.h"

QList<QString> urls;
int changeUrlInterval;
QTimer *timer = new QTimer();

WallDisplay::WallDisplay(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WallDisplay)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);

    /* start with hidden menubar */
    ui->menuBar->hide();

    /* Enable interval stop button, connect interval start/stop buttons */
    ui->actionStart_interval->setDisabled(true);
    ui->actionS_top_interval->setEnabled(true);
    connect(ui->actionStart_interval, SIGNAL(triggered()), this, SLOT(startInterval()));
    connect(ui->actionS_top_interval, SIGNAL(triggered()), this, SLOT(stopInterval()));

    /* wire up the settings and about dialog */
    connect(ui->action_Info, SIGNAL(triggered()), this, SLOT(showAbout()));
    connect(ui->action_settings, SIGNAL(triggered()), this, SLOT(showSettingsDialog()));

    /* read urls and cycle interval from the settings file */
    settings_ = new QSettings();
    changeUrlInterval = settings_->value("wall-display/interval", 10).toInt();
    QStringList urls = settings_->value("wall-display/urls","https://github.com/mattthias/wall-display/wiki").toStringList();

    /* Load the first url */
    ui->webView->setUrl(QUrl(urls[0]));

    /* start the timer with interval */
    connect(timer, SIGNAL(timeout()), this, SLOT(changeUrl()));
    timer->start(changeUrlInterval * 1000);


}

WallDisplay::~WallDisplay()
{
    delete ui;
    delete settings_;
}

/* triggered by the timer change the shown url */
void WallDisplay::changeUrl() {
    if ( urls.length() > 1) {
        QString url = urls.takeFirst();
        urls.append(url);
        ui->webView->setUrl(QUrl(urls[0]));
    }
}

void WallDisplay::startInterval() {
    timer->start();
    ui->actionStart_interval->setDisabled(true);
    ui->actionS_top_interval->setEnabled(true);
}

void WallDisplay::stopInterval() {
    timer->stop();
    ui->actionStart_interval->setEnabled(true);
    ui->actionS_top_interval->setDisabled(true);

}

/* on a key press unhide the menubar */
bool WallDisplay::eventFilter(QObject *obj, QEvent *event) {
    if ( event->type() == QEvent::KeyPress ){
            QKeyEvent *key = static_cast<QKeyEvent *>(event);
            qDebug() << "Key " << key->key() << " pressed in " << obj->objectName();
            if ( ui->menuBar->isHidden() ) {
                ui->menuBar->setVisible(true);
            }
    } else if (event->type() == QEvent::MouseButtonDblClick ) {
        if ( ui->menuBar->isHidden() ) {
            ui->menuBar->setVisible(true);
        }
    }

    // pass the event on to the parent class
    return QMainWindow::eventFilter(obj, event);
}


void WallDisplay::showAbout(){
    QMessageBox::about(this, tr("About wall-display"),
                 tr("Wall-Display was written by\n"
                    "Matthias Schmitz <matthias@sigxcpu.org>\n"
                    "Nikolas Sepos <nikolas@endocode.com>\n"
                    "Gerald Schmidt"));
}

void WallDisplay::showSettingsDialog() {
    qDebug() << "showSettingsDialog aufgerufen";
    WallDisplaySettings *settingsdialog = new WallDisplaySettings(settings_);
    int retval = settingsdialog->exec();
    if ( retval == QDialog::Accepted) {
        urls = settings_->value("wall-display/urls","https://github.com/mattthias/wall-display").toStringList();
        changeUrlInterval = settings_->value("wall-display/interval", 10).toInt();
    }
}
