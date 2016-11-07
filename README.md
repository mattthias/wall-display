wall-display
============
To compile the application (eg. on a Raspberry Pi with Raspbian/Wheezy) install QT4-dev:

        apt-get install libqt4-dev libqtwebkit-dev qt4-qmake build-essential

Build:

        qmake # or qmake-qt4 on Ubuntu >= 16.04
        make

Configure the application with the settings dialog

![settings dialog](https://raw.githubusercontent.com/mattthias/wall-display/master/settings.png)

Or edit the config file in $HOME/.config/endocode/wall-display.conf:

        [wall-display]
        urls = http://endocode.com, http://heise.de
        interval = 25

```urls```: A comma separated list of urls to show.

```interval```: How many seconds every url should be displayed.

Web applications like Grafana have to use [`LocalStorage`](http://doc.qt.io/qt-4.8/qwebsettings.html#localStoragePath) database. Application stores this data inside the `$HOME/.local/share/data/endocode/wall-display` path.
