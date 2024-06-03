#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_DATARECOGNIZER_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_DATARECOGNIZER_H_

#include <string>

namespace s21 {

/**
 * @brief Является ли строка с i позиции открывающей скобкой
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsBrOpen(const std::string &expression, size_t i);

/**
 * @brief Является ли строка с i позиции закрывающей скобкой
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsBrClose(const std::string &expression, size_t i);

/**
 * @brief Является ли строка с i позиции плюсом
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsPlus(const std::string &expression, size_t i);

/**
 * @brief Является ли строка с i позиции минусом
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsMinus(const std::string &expression, size_t i);

/**
 * @brief Является ли строка с i позиции знаком умножения
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsMultiply(const std::string &expression, size_t i);

/**
 * @brief Является ли строка с i позиции делением
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsDivide(const std::string &expression, size_t i);

/**
 * @brief Является ли строка с i позиции степенью
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsPow(const std::string &expression, size_t i);

/**
 * @brief Является ли строка с i позиции остатком от деления
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsMod(const std::string &expression, size_t i);

/**
 * @brief Является ли строка с i позиции синусом
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsSin(const std::string &expression, size_t i);

/**
 * @brief Является ли строка с i позиции арксинусом
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsAsin(const std::string &expression, size_t i);

/**
 * @brief Является ли строка с i позиции косинусом
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsCos(const std::string &expression, size_t i);

/**
 * @brief Является ли строка с i позиции арккосинусом
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsAcos(const std::string &expression, size_t i);

/**
 * @brief Является ли строка с i позиции тангенсом
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsTan(const std::string &expression, size_t i);

/**
 * @brief Является ли строка с i позиции арктангенсом
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsAtan(const std::string &expression, size_t i);

/**
 * @brief Является ли строка с i позиции котангенсом
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsCtg(const std::string &expression, size_t i);

/**
 * @brief Является ли строка с i позиции квадратным корнем
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsSqrt(const std::string &expression, size_t i);

/**
 * @brief Является ли строка с i позиции натуральным логарифмом
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsLn(const std::string &expression, size_t i);

/**
 * @brief Является ли строка с i позиции десятичным логарифмом
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsLog(const std::string &expression, size_t i);

/**
 * @brief Является ли строка с i позиции цифрой
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsDigit(const std::string &expression, size_t i);

/**
 * @brief Является ли строка с i позиции числом
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsValidForDigit(const std::string &expression, size_t i);

/**
 * @brief Является ли строка с i позиции бинарным оператором
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsBinary(const char op);

/**
 * @brief Является ли строка с i позиции унарным оператором
 *
 * @param expression - строка
 * @param i - позиция
 * @return true - является
 * @return false - не является
 */
bool IsUnary(const std::string &str);

} // namespace s21

#endif // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_DATARECOGNIZER_H_