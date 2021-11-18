# Contributing

<p align = "center">
<img src = "screenshots/contribute.jpg" height = "300" margin-left =  />
</p>

We would ❤️ for you to contribute to this Awesome Dino Thunder Project and help make it better! We want contributing to this repo to be fun, enjoyable, and educational for anyone and everyone. All contributions are welcome, including issues, doc improvements as well as updates and tweaks.

## How to Start?

If you are worried or don’t know where to start, check out our next section explaining what kind of help we could use and where can you get involved. You can reach out with questions to [Bishwajeet Parhi (@biswa_20p)](https://twitter.com/biswa_20p) on Twitter. You can also submit an issue, and a maintainer can guide you!

## Code of Conduct

Help us keep Dino Thunder Project open and inclusive. Please read and follow our [Code of Conduct](/CODE_OF_CONDUCT.md).

## Submit a Pull Request 🚀

Branch naming convention is as following

`TYPE-ISSUE_ID-DESCRIPTION`

example:

```
doc-548-submit-a-pull-request-section-to-contribution-guide
```

When `TYPE` can be:

- **feat** - is a new feature
- **doc** - documentation only changes
- **cicd** - changes related to CI/CD system
- **fix** - a bug fix
- **refactor** - code change that neither fixes a bug nor adds a feature

**All PRs must include a commit message with the changes description!**

For the initial start, fork the project and use git clone command to download the repository to your computer. A standard procedure for working on an issue would be to:

1. `git pull`, before creating a new branch, pull the changes from upstream. Your master needs to be up to date.

```
git pull
```

2. Create new branch from `master` like: `doc-548-submit-a-pull-request-section-to-contribution-guide`<br/>

```
git checkout -b [name_of_your_new_branch]
```

3. Work - commit - repeat ( be sure to be in your branch )

4. Push changes to GitHub

```
git push origin [name_of_your_new_branch]
```

5. Submit your changes for review
If you go to your repository on GitHub, you'll see a `Compare & pull request` button. Click on that button.
6. Start a Pull Request
Now submit the pull request and click on `Create pull request`.
7. Get a code review approval/reject
8. After approval, merge your PR
9. GitHub will automatically delete the branch after the merge is done. (they can still be restored).

## Setup From Source

To set up a working **development environment**, fork the project git repository and ensure you have a C++ Compiler and GNU Make installed. Details about it is given in the readme file.

```bash
git clone git@github.com:[YOUR_FORK_HERE]/Dinasaur-Game-CPP.git

cd dinothunder

code .
```

### Code Autocompletion

To get proper autocompletion for all the different functions and classes in the codebase, you'll need to install the recommended C/C++ extensions.

### Get Started

After finishing the installation process, you can start writing and editing code.

#### Advanced Topics

We love to create issues that are good for beginners and label them as `good first issue` or `hacktoberfest`, but some more advanced topics might require extra knowledge. Below is a list of links you can use to learn more about some of the more advance topics that will help you master the SFML .

### File Structure

```bash
.
├─ assets # Assets of the game
│  ├─ fonts # Fonts used in the game
│  │  ├─ 8bitOperatorPlus-Bold.ttf
│  │  ├─ 8bitOperatorPlus-Regular.ttf
│  │  ├─ 8bitOperatorPlus8-Bold.ttf
│  │  ├─ 8bitOperatorPlus8-Regular.ttf
│  │  ├─ 8bitOperatorPlusSC-Bold.ttf
│  │  ├─ 8bitOperatorPlusSC-Regular.ttf
│  │  └─ SIL Open Font License.txt
│  ├─ music # Music used in the game
│  │  ├─ game_music.ogg
│  │  └─ mainmenu.ogg
│  ├─ sounds # Sounds used in the game play state
│  │  ├─ game_over.ogg
│  │  └─ jump.wav
│  └─ sprites # Sprites used in the game
│     ├─ background # Background Sprite
│     │  ├─ layers
│     │  │  ├─ parallax-mountain-bg.png
│     │  │  ├─ parallax-mountain-foreground-trees.png  
│     │  │  ├─ parallax-mountain-montain-far.png
│     │  │  ├─ parallax-mountain-mountains.png
│     │  │  ├─ parallax-mountain-trees.png
│     │  │  └─ parallax-mountain.png
│     │  ├─ license.txt
│     │  └─ parallax-mountain.psd
│     ├─ birds # Obstacle Bird Sprite
│     │  ├─ BirdSprite.png
│     │  ├─ BirdSpriteBig.png
│     │  └─ readme.txt
│     ├─ clouds #Clouds 
│     │  ├─ Clouds V2-2.png
│     │  ├─ Clouds V2.aseprite
│     │  └─ Clouds V2.png
│     ├─ Dino # Dino(Main Character)
│     │  ├─ aseprite
│     │  │  ├─ dinoCharacters-display.ase
│     │  │  └─ DinoSprites.ase
│     │  ├─ gifs
│     │  │  ├─ DinoSprites_doux.gif
│     │  │  ├─ DinoSprites_mort.gif
│     │  │  ├─ DinoSprites_tard.gif
│     │  │  └─ DinoSprites_vita.gif
│     │  ├─ misc
│     │  │  └─ shadow_2.png
│     │  ├─ sheets
│     │  │  ├─ DinoSprites - doux.png
│     │  │  ├─ DinoSprites - mort.png
│     │  │  ├─ DinoSprites - vita.png
│     │  │  └─ DinoSprites-tard.png
│     │  └─ credits.txt
│     ├─ floor # Tiles
│     │  └─ Wasteland-Files.png
│     └─ obstacles  #Obstacles
│        ├─ winter_tree_1.png
│        ├─ winter_tree_2.png
│        ├─ winter_tree_3.png
│        ├─ winter_tree_4.png
│        └─ winter_tree_5.png
├─ include # Declaration of all the classes and functions used in the game
│  ├─ asset_manager.hpp
│  ├─ game.hpp
│  ├─ game_over.hpp
│  ├─ game_play.hpp
│  ├─ main_menu.hpp
│  ├─ pause_game.hpp
│  ├─ State.hpp
│  └─ state_manager.hpp
├─ lib # Defination of all the classes and functions used in the game
│  ├─ asset_manager.cpp
│  ├─ game.cpp
│  ├─ game_over.cpp
│  ├─ game_play.cpp
│  ├─ main_menu.cpp
│  ├─ pause_game.cpp
│  └─ state_manager.cpp
├─ screenshots # Screenshots of the game
├─ src # SFML source code (Do not touch this)
│  ├─ include
│  │  └─ SFML
│  │     ├─ Audio
│  │     ├─ Graphics
│  │     ├─ Network
│  │     ├─ System
│  │     ├─ Window
│  │     ├─ Audio.hpp
│  │     ├─ Config.hpp
│  │     ├─ GpuPreference.hpp
│  │     ├─ Graphics.hpp
│  │     ├─ Main.hpp
│  │     ├─ Network.hpp
│  │     ├─ OpenGL.hpp
│  │     ├─ System.hpp
│  │     └─ Window.hpp
│  └─ lib
├─ CODE_OF_CONDUCT.md
├─ CONTRIBUTING.md
├─ LICENSE
├─ main.cpp # main execution of the game
├─ Makefile
├─ openal32.dll # DLL Files
├─ README.md
├─ sfml-audio-2.dll  # DLL Files
├─ sfml-audio-d-2.dll # DLL Files
├─ sfml-graphics-2.dll # DLL Files
├─ sfml-graphics-d-2.dll # DLL Files
├─ sfml-network-2.dll # DLL Files
├─ sfml-network-d-2.dll # DLL Files
├─ sfml-system-2.dll # DLL Files
├─ sfml-system-d-2.dll # DLL Files
├─ sfml-window-2.dll # DLL Files
├─ sfml-window-d-2.dll # DLL Files
```

### The Monolithic Part

Appwrite's main API container is designed as a monolithic app. This is a decision we made to allow us to develop the project faster while still being a very small team.

Although the Appwrite API is a monolithic app, it has a very clear separation of concern as each internal service or worker is separated by its container, which will allow us as we grow to start breaking services for better maintenance and scalability.

### The Microservice Part

Each container in Appwrite is a microservice on its own. Each service is an independent process that can scale without regard to any of the other services.

Currently, all of the Appwrite microservices are intended to communicate using the TCP protocol over a private network. You should be aware to not expose any of the services to the public-facing network, besides the public port 80 and 443, who, by default, are used to expose the Appwrite HTTP API.

## Ports

Appwrite dev version uses ports 80 and 443 as an entry point to the Appwrite API and console. We also expose multiple ports in the range of 9500-9504 for debugging some of the Appwrite containers on dev mode. If you have any conflicts with the ports running on your system, you can easily replace them by editing Appwrite's docker-compose.yml file and executing `docker-compose up -d` command.

## Technology Stack

To start helping us to improve the Dino Thunder by submitting code, prior knowledge of Dino Thunder technology stack can help you with getting started.

Dino Thunder is a game made using the [SFML library](https://www.sfml-dev.org/index.php). The SFML library is a cross-platform C++ library that provides a simple interface to 2D and 3D graphics, audio, and network functionality.

## Coding Standards

Currently Dino Thunder doesn't use any Coding Standards. If you would like to implement a coding standart
We use prettier for our JS coding standards and auto-formatting our code.

## Introducing New Features

We would 💖 you to contribute to this game, but we would also like to make sure Appwrite is as great as possible and loyal to its vision and mission statement 🙏.

For us to find the right balance, please open an issue explaining your ideas before introducing a new pull request.

This will allow us to have sufficient discussion about the new feature value and how it can impact this game

This is also important for the maintainers to be able to give technical input and different emphasis regarding the feature design and architecture.

## Build

To build a new version of the game, all you need to do is run the `make` command like this:

```bash
make
```

## Code Maintenance  

We use some automation tools to help us keep a healthy codebase.

## Other Ways to Help

Pull requests are great, but there are many other areas where you can help on this Project.

### Sending Feedbacks & Reporting Bugs

Sending feedback is a great way for us to know how do you liked this game. If you had any issues, bugs, or want to share about your experience, feel free to do so on our GitHub issues page.

### Submitting New Ideas

If you think this Game could use a new feature, please open an issue on our GitHub repository, stating as much information as you can think about your new idea and it's implications. We would also use this issue to gather more information, get more feedback from the community, and have a proper discussion about the new feature.

### Improving Documentation

Submitting documentation updates, enhancements, designs, or bug fixes. Spelling or grammar fixes will be very much appreciated.

### Helping Someone

Since this project is more of a tuorial, you could share this project with your friends and colleagues.
