/*
You're free to use it
but not recomended in large or serious projects
thanks, have fun!
*/

#pragma once


#ifndef NO_IO

#include <string>
#include <iostream>
#define print(...) _print_wrapper(false, __VA_ARGS__)
#define println(...) _print_wrapper(true, __VA_ARGS__)

template<typename... Args>
void _print_wrapper(bool nl, Args&&... args) {
    (std::cout << ... << std::forward<Args>(args));
    if (nl) std::cout << "\n";
}
#define input() ([](){ \
    std::string text; \
    std::getline(std::cin, text); \
    return text; \
}())

#endif

#ifndef NO_TYPENAME
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>  // Для std::pair

// Безопасные псевдонимы с префиксом py_
using py_str = std::string;
template<typename K, typename V>
using py_dict = std::unordered_map<K, V>;
template<typename T>
using py_list = std::vector<T>;

// Вывод словаря
template<typename K, typename V>
std::ostream& operator<<(std::ostream& os, const py_dict<K, V>& map) {
    os << "{";
    bool first = true;
    for (const auto& [key, value] : map) {
        if (!first) os << ", ";
        os << key << ": " << value;
        first = false;
    }
    os << "}";
    return os;
}

// Обёртка с Python-методами
template<typename K, typename V>
class PyDict : public py_dict<K, V> {
public:
    // Конструкторы
    PyDict() = default;
    PyDict(std::initializer_list<std::pair<const K, V>> init) : py_dict<K, V>(init) {}

    // Python-методы
    bool contains(const K& key) const {
        return this->count(key) > 0;
    }

    py_list<K> keys() const {
        py_list<K> result;
        for (const auto& [key, _] : *this) {
            result.push_back(key);
        }
        return result;
    }

    py_list<V> values() const {
        py_list<V> result;
        for (const auto& [_, value] : *this) {
            result.push_back(value);
        }
        return result;
    }
};

// Функция для создания словаря
template<typename K, typename V>
PyDict<K, V> make_dict(std::initializer_list<std::pair<const K, V>> init) {
    return PyDict<K, V>(init);
}

#define str(...) std::string(__VA_ARGS__)

#endif

#define elif else if
#define is ==
#define _not !
