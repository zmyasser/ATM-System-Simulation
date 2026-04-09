# 🏦 ATM System (C++ OOP Project)

<div align="center">

```
   █████╗ ████████╗███╗   ███╗
  ██╔══██╗╚══██╔══╝████╗ ████║
  ███████║   ██║   ██╔████╔██║
  ██╔══██║   ██║   ██║╚██╔╝██║
  ██║  ██║   ██║   ██║ ╚═╝ ██║
  ╚═╝  ╚═╝   ╚═╝   ╚═╝     ╚═╝

   Automated Teller Machine System
```

✨ **Secure • Modular • Object-Oriented • File-Based Simulation** ✨

</div>

---

## 📌 Overview

This project is a **console-based ATM system** built using **C++ and Object-Oriented Programming (OOP)** principles.
It simulates real-world ATM operations such as authentication, transactions, and account management.

The system is designed with a **modular architecture**, separating responsibilities into multiple classes (screens, utilities, and core entities).

---

## 🚀 Features

### 🔐 Authentication

* Client login using **Account Number + PIN**
* Limited login attempts (security mechanism)
* Login activity logging
* Encryption and decryption of data

### 💳 Banking Operations

* 💸 Quick Withdraw
* 💵 Normal Withdraw
* 📥 Deposit
* 📊 Check Balance
* 🔁 Transfer between accounts

### ⚙️ Client Management

* Update personal information:

  * Email
  * Phone number
  * PIN code

### 🧾 Logging System

* Transfer history recording
* Login register tracking
* File-based persistence

---

## 🧠 System Design

### 🧩 Core Concepts Used

* Object-Oriented Programming (OOP)
* Encapsulation & Abstraction
* File Handling (`fstream`)
* Data Serialization (custom format with separators)
* Static methods & factory patterns

---

## 🏗️ Project Structure

```
ATM-System/
│
├── Core/
│   ├── clsBankClient
│   ├── clsPerson
│
├── Screens/
│   ├── clsClientLoginScreen
│   ├── clsClientMainMenuScreen
│   ├── clsQuickWithdrawScreen
│   ├── clsNormalWithdrawScreen
│   ├── clsDepositScreen
│   ├── clsCheckBalanceScreen
│   ├── clsChangeClientInfoScreen
│
├── Utilities/
│   ├── clsString
│   ├── clsDate
│   ├── clsInputValidate
│   ├── clsUtility
│
├── Data Files/
│   ├── Clients.txt
│   ├── TransferRegister.txt
│   ├── RegisterClientLogin.txt
```

---

## 🔄 How It Works

### 1. Login Flow

```
User → Enter Credentials → Validate → Load Client → Open Main Menu
```

### 2. Transaction Flow (Example: Transfer)

```
Check Balance → Withdraw → Deposit → Log Transfer → Save Data
```

---

## 💾 Data Storage

All data is stored using **text files**:

* `Clients.txt` → client records
* `TransferRegister.txt` → transaction logs
* `RegisterClientLogin.txt` → login history

Custom separator:

```
#//#
```

---

## 🧪 Example Record Format

```
Date#//#SourceAcc#//#DestinationAcc#//#Amount#//#SourceBalance#//#DestinationBalance#//#User
```

---

## 🎯 Design Philosophy

* ✅ Keep the system **simple but structured**
* ✅ Focus on **real-world simulation**
* ✅ Prioritize **readability and maintainability**
* ✅ Avoid over-engineering

---

## ⚠️ Notes

* Uses `__declspec(property)` → works on **Visual Studio (MSVC only)**
* File-based system (no database)
* Console UI (no GUI)

---

## 🧑‍💻 Author

**Yasser Mouhamed**

* C, C++, C# Developer (in progress 🚀)
* Full-Stack Desktop Application Developer
* Future Embedded Systems Engineer ⚙️

---

<div align="center">

⭐ If you like this project, consider improving it further!

</div>
