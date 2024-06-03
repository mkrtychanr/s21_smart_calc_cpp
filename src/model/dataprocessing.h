#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_DATAPROCESSING_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_DATAPROCESSING_H_

#include <stack>
#include <string>
#include <vector>

namespace s21 {

/**
 * @brief Функция подсчета для бинарного оператора
 *
 * @param lhs - левая часть выражения
 * @param rhs - правая часть выражения
 * @param op - оператор
 * @return double - значение
 */
double Binary(const double rhs, const double lhs, const char op);

/**
 * @brief Функция подсчета для унарного оператора
 *
 * @param number - число внутри оператора
 * @param op - оператор
 * @return double - значение
 */
double Unary(const double number, const char op);

/**
 * @brief Функция для обнаружения приоритета
 *
 * @param c - лексема
 * @return int - приоритет
 */
int Check(char c);

/**
 * @brief Подсчет одного шага
 *
 * @param tokens - вектор токенов выражение в обратной польской нотации
 * @param x - значение для x
 * @return double - значение
 */
double CalculateOneStep(const std::vector<std::string> &tokens, double x);

/**
 * @brief Вспомогательная функция обертка над стеком
 *
 * @param number стек
 * @return double значение наверху
 */
double StackWrap(std::stack<double> &number);

} // namespace s21

#endif // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_DATAPROCESSING_H_