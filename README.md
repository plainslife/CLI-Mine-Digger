## Code Mine Digger  
Is a variation of the classic Minesweeper game.<br>
It’s sure to test your strategy and luck.<br>
Are you up for the challenge!<br>

## 📁 Project Folder Tree Structure
``````
Code Mine Digger/
│
│
├── data/ 
│     -> (contain the data for the leaderboard)
│     -> (files are automatically added as the game start to recieve the data from the game) 
│     -> (the data is used by the ranking library to create the leaderboard)
│
├── include/
│   ├── assets.h      (ASCII Designs interface) 
│   └── rankings.h    (Leaderboard && Sorting interface)
│
├── obj/              (object files will be stored here)
│
├── src/
│   ├── assets.cpp    (ASCII Designs Implementation)
│   └── helper.cpp    (Leaderboard && Sorting Implementation)
│
│
└── main.cpp (Array Impementation -> through minesweeper game and modes)
``````

## 🛠️Instructions to Run and Play the Program
Make sure that the Code Mind Digger folder is downloaded before continuing ...

##### Compiling  
(*Assumes you have [MinGW](https://sourceforge.net/projects/mingw/) installed*)
1. Open your terminal (CMD, PowerShell, etc.) and navigate to the Code Mine Digger directory
2. Compile the two libraries into object using:
       * g++ -c src/assets.cpp -I include -o obj/assets.o
       * g++ -c src/rankings.cpp -I include -o obj/rankings.o

##### Building
3. After turning the two files to object link it together with the main files:
       * g++ src/main.cpp obj/assets.o obj/rankings.o -I include -o bin/mines
       note: you can name the excutable mines with any name you want       

##### Run and play the game:
4. The run the executable using: (or if you change the name of the excutable please use that) 
       * ./bin/mines 

#### 🎯 How to Play Minesweeper
1. Objective: Clear the board without triggering any mines.
2. Board: A grid of cells; some contain mines, others are safe.
3. Gameplay:<br>
       First move is always safe.<br>
       Click a cell to reveal its content.<br>
       Numbers show how many mines are adjacent.<br>
       Use flags to mark potential mines.<br>
4. Winning: Clear all safe cells.
5. Losing: Clicking a mine ends the game.
6. Flagging: Flagged cells cannot be revealed until unflagged.

#### Game modes
1. Difficulty Levels mode 
       - Choose from Easy, Medium, or Hard.<br>
       - Board size and mine count adjust based on difficulty.<br>
2. Custom mode 
       - You decide the board size and mine count.<br>
       - Minimum board size is 3×3, and mines must be fewer than total cells.<br>
3. Infinite Roulette mode 
       - Random board and mine count every round.<br>
       - Play continues until the player quits or loses.<br>
       
#### Leaderboard
1. Difficulty Levels mode
       - Ranked by time taken to win.<br>
       - Faster times = higher ranks.<br>
2. Infinite Roulette mode
       - Ranked by win streaks.<br>
       - The longer the streak, the higher the rank.<br>

By the way I'm just a begginner in programming, and i'm sure there is still alot to improve in this program.
Thanks you for checking the game, I hope you have fun playing!
