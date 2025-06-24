# Naming Conventions

Naming conventions are essential for improving code readability, consistency, and maintainability. Below are common naming styles used across various programming languages:

## camelCase

- **Definition**: The first letter is lowercase, and each subsequent word starts with an uppercase letter.
- **Example**: `firstName`
- **Used In**: JavaScript, Java, C#

## PascalCase

- **Definition**: Similar to camelCase, but the first letter is also uppercase.
- **Example**: `BankAccount`
- **Used In**: C#, Java (especially for class names)

## snake_case

- **Definition**: All words are lowercase and separated by underscores.
- **Example**: `user_name`
- **Used In**: Python, SQL

## UPPER_SNAKE_CASE (also known as SCREAMING_SNAKE_CASE)

- **Definition**: All uppercase letters with words separated by underscores.
- **Example**: `MAX_USERS`, `MAX_LOGIN_ATTEMPTS`
- **Used In**: Python, C, C++, Java (typically for constants)

## kebab-case

- **Definition**: All lowercase letters with words separated by hyphens.
- **Example**: `user-profile`
- **Used In**: CSS, URLs

## Hungarian Notation

- **Definition**: Prefixing variables with a type or purpose.
- **Example**: `iAge` (int), `fPrice` (float)
- **Used In**: C++, older programming styles

---

### Summary Table

| Naming Style           | **Example**          | Common Usage               |
| ---------------------- | -------------------- | -------------------------- |
| `camelCase`            | `firstName`          | JavaScript, Java, C#       |
| `PascalCase`           | `BankAccount`        | C#, Java (class names)     |
| `snake_case`           | `user_name`          | Python, SQL                |
| `UPPER_SNAKE_CASE`     | `MAX_USERS`          | C, C++, Python (constants) |
| `SCREAMING_SNAKE_CASE` | `MAX_LOGIN_ATTEMPTS` | Python, Java               |
| `kebab-case`           | `user-profile`       | CSS, URLs                  |
| `Hungarian Notation`   | `iAge`, `fPrice`     | C++, legacy code           |

---

## Code Documentation

### Language 1: C

- Used `snake_case` for variable and function names (e.g., `user_name`, `print_user_info`).
- Used `UPPER_SNAKE_CASE` for constants (e.g., `MAX_USERS`).
- These conventions are standard in C and help distinguish variables from constants.

### Language 2: C++

- Used `camelCase` for methods and variables (e.g., `firstName`, `displayInfo`).
- Used `PascalCase` for class names (e.g., `UserInfo`), common in C++ and Java.
- These conventions enhance readability and align with object-oriented practices.

### Why Use Naming Conventions?

- Increases code readability and clarity.
- Helps developers understand the role of identifiers at a glance.
- Improves collaboration and future maintainability.
