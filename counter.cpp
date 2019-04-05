//
// Created by Joost Aafjes on 2019-04-04.
//

#include <cmath>
#include "counter.h"

Counter::Counter() {
}

void Counter::update(double number) {
  sum = sum + number;
  count++;
}

void Counter::calculate_mean_and_standard_deviation(double number) {

  mean = sum / count;

  standard_deviation_2 = standard_deviation_2 + pow(number - mean, 2);
}

void Counter::calculate_mean_and_standard_deviation_poststep() {
  standard_deviation_2 = standard_deviation_2 / count;
}

double Counter::predict_cond_p(double number) {
  return exp(-pow(number - mean, 2) / (2 * standard_deviation_2)) / sqrt(2 * M_PI * standard_deviation_2);
}