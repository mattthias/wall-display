#ifndef WALLDISPLAY_H
#define WALLDISPLAY_H

#include <QMainWindow>
#include <QTimer>
#include <QUrl>
#include <QSettings>


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
};

#endif // WALLDISPLAY_H
