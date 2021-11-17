# Dinosaur-Game-CPP

This is an attempt to make a chrome dinosaur game using SFML - a wrapper for OpenGL but with lots of extra features.

## Why SFML?

Honestly when we decided to make this game for our college project, we were told to make this in 20 yr old `<graphics>` library. I really didn't wanted to make a game using an Old library, also some of the functionalites were too limited in that library. For instance you only create a **640x480 window**, you can't change the size of the window, you can't change the color of the window, you can't change the title of the window, also you would need DOS to run the game and the graphics were horrible and you can't use sprites.

Then the quest for a graphic library began. I was amazed to see different libraries written in C++. OpenGL - the library used to create and render graphics, that's something which had a lot of learning curve and there were endless tutorials which were quite intriguing.

I referred to this site - <https://en.cppreference.com/w/cpp/links/libs> to find out about the libraries available in C++.

I looked in SDL first, didn't loved its syntaxes and docs were a little confusing and a bit overwhelming for me.

Then I saw SFML - a library written in C++, which is a wrapper for OpenGL. It's a very simple library, and it's very easy to use. It's also very easy to learn.
Also the documentation is awesome. It has an awesome community and almost any difficulty you can think of is solved. Also you can scale your game using SFML.

##### As the description says

>*Simple and Fast Multimedia Library; multi-platform (Windows, Linux, macOS and soon Android & iOS); provides a simple interface to ease the development of games and multimedia applications. It is composed of five modules: system, window, graphics (over OpenGL), audio and network.*

That's when we decided to use this library to make this game.

## Installation

This repo already consists of all the SFML header files in `src/` folder.  However you need to add those path in your workspace folder. Usually the `C/C++` extension in VSCode will give you a suggesstion to add in the path.

If it doesn't happen add the following lines in your `c_cpp_properties.json` file inside `.vscode` folder.

```json
{
"configurations": [
    {
        "includePath": [
            "${workspaceFolder}/**",
            "${workspaceFolder}/src/include"
        ],
      
    }
],
}
```

If you are using any other IDE or texteditor, good luck in figuring out how to detect those files in the editor so you can edit it and the extension won't complain when that it can't find the libraries. Though you won't face any difficulties in compiling it.

You would also need a C++ compiler (gcc, clang, etc) cause this project uses some standard header files.

And lastly you would need [GNU Make](http://gnuwin32.sourceforge.net/packages/make.htm) to compile and make an executable file.

**NOTE:** The following link above is for installing GNU Make on Windows. If you are using linux, GNU Make should be installed by default. Not sure about MacOS yet.

## Building

1. Open `Terminal`
2. Type `make`

That's it you would have a `main.exe` file in the directory. type `.\main.exe` to run the game

## Roadmap

Since we were a big nooble in game development, honestly we didn't knew at start how to begin making a game. That's when we started watching random YouTube tutorials to get to know the basics of SFML. We binged watch a lot of tutorials read the docs and start experimenting on some Stuffs. Now since we were in confident in our using the library, then came a major concern. How to oraganize the code and make it easy to read and understand. We had to implement the game engine to ensure smooth flow of the Game states. [SFML WIKI](https://github.com/SFML/SFML/wiki/Sources) had a lots of resources for the same. It also had many game examples as well some of the **FAQs** .

We would like to give a huge shoutout to [DevKage](https://www.youtube.com/watch?v=xtZHJxYA6q8&list=PLiZZKL9HLmWMF8PlzvZu2WOC9kjs1zzhm) for his awesome C++ SFML tutorials. This tutorial actually helped us build a basic game engine for this Dino Game. Rest we all had to implement our own game logic, assets and states.

### Main Menu

Every game must have a main menu state. We decided to keep it simple and sober. We would display the tile of the game in pixelated font. we would have two buttons then - `Play` and `Exit`. These are self explanatory. On the we decided to keep a scenary which would be used in main game state too. To add something more funky, we decided to add some clouds which would move to display realism. Also we decided to add Dino in the main screen which could be moved by right and left arrow keys. Since we have added a music in the main menu, it would be great if a user wants to listen to that song while goofing around with dinosaur.

### Game Play State

This was the state where the actual magic happens. In the game play state we actually had to work on small small parts to not be overwhelmed.

**We Started with the following first**

* Adding Background to the Gameplay State
* Adding Floor sprite
* Adding Dino Sprite
* Adding ingame music
* Moving Dino Animation
* Jumping Physics on Dino
* Jumping Sound Dino
* Obstacle Swapning
* Parallax Effect (though not properly done)
* Random Obstacle swapning and movement
* Calculating Score
* Moving to Pause Game and Game Over states

Then all was left to implement `GameOver` state and `Pause Game` state.

## Creators

| Author | About | Github username |
| ----------------- | --- | ---------------- |
| Bishwajeet Parhi| Bishwajeet Parhi is currently a second year undergrad student  Computer Science student at the Indraprastha University. He is a passionate programmer and a gamer. He is also an active Open Source Contributor | [@2002Bishwajeet](https://github.com/2002bishwajeet) |
| Akshat Gupta | Akshat Gupta is also currently a second year undergrad student Computer Science student at the Indraprastha University. He is new to programming and stuffs. He is enthusiastic and its his first project to work together as a team | [@AKG2506](https://github.com/AKG2506)
| Amisha Sagar | Amisha Sagar is also currently a second year undergrad student Computer Science student at the Indraprastha University. she is also a passionate programmer and loves to build new stuffs. She is more keen and interested in Game Development. She knows Unity and had experimented a lots of things in game dev | [@oceanofamisha](https://github.com/oceanofamisha)
