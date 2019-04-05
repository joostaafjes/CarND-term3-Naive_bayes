//
// Created by Joost Aafjes on 2019-04-03.
//

#ifndef CARND_TERM3_LESSON3_NAIVE_BAYES_FEATURE_H
#define CARND_TERM3_LESSON3_NAIVE_BAYES_FEATURE_H

#include <string>
#include <vector>

#include "counter.h"

using std::string;
using std::vector;

class Feature {

 public:
  /*
   * Constructor
   */
  Feature(string feature_name);

  string feature_name;

  void update(vector<double> row);
  void calculate_mean_and_standard_deviation(vector<double> row, double total_occurances);
  void calculate_mean_and_standard_deviation_poststep();
  double predict(vector<double> sample);
  double prior_probability = 0.0;

  double get_d(vector<double> row);

  Counter s, delta_s, d, delta_d;
};

#endif //CARND_TERM3_LESSON3_NAIVE_BAYES_FEATURE_H
