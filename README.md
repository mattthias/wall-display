wall-display
============

To compile the application on a Raspberry Pi with Rasbian install the Qt5 develpment tools:

        sudo apt install qt5-default

Build:

        qmake
        make

Configure the application with the settings dialog

![settings dialog](https://raw.githubusercontent.com/mattthias/wall-display/master/settings.png)

Or edit the config file in $HOME/.config/endocode/wall-display.conf:

        [wall-display]
        urls = http://endocode.com, http://heise.de
        interval = 25

```urls```: A comma separated list of urls to show.

```interval```: How many seconds every url should be displayed.
