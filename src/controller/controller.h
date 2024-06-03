#ifndef CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_H_

#include <string>

#include "../model/model.h"

namespace s21 {

class Controller {
public:
  /**
   * @brief Возвращает ссылку на синглтон контроллера
   *
   * @return Controller& - ссылка на контроллер
   */
  static Controller &Instance();

  Controller(Controller const &) = delete;
  Controller &operator=(Controller const &) = delete;

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
   * @brief Ресет данных в модели
   *
   */
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

  /**
   * @brief Является ли выражение в модели функцией
   *
   * @return true - является
   * @return false - не является
   */
  bool GetXStatus();

  /**
   * @brief Компиляция выражения в обратную польскую нотацию
   *
   */
  void Compile();

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

private:
  Model &m_ = s21::Model::Instance();
  Controller() = default;
};

} // namespace s21

#endif // CPP3_SMARTCALC_V2_0_1_SRC_CONTROLLER_H_