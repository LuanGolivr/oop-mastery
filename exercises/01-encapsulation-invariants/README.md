# Challenge 01: Encapsulation & Domain Invariants (Digital Escrow Account)

## Overview
A frequent anti-pattern in Object-Oriented Programming is the **Anemic Domain Model**: classes that act merely as passive data bags with indiscriminate public getters and setters. This delegates business logic and invariant validation to external consumers, making internal state corruption inevitable.

Your goal is to design and implement a **Digital Escrow Account** entity that fully encapsulates its internal state, exposes expressive business-oriented operations, and strictly enforces its domain invariants without relying on external validators.

---

## Domain Rules & Invariants

### 1. Identity & Balance
- An escrow account must be initialized with a unique identifier and an initial status of `PENDING`.
- The initial balance is zero unless explicitly provided via an initial valid funding operation.
- The balance must **never** be updated through generic setters (`setBalance`) or direct field manipulation.
- Represent currency values safely (e.g., integer cents/minor units to prevent floating-point precision issues).

### 2. Lifecycle & State Machine
- **Valid States:** `PENDING`, `ACTIVE`, `FROZEN`, `CLOSED`.
- **Allowed Transitions:**
  - `PENDING` $\rightarrow$ `ACTIVE`: Occurs automatically or exclusively upon the first successful deposit.
  - `ACTIVE` $\rightarrow$ `FROZEN`: Account can be frozen (e.g., audit, dispute).
  - `FROZEN` $\rightarrow$ `ACTIVE`: Account can be unfrozen.
  - `ACTIVE` or `FROZEN` $\rightarrow$ `CLOSED`: Final state. Once closed, no further transitions or operations are allowed.
- Any transition not explicitly listed above must be rejected as invalid.

### 3. Financial Invariants
- **Deposits:**
  - Only allowed in `PENDING` or `ACTIVE` states.
  - Amount must be strictly greater than zero.
- **Withdrawals / Fund Releases:**
  - Only allowed in `ACTIVE` state.
  - Amount must be strictly greater than zero and cannot exceed the current available balance.
  - The balance can **never** become negative under any circumstance.
- **Closure:**
  - An account can only transition to `CLOSED` if its current balance is **exactly zero**. All funds must be released or refunded prior to closing.

---

## Requirements & Constraints

1. **Rich Domain Methods:** Expose intention-revealing methods (e.g., `deposit(amount)`, `freeze()`, `unfreeze()`, `releaseFunds(amount)`, `close()`) rather than property mutators.
2. **Strict Invariant Protection:** Any operation violating business rules must fail cleanly (throw an idiomatic domain exception or return an explicit result/error type).
3. **Language-Specific Guidance:**
   - **C++:**
     - Enforce `const`-correctness for inspection methods (e.g., getters).
     - Keep member variables strictly `private`.
     - Manage object lifecycle cleanly without memory leaks.
   - **TypeScript:**
     - Enforce encapsulation using `private` or ECMAScript private fields (`#field`).
     - Leverage literal union types for finite state representations.
     - Ensure read-only exposure of critical metadata.

---

## Deliverables
- Source code in `cpp/` and/or `ts/`.
- A minimal execution script or unit test suite proving that invalid states cannot be reached.
- `solution.md` containing your rationale on how encapsulation was preserved and how errors/edge cases were handled.