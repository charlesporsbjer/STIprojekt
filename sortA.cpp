#include <fstream>
#include <string>
#include <algorithm>

int main() {
  // Open the input file
  std::ifstream input_file("input.txt");
  if (!input_file) {
    std::cerr << "Error opening input file" << std::endl;
    return 1;
  }

  // Open the output file
  std::ofstream output_file("output.txt");
  if (!output_file) {
    std::cerr << "Error opening output file" << std::endl;
    input_file.close();
    return 1;
  }

  // Read words from input file into a vector
  std::vector<std::string> words;
  std::string word;
  while (std::getline(input_file, word)) {
    words.push_back(word);
  }

  // Sort the words
  std::sort(words.begin(), words.end());

  // Write sorted words to output file
  for (const auto& word : words) {
    output_file << word << std::endl;
  }

  // Close files
  input_file.close();
  output_file.close();

  return 0;
}