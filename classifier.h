#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include <iostream>
#include <string>
#include <vector>
#include "Eigen/Dense"

#include "feature.h"

using Eigen::ArrayXd;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class GNB {
 public:
  /**
   * Constructor
   */
  GNB();

  /**
   * Destructor
   */
  virtual ~GNB();

  /**
   * Train classifier
   */
  void train(const vector<vector<double>> &data,
             const vector<string> &labels);

  /**
   * Predict with trained classifier
   */
  string predict(const vector<double> &sample);

  vector<string> possible_labels = {"left","keep","right"};
};

#endif  // CLASSIFIER_H