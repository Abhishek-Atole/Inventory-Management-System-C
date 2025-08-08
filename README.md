# 🗃️ Inventory Management System in C

A robust, feature-rich **Inventory & Stock Management System** written in the **C programming language**, designed with an industry-standard modular structure. Perfect for learning advanced data structures, file handling, and system design.

---

## 📸 **System Screenshots**

### 🏠 **Main Interface**
<div align="center">

![Main Menu](images/01.png)
*Professional menu-driven interface with 13 comprehensive operations*

</div>

### 📋 **Menu Navigation**
<div align="center">

![Main Menu Navigation](images/02.png)
*Interactive menu system showing all available inventory management options*

</div>

### 📦 **Inventory Display & Management**

<table>
<tr>
<td width="50%">

![Display All Items](images/03.png)
*Display All Items - Complete inventory listing with formatted table view*

</td>
<td width="50%">

![Low Stock Alert](images/04.png)
*Low Stock Alert - Configurable threshold warnings for inventory monitoring*

</td>
</tr>
</table>

### 📊 **Analysis & Statistics**
<div align="center">

![Inventory Statistics](images/05.png)
*Comprehensive inventory statistics showing total value, item counts, and financial analysis*

</div>

### 💾 **File Operations**

<table>
<tr>
<td width="50%">

![Load Inventory from CSV](images/06.png)
*Load Inventory - Import inventory items from CSV file with data validation*

</td>
<td width="50%">

![Create Backup](images/07.png)
*Create Backup - Generate timestamped backup of current inventory data*

</td>
</tr>
</table>

### 🔍 **Search & Save Operations**

<table>
<tr>
<td width="50%">

![Search by ID](images/08.png)
*Search by ID - Quick item lookup functionality with detailed results*

</td>
<td width="50%">

![Save and Exit](images/09.png)
*Save Inventory & Exit - Persistent data storage with auto-save functionality*

</td>
</tr>
</table>

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
- 🎨 **Beautiful CLI Interface** - Professional ASCII formatting
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
├── images/             # System screenshots
│   ├── 01.png         # Main menu interface
│   ├── 02.png         # Menu navigation system
│   ├── 03.png         # Display all inventory items
│   ├── 04.png         # Low stock alert system
│   ├── 05.png         # Inventory statistics & analysis
│   ├── 06.png         # Load inventory from CSV file
│   ├── 07.png         # Create backup functionality
│   ├── 08.png         # Search inventory by ID
│   └── 09.png         # Save inventory and exit program
├── .vscode/           # VS Code configuration
├── .gitignore         # Git ignore rules
├── Makefile           # Build configuration
├── run_inventory.bat  # Windows execution script
├── sample_data.csv    # Test dataset
├── test_data.csv      # Clean test data
└── README.md          # Project documentation
```

---

## 🛠️ Technical Implementation

### Data Structures Used
- **Singly Linked List**: Dynamic inventory storage
- **Structures**: Custom NODE type for item representation
- **Pointers**: Advanced pointer manipulation for list operations

### Key Features
- **Memory Management**: Dynamic allocation and proper cleanup
- **File Handling**: Robust CSV parsing and generation
- **Error Handling**: Comprehensive input validation
- **Sorting Algorithms**: Bubble sort implementation
- **Search Algorithms**: Linear search by ID and name

---

## 🚀 Quick Start

### Prerequisites
- GCC compiler (4.9 or later)
- Windows/Linux/macOS operating system
- 50MB free disk space

### Installation & Running

```bash
# Clone the repository
git clone https://github.com/Abhishek-Atole/Inventory-Management-System-C.git
cd Inventory-Management-System-C

# Compile using GCC
gcc -Wall -Wextra -std=c99 -Iinclude src/main.c src/inventory.c src/database.c -o inventory_system

# Run the program
./inventory_system

# Or use the Windows batch file
run_inventory.bat
```

### Using Makefile
```bash
# Build the project
make all

# Clean build artifacts
make clean

# Debug build
make debug
```

---

## 💡 Usage Guide

1. **Starting the System**: Run the executable to see the main menu (Image 01 & 02)
2. **Loading Sample Data**: Use option 10 to load CSV files (Image 06)
3. **Viewing Inventory**: Use option 2 to display all items (Image 03)
4. **Monitoring Stock**: Use option 7 for low stock alerts (Image 04)
5. **Analytics**: Use option 13 for comprehensive statistics (Image 05)
6. **Searching**: Use option 3 for ID-based searches (Image 08)
7. **Backups**: Use option 11 to create timestamped backups (Image 07)
8. **Saving**: Auto-save on exit ensures data persistence (Image 09)

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

- 🗄️ **Database Integration** - SQLite support
- 🔐 **User Authentication** - Multi-user access
- 📊 **Advanced Analytics** - Charts and graphs
- 🌐 **Web Interface** - Browser-based UI
- 📱 **Mobile App** - Cross-platform mobile support
- 🔄 **Real-time Sync** - Cloud synchronization
- 📧 **Email Alerts** - Automated notifications
- 🏷️ **Barcode Support** - Scanner integration

---

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes:

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 🙏 Acknowledgments

- C programming community for inspiration
- Open source contributors
- Data structures and algorithms resources

---

## 📞 Contact

**Project Link**: [https://github.com/Abhishek-Atole/Inventory-Management-System-C](https://github.com/Abhishek-Atole/Inventory-Management-System-C)

**Happy Coding! 🚀**

---

<div align="center">

**⭐ If you found this project helpful, please consider giving it a star! ⭐**

![GitHub stars](https://img.shields.io/github/stars/Abhishek-Atole/Inventory-Management-System-C?style=social)
![GitHub forks](https://img.shields.io/github/forks/Abhishek-Atole/Inventory-Management-System-C?style=social)
![GitHub issues](https://img.shields.io/github/issues/Abhishek-Atole/Inventory-Management-System-C)

</div>