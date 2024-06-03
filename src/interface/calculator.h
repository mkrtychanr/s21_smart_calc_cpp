/*!
\file
\brief Заголовочный файл с объявлениям класса калькулятора (главного окна
программы)
*/

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QVector>
#include <stack>
#include <vector>

#include "graphic.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow {
  Q_OBJECT

public:
  /**
   * @brief Конструктор нового объекта калькулятора
   *
   * @param parent – Указатель на родительский виджет
   */
  Calculator(QWidget *parent = nullptr);

  /**
   * @brief Декструктор объекта
   *
   */
  ~Calculator();

private slots:

  /**
   * @brief Кнопка AC
   *
   */
  void on_acButton_clicked();

  /**
   * @brief Кнопка <-
   *
   */
  void on_backSpaceButton_clicked();

  /**
   * @brief Кнопка .
   *
   */
  void on_dotButton_clicked();

  /**
   * @brief Кнопка 0
   *
   */
  void on_zeroButton_clicked();

  /**
   * @brief Кнопка 1
   *
   */
  void on_oneButton_clicked();

  /**
   * @brief Кнопка 2
   *
   */
  void on_twoButton_clicked();

  /**
   * @brief Кнопка 3
   *
   */
  void on_threeButton_clicked();

  /**
   * @brief Кнопка 4
   *
   */
  void on_fourButton_clicked();

  /**
   * @brief Кнопка 5
   *
   */
  void on_fiveButton_clicked();

  /**
   * @brief Кнопка 6
   *
   */
  void on_sixButton_clicked();

  /**
   * @brief Кнопка 7
   *
   */
  void on_sevenButton_clicked();

  /**
   * @brief Кнопка 8
   *
   */
  void on_eightButton_clicked();

  /**
   * @brief Кнопка 9
   *
   */
  void on_nineButton_clicked();

  /**
   * @brief Кнопка +
   *
   */
  void on_plusButton_clicked();

  /**
   * @brief Кнопка -
   *
   */
  void on_minusButton_clicked();

  /**
   * @brief Кнопка *
   *
   */
  void on_mulButton_clicked();

  /**
   * @brief Кнопка /
   *
   */
  void on_divButton_clicked();

  /**
   * @brief Кнопка ^
   *
   */
  void on_powButton_clicked();

  /**
   * @brief Кнопка %
   *
   */
  void on_modButton_clicked();

  /**
   * @brief Кнопка )
   *
   */
  void on_closeBracketButton_clicked();

  /**
   * @brief Кнопка (
   *
   */
  void on_openBracketButton_clicked();

  /**
   * @brief Кнопка x
   *
   */
  void on_xButton_clicked();

  /**
   * @brief Кнопка sqrt
   *
   */
  void on_sqrtButton_clicked();

  /**
   * @brief Кнопка sin
   *
   */
  void on_sinButton_clicked();

  /**
   * @brief Кнопка cos
   *
   */
  void on_cosButton_clicked();

  /**
   * @brief Кнопка tan
   *
   */
  void on_tanButton_clicked();

  /**
   * @brief Кнопка asin
   *
   */
  void on_asinButton_clicked();

  /**
   * @brief Кнопка acos
   *
   */
  void on_acosButton_clicked();

  /**
   * @brief Кнопка atan
   *
   */
  void on_atanButton_clicked();

  /**
   * @brief Кнопка ln
   *
   */
  void on_lnButton_clicked();

  /**
   * @brief Кнопка log
   *
   */
  void on_logButton_clicked();

  /**
   * @brief Кнопка =
   *
   */
  void on_equalsButton_clicked();

  void on_eButton_clicked();

private:
  /**
   * @brief Объект графического интерфейса
   *
   */
  Ui::Calculator *ui;

  /**
   * @brief Строка с выражением
   *
   */
  QString str;

  s21::Controller &c = s21::Controller::Instance();

  /**
   * @brief Функция заглушка для восстановления валидности снимков состояний
   * после подсчета обычного выражения
   *
   * @param resultOfCalculation – Результат вычисления, по которому будут
   * валидироваться снимки состояний
   */
  void fillMomentsAfterCalcualte(const std::string &resultOfCalculation);

  void almostAnyButton(const std::string &handeledString);
};

#endif // CALCULATOR_H
