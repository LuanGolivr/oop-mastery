# 🏛️ OOP & Software Design Mastery Lab

A hands-on laboratory for deep-diving into **Object-Oriented Programming (OOP)**, **SOLID Principles**, and **Design Patterns (GoF & Architectural)** through idiomatic implementations in modern **C++** and **TypeScript**.

The primary objective of this repository is not merely solving algorithmic problems, but mastering domain modeling, cohesive contract design, infrastructure decoupling, object lifecycles, and trade-off analysis.

---

## 🎯 Learning Objectives

- Master core OOP pillars (Abstraction, Encapsulation, Composition over Inheritance, Polymorphism).
- Apply and stress-test the **SOLID** principles:
  - **S**ingle Responsibility Principle (SRP)
  - **O**pen/Closed Principle (OCP)
  - **L**iskov Substitution Principle (LSP)
  - **I**nterface Segregation Principle (ISP)
  - **D**ependency Inversion Principle (DIP)
- Implement Creational, Structural, and Behavioral Design Patterns across real-world business scenarios.
- Analyze design trade-offs between a statically typed, manually managed memory model (**C++**) and a structural type system running on an asynchronous runtime (**TypeScript**).

---

## 📂 Repository Structure

```text
.
├── docs/
│   └── PROMPT_FEEDBACK.md        # Standardized prompt template for LLM/peer code reviews
├── exercises/
│   ├── 01-srp-checkout/          # Exercise 1: Single Responsibility Principle
│   │   ├── README.md             # Problem statement and domain constraints
│   │   ├── solution.md           # Architectural defense and design rationale
│   │   ├── cpp/                  # C++ implementation
│   │   └── ts/                   # TypeScript implementation
│   ├── 02-ocp-discounts/         # Exercise 2: Open/Closed Principle
│   └── ...                       # Upcoming modules (LSP, ISP, DIP, Patterns)
└── README.md                     # Roadmap and repository overview