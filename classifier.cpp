#include "classifier.h"
#include <math.h>
#include <string>
#include <vector>

using Eigen::ArrayXd;
using std::string;
using std::vector;

vector<Feature> features;

// Initializes GNB
GNB::GNB() {
  /**
   * TODO: Initialize GNB, if necessary. May depend on your implementation.
   */
  for (auto const &label : possible_labels) {
    features.push_back(Feature(label));
  }
}

GNB::~GNB() {}

void GNB::train(const vector<vector<double>> &data,
                const vector<string> &labels) {
  /**
   * Trains the classifier with N data points and labels.
   * @param data - array of N observations
   *   - Each observation is a tuple with 4 values: s, d, s_dot and d_dot.
   *   - Example : [[3.5, 0.1, 5.9, -0.02],
   *                [8.0, -0.3, 3.0, 2.2],
   *                 ...
   *                ]
   * @param labels - array of N labels
   *   - Each label is one of "left", "keep", or "right".
   */

  int index = 0;
  for (auto row: data) {
    for (auto &feature: features) {
      cout << feature.feature_name << endl;
      cout << labels[index] << endl;
      if (feature.feature_name == labels[index]) {
        feature.update(row);
        break;
      }
    }
    index++;
  }

  index = 0;
  for (auto row: data) {
    for (auto &feature: features) {
      cout << feature.feature_name << endl;
      cout << labels[index] << endl;
      if (feature.feature_name == labels[index]) {
        feature.calculate_mean_and_standard_deviation(row, data.size());
        break;
      }
    }
    index++;
  }

  for (auto &feature: features) {
    feature.calculate_mean_and_standard_deviation_poststep();
  }

  cout << "Totals:" << endl;
  for (auto feature: features) {
    cout << feature.feature_name << " (prior p = " << feature.prior_probability << ")" << endl;
    cout << "s       - mean : " << feature.s.mean << "(" << feature.s.count << ") std dev 2 : "
         << feature.s.standard_deviation_2 << endl;
    cout << "d       - mean : " << feature.d.mean << "(" << feature.d.count << ") std dev 2 : "
         << feature.d.standard_deviation_2 << endl;
    cout << "delta_s - mean : " << feature.delta_s.mean << "(" << feature.delta_s.count << ") std dev 2 : "
         << feature.delta_s.standard_deviation_2 << endl;
    cout << "delta_d - mean : " << feature.delta_d.mean << "(" << feature.delta_d.count << ") std dev 2 : "
         << feature.delta_d.standard_deviation_2 << endl;
  }
}

string GNB::predict(const vector<double> &sample) {
  /**
   * Once trained, this method is called and expected to return 
   *   a predicted behavior for the given observation.
   * @param observation - a 4 tuple with s, d, s_dot, d_dot.
   *   - Example: [3.5, 0.1, 8.5, -0.2]
   * @output A label representing the best guess of the classifier. Can
   *   be one of "left", "keep" or "right".
   *
   * TODO: Complete this function to return your classifier's prediction
   */

  double best_p = 0.0;
  string best_label = "none";
  for (auto feature: features) {
    double p_feature = feature.predict(sample);
    if (p_feature > best_p) {
      best_p = p_feature;
      best_label = feature.feature_name;
    }
  }

  return best_label;
}