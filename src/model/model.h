#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_H_

#include <stack>
#include <string>
#include <vector>

// 1. Унарные операторы можно поставить только если строка пустая или предыдушая
// строка (
// 2. Цифры можно писать только после цифр, или после точки или если строка
// пустая или после (

namespace s21 {

class Model {
public:
  static Model &Instance();
  Model(Model const &) = delete;
  Model &operator=(Model const &) = delete;

  /**
   * @brief Метод добавления новой ликсемы в строку
   *
   * @param str - лексема к добавлению
   * @return true - валидная строка
   * @return false - невалидная строка
   */
  bool AddToExression(const std::string &str);

  /**
   * @brief Удаление последней лексемы из строки
   *
   * @return size_t - размер удаленной лексемы
   */
  size_t DeleteFromExpression();

  /**
   * @brief Компиляция выражения в обратную польскую нотацию
   *
   */
  void Compile();

  /**
   * @brief Является ли выражение в модели функцией
   *
   * @return true - является
   * @return false - не является
   */
  bool GetXStatus();

  /**
   * @brief Подсчет выражения
   *
   * @param from - х начальная
   * @param to - х конечная
   * @return std::pair<std::vector<double>, std::vector<double>> пара из
   * векторов точек по х и по у
   */
  std::pair<std::vector<double>, std::vector<double>> Calculate(double from,
                                                                double to);
  void Reset();

  /**
   * @brief Возвращает строку из модели
   *
   * @return std::string - строка
   */
  std::string GetExpression();

  /**
   * @brief Валидная ли строка в модели для подсчета
   *
   * @return true - валидная
   * @return false - не валидная
   */
  bool IsReadyToCalculate();

private:
  std::string expression_ = "";
  std::vector<std::string> compiled_expression_;
  bool x_status_ = false;

  Model() { snapshots_.push_back(Snapshot(0, 0, 0)); }
  std::vector<std::string> ToSimpleForm(const std::string &expression);
  void CompileExpression(const std::vector<std::string> &tokens);

  // 0 - пустая строка или ( или после бинарного оператора
  // 1 - число без точки
  // 2 - число с точкой
  // 3 - после E
  // 4 - после )
  // 5 - после бинарного оператора
  // 6 - после знака у E
  // 7 - после первого числа у Е
  // 8 - после х

  // после 0 может быть ( или число или любой унарный оператор или х
  // после 1 может быть ) или бинарный оператор или E или точка
  // после 2 все, что после 1 кроме точки
  // после 3 может быть + или -
  // после 4 может быть либо ) либо бинарный оператор
  // после 5 может быть ( или число или другой унарный оператор или х
  // после 6 могут быть только числа
  // после 7 может быть что и в 2, кроме E
  // после 8 может быть ) или бинарный оператор
  struct Snapshot {
    size_t bracketCounter = 0;
    size_t tokenSize = 0;
    size_t status = 0;

    Snapshot(size_t bracketCounter, size_t tokenSize, size_t status) {
      this->bracketCounter = bracketCounter;
      this->tokenSize = tokenSize;
      this->status = status;
    }
  };

  std::vector<Snapshot> snapshots_;
};

} // namespace s21

#endif // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_H_
