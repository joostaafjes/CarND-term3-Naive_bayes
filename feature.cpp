//
// Created by Joost Aafjes on 2019-04-03.
//

#include <cmath>
#include "feature.h"

Feature::Feature(string feature_name) {
  this->feature_name = feature_name;
}

void Feature::update(vector<double> row) {
  s.update(row.at(0));
  d.update(get_d(row));
  delta_s.update(row.at(2));
  delta_d.update(row.at(3));
}

void Feature::calculate_mean_and_standard_deviation(vector<double> row, double total_occurances) {
  s.calculate_mean_and_standard_deviation(row.at(0));
  d.calculate_mean_and_standard_deviation(get_d(row));
  delta_s.calculate_mean_and_standard_deviation(row.at(2));
  delta_d.calculate_mean_and_standard_deviation(row.at(3));

  prior_probability = s.count / total_occurances;
}

void Feature::calculate_mean_and_standard_deviation_poststep() {
  s.calculate_mean_and_standard_deviation_poststep();
  d.calculate_mean_and_standard_deviation_poststep();
  delta_s.calculate_mean_and_standard_deviation_poststep();
  delta_d.calculate_mean_and_standard_deviation_poststep();
}

double Feature::predict(vector<double> sample) {
  return prior_probability
//      * s.predict_cond_p(sample.at(0))
      * d.predict_cond_p(get_d(sample))
      * delta_s.predict_cond_p(sample.at(2))
      * delta_d.predict_cond_p(sample.at(3));
}

double Feature::get_d(vector<double> row) {
 return row.at(1);
//  return fmod(row.at(1), 4.0); // 83.6% in stead of 84.4%
}