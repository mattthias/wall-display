wall-display
============
To compile the application (eg. on a Raspberry Pi with Raspbian/Wheezy) install QT4-dev:

        apt-get install libqt4-dev libqtwebkit-dev qt4-qmake

Build:

        qmake
        make

Configure the application in $HOME/.config/endocode/wall-display.conf:

        [wall-display]
        urls = http://endocode.com, http://heise.de
        interval = 25

```urls``` comma separated list of urls
```interval``` in seconds
