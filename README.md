# Simplified PacMan

![ReadyGIF](https://bitbucket.org/XiaodongQuan/simplified_pacman/raw/c995e50dcc1163d5cc3539d5f3fe27d1f1908939/introduction/showReady.gif)  

## References List:
>### -> Lazy Foo' Productions (Some loadTexture functions and structure from this SDL2 tutorial)
>###	http://lazyfoo.net/tutorials/SDL

>### -> ebuc99's Pacman (Get medias from this git, and hinted by it's Rail structure)
>### https://github.com/ebuc99/pacman


## How to Run:
>### get into /src folder
>### $ make pacman
>### $ ./pacman

## Bugs Report:
>### *Don't eat another PowerPill when u r in Hunting mode!!!!!!*

## What's Different:
>### *This PacMan more Strategy!*
### *PacMan will move step by step,*
### *And Ghost only move when PacMan are Moving!*
### *So, you can make decision for each avalible movement!*

## Features:
>### *1. EatPill to get SCORE!*
>### *2. PowerPill provide PacMan the power to kill GHOST for a while!* 
>### *If Ghosts be eaten by Pacman, they will be reset postion to then central of map!*
  
![PillGIF](https://bitbucket.org/XiaodongQuan/simplified_pacman/raw/87a474c809b398df4d896ef262f30512469929f5/introduction/showPowerPill.gif)  

>### *3. Touch Ghost Will be kill!* 
>### *3 life only!* 
>### *Will be rescue after be killed if still have life avalible* 

![PillGIF](https://bitbucket.org/XiaodongQuan/simplified_pacman/raw/87a474c809b398df4d896ef262f30512469929f5/introduction/showDeath.gif)

>### *4. GAME OVER WHEN ALL LIFE SPENT!* 

![OVERGIF](https://bitbucket.org/XiaodongQuan/simplified_pacman/raw/f6074201a0ebdb449050c18569233e35c5ac997c/introduction/showGameOver.gif)

## Project Structure:
>### Classes:

>#### main 
>#### -> *Run the Game*

>#### constants
>#### -> *Include All const Varibles and Objects for the Game*

>#### labyrinth 
>#### -> *The Game Labyrinth Obj*

>#### rail
>#### -> *Obj which the way Pacman and Ghost can use to walk*
>#### -> *Uses to limit thems movement*

>#### loadTexture
>#### -> *A general help class to esier render objs to SDL_Render*

>#### pacman
>#### -> *Save all info of Pacman, with all Pacman's logics*

>#### ghost
>#### -> *Save all info of Ghost, with all Ghost's logics*

>#### pill
>#### -> *With basic info of Pill Obj, like coordinates*

>#### powerPill
>#### -> *With basic info of PowerPill Obj, and logics*

>#### gameTimer
>#### -> *A simple SDL_2 based timer, uses to calculate time when needs.*

## Challenges:

### 1. Learn Totally new stuff
>#### SDL2
>#### -> which is basic SDL2 library, help us show window and images.
>#### SDL2_image
>#### -> which is extend SDL2 library, make us could use .png image.
>#### SDL2_ttf
>#### -> which is extend SDL2 library, make us could set our fonts.
>#### SDL2_mixer
>#### -> which is extend SDL2 library, make us could add sounds.

### 2. Limit the movement and Detect the collision
>#### In order to limit objs movement, we have to add class Rail to set all CONST rails for them to walk.
>#### We even graphed a rail map by to determine the correct rail cooridinates and infos.

![Rail](https://bitbucket.org/XiaodongQuan/simplified_pacman/raw/d64a3000a120bf899bfdbdbe507c4289fbaa52ea/introduction/rail.jpg)

### 3. PowerPill and HuntMode
>#### We need relogic lots of part of Pacman and Ghost inoder to make Pacman could eat Ghosts rahter than killed by them when collision.

