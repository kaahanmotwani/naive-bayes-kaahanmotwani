// Copyright (c) 2020 Kaahan Motwani. All rights reserved.

#ifndef BAYES_CLASSIFIER_H_
#define BAYES_CLASSIFIER_H_

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using std::ifstream;
using std::istream;
using std::string;
using std::vector;
using std::cout;
using std::endl;

namespace bayes {
  const int kNumDigits = 10;
  const int kImageSize = 28;

  /**
   *
   * @param test_images_stream
   * @param test_labels_stream
   */
  void ValidateClassification(ifstream& test_images_stream,
      ifstream& test_labels_stream);

  /**
   *
   * @param posterior_probabilities
   * @param test_labels
   */
  void ClassifyAnImage(vector<double>& posterior_probabilities,
      const vector<double>& test_labels);

  /**
   *
   * @param test_labels_stream
   * @return
   */
  vector<double> AddLabelsToAVector(ifstream& test_labels_stream);

  /**
   *
   * @param test_images_stream
   * @param csv_probabilities
   * @param priors
   * @param test_labels
   */
  void IterateThroughImages(ifstream& test_images_stream,
      const vector< vector< vector<double>>>& image_probabilities,
      const vector<double>& priors, const vector<double>& test_labels);

  /**
   *
   * @param input_stream
   * @return
   */
  vector< vector< vector<double>>> ReadModelData(istream& input_stream);

  /**
   *
   * @param input_stream
   * @return
   */
  vector<double> ReadPriorsFromModel(istream& input_stream);
}  // namespace bayes

#endif  // BAYES_CLASSIFIER_H_

