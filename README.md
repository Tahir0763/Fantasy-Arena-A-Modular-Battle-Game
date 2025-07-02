# Fantasy-Arena-A-Modular-Battle-Game
# ⚔️ Fantasy Arena: A Modular Turn-Based Battle Game in C++

**Fantasy Arena** is a scalable, turn-based battle game that lets players create custom characters, select dynamic arenas, and engage in strategic battles. Designed as a C++ Object-Oriented Programming project, Fantasy Arena implements key OOP concepts including inheritance, polymorphism, composition, aggregation, operator overloading, exception handling, file I/O, and custom mechanics.

---

## 🎯 Objective

Build a modular and unique terminal-based battle simulator in which different character types use strategic special abilities to fight in a variety of arenas—each impacting the battle. The goal is to explore and apply core OOP principles in an engaging and challenging context.

---

## 🧱 Core Features

### 🧙 Character System (Inheritance & Polymorphism)

- Abstract base class `Character`:
  - Attributes: `name`, `level`, `health`, `attack`, `defense`
  - Pure virtual methods: `attackTarget(Character&)`, `useSpecialAbility()`
- Derived classes: `Warrior`, `Mage`, `Archer`, etc.
- **Bonus:** `LegendaryCharacter` class inherits from existing character and unlocks passive ability after 2 wins.

### 🏟️ Arena System (Aggregation)

- Class `Arena` contains:
  - Name, environment type (e.g., Fire, Ice, Jungle)
  - Aggregates two or more characters
  - Applies buffs/debuffs based on environment & character class
- **Bonus:** Random weather events (storm, heatwave) affect attack/defense temporarily

### 🧩 Game Manager (Composition)

- Class `GameManager` includes:
  - List of Arenas
  - List of Characters
  - Handles:
    - Matchups & turn-based logic
    - Battle result display
- **Bonus:** Battle history system saved as `.txt` or `.csv` using file I/O

### ➕ Operator Overloading

- `+` operator: Combine two characters’ attacks for a combo move
- `==` operator: Compare two characters’ total power
- `<<` operator: Print detailed character stats
- **Bonus:** `-` operator to simulate health stealing on attack

### ✨ Unique Special Ability System

- Each student must create a **completely unique** `useSpecialAbility()` implementation for at least one character
- Abilities can include:
  - Healing
  - Dodge/Teleport
  - Reflection
  - Clone/Split
  - Berserk Mode
  - Stat drain, etc.
- **Bonus:** Add cooldown system (special abilities usable only after X turns)

### 📝 Battle Logging

- All battle actions are logged into a `.txt` file using `ofstream`
  - Includes attack moves, special abilities, outcomes
- **Bonus:** Add real-time timestamps to each log entry

### 🧩 Modular Architecture

Split into clean files:
