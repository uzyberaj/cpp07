<p align="left">
  <a href="#--------cpp07--">🇬🇧 English</a> |
  <a href="#--------cpp07---1">🇫🇷 Français</a>
</p>

<h1 align="center">
  <br>
  <img src="https://i.ibb.co/MkL14CvZ/logo-cpp-bonus.png" alt="C++ logo" width="150">
  <br>
  cpp07
  <br>
</h1>

<h4 align="center"><em>C++ Module 07 — C++ templates: generic functions and a dynamic array class.</em></h4>

<p align="center">
  <img src="https://img.shields.io/badge/exercises-3-orange">
  <img src="https://img.shields.io/badge/C%2B%2B-100%25-blue">
  <img src="https://img.shields.io/badge/Grade-100%2F100-brightgreen">
  <img src="https://img.shields.io/badge/standard-C%2B%2B98-informational">
</p>

<p align="center">
  <a href="./subject.md">Subject</a> |
  <a href="#-project-overview">Overview</a> •
  <a href="#-code-architecture-and-organization">Architecture</a> •
  <a href="#-operating">Operating</a> •
  <a href="#%EF%B8%8F-compiling-and-testing">Compiling</a>
</p>

---

## 📌 **Project overview**

**cpp07** is the seventh C++ module of the 42 Common Core. It introduces **C++ templates** through three progressive exercises: generic utility functions, a generic array iterator, and a class template that behaves like a fixed-size dynamic array.

The project is split into **3 independent exercises**. All code complies with **C++98**. No STL containers or algorithms are used (forbidden until Module 08).

### 1. Exercise 00 — Start with a few functions ✅

Three **function templates** in `whatever.hpp`:

* `swap(a, b)` — swaps two values of the same type by reference
* `min(a, b)` — returns the smallest value; if equal, returns the **second** argument
* `max(a, b)` — returns the greatest value; if equal, returns the **second** argument

Works with any type supporting comparison operators (`int`, `std::string`, etc.). Templates must be defined in the header file.

### 2. Exercise 01 — Iter ✅

A **function template** `iter(array, length, func)` that:

* Takes the address of an array, its length as a `const` value, and a callable function
* Applies `func` to every element without returning anything
* Supports both **const reference** and **non-const reference** callbacks depending on context
* Works with any array type; the third parameter can be an instantiated function template

### 3. Exercise 02 — Array ✅

A **class template** `Array<T>` that implements a fixed-size dynamic array:

* Default constructor → empty array (`size() == 0`)
* Constructor `(unsigned int n)` → `n` elements value-initialized via `new T[n]()`
* Copy constructor and assignment operator with **deep copy** (independent arrays)
* `operator[]` for read/write access + `const` overload for read-only access
* Out-of-bounds access throws `std::exception`
* `size()` returns the number of elements without modifying the instance
* Memory allocated exclusively with `new[]`, freed with `delete[]`

### Error handling ⚠️

`Array::operator[]` throws `std::exception` when the index is out of range. Catchable via `catch (std::exception& e)`.

---

## 📂 **Code architecture and organization**

```
cpp07/
├── ex00/   whatever.hpp — swap, min, max
├── ex01/   iter.hpp — iter
├── ex02/   Array.hpp + Array.tpp — Array<T>
├── subject.md
└── evaluation_sheet.md
```

#### 🔹 Function templates — `swap`, `min`, `max` (ex00)

| Function | Description |
|----------|-------------|
| `swap(T& a, T& b)` | Swaps two values in place; returns nothing |
| `min(T const& a, T const& b)` | Returns the smaller value; on equality, returns `b` |
| `max(T const& a, T const& b)` | Returns the greater value; on equality, returns `b` |

#### 🔹 Function template — `iter` (ex01)

| Function | Description |
|----------|-------------|
| `iter(T* array, size_t const& length, F func)` | Iterates over `length` elements and calls `func` on each one |

`T` deduces the element type (including `const` when the array is const). `F` deduces the callback type (function pointer or instantiated function template).

#### 🔹 Class template — `Array<T>` (ex02)

| Method | Description |
|--------|-------------|
| `Array()` | Creates an empty array |
| `Array(unsigned int n)` | Creates an array of `n` value-initialized elements |
| `Array(Array const& other)` | Deep copy constructor |
| `operator=(Array const& other)` | Deep copy assignment |
| `~Array()` | Frees memory with `delete[]` |
| `operator[](unsigned int index)` | Read/write access; throws if out of bounds |
| `operator[](unsigned int index) const` | Read-only access on const instances |
| `size() const` | Returns the number of elements |

