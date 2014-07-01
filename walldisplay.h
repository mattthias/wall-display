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
    explicit WallDisplay(QWidget *parent = 0);
    ~WallDisplay();

private:
    Ui::WallDisplay *ui;

private Q_SLOTS:
    void changeUrl();
    void stopInterval();
    void startInterval();
    void showSettingsDialog();
    void showAbout();

protected:
    bool eventFilter(QObject *obj, QEvent *event);
};

#endif // WALLDISPLAY_H
