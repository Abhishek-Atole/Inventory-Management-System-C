# 🗃️ Inventory Management System in C

A robust, feature-rich **Inventory & Stock Management System** written in the **C programming language**, designed with an industry-standard modular structure. Perfect for learning advanced data structures, file handling, and system design.

---

## 🚀 Features

### Core Inventory Operations
- 📦 **Add/Delete/Update Items** - Complete CRUD operations
- 🔍 **Search Functionality** - Search by ID or Name
- 📊 **Comprehensive Display** - Formatted inventory tables with totals
- 🛠️ **Low Stock Alerts** - Configurable threshold notifications
- 📈 **Sorting Capabilities** - Sort inventory by price

### Data Management
- 💾 **File I/O Operations** - Save and load inventory data
- 📁 **Backup System** - Automatic timestamped backups
- 📤 **CSV Import/Export** - Industry-standard data format
- 🔄 **Auto-save** - Persistent data storage

### Analysis & Reporting
- 📊 **Inventory Statistics** - Total value, item counts
- 💰 **Financial Analysis** - Most expensive items, total valuation
- ⚠️ **Alert System** - Low stock warnings
- 📈 **Sorting & Organization** - Multiple sorting options

### User Experience
- 🎨 **Beautiful CLI Interface** - Box-drawing characters and emojis
- ✅ **Input Validation** - Robust error handling
- 📱 **Menu-driven UI** - Intuitive navigation
- 🚀 **Fast Performance** - Efficient linked list implementation

---

## 🏗️ Project Structure

```
Inventory-Management-System-C/
├── src/
│   ├── main.c          # Main program with UI
│   ├── inventory.c     # Core inventory operations
│   └── database.c      # File I/O and data persistence
├── include/
│   ├── inventory.h     # Inventory function prototypes
│   └── database.h      # Database function prototypes
├── .vscode/           # VS Code configuration
├── .gitignore         # Git ignore rules
├── Makefile           # Build configuration
├── run_inventory.bat  # Windows batch file to run the program
├── sample_data.csv    # Sample inventory data
└── README.md          # This file
```

---

## 🛠️ Compilation & Usage

### Quick Start
```bash
# Clone the repository
git clone <repository-url>
cd Inventory-Management-System-C

# Compile the program
gcc -Wall -Wextra -std=c99 -Iinclude src/main.c src/inventory.c src/database.c -o inventory_system

# Run the program
./inventory_system.exe

# Or use the batch file on Windows
./run_inventory.bat
```

### Using Makefile (if available)
```bash
make all        # Build the project
make run        # Build and run
make clean      # Clean build artifacts
make debug      # Build with debug symbols
```

---

## 📋 Menu Options

1. **Add New Item** - Add products to inventory
2. **Display All Items** - View complete inventory with totals
3. **Search by ID** - Find specific items by ID
4. **Search by Name** - Find items by name (case-sensitive)
5. **Update Item** - Modify existing item details
6. **Delete Item** - Remove items from inventory
7. **Low Stock Alert** - Check items below threshold
8. **Sort by Price** - Organize inventory by price
9. **Save to File** - Export to custom file
10. **Load from File** - Import inventory data
11. **Create Backup** - Generate timestamped backup
12. **Export to CSV** - Export in CSV format
13. **View Statistics** - Comprehensive inventory analysis
0. **Exit Program** - Save and quit

---

## 💡 Key Features Explained

### Data Structures
- **Linked Lists**: Dynamic memory management for inventory items
- **Struct-based Design**: Organized data representation
- **Pointer Manipulation**: Efficient memory usage

### File Operations
- **CSV Format**: Industry-standard data exchange
- **Error Handling**: Robust file I/O with validation
- **Backup System**: Automatic data protection

### User Interface
- **Input Validation**: Prevents crashes from invalid input
- **Formatted Output**: Professional-looking tables
- **Error Messages**: Clear feedback for users

---

## 🧪 Sample Data

The system includes `sample_data.csv` with pre-loaded inventory items:
- Electronics (Laptops, Mice, Keyboards)
- Computer Components (RAM, Hard Drives)
- Accessories (Cables, Webcams, Speakers)

---

## 🔧 Technical Details

- **Language**: C (C99 standard)
- **Compiler**: GCC with strict warnings
- **Memory Management**: Dynamic allocation with proper cleanup
- **Data Structure**: Singly linked list
- **File Format**: CSV for data persistence
- **Platform**: Cross-platform (Windows/Linux/macOS)

---

## 🎯 Learning Objectives

This project demonstrates:
- ✅ Linked List implementation and manipulation
- ✅ File I/O operations and error handling
- ✅ Memory management and pointer usage
- ✅ Modular programming with headers
- ✅ User interface design in console applications
- ✅ Data validation and error handling
- ✅ CSV parsing and generation

---

## 🚧 Future Enhancements

- 🗄️ **Database Integration** - SQLite/MariaDB support
- 🔐 **User Authentication** - Multi-user support
- 📊 **Advanced Reports** - Graphical charts and analytics
- 🌐 **Web Interface** - Browser-based UI
- 📱 **Mobile App** - Cross-platform mobile access

---

## 🤝 Contributing

Contributions are welcome! Please feel free to submit pull requests or open issues for bugs and feature requests.

---

## 📄 License

This project is open source. Feel free to use it for educational purposes.

---

## 👨‍💻 Author

Developed with ❤️ for learning C programming and data structures.

**Happy Coding! 🚀**