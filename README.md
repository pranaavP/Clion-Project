Marble Racing Game

Pranaav Paladugu

11/4/2025

Overview:
The Marble Racing Game is an game where players can bet on marbles racing to the finish line. Players place strategic bets on marble outcomes and win coins based on their predictions. The game features multiple betting methods, animated marble races, and a coin-based system.
This project demonstrates object-oriented design, random number generation, user input validation, and game loop mechanics in C++.

**Features**

Animated Marble Races:

  - Six marbles race along a track of configurable length.

  - Race animation updates in real-time in the console.

Multiple Betting Methods:

  - Predict the exact order of all marbles.

  - Pick a single winner or top marbles in any order.

  - Predict adjacent marbles or top positions

  - Option for “All-in” betting covering all methods.

Player Management:

  - Track multiple players with coin balances.

  - Eliminate players with zero coins.

  - Declare winners when a player exceeds the coin threshold.

Randomized Outcomes: 

  - Marble speeds are random each race, making betting unpredictable and exciting.

Betting System:

  - Bets are evaluated independently of previous races.

  - All winnings are applied to the player’s coin balance immediately.

**Classes**

Marble:

  - Represents a marble in the race.

  - Tracks position and allows movement along the track.

FinishLine:

  - Manages race animation and records final marble order.

Player:

  - Represents a player, tracking name and coin balance.

  - Handles bets and rewards.

BettingMethod:

  - Static class contains all betting calculation logic.

MarbleRacingGame:

  - Coordinates players, races, betting, and overall game flow.

**How to Play**

1. Run the game executable.

2. Enter player names (at least 2 players required).

3. Each player takes turns placing bets:

    - Select a betting method from the menu.

    - Choose marbles according to the betting method.

    - Pay the bet cost in coins.

4. The race runs automatically with animated marble positions.

5. Winners are awarded coins based on betting results.

6. Players continue betting until:

    - A player reaches the winning coin threshold (150 coins).

    - All other players are eliminated.
  
**Requirements:**

  - C++17 or later

  - Standard C++ libraries: <vector>, <string>, <iostream>, <algorithm>, <thread>, <chrono>, <cstdlib>

**Program Example:**

Welcome to the Marble Racing Game!

Enter player name: Alice

1. Add another player
   
2. Begin the game
   
Choose an option: 1

Enter player name: Bob

1. Add another player
   
2. Begin the game

Choose an option: 2

Alice, it's your turn!

Choose a betting method:

1. Exact order of all marbles | Cost: 15 | Reward: 500

...

Enter your choice (1-9): 2

Enter 1 marble to win: Red

Race starting...

o      |  <-- Red

   o   |  <-- Blue
   
... (race animation)

Race finished!

Ranking:

1. Blue
   
2. Red

...

Alice won 0 coins!

Alice has 85 coins.
