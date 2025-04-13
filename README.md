
# Arcade

- Arcade is a gaming platform : a program that lets the user choose a game to play and keeps a register of player scores.
- To be able to deal with the elements of your gaming plateform at run-time, your graphics libraries and your games must be implemented as dynamic libraries, loaded at run-time.
- Each GUI available for the program must be used as a shared library that will be loaded and used dynamically by the main program. This also applies to your games

## Prerequisites

You need to install :

- SFML : [2.6.2](https://www.sfml-dev.org/fr/)
- SDL2 : [2.26.5](https://www.libsdl.org/)
- NCURSES : [6.4.20221231](https://github.com/mirror/ncurses/blob/master/INSTALL)
- CMAKE to compile project
## Installation

Clone the project

```bash
    git clone git@github.com:EpitechPromo2028/B-OOP-400-LIL-4-1-arcade-mathis.bukowski.git arcade
```

Init and create the project

```bash
    mkdir -p build && cd build
    cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
    cmake --build .
    cd ..
```

Run the project!

```bash
    ./arcade ./lib/arcade_sfml.so
```

## Documentation

For the documentation, you can go in the arcade-documentation.md file to have more informations about how create a library or a game.

## Keybinds
- Up Arrow : Move up
- Down Arrow : Move down
- Left Arrow : Move left
- Right Arrow : Move right
- A : Restart
- Enter : Select
- ESC (SDL2/SFML) : Quit
- Q (NCURSES) : Quit

## Authors

- Mathis Bukowski - Group Creator, Mail: mathis.bukowski@epitech.eu
- Rafael Drouart - Developer. Contact: rafael.drouart@epitech.eu
- Valentin Frappart - Developer. Contact: valentin.frappart@epitech.eu

#### We work with another group :
- Alexandre Detoeuf - Group Creator, Mail: alexandre.detoeuf@epitech.eu
- Maxime Bertin - Mail: maxime.bertin@epitech.eu
- Raphaël Richaud - Mail: raphael.richaud@epitech.eu

