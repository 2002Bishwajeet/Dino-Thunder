# Dinosaur-Game-CPP

This is an attempt to make a chrome dinosaur game using SFML - a wrapper for OpenGL but with lots of extra features.

## Why SFML?

Honestly when we decided to make this game for our college project, we were told to make this in 20yr old `<graphics>` library. I really didn't wanted to make a game using an Old library, also some of the functionalites were too limited in that library. For instance you only create a **640x480 window**, you can't change the size of the window, you can't change the color of the window, you can't change the title of the window, also you would need DOS to run the game and the graphics were horrible and you can't use sprites.

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

That's it you would have a `main.exe` file in the main folder. type `.\main.exe` to run the game
