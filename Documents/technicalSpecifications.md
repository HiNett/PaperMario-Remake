# Paper Mario - Remake | Technical Specification

<details>
<summary>Table of content</summary>

- [Paper Mario - Remake | Technical Specification](#paper-mario---remake--technical-specification)
  - [1. Gameplays](#1-gameplays)
    - [1.1 Exploration Mode](#11-exploration-mode)
    - [1.2 Combat Mode](#12-combat-mode)
    - [1.3 Controls](#13-controls)
  - [2. Characters](#2-characters)
    - [2.1 Mario](#21-mario)
    - [2.2 Passive NPCs](#22-passive-npcs)
    - [2.4 NPCs Diagram](#24-npcs-diagram)
  - [3. Items](#3-items)
    - [3.1 In overworld](#31-in-overworld)
    - [3.2 In combat](#32-in-combat)
    - [3.3 Item Diagram](#33-item-diagram)
  

</details>

## 1. Gameplays

### 1.1 Exploration Mode
During this phase the player will be able to control Mario the left to the right, the player will also have the ability to jump and use the hammer to it, break element of the game (ennemies and environement) and talk with passive NPCs.

### 1.2 Combat Mode
During this phase the player be not able to move the right to the left. An wheel option will appears an give multiple choices :
- Jump
- Hammer
- Inventory
- Escape the battle

### 1.3 Controls
To control Mario the with the keypad will be :
| Mode | Button | Action |
|---|:---:|---|
|Exploration| Q | Move Mario on the left |
|Exploration| D | Move Mario on the right |
|Exploration| Spacebar | Mario jump |
|Exploration| Esc | Pause button |
|Exploration| Enter | Mario slam with is hammer |
|Exploration| Spacebar | Mario interact with passive NPCs near them |
|Exploration| I | Open Mario's inventory |
|Inventory Menu| Q | Navigate to the left in Mario's inventory |
|Inventory Menu| D | Navigate to the right in Mario's inventory |
|Inventory Menu| Space | Select the option hoverled  |
|Fight| Q | Navigate in the between options on the left |
|Fight| D | Navigate in the between options on the right |
|Fight| Space | Will transform the option in action |
|Fight| Space | During the action if well executed attribute a bonus of damage or a bonus defense (0.20s) |
|Fight| Enter | During the action if well executed cancel the damage supposed to take (0.05s) |
|LevelUp Menu| Q | Permit to navigate in options to the left |
|LevelUp Menu| D | Permit to navigate in options to the right |
|LevelUp Menu| Space | Select the option hoverled |
|LevelUp Menu| Esc | Leave the inventory menu to the Exploration |

## 2. Characters
### 2.1 Mario
The game will start with Mario as main character and mulitple statistics :
- Life points = 10/10
- FLower points = 5/5
- Badge points = 3/3
- Experience points = 0
- Kamas = 100

Every 100 experience points the player have the ability to increase the life points, the flower points or the badge points. If the the experience points are over 100 the extras points are keeped but reduced of 100 (e.g. 105exp -> 5exp)

### 2.2 Passive NPCs
Every passive NPC's will have a name, dialogue, and can give items to Mario (good or bad). They cannot jump or use external animation expect move the right to the left and talk.

### 2.4 NPCs Diagram
![charatersDiamgrams](..\Assets\characterDiagram.png)

## 3. Items
### 3.1 In overworld
The player will be able to use some items at any time.
### 3.2 In combat
The player will be able to use all items during the fight, after using the option the turn is over.
### 3.3 Item Diagram
![itemDiagram](..\Assets\itemDiagram.png)
