# Quest System for Unreal Engine 5.4.4

## Summary
The **Quest System** is a modular and scalable framework designed to manage quests in Unreal Engine 5.4.4. This system supports multiple quest types, objectives, and rewards, providing an extensible foundation for diverse gameplay experiences. It is easy to integrate into your projects and offers flexibility for customization.

---

## External Dependencies
- **Unreal Engine 5.4.4**: Required for implementation.
- **C++ Development Environment**: Needed for coding and extending the system.

---

## How It Works
The Quest System operates through its two primary components:

### **BaseQuest**
This class manages the lifecycle of quests, including initialization, progression, and completion.
- **Quest Details**: Stores name and description.
- **Objectives**: Tracks objectives like slaying enemies or collecting items.
- **Rewards**: Awards experience points or items upon completion.

### **DefaultEnemy**
This class represents the entities players interact with to complete objectives.
- **Health System**: Tracks the enemy’s health and handles its death state.
- **Integration**: Notifies the quest system when a quest-related enemy is defeated.

---

## Implementation
The code is organized into modular components for easy extension and maintenance:

### **BaseQuest Implementation**
#### Properties:
- `FString name`: Quest name.
- `FString description`: Quest description.
- `TArray<ObjectiveStruct> objectives`: Array storing objective details.

#### Functions:
1. `SetQuestDetails()`: Configures quest name and description.
2. `SetUpObjective()`: Defines quest objectives with specific conditions.
3. `UpdateObjective()`: Tracks progress and updates objectives.
4. `FinishQuest()`: Finalizes the quest and awards rewards.

### **DefaultEnemy Implementation**
#### Properties:
- `float health`: Tracks health.
- `bool isDead`: Indicates if the enemy is dead.

#### Functions:
1. `TakeDamage()`: Reduces health and checks for death.
2. `Die()`: Triggers integration with the quest system.

---

## Tutorial: Implementing and Extending the Quest System

### **1. Setting Up a New Quest**
1. Create a new `UBaseQuest` instance.
2. Use `SetQuestDetails()` to define the quest name and description.
3. Add objectives with `SetUpObjective()` by specifying enemy or item types and required counts.

### **2. Tracking Progress**
1. Use `UpdateObjective()` to log player progress (e.g., defeating an enemy).
2. Check completion status and mark objectives as complete when conditions are met.

### **3. Completing the Quest**
1. When all objectives are completed, call `FinishQuest()`.
2. The system will distribute rewards to the player.

### **4. Extending the System**
- **Add New Objectives**: Extend the `EClearCondition` enum and update the `SetUpObjective()` function.
- **Enhance Rewards**: Modify the reward logic to include additional reward types like gold or skills.
- **Multiplayer Support**: Synchronize quest progress across clients in a multiplayer session.

---

## Future Enhancements
- **Dynamic Objectives**: Support location-based goals.
- **Advanced Rewards**: Include multiple reward types.
- **Quest Editor**: Develop a visual quest creation tool within Unreal Editor.

---

## Installation
1. Clone or download this repository:
   ```bash
   git clone https://github.com/TheCompindium13/QuestSystem.git
   ```
2. Open your Unreal Engine project.
3. Add the Quest System files to your project’s `Source` folder.
4. Compile the project to integrate the system.

---

## Contributing
Contributions are welcome! Follow these steps to contribute:
1. Fork the repository.
2. Create a new branch: `git checkout -b feature/YourFeature`.
3. Commit your changes: `git commit -m 'Add some feature'`.
4. Push to the branch: `git push origin feature/YourFeature`.
5. Open a Pull Request.

---

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## Contact
For questions or suggestions, please reach out:
- **Email**: Haidonmcosse@gmail.com
- **GitHub**: [TheCompindium13](https://github.com/TheCompindium13)

