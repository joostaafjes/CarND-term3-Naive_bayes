//
// Created by Joost Aafjes on 2019-04-04.
//

#ifndef CARND_TERM3_LESSON3_NAIVE_BAYES_COUNTER_H
#define CARND_TERM3_LESSON3_NAIVE_BAYES_COUNTER_H

class Counter {
 public:
  Counter();

  double sum = 0;
  int count = 0;
  double mean = 0.0, standard_deviation_2 = 0.0;

  void update(double number);
  void calculate_mean_and_standard_deviation(double number);
  void calculate_mean_and_standard_deviation_poststep();
  double predict_cond_p(double number);
};

#endif //CARND_TERM3_LESSON3_NAIVE_BAYES_COUNTER_H