---

## 🏛 **Operating**

### 🔸 **Function templates (ex00–ex01)**

A function template is a blueprint that generates a function for each type used at compile time:

```cpp
template<typename T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
```

When calling `swap(a, b)` with `int` variables, the compiler generates a `swap(int&, int&)` version. No `void*` or type casting needed.

**Key rule from the subject:** templates must be **defined in header files** (`.hpp`), not in `.cpp` files — otherwise the linker cannot instantiate them.

### 🔸 **min / max — equality returns the second argument**

```cpp
min(3, 5);  // → 3
min(5, 5);  // → 5 (second argument)
max(3, 5);  // → 5
max(5, 5);  // → 5 (second argument)
```

Use `::min` and `::max` (global namespace) to avoid conflict with `std::min` / `std::max`.

### 🔸 **iter — const vs non-const (ex01)**

The single overload `iter(T*, size_t const&, F)` handles both cases through template deduction:

* `int arr[]` + `void f(int&)` → modifies elements in place
* `const int arr[]` + `void f(int const&)` → read-only iteration

The third parameter `F` accepts plain functions, function pointers, or instantiated function templates (`print<int>`, etc.).

### 🔸 **Class templates (ex02)**

A class template is a blueprint for a class parameterized by type:

```cpp
Array<int> numbers(5);          // array of 5 ints (all 0)
Array<std::string> words(3);    // array of 3 default-constructed strings
```

Implementation is split between `Array.hpp` (declaration) and `Array.tpp` (definitions), included at the bottom of the header.

### 🔸 **Value initialization with `new T[n]()`**

The subject tip: `new int()` gives `0`. Similarly, `new T[n]()` value-initializes every element:

* `int` → `0`
* `std::string` → empty string
* Custom types → default constructor

### 🔸 **Deep copy (ex02)**

Copy constructor and assignment operator allocate a **new** array and copy each element individually. Modifying the copy never affects the original:

```cpp
Array<int> a(2);
a[0] = 42;
Array<int> b = a;   // deep copy
b[0] = 99;
// a[0] is still 42
```

### 🔸 **Out-of-bounds access**

Both `operator[]` overloads check `index >= _size` and throw `std::exception`. An empty array (`size() == 0`) throws on any access attempt.

---

## ⚙️ **Compiling and testing**

Each exercise is **independent** and has its own `Makefile`. Compile and run from the exercise directory.

### 🔧 Compiling

| Exercise | Binary | Command |
|----------|--------|---------|
| ex00 | `whatever` | `cd ex00 && make` |
| ex01 | `iter` | `cd ex01 && make` |
| ex02 | `array` | `cd ex02 && make` |

```bash
make        # compile
make re     # full rebuild
make fclean # remove binary and object files
```

Compiler flags: `c++ -Wall -Wextra -Werror -std=c++98`

---

### ▶️ Use and execution

- #### ✅ Exercise 00 — `./whatever`

  ```bash
  cd ex00 && make && ./whatever
  ```

  Tests cover: subject example with `int` and `std::string`, `min`/`max` on equal values, `char`, `float`, `double`.

- #### ✅ Exercise 01 — `./iter`

  ```bash
  cd ex01 && make && ./iter
  ```

  Tests cover: evaluation output (`0 1 2 3 4` then `42 × 5`), const array + const ref, in-place modification, `std::string`, zero-length array, instantiated function template.

- #### ✅ Exercise 02 — `./array`

  ```bash
  cd ex02 && make && ./array
  ```

  Tests cover: empty array, value initialization, read/write and const access, out-of-bounds exception, copy constructor and assignment independence, `std::string` complex type.

  * Check memory leaks (macOS): `leaks -atExit -- ./array`

#### Example — subject snippet (ex00)

```cpp
int a = 2;
int b = 3;

::swap(a, b);
std::cout << "a = " << a << ", b = " << b << std::endl;
// Output: a = 3, b = 2
```

---

<h1 align="center">
  <br>
  <img src="https://i.ibb.co/MkL14CvZ/logo-cpp-bonus.png" alt="logo C++" width="150">
  <br>
  cpp07
  <br>
</h1>

<h4 align="center"><em>Module C++ 07 — Templates C++ : fonctions génériques et tableau dynamique.</em></h4>

