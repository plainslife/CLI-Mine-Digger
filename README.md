## CLI Mine Digger  
Is a variation of the classic Minesweeper game.<br>
It’s sure to test your strategy and luck.<br>
Are you up for the challenge!<br>

## 🛠️Instructions to Run and Play the Program

##### Compiling  
(*Assumes you have [MinGW](https://sourceforge.net/projects/mingw/) installed*)
1. Open your terminal (CMD, PowerShell, etc.) and navigate to the CLI Mine Digger directory
2. Compile the two libraries into object using:
``````
    g++ -c src/assets.cpp -I include -o obj/assets.o
    g++ -c src/rankings.cpp -I include -o obj/rankings.o
``````

##### Building
3. After turning the two files to object link it together with the main files:
``````
    g++ src/main.cpp obj/assets.o obj/rankings.o -I include -o bin/mines
``````

##### Run and play the game:
4. The run the executable using: (or if you change the name of the excutable please use that) 
``````
    * ./bin/mines 
``````

### 🧠 How to Play Minesweeper

    Objective: Clear the board without triggering any mines.

    Board: A grid of cells; some hide mines, others are safe.

    Gameplay:

        First move is always safe.

        Click a cell to reveal its content.

        Numbers tell how many mines are adjacent.

        Flag suspicious cells to mark potential mines.

    Winning: Clear all safe cells and flag all mines correctly.

    Losing: Click a mine and it’s game over.

    Flags: Flagged cells cannot be revealed unless unflagged first.

### 🎮 Game Modes

    Difficulty Levels Mode

        Choose from Easy, Medium, or Hard.

        Board size and mine count adjust based on difficulty.

    Custom Mode

        You decide the board size and mine count.

        Minimum board size is 3×3, and mines must be fewer than total cells.

    Infinite Roulette Mode

        Random board and mine count every round.

        Play continues until the player quits or loses.
       
### 🏆 Leaderboard System

    Difficulty Mode Leaderboard

        Ranks based on completion time.

        Faster times = higher ranks.

    Infinite Roulette Leaderboard

        Ranks based on win streaks.

        The longer your streak, the better your rank.

By the way I'm just a begginner in programming, and i'm sure there is still alot to improve in this program.
Thanks you for checking the game, I hope you have fun playing!
