#ifndef WALLDISPLAY_H
#define WALLDISPLAY_H

#include <QMainWindow>
#include <QTimer>
#include <QUrl>
#include <QSettings>
#include <QDebug>
#include <QKeyEvent>

namespace Ui {
class WallDisplay;
}

class WallDisplay : public QMainWindow
{
    Q_OBJECT

public:
    explicit WallDisplay(QWidget *parent = nullptr);
    ~WallDisplay();

private:
    Ui::WallDisplay *ui;
    QSettings *settings_;

private Q_SLOTS:
    void changeUrl();
    void stopInterval();
    void startInterval();
    void showSettingsDialog();
    void showAbout();

protected:
    bool eventFilter(QObject *obj, QEvent *event);
};

extern QList<QString> urls;
extern int changeUrlInterval;
extern QTimer *timer;

#endif // WALLDISPLAY_H