<p align="center">
  <img src="https://img.shields.io/badge/exercices-3-orange">
  <img src="https://img.shields.io/badge/C%2B%2B-100%25-blue">
  <img src="https://img.shields.io/badge/Note-100%2F100-brightgreen">
  <img src="https://img.shields.io/badge/standard-C%2B%2B98-informational">
</p>

<p align="center">
  <a href="./subject.md">Sujet</a> |
  <a href="#-aperçu-du-projet">Aperçu</a> •
  <a href="#-architecture-et-organisation-du-code">Architecture</a> •
  <a href="#-fonctionnement">Fonctionnement</a> •
  <a href="#%EF%B8%8F-compilation-et-tests">Compilation</a>
</p>

---

## 📌 **Aperçu du projet**

**cpp07** est le septième module C++ du Common Core de 42. Il introduit les **templates C++** à travers trois exercices progressifs : fonctions utilitaires génériques, itération générique sur un tableau, et une classe template qui se comporte comme un tableau dynamique de taille fixe.

Le projet est découpé en **3 exercices indépendants**. Tout le code respecte le standard **C++98**. Aucun conteneur ni algorithme STL n'est utilisé (interdit jusqu'au Module 08).

### 1. Exercice 00 — Start with a few functions ✅

Trois **fonctions template** dans `whatever.hpp` :

* `swap(a, b)` — échange deux valeurs du même type par référence
* `min(a, b)` — retourne la plus petite ; si égales, retourne le **second** argument
* `max(a, b)` — retourne la plus grande ; si égales, retourne le **second** argument

Fonctionne avec tout type supportant les opérateurs de comparaison (`int`, `std::string`, etc.). Les templates doivent être définis dans le header.

### 2. Exercice 01 — Iter ✅

Une **fonction template** `iter(array, length, func)` qui :

* Prend l'adresse d'un tableau, sa longueur en `const`, et une fonction callable
* Applique `func` sur chaque élément sans rien retourner
* Supporte les callbacks en **const reference** et **non-const reference** selon le contexte
* Fonctionne avec tout type de tableau ; le 3ᵉ paramètre peut être une fonction template instanciée

### 3. Exercice 02 — Array ✅

Une **classe template** `Array<T>` qui implémente un tableau dynamique de taille fixe :

* Constructeur par défaut → tableau vide (`size() == 0`)
* Constructeur `(unsigned int n)` → `n` éléments value-initialisés via `new T[n]()`
* Constructeur de copie et opérateur d'affectation en **copie profonde** (tableaux indépendants)
* `operator[]` en lecture/écriture + surcharge `const` en lecture seule
* Accès hors limites → `std::exception`
* `size()` retourne le nombre d'éléments sans modifier l'instance
* Mémoire allouée exclusivement avec `new[]`, libérée avec `delete[]`

### Gestion des erreurs ⚠️

`Array::operator[]` lance `std::exception` quand l'index est hors limites. Attrapable via `catch (std::exception& e)`.

---

## 📂 **Architecture et organisation du code**

```
cpp07/
├── ex00/   whatever.hpp — swap, min, max
├── ex01/   iter.hpp — iter
├── ex02/   Array.hpp + Array.tpp — Array<T>
├── subject.md
└── evaluation_sheet.md
```

#### 🔹 Fonctions template — `swap`, `min`, `max` (ex00)

| Fonction | Description |
|----------|-------------|
| `swap(T& a, T& b)` | Échange deux valeurs sur place ; ne retourne rien |
| `min(T const& a, T const& b)` | Retourne la plus petite ; à égalité, retourne `b` |
| `max(T const& a, T const& b)` | Retourne la plus grande ; à égalité, retourne `b` |

#### 🔹 Fonction template — `iter` (ex01)

| Fonction | Description |
|----------|-------------|
| `iter(T* array, size_t const& length, F func)` | Parcourt `length` éléments et appelle `func` sur chacun |

`T` déduit le type des éléments (y compris `const` si le tableau est const). `F` déduit le type du callback (pointeur de fonction ou fonction template instanciée).

#### 🔹 Classe template — `Array<T>` (ex02)

| Méthode | Description |
|---------|-------------|
| `Array()` | Crée un tableau vide |
| `Array(unsigned int n)` | Crée un tableau de `n` éléments value-initialisés |
| `Array(Array const& other)` | Constructeur de copie profonde |
| `operator=(Array const& other)` | Affectation par copie profonde |
| `~Array()` | Libère la mémoire avec `delete[]` |
| `operator[](unsigned int index)` | Accès lecture/écriture ; throw si hors limites |
| `operator[](unsigned int index) const` | Accès lecture seule sur instance const |
| `size() const` | Retourne le nombre d'éléments |

---

## 🏛 **Fonctionnement**

### 🔸 **Fonctions template (ex00–ex01)**

Une fonction template est un modèle qui génère une fonction pour chaque type utilisé à la compilation :

```cpp
template<typename T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
```

En appelant `swap(a, b)` avec des `int`, le compilateur génère une version `swap(int&, int&)`. Pas besoin de `void*` ni de cast.

**Règle du sujet :** les templates doivent être **définis dans les headers** (`.hpp`), pas dans les `.cpp` — sinon le linker ne peut pas les instancier.

### 🔸 **min / max — égalité → second argument**

```cpp
min(3, 5);  // → 3
min(5, 5);  // → 5 (second argument)
max(3, 5);  // → 5
max(5, 5);  // → 5 (second argument)
```

Utiliser `::min` et `::max` (espace de noms global) pour éviter le conflit avec `std::min` / `std::max`.

### 🔸 **iter — const vs non-const (ex01)**

La surcharge unique `iter(T*, size_t const&, F)` gère les deux cas par déduction de template :

* `int arr[]` + `void f(int&)` → modification in-place
* `const int arr[]` + `void f(int const&)` → itération en lecture seule

Le 3ᵉ paramètre `F` accepte des fonctions classiques, des pointeurs de fonction, ou des fonctions template instanciées (`print<int>`, etc.).

### 🔸 **Classes template (ex02)**

Une classe template est un modèle de classe paramétré par un type :

```cpp
Array<int> numbers(5);          // tableau de 5 int (tous à 0)
Array<std::string> words(3);    // tableau de 3 string vides
```

L'implémentation est séparée entre `Array.hpp` (déclaration) et `Array.tpp` (définitions), inclus à la fin du header.

### 🔸 **Value initialization avec `new T[n]()`**

L'astuce du sujet : `new int()` donne `0`. De même, `new T[n]()` value-initialise chaque élément :

* `int` → `0`
* `std::string` → chaîne vide
* Types custom → constructeur par défaut

### 🔸 **Copie profonde (ex02)**

Le constructeur de copie et l'opérateur d'affectation allouent un **nouveau** tableau et copient chaque élément. Modifier la copie n'affecte jamais l'original :

```cpp
Array<int> a(2);
a[0] = 42;
Array<int> b = a;   // copie profonde
b[0] = 99;
// a[0] vaut toujours 42
```

### 🔸 **Accès hors limites**

Les deux surcharges de `operator[]` vérifient `index >= _size` et lancent `std::exception`. Un tableau vide (`size() == 0`) throw à tout accès.

---

## ⚙️ **Compilation et tests**

Chaque exercice est **indépendant** et possède son propre `Makefile`. Compiler et exécuter depuis le dossier de l'exercice.

### 🔧 Compilation

| Exercice | Binaire | Commande |
|----------|---------|----------|
| ex00 | `whatever` | `cd ex00 && make` |
| ex01 | `iter` | `cd ex01 && make` |
| ex02 | `array` | `cd ex02 && make` |

```bash
make        # compiler
make re     # recompilation complète
make fclean # supprime binaire et fichiers objets
```

Flags : `c++ -Wall -Wextra -Werror -std=c++98`

---

### ▶️ Utilisation et exécution

- #### ✅ Exercice 00 — `./whatever`

  ```bash
  cd ex00 && make && ./whatever
  ```

  Tests : exemple du sujet avec `int` et `std::string`, `min`/`max` à égalité, `char`, `float`, `double`.

- #### ✅ Exercice 01 — `./iter`

  ```bash
  cd ex01 && make && ./iter
  ```

  Tests : sortie d'évaluation (`0 1 2 3 4` puis `42 × 5`), tableau const + const ref, modification in-place, `std::string`, longueur nulle, fonction template instanciée.

- #### ✅ Exercice 02 — `./array`

  ```bash
  cd ex02 && make && ./array
  ```

  Tests : tableau vide, value initialization, accès lecture/écriture et const, exception hors limites, indépendance copie/affectation, type complexe `std::string`.

  * Vérifier les fuites mémoire (macOS) : `leaks -atExit -- ./array`

#### Exemple — extrait du sujet (ex00)

```cpp
int a = 2;
int b = 3;

::swap(a, b);
std::cout << "a = " << a << ", b = " << b << std::endl;
// Sortie : a = 3, b = 2
```
